#include <iostream>
#include "Student.hpp"
#include "Course.hpp"
using namespace std;

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

LinkedList::LinkedList() {
   head = nullptr;
} 

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
        // Insert at the end
        StudentNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    cout << "Student added successfully!" << endl;
}

void LinkedList::deleteStudent(int id) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    // If head node is deleted
    if (head->student.getId() == id) {
        StudentNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Student with ID " << id << " deleted successfully!" << endl;
        return;
    }
    
    // searching for student to delete
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
        cout << "Student with ID " << id << " deleted successfully!" << endl;
    }
}

void LinkedList::searchStudent(int id) {
    StudentNode* current = head;
    
    while (current != nullptr) {
        if (current->student.getId() == id) {
            cout << "\n--- Student Found ---" << endl;
            current->student.display();
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
    
    cout << "\n=== All Students ===" << endl;
    StudentNode* current = head;
    int count = 1;
    
    while (current != nullptr) {
        cout << "\nStudent #" << count++ << ":" << endl;
        current->student.display();
        cout << "-------------------" << endl;
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
            cout << "Course added to student successfully!" << endl;
            return;
        }
        current = current->next;
    }
    
    cout << "Student with ID " << id << " not found!" << endl;
}

void displayMenu() {
    cout << "\n======= Student Management System =======" << endl;
    cout << "1. Insert a student" << endl;
    cout << "2. Delete a student by ID" << endl;
    cout << "3. Search for a student by ID" << endl;
    cout << "4. Display all students" << endl;
    cout << "5. Count students" << endl;
    cout << "6. Add a course to student" << endl;
    cout << "7. Exit" << endl;
    cout << "=========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    LinkedList studentList;
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                int id;
                string name;
                double gpa;
                
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student GPA: ";
                cin >> gpa;
                
                Student student(name, id, gpa);
                studentList.insertStudent(student);
                break;
            }
            
            case 2: {
                int id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                studentList.deleteStudent(id);
                break;
            }
            
            case 3: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                studentList.searchStudent(id);
                break;
            }
            
            case 4:
                studentList.displayStudents();
                break;
            
            case 5: {
                int count = studentList.studentCount();
                cout << "Total number of students: " << count << endl;
                break;
            }
            
            case 6: {
                int id;
                string courseName, location;
                
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter course name: ";
                getline(cin, courseName);
                cout << "Enter course location: ";
                getline(cin, location);
                
                Course course(courseName, location);
                studentList.addCourseToStudent(id, course);
                break;
            }
            
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}