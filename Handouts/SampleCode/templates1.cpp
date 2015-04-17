#include<vector>
#include<string>
#include<iostream>

// std
// cout 
// protected, private, public 
// Inheritance as private or public ? 
// Function override 

template <typename T> 
T increment(T x) {
  //  printf("x = %d\n", (int32_t) x);
  return x + sizeof(T);
}

/* 
int32_t increment(int32_t x) {
  return x + sizeof(int32_t);
}

int64_t increment(int64_t x) {
  return x + sizeof(int64_t);
}

int64_t* increment(int64_t* x) {
  return x + sizeof(int64_t*);
}

char* increment(char* x) {
  return x + sizeof(char*);
}
*/

template <typename T>
class number {
  T value;
  void print(){
    // 
  }
};


/*

class number_sdfhq4t {
  int32_t value;
  void print(){
    // 
  }
};

class number_sd;kje {
  int64_t value;
  void print(){
    // 
  }
};

class number_asdf;j {
  int8_t value;
  void print(){
    // 
  }
};


 */

int main(int argc, char **argv){

  printf("%d\n", increment<int32_t>(5));
  printf("%lld\n", increment<int64_t>(5));

  printf("%p\n", main);
  printf("%p\n", increment<int32_t>);
  printf("%p\n", increment<int64_t>);
  printf("%p\n", increment<char>);

  printf("%d\n", increment(5)); // increment<int32_t>
  printf("%lld\n", increment( (int64_t) 5));

  // random value returned
  printf("%p\n", increment( (int64_t*) 5));
  printf("%p\n", increment("str"));

  //printf("%p\n", increment<int32_t>("str"));

  std::vector<int32_t> v1, v2, v3;
  std::vector<char> v4, v5;

  number<int32_t> n1;
  number<int64_t> n2;
  number<int8_t> n3;
}
