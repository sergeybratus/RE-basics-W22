class Person {
  private:
    std::string name;
    int age;

  public:
    virtual void setName( std::string name ) { this->name = name; };
    virtual void setAge( int age ) { this->age = age; };
    virtual std::string getName( void ) { return this->name; };
    virtual int getAge( void ) { return this->age; };
};
