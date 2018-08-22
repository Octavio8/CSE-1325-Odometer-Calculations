// This program will calculate the MPG for a vehicle based on user input
#include <cstdlib>
#include <iostream>
using namespace std;

/* This is the class that contains the variables that will hold the user 
 * input as well as the declarations of the functions that can access 
 * them.
 */
class Mpg_log{
    double last_odometer;
    double this_odometer;
    double this_gas;
public:
    Mpg_log(double starting_odometer);
    void  buy_gas(double odometer, double gas);
    double get_current_mpg();
};

/* This function will set the initial odometer reading
 */
Mpg_log::Mpg_log(double starting_odometer){
   
    cout << "Initial odometer: " << starting_odometer << endl; 
    last_odometer = starting_odometer;    
}

/* This function will accept the current odometer and gas readings
 * and will save the readings to the object variables
 */
void Mpg_log::buy_gas(double odometer, double gas){
    
    this_odometer = odometer;
    this_gas = gas;
}

/* This function will calculate the MPG of the vehicle and will
 * assign the current odometer reading to the last odometer reading
 * so that it can be used for the next calculation.
 */
double Mpg_log ::get_current_mpg(){
    
    double result;
    result = (this_odometer - last_odometer)/this_gas;
    last_odometer = this_odometer;
    return result;
}


/* This is the main function of the program it will prompt the user for input
 * and instantiate an object of the class Mpg_log to keep up with the user
 * input and to calculate the MPG. The program will continue to run until the 
 * user inputs 0.0 for the odometer reading.
 */
int main() {
    
    double odometer = 0,gas = 0;
    cout << "Enter initial odometer reading: ";
    cin >> odometer;
    Mpg_log mpgLog(odometer);
    
    do{
        mpgLog.buy_gas(odometer,gas);
    cout << "Odometer: ";
    cin >> odometer;
    
    if(odometer != 0){
    cout << "Gallons: " ;
    cin >> gas;
    mpgLog.buy_gas(odometer,gas);
    
    cout << "This mpg: " << mpgLog.get_current_mpg() << endl;
    }    
    }while(odometer != 0);
    
  
    return 0;
}

