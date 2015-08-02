#include <stdio.h>
#include <stdint.h>

int GlobalVariable = 10;

void foo(int32_t in){
  printf("foo: &in=%p\n", &in);

  in = 5;
  return;
}

void bar(int32_t *in){
  printf("bar: in=%p\n", in);
  *in = 5;
  return;
}

int main() {
  int32_t a = 10;
  int32_t b = -10;
  int32_t c[4];
  int32_t *d;

  printf("GlobalVariable  = %d\n", GlobalVariable);
  printf("&GlobalVariable = %p\n", &GlobalVariable);

  printf("---------------------------------\n");
  // how to get address of a variable
  printf("a  = %d\n", a);
  printf("&a = %p\n", &a);
  printf("---------------------------------\n");
  // notice the size of a (in bytes)
  printf("b  = %d\n", b);
  printf("&b = %p\n", &b);
  printf("---------------------------------\n");
  // note that c is a pointer
  printf("c  = %p\n", c);
  printf("&c = %p\n", &c);
  printf("---------------------------------\n");
  // note the size of d
  d = &a;
  printf("d  = %p\n", d);
  printf("&d = %p\n", &d);
  printf("---------------------------------\n");
  // note the size of c[0]
  printf("c[1]  = %d\n", c[1]);
  printf("&c[1] = %p\n", &(c[1]));
  //printf("c[4]  = %d\n", c[4]);
  //printf("&c[4] = %p\n", &(c[4]));

  printf("---------------------------------\n");

  c[0] = 1;

  // how casting and endianess works
  printf("c[0] byte 0 = %d\n", *( ( (char*) &(c[0]) ) + 0 ) );
  printf("c[0] byte 1 = %d\n", *( ( (char*) &(c[0]) ) + 1 ) );
  printf("c[0] byte 2 = %d\n", *( ( (char*) &(c[0]) ) + 2 ) );
  printf("c[0] byte 3 = %d\n", *( ( (char*) &(c[0]) ) + 3 ) );
  printf("---------------------------------\n");

  // pass by value
  foo(a);
  printf("---------------------------------\n");

  // pass by reference
  bar(&a);
  printf("---------------------------------\n");
}


