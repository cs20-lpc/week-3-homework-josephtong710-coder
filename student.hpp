#ifndef student_HPP
#define student_HPP
#include <string>
#include "course.hpp"
using namespace std;
struct CourseNode {
    Course course;
    CourseNode* next;
    CourseNode(Course c){
        course = c;
        next = nullptr;
    }
};
class Student {
    private:
        string name;
        int id;
        double gpa;
        CourseNode* head;
    public:
        Student();
        Student(string n, int i, double gpa);
        //getters
        string getName()const;
        int getId()const;
        double getGpa()const;
        //setters
        void setName(string n);
        void setId(int i);
        void setGpa(double g);
        //manage courses
        void addCourse(Course c);
        void displayInline()const;
        void displayCourses()const;
        //display info
        void display()const;
};
struct StudentNode{
            Student student;
            StudentNode* next;
            StudentNode(Student s){
                student = s;
                next = nullptr;
            }
};
#endif 