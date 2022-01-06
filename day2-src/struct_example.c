#include <stdio.h>
#include <malloc.h>

typedef struct Person {
  char *name;
  int age;
  long unique_id;
  int birth_year;
  char initial;
} Person;

int main(int argc, char**argv)
{
  Person *bob = malloc( sizeof(Person) );

  bob->name = "Bob";
  bob->age = 30;
  bob->unique_id = 0xdeadbeefd00dd00d;
  bob->birth_year = 1991;
  bob->initial = 'C';

  return 0;
}

