#include <iostream>
#include <iomanip>

using namespace std;

class Time{
    public:
        Time();
        void setTime(int, int, int);
        void printUniversal();
        void printStandard();
        void resetTime( );
        void compareTime(Time);
        void advanceTime(int); // use to advance the time by numMinutes

    private:
        int hour;
        int minute;
        int second;
};

Time::Time(){
    hour = 0;
    minute = 0;
    second = 0;
}

// set new Time value using universal time, ensure that the data remains consistent by setting invalid values to zero
void Time::setTime(int h, int m, int s){
    hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
    minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
    second = ( s >= 0 && s < 60 ) ? s : 0; // validate seconds
} // end function setTime
// print Time in Universal-Time format (HH:MM:SS)
void Time::printUniversal(){
    cout << setfill( '0' ) << setw(2) << (hour > 24 ? hour % 24 : hour)  << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
}
// print Time in standard-Time format (HH:MM:SS | AM or PM)
void Time::printStandard(){
    cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill ( '0' ) << setw ( 2 ) << minute << ":" << setw ( 2 ) << second << ( hour < 12 ? " AM" : " PM" ) << endl;
} // end function printStandard
void Time::resetTime( ){
    hour = 0;
    minute = 0;
    second = 0;
}
void Time::advanceTime(int numMinutes){
    hour = (hour + (numMinutes / 60));

}
void Time::compareTime(Time t2){
    int t1Time = ((hour * 60) * 60);
    int t2Time = ((t2.hour * 60) * 60);

    if (t1Time > t2Time)
        cout << "Later" << endl;
    else if (t1Time == t2Time)
        cout << "Same" << endl;
    else
        cout << "Earlier" << endl;

}

int main(){
    Time t;
    Time *tPtr = &t;        //#####################################################
    Time t1;                //#####################################################
    Time &tRef = t;         //####################################################

    // output Time object t's initial values
    t.printUniversal(); // 00:00:00
    t.printStandard(); // 12:00:00 AM

    t.setTime(22, 22, 22);  //############################################

    // output Time object t's new values using object name as a handle
    t.printUniversal(); // 22:22:22
    t.printStandard(); // 10:22:22 PM

    // output Time object t's new values using object reference as a handle
    tRef.printUniversal(); // 22:22:22
    tRef.printStandard(); // 10:22:22 PM

    // output Time object t's new values using object pointer as a handle
    tPtr->printUniversal(); // 22:22:22
    tPtr->printStandard(); // 10:22:22 PM

    // advance time by 360 minutes
    tPtr->advanceTime(360); // Plus 6 hours

    tPtr->printUniversal(); // 04:22:22
    tPtr->printStandard(); // 04:22:22 AM

    // rest Time object t
    tRef.resetTime(); // 00:00:00

    t.printUniversal(); //00:00:00
    t.printStandard(); // 12:00:00 AM
    // tRef and t are the same
    t1.setTime( 23, 23, 23 ); // set a new time

    // output Time object t1's new values
    t1.printUniversal(); // 23:23:23
    t1.printStandard();// 11:23:23 PM

    t1.compareTime( *tPtr ); //**********************************
    tPtr->compareTime( t1 ); //******************************
    t1.compareTime( t1 ); // SAME
} // end main

//LATER
//EARLIER
//SAME

//t1 = 23:23:23
//t1 = 11:23:23 PM
// tPtr = t = 00:00:00
// tPtr = t = 12:00:00 AM
