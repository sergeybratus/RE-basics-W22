#include "building.hpp"

class House: public Building {
  private:
    int rooms;
    int baths;

  public:
    virtual void setRooms( int rooms ) { this->rooms = rooms; }
    virtual void setBaths( int baths ) { this->baths = baths; }

    virtual int getRooms( void ) { return this->rooms; }
    virtual int getBaths( void ) { return this->baths; }
};
