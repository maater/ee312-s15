#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct _StudentGrade {
  int32_t grade;
  char name[20];
} StudentGrade;

typedef struct _StudentGrade2 {
  char name[20];
  int32_t grade;
} StudentGrade2;


typedef struct _StudentGrade3 {
  char *name;
  int32_t grade;
} StudentGrade3;

int main(int argc, char **argv) {
  StudentGrade a;
  a.grade = 10;
  a.name[0] = 'f';
  a.name[1] = 'o';
  a.name[2] = 'o';
  a.name[3] = '\0';

  printf("&a = %p\n", &a); 
  printf("&(a.grade) = %p\n", &(a.grade)); 
  printf("&(a.name) = %p\n", &(a.name)); 

  printf("---------------------------------\n");

  printf("a.grade = %d\n", a.grade); 
  printf("a.name = %s\n", a.name); 


  printf("---------------------------------\n");

  StudentGrade *Ptr = &a;

  printf("&Ptr = %p\n", &Ptr); 
  printf("Ptr = %p\n", Ptr); 
  printf("Ptr->grade = %d\n", Ptr->grade); 
  printf("Ptr->name = %s\n", Ptr->name); 

  printf("---------------------------------\n");

  printf("Ptr->name (casting 1) = %s\n", (char*) (((int32_t*) Ptr) + 1) ); 
  printf("Ptr->name (casting 2) = %s\n", (((char*) Ptr) + sizeof(int32_t)) ); 

  printf("---------------------------------\n");

  StudentGrade2 b;

  printf("&b = %p\n", &b); 
  printf("&(b.name) = %p\n", &(b.name)); 
  printf("&(b.grade) = %p\n", &(b.grade)); 

  printf("---------------------------------\n");

  StudentGrade3 c;
  printf("&c = %p\n", &c); 
  printf("&(c.name) = %p\n", &(c.name)); 
  printf("&(c.grade) = %p\n", &(c.grade));   
  c.name = (char*) malloc(sizeof(char) * 20);
  printf("c.name = %p\n", c.name); 

  printf("---------------------------------\n");

  StudentGrade *d = (StudentGrade *) malloc (sizeof(StudentGrade));
  d->grade = 10;
  d->name[0] = 'b';
  d->name[1] = 'a';
  d->name[2] = 'r';
  d->name[3] = '\0';
  
  printf("d->grade = %d\n", d->grade);
  free(d);

  printf("d->grade (error) = %d\n", d->grade);
}
