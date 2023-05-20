#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
  int id;
  id = fork();
  if (id == 0)
  {
    printf("B\n");
    if (fork()==0)
      printf("C\n");
  }
  else
  {
    printf("A\n");
    if (fork()==0)
      printf("D\n");
  }
  return 0;
}