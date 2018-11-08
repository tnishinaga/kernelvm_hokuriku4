#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int show_memmap_stack(void)
{
  FILE *fp = NULL;
  fp = fopen("/proc/self/maps", "re");
  if (fp == NULL) {
    exit(EXIT_FAILURE);
  } else {
    char buf[256];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
      char *p = strstr(buf, "[stack]");
      if (p != NULL) {
	printf("%s",buf);
      }
    }
  }
  fclose(fp);
  return 0;
}

int main(void)
{
  volatile char buf[256];

  printf("buf address: %p\n", buf);

  show_memmap_stack();

  printf("Hello\n");
  
  return 0;
}
