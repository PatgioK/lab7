#include "Course.hpp"

using namespace std;

//Constructor with full params
Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}

//Course constructor with needed params
Course::Course (const Course & course) : title (course.title), day (course.day), start_time (course.start_time), finish_time (course.finish_time)
{
}

Course & Course::operator =(const Course & course) = default;


//Overloading = operation, checks if member vars are the same.
//Function takes 1 course param and checks with course caller.
//Returns a boolean, true if the same.
bool Course::operator == (const Course & course) const {
    //TODO implement the operator
    return title == course.title && day == course.day && start_time == course.start_time && finish_time == course.finish_time;
}


//Overloading < operator to check which courses have earlier start time by day, time
//function takes 1 course param and checks with course caller
//returns a boolean, true if course caller is earlier.
bool Course::operator < (const Course & course) const
{
    //TODO implement the operator
    if(day == course.day) {
        if(start_time < course.start_time) {
            return true;
        }
    }
    return day < course.day;
}

//Function to change course day ENUM to a string
//Function takes takes 1 parameter, the courses member var ENUM day
//Returns a string of the day
string ENUMtoDay(Course::dayOfWeek day) {
    switch(day) {
        case Course::MON:
            return "M";
        case Course::TUE:
            return "T";
        case Course::WED:
            return "w";
        case Course::FRI:
            return "F";
        default:
            break;
    }
}

//Overloaded << operator to print course details to ostream
//Function takes 2 params, a out stream and a course
//Returns an o stream.
ostream & operator << (ostream &os, const Course & m)
{
    //TODO implement the operator

    os << m.title
       <<  " " << ENUMtoDay(m.day)
       << " " << m.start_time
       << " " << m.finish_time;
    return os;
}