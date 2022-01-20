#include <iostream>

#include "house.hpp"

int main( int argc, char** argv)
{
  House *home = new House;

  home->setHeight(10);
  home->setWidth(10);
  home->setAddress("Nowhere");
  home->setRooms(4);
  home->setBaths(4);

  return 0;
}
