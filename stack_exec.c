#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int ret1(void);
extern void ret1_fin(void);

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

  printf("ret1 addr: %p\n", ret1);
  printf("ret1_fin addr: %p\n", ret1_fin);
  memcpy((void *)buf, (void *)ret1, (size_t)((void *)ret1_fin - (void *)ret1));
  
  int (*func)() =  (int (*)())buf;
  int retval = func();
  printf("func addr = %p\n", func);
  printf("retval = %d\n", retval);
  
  return 0;
}
