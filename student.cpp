#include "student.hpp"
#include <iostream>
Student::Student(){
    name = "";
    id = 0;
    gpa = 0.0;
    head = nullptr;
}
Student::Student(string n, int i, double gpa){
    name = n;
    id = i;
    gpa = gpa;
    head = nullptr;
}
string Student::getName()const{
    return name;
}
int Student::getId()const{
    return id;
}
double Student::getGpa()const{
    return gpa;
}
void Student::setName(string n){
    name = n;
}
void Student::setId(int i){
    id = i;
}
void Student::setGpa(double g){
    gpa = g;
}
Student::~Student(){
    CourseNode*current = head;
    while(current!=nullptr){
        CourseNode* temp = current;
        current = current->next;
        delete temp; 
    }
}
void Student::addCourse(Course c){
    CourseNode* newNode = new CourseNode(c);
    if(head == nullptr){
        head = newNode;
    }else{
        CourseNode* current = head; 
        while (current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
}
void Student::displayCourses()const{
    if(head == nullptr){
        cout << "No courses enrolled." << endl;
}
CourseNode* current = head;
cout << "Courses: " << endl;
bool first = true; 
while(current!= nullptr){
    if (!first){
        cout <<"         ";
    }
    cout << current->course.getCourseName() << " " <<
    current->course.getLocation() << endl;
    first = false;
    current = current->next;
    }
}
void Student::displayInline() const {
    if (head == nullptr) {
        cout << "None" << endl;
    } else {
        CourseNode* current = head;
        while (current != nullptr) {
            cout << current->course.getCourseName();
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << endl;
    }
}
void Student::display()const{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "GPA: " << gpa << endl;
    displayCourses();
   
}
