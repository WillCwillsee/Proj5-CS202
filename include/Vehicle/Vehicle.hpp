#ifndef Vehicle_hpp
#define Vehicle_hpp
#include <iostream>
#include <fstream>

using namespace std;

/*  This is the declaration of the Base class Vehicle.  More information about all the members and methods of this class can be found in Vehicle.cpp
 */

class Vehicle{
    
public:
    
    Vehicle();
    Vehicle(const int vin);
    Vehicle(const int vin, const float * lla);
    Vehicle(const Vehicle & vehicle);
    ~Vehicle();
    
    friend ostream & operator<<(ostream & os, const Vehicle & v);
    void operator=(const Vehicle & v);
    
    const float * getLLA() const;
    void setLLA(const float * lla);
    void move(const float * lla);
    
    static int getIdgen();
    
protected:
    
    float m_lla[3];
    const int m_vin;
    
private:
    
    static int s_idgen;
    
};


#endif /* Vehicle_hpp */
