#ifndef COURSE_HPP
#define COURSE_HPP
#include <string>

using namespace std;

class Course {
    private:
        string courseName;
        string location;
    public:
        Course();
        Course(string name, string loco);
        string getCourseName()const;
        string getLocation()const;

        void setCourseName(string name);
        void setLocation(string loco);

        void displayCourseInfo()const;    
};
#endif
