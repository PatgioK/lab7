#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;


/*
* print schedule - outputs course schedule to the screen
* @param - add any new parameters you need
*/
void printSch(vector<Course> courses) {
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    copy(courses.begin(),courses.end(),ostream_iterator<Course>(cout, "\n"));
}

int main () {
    //TODO read from courses.txt
    vector<Course> courses;
    ifstream input{"../courses.txt"};
    if(!input.is_open()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }

    //TODO store data in an STL container

    string store_line, store_title, store_day;
    Course::dayOfWeek store_dayOfWeek;

    unsigned int store_start, store_finish;

    while(getline(input,store_line)) {
        istringstream istringstream1{store_line};
        istringstream1 >> store_title >> store_day >> store_start >> store_finish;
        if (store_day == "M") store_dayOfWeek = Course::dayOfWeek::MON;
        if (store_day == "T") store_dayOfWeek = Course::dayOfWeek::TUE;
        if (store_day == "W") store_dayOfWeek = Course::dayOfWeek::WED;
        if (store_day == "F") store_dayOfWeek = Course::dayOfWeek::FRI;
        Course new_course(store_title, store_dayOfWeek, store_start, store_finish);
        courses.push_back(new_course);
    }
    //TODO sort your STL container with the sort algorithm
    sort(courses.begin(), courses.end());
    //TODO implement code to determine schedule conflicts

    //TODO print out schedule conflicts
    for (auto iterator1 = courses.begin(); iterator1 != courses.end(); ++iterator1) {
        for (auto iterator2 = iterator1 + 1; iterator2 != courses.end(); ++iterator2) {
            if (iterator2->start_time <= iterator1->finish_time && iterator1->day == iterator2->day) {
                string conflicts_string = "CONFLICT:\n";
                conflicts_string+=iterator1->title + " "
                                  + ENUMtoDay(iterator1->day) + " "
                                  + to_string(iterator1->start_time) + " "
                                  + to_string(iterator1->finish_time) + "\n";
                conflicts_string += iterator2->title + " "
                                    + ENUMtoDay(iterator2->day) + " "
                                    + to_string(iterator2->start_time) + " "
                                    + to_string(iterator2->finish_time) + "\n";
                cout<<conflicts_string<<endl;
            }
        }
    }

    //TODO print out schedule
    printSch(courses);
    return 0;
}