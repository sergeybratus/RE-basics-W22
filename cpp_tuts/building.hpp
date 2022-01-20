class Building {
  private:
    int height;
    int width;
    std::string address;

  public:
    virtual void setHeight( int height ) { this->height = height; }
    virtual void setWidth( int width ) { this->width = width; }
    virtual void setAddress( std::string address ) { this->address = address; }
    
    virtual int getHeight( void ) { return this->height; }
    virtual int getWidth( void ) { return this->width; }
    virtual std::string getAddress( void ) { return this->address; }
};
