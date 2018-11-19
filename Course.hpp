// Course.h
#include <iostream>

using namespace std;
struct Course {

    enum dayOfWeek {MON, TUE, WED, THUR, FRI, SAT, SUN};

    Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time);
    Course (const Course & course);

    Course & operator = (const Course & course);
    bool operator < (const Course & course) const;
    bool operator == (const Course & course) const;
    string title; // Name of Course
    dayOfWeek day; // Day of Course
    unsigned int start_time; // Course start time in HHMM format
    unsigned int finish_time; // Course finish time in HHMM format
};
string ENUMtoDay(Course::dayOfWeek day);
// Helper operator for output
ostream &operator << (ostream &os, const Course & m);