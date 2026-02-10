#include "LinkedList.hpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    StudentNode* current = head;
    while (current != nullptr) {
        StudentNode* temp = current;
        current = current->next;
        delete temp;
    }
}
void LinkedList::insertStudent(Student student) {
    StudentNode* newNode = new StudentNode(student);
    
    if (head == nullptr) {
        head = newNode;
    } else {
        StudentNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void LinkedList::deleteStudent(int id) {
    if (head == nullptr) {
        cout << "Student with ID " << id << " not found!" << endl;
        return;
    }
    
    if (head->student.getId() == id) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted student with ID " << id << endl;
        return;
    }
    
    StudentNode* current = head;
    while (current->next != nullptr && current->next->student.getId() != id) {
        current = current->next;
    }
    
    if (current->next == nullptr) {
        cout << "Student with ID " << id << " not found!" << endl;
    } else {
        StudentNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Deleted student with ID " << id << endl;
    }
}

void LinkedList::searchStudent(int id) {
    StudentNode* current = head;
    
    while (current != nullptr) {
        if (current->student.getId() == id) {
            cout << "Found: " << current->student.getId() << " " 
                 << current->student.getName() << " " 
                 << current->student.getGpa() << endl;
            current->student.displayCourses(true);
            return;
        }
        current = current->next;
    }
    
    cout << "Student with ID " << id << " not found!" << endl;
}

void LinkedList::displayStudents() {
    if (head == nullptr) {
        cout << "No students in the list!" << endl;
        return;
    }
    
    cout << "Students in List:" << endl;
    StudentNode* current = head;
    
    while (current != nullptr) {
        cout << current->student.getId() << " " 
             << current->student.getName() << " " 
             << current->student.getGpa() << " ";
        current->student.displayCourses(false);
        current = current->next;
    }
}

int LinkedList::studentCount() {
    int count = 0;
    StudentNode* current = head;
    
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
void LinkedList::addCourseToStudent(int id, Course course) {
    StudentNode* current = head;
    
    while (current != nullptr) {
        if (current->student.getId() == id) {
            current->student.addCourse(course);
            return;
        }
        current = current->next;
    }   
    cout << "Student with ID " << id << " not found!" << endl;
}