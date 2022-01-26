
#include "shapes.hpp"

int main(){
  Shape* line[10];

  for(int i=0; i < 10; i++){
    line[i] = (i%2) ? (Shape*) new Circle() : (Shape*) new Square();
  }

  for(int i=0; i < 10; i++){
    line[i]->draw();
  }
    
  return 0;
}
