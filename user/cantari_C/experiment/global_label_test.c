#include <stdio.h>


int main(){

  void *pp = &&p;

  goto *pp;
  goto q;

  p:
  printf("exp.c with pp");

  q:

}
