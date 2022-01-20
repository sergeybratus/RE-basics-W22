#include <iostream>
#include <unistd.h>

#include "class_layout.hpp"

char name[32];

static void hello_world()
{
    std::cout << "Hello World" << std::endl;
    exit(0);
}

void read_it( char *it, long i)
{
  std::cout << "Give me some data: " << std::endl;

    asm("xorq %%rax, %%rax;"
        "movq %0, %%rsi;"
        "movq %1, %%rdx;"
        "xorq %%rdi, %%rdi;"
        "syscall;"
        :
        :"r"(it), "r"(i)
        :"%rax", "%rdi", "%rsi", "%rdx"
       );

    return;
}

#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv)
{
  char *data = (char*)malloc(32);
  Person *bob = new Person();

  read_it(name, 31);

  bob->setName(name);
  bob->setAge(42);

  std::cout << "Name: " << bob->getName() << " Age: " << bob->getAge() << std::endl;

  read_it(data, 100);

  std::cout << "Name: " << bob->getName() << " Age: " << bob->getAge() << std::endl;

  return 0;
}
