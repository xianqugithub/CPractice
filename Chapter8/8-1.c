#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#define BUFSIZE 100

int main(int argc, char *argv[])
{
   /* file descriptor */
  int fd, n;
  char buf[BUFSIZE];
  
  if (argc == 1) {
    while ((n = read(0, buf, BUFSIZE)) > 0)
      write(1, buf, n);
  }

  else
    while (--argc > 0)
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
	fprintf(stderr, "can't open file: %s\n", *argv);
	exit(1);
      } else {
	while ((n = read(fd, buf, BUFSIZE)) > 0)
	  write(1, buf, n);
	close(fd);
      }

  exit(0);
      
}
