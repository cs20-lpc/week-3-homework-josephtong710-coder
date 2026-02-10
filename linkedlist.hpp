#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Student.hpp"
#include "Course.hpp"

class LinkedList {
private:
    StudentNode* head;

public:
    LinkedList();
    ~LinkedList();
    
    void insertStudent(Student student);
    void deleteStudent(int id);
    void searchStudent(int id);
    void displayStudents();
    int studentCount();
    void addCourseToStudent(int id, Course course);
};
#include "LinkedList.tpp"
#endif