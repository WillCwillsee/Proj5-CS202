#include <Car/Car.hpp>

/*  This is the definition of the default constructor override for the Derived class Vehicle::Car
 */

Car::Car() : Vehicle(), m_plates(), m_throttle(0)
{
    cout << endl << "Car #" << m_vin << ": Default-ctor" << endl;
}

/*  This is the definition of the parameterized constructor override for the Derived class, which takes 3 parameters.  A const char pointer to the license plates, a const int of the VIN, and a const float pointer to the LLA.  It uses an initializer for the VIN because it is a const int and uses set methods for the other arguments
 */

Car::Car(const char * plates, const int vin, const float * lla) : Vehicle(vin), m_plates(), m_throttle(0)
{
    setPlates(plates);
    setLLA(lla);
    cout << endl << "Car #" << m_vin << ": Parametrized-ctor" << endl;
}

/*  This is the definition of the copy constructor override for the Derived class.  It takes one parameter, a reference to a Car object.  Since the VIN is unique, it allows the default process of VIN creation using the static int s_idgen
 */

Car::Car(const Car & c) : Vehicle(), m_plates(), m_throttle(0)
{
    setPlates(c.m_plates);
    setLLA(c.m_lla);
    cout << endl << "Car #" << m_vin << ": Copy-ctor" << endl;
}

/*  This is the definition of the default destructor override for the Derived class.
 */

Car::~Car()
{
    cout << endl << "Car #" << m_vin << ": Default-dtor" << endl;
}

/*  This is the definition of the insertion operator override for the Derived class.  It prints all available information about the Car object reference (passed as an argument) to the terminal
 */

ostream& operator<<(ostream & os, const Car & c){
    os << "Car #" << c.m_vin << " Plates: " << c.m_plates << ", Throttle: " << c.m_throttle <<  " @ " << "[" << c.m_lla[0] << ", " << c.m_lla[1] << ", " << c.m_lla[2] << "]" ;
    return os;
}

/*  This is the definition of the assigment operator override for the Derived class.  It essentially allows the program to copy one Car to the location of another, without chaning the VIN.
 */

void Car::operator=(const Car & c){
    setPlates(c.m_plates);
    drive(c.m_throttle);
    setLLA(c.m_lla);
    cout << endl << "Vehicle #" << m_vin << ": Assignment" << endl;
}

/*  This is the definition of the Car set method for the license plates of the Car.  It takes one parameter which is a const char pointer to the license plate information
 */

void Car::setPlates(const char * plates){
    for (int i = 0; i < 256; i++){
        m_plates[i] = plates[i];
    }
}

/*  This is the definiton of the Car drive method, which changes the throttle in the Car from which the method is called
 */

void Car::drive(const int throttle){
    m_throttle = throttle;
}

/*  This is the definiton of the Car move method, which changes the location (lla) in the Car from which the method is called
 */

void Car::move(const float *lla){
    for (int i = 0; i < 3; i++){
        m_lla[i] = lla[i];
    }
}
