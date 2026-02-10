#include "course.hpp"
#include <iostream>
Course::Course() {
    courseName = "";
    location = "";
}
Course::Course(string name, string loco) {
    courseName = name;
    location = loco;
}
string Course::getCourseName()const {
    return courseName;
}
string Course::getLocation()const {
    return location;
}

void Course::setCourseName(string name) {
    courseName = name;
}
void Course::setLocation(string loco) {
    location = loco;
}