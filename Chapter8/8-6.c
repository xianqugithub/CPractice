void *_calloc (unsigned n, unsigned size)
{
  unsigned i, nb;
  char *p, *q;

  nb = n * size;

  if ((p = q = malloc(nb)) != NULL)
    for (i = 0; i < nb; i++)
      *p++ = 0;

  return q; /* no need to cast to void pointer? */
}
