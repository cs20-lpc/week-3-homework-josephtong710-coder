#include <iostream>
#include <iomanip>
#include "LinkedList.hpp"
using namespace std;

int main() {
    cout << fixed << setprecision(1);
    
    LinkedList studentList;
    int choice;
    
    cout << "1. Insert Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Search Student" << endl;
    cout << "4. Display All" << endl;
    cout << "5. Count Students" << endl;
    cout << "6. Add a course" << endl;
    cout << "7. Exit" << endl;
    
    do {
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        
        if (choice == 1) {
            int id;
            string name;
            double gpa;
            
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            
            Student student(id, name, gpa);
            studentList.insertStudent(student);
            cout << endl;
            
        } else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            studentList.deleteStudent(id);
            cout << endl;
            
        } else if (choice == 3) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            studentList.searchStudent(id);
            cout << endl;
            
        } else if (choice == 4) {
            studentList.displayStudents();
            cout << endl;
            
        } else if (choice == 5) {
            int count = studentList.studentCount();
            cout << "Total students: " << count << endl;
            cout << endl;
            
        } else if (choice == 6) {
            int id;
            string courseName, location;
            
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Course Name: ";
            getline(cin, courseName);
            cout << "Enter location: ";
            getline(cin, location);
            
            Course course(courseName, location);
            studentList.addCourseToStudent(id, course);
            cout << endl;
            
        } else if (choice == 7) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice!" << endl;
            cout << endl;
        }
        
    } while (choice != 7);
    
    return 0;
}
