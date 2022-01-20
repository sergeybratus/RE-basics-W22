#include <iostream>

#include "class_layout.hpp"

int main(int argc, char **argv)
{
  Person *bob = new Person;

  bob->setName("bob");
  bob->setAge(42);

  std::cout << "Name: " << bob->getName() << " Age: " << bob->getAge() << std::endl;

  return 0;
}
