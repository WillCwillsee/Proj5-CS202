#include <Vehicle/Vehicle.hpp>

/* This is the value initialization for the static int s_idgen, which is used to create unique VINs for each Vehicle created
 */

int Vehicle::s_idgen = 1;

/*  This is the definition of the default Vehicle constructor, which takes no parameters, and only creates a unique VIN for the Vehicle
 */

Vehicle::Vehicle() : m_lla(), m_vin(s_idgen++)
{
    cout << endl << "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

/*  This is the definition of the first parameterized constructor which takes one parameter, a user defined VIN number and leaves the rest of the information uninitalized
 */

Vehicle::Vehicle(const int vin) : m_vin(vin)
{
    cout << endl << "Vehicle #" << m_vin << ": Default-ctor" << endl;
}

/*  This is the definition of the second parameterized constructor which takes two parameters.  It takes a const int for the VIN creation and a const float pointer for the lla
 */

Vehicle::Vehicle(const int vin, const float * lla) : m_lla(), m_vin(vin)  {
    setLLA(lla);
    cout << endl << "Vehicle #" << m_vin << ": Parametrized-ctor" << endl;
}

/*  This is the definition of the copy constructor which takes one parameter, a Vehicle object reference.  It copies all available information to a newly constructed Vehicle object
 */

Vehicle::Vehicle(const Vehicle & v) : m_lla(), m_vin(s_idgen++)
{
    setLLA(v.m_lla);
    cout << endl << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
}

/*  This is the definition of the default destructor.
 */

Vehicle::~Vehicle()
{
    cout << endl << "Vehicle #" << m_vin << ": Default-dtor" << endl;
}

/*  This is the definiton of the insertion operator.  It prints all available information in a Vehicle object reference to the terminal
 */

ostream & operator<<(ostream & os, const Vehicle & v){
    os << "Vehicle #" << v.m_vin << " @ " << "[" << v.m_lla[0] << ", " << v.m_lla[1] << ", " << v.m_lla[2] << "]";
    return os;
}

/*  This is the definition of the assigment operator.  It essentially copies the members of a preexsting Vehicle object reference into another Vehicle object
 */

void Vehicle::operator=(const Vehicle & v){
    setLLA(v.m_lla);
    cout << endl << "Vehicle #" << m_vin << ": Assignment" << endl;
}

/*  This is the definiton fo the get method for s_idgen member.  It returns the value of the next VIN to be created
 */

int Vehicle::getIdgen(){
    return s_idgen;
}

/*  This is the definition of the get method for the m_lla member.  It returns the value of m_lla
 */

const float * Vehicle::getLLA() const{
    return m_lla;
}

/*  This is the definition of the set method for the m_lla member.  It takes one parameter, a const float pointer and uses that to set the value of m_lla
 */

void Vehicle::setLLA(const float * lla){
    for (int i = 0; i < 3; i++){
        m_lla[i] = lla[i];
    }
}

/*  This is the definiton of the move method.  It is intended to be used only for an object of the Derived class Vehicle in order to change its location (stored in m_lla)
 */

void Vehicle::move(const float * lla){
    
    cout << endl << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << endl;
}



