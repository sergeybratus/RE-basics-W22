#include <iostream>

// https://en.cppreference.com/w/cpp/language/derived_class

class Shape {
private:
  int id;
public:
  virtual void draw(){
    std::cout << "x";
  }
};

class Circle : Shape {  
public:
  void draw(){
    std::cout << "()";
  }
};

class Square : Shape {  
public:
  void draw(){
    std::cout << "[]";
  }
};


