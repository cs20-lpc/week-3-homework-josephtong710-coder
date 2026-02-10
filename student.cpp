#include "student.hpp"
#include <iostream>
#include <iomanip>
Student::Student() {
    name = "";
    id = 0;
    gpa = 0.0;
    head = nullptr;
}
Student::Student(int id, string name, double gpa){
    this->id = id;
    this->name = name;
    this->gpa = gpa;
    head = nullptr;
}
Student::~Student() {
    CourseNode* current = head;
    while (current != nullptr) {
        CourseNode* temp = current;
        current = current->next;
        delete temp;
    }
}
int Student::getId()const {
    return id;
}
string Student::getName()const {
    return name;
}
double Student::getGpa()const {
    return gpa;
}
void Student::setId(int i) {
    id = i;
}
void Student::setName(string n) {
    name = n;
}
void Student::setGpa(double g) {
    gpa = g;
}
void Student::addCourse(Course c) {
    CourseNode* newNode = new CourseNode(c);
    if (head == nullptr) {
        head = newNode;
    } else {
        CourseNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void Student::displayCourses(bool detail) const{
    if (head == nullptr) {
        if (detail) {
            cout << "No courses enrolled." << endl;
        } else {
            cout << "No courses." << endl;
        }
        return;
    }
    if(detail){
        CourseNode* current = head;
        cout <<"Courses: " << endl;
        bool first = true;
        while (current != nullptr) {
            if (!first) {
                cout << "            " << endl;
            }
            cout <<current->course.getCourseName() << "    " << 
            current->course.getLocation() << endl; 
            first = false;
            current = current->next;
        }
    } else {
        CourseNode* current = head;
        while (current != nullptr) {
           cout << current->course.getCourseName() << endl;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << endl;
    }
}

    
    
