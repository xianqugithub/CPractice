/* this is a genric flush buffer program. */
/* it flushes out the old buffer and put the input x into the buffer. */
/* can flush buffer at any time, NOT necessarily when the buffer is full. */
int _flushbuf(int x, FILE *fp)
{
  unsigned nc; /* record size of buffer for flush */
  int bufsize;

  if (fp < _iob || fp >= _iob + OPEN_MAX)
    return EOF;
  
  if (fp->flag & (_WRITE|_ERR) != _WRITE)
    return EOF;

  bufsize = (flag->flag & _UNBUF) ? 1:BUFSIZE;

  if (fp->base == NULL)
    if ((fp->base = (char *) malloc (bufsize)) == NULL) {
      fp->flag |= _ERR; /* open up flags for error */
      return EOF;
    }

  nc = fp->ptr - fp->base; /* record the number of characters in the buffer for flush*/

  if (write(fp->fd, fp->base, nc) != nc) {
    fp->flag |= _ERR;
    return EOF;
  }

  fp->ptr = fp->base;
  
  fp->cnt = bufsize - 1;

  *fp->ptr++ = (char) x; 

  return x;
}


/* completely flush the buffer associated with fp */
int fflush(FILE *fp)
{

  int fr = 0; /* flush result */
  
  if (fp < _iob || fp >= _iob + OPEN_MAX)
    return EOF;

  if (fp->flag & _WRITE)
    fr = _flushbuf(0, fp);
  
  fp->ptr = fp->base;
  fp->cnt = (fp->flag & _UNBUF) ? 1:BUFSIZE;

  return fr;
}

/* close up a file*/
int fclose(FILE *fp)
{
  int fr;

  if ((fr = fflush(fp)) != EOF) {
    free(fp->base);
    fp->ptr = NULL;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag &= ~(_READ|_WRITE);
  }

  return fr;

}
