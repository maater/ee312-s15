#include<vector>
#include<string>
#include<iostream>

class User {

protected: 
  int32_t userId; 
  std::string username;


private: 
  std::string password; 

public:
  User(){
    printf("default constructor in user called\n");
  }

  User(int32_t userId, std::string username, std::string password){
    printf("constructor in user called\n");
    this->username = username;
    this-> userId = userId;
    this->password = password;
  }

  bool login(std::string typedPassword) { 
    if (typedPassword == password){
      return true;
    }
    return false;
  }

  void resetPassword(std::string new_password){
    this->password = new_password;
  }

  void print(){
    printf("Print in User called for %s\n", username.c_str());
  }
};

class Student : private User {
  std::string major;

public:
  Student(int32_t userId, std::string username, std::string password, std::string major) : User(userId, username, password) {
    printf("constructor in student called\n");
    this->major = major;
  }

  void print() {
    //std::cout << "print in student " << username << " called" << std::endl;
    printf("print in student %s called\n", this->username.c_str());
  }

};

class Instructor : public User {

  std::string level;
public:
  Instructor(int32_t userId, std::string username, std::string password, std::string level) : User(userId, username, password) {
    printf("constructor in instructor called\n");
    this->level = level;
  }

};

template <typename T> 
T increment(T x) {
  return x + sizeof(T);
}

/* 
int32_t increment(int32_t x) {
  return x + sizeof(int32_t);
}

int64_t increment(int64_t x) {
  return x + sizeof(int64_t);
}
*/

// struct DateType {
//   int64_t seconds;
//   DateType(int64_t seconds){
//     
//   }
//   DateType operator+ (int32_t i){
//     return DateType(10);
//   }
// };
// 

int main(int argc, char **argv){

  // Inheritance

  printf("No consutrctor is called when you define a pointer\n");
  Student *s;

  printf("==========================================\n");
  printf("Constructor will be called; \n Student constructor will call User contructor first and then execute the student contructor\n");
  s = new Student(123, "student1", "1234", "ECE");

  printf("==========================================\n");
  printf("Instructor constructor will call User constructor first\n");
  Instructor *i = new Instructor(456, "instructor1", "password1", "adjunct");

  printf("==========================================\n");
  printf("Calling s->print(). Since Student overrides print, the print in student will be called\n");
  s->print();

  printf("==========================================\n");
  printf("Calling i->print(). Since Instructor does not define print, the print in User will be called\n");

  i->print();

  printf("==========================================\n");
  printf("Declaring another student on the stack. Note the arguments can be passed and this will lead to a call of the student constructor\n");

  Student s2(999, "student2", "password2", "ECE");

  //printf("userid: %d\n", s->userId);
  //printf("userid: %d\n", i->userId);

  printf("==========================================\n");
  printf("With casting, it is possible to see that userid occurpies the first 4 bytes of Student object, which is expected\n"); 
  printf("userid: %d\n", *( (int32_t*) s));

  // Tempaltes 
  printf("==========================================\n");

  printf("%d\n", increment<int32_t>(5));
  printf("%lld\n", increment<int64_t>(5));


  printf("%d\n", increment(5));
  printf("%lld\n", increment( (int64_t) 5));

  //=====================

  /* std::vector<int32_t> v; 
  v.push_back(3);
  v.size();

  std::cout << increment( (int64_t) 3 ) << std::endl;
  */
}
