#ifndef DOCTOR
#define DOCTOR

#include <iostream>
#include <vector>
#include <memory>
#include<iomanip>
#include<algorithm>
#include "course.h"

using namespace std ;

struct Course;

struct Doctor{
    int id_;
    static int count ;
    string  username_,
            password_,
            name_,
            email_;
    vector<shared_ptr<Course>> teaching_;
    vector<string> menu;
    Doctor()
    {
        id_ = count++;
    }
    void drListCoursesGui();
    void getCourseAssignments()     ;
    //enrollCourseDoctor function used to enroll course and doctor
    void enrollCourseDoctor(vector<shared_ptr<Course>>&courses, shared_ptr<Course>course);
    void createCourseGui(vector<shared_ptr<Course>>&courses);
    void drViewCourses();
    void doctorGui(vector<shared_ptr<Course>>&courses);
    bool isAuthInfo(string username,string password) ;
};


#endif // DEMO_H_INCLUDED
