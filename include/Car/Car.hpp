
#ifndef Car_hpp
#define Car_hpp
#include <Vehicle/Vehicle.hpp>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*  This is the declaration of the Derived class Car belonging to the Base class Vehicle.  More information about all the members and methods of this class can be found in Car.cpp
 */

class Car : public Vehicle{
    
public:
    Car();
    Car(const char * plates, const int vin, const float * lla);
    Car(const Car & c);
    ~Car();
    
    friend ostream&  operator<< (ostream & os, const Car & c);
    void operator=(const Car & c);
    
    void setPlates(const char * plates);
    void drive(const int throttle);
    void move(const float *lla);
    
protected:
    
    
private:
    char m_plates[256];
    int m_throttle;
    
};

#endif /* Car_hpp */
