#include<iostream> 
#include<stdio.h>
#include<string.h>


class DateType {

private:
  char *date;
  int32_t token;
  int32_t token1; // requires its own getter and setter

public:

  int32_t getToken() { return token; }
  void setToken(int32_t _token) { token = _token; }

  void print(){
    printf("Date: %s\n", date);
    printf("Token: %d\n", token);
    printf("this pointer: %p\n", this);
    printf("%d\n", this->token);
  }

  DateType(){  
    date = new char[20];
    token = 0;
    // date = (char *) malloc ( sizeof(char) * 20);
    printf("Constructor 1 called\n");
  } 

  DateType(int32_t _token){  
    date = new char[20];
    token = _token;
    //token = _token;
   // date = (char *) malloc ( sizeof(char) * 20);
    printf("Constructor 2 called\n");
  } 

  ~DateType(){
    delete date;
    // free(date)
    printf("Destructor called\n");
  }
  
};

int main(){
  DateType A(15), A1, A2;
  DateType *B;
  B = new DateType(15);
  // under the hood: malloc, constructor
  delete B;

  printf("&A: %p\n", &A);
  A.print();

  // printf("%d\n", A.token); <--- this will give an error
  // printf("%d\n", (&A)->token); <-- fails as its not a member function
  printf("Cheated A->token: %d\n", *((int32_t*) ((char*) &A + sizeof(char*))) );


  printf("&A1: %p\n", &A1);
  A1.print();
  printf("&A2: %p\n", &A2);
  A2.print();

  // lets use a Getter to get the token
  printf("%d\n", A.getToken());

  // what happens when you call delete without the []???
  DateType *array = new DateType[10];
  delete[] array;

}
