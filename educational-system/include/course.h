#ifndef COURSE
#define COURSE

#include <iostream>
#include <vector>
#include <memory>
#include<iomanip>
#include<algorithm>
#include "doctor.h"
#include "student.h"
#include "assignment.h"

struct Doctor;

using namespace std ;

struct Course
{
    int id_;
    static int count;
    string title_,
            code_;
    shared_ptr<Doctor> doctor_ ;
    vector<shared_ptr<Student>>registeredStudents_;
    vector<shared_ptr<Assignment>>assignments_ ;
public:
    Course()
    {
        id_ = ++count;
    }
    void printInfo();
    //This method is used to print the assignments of course ;
    void printAssignments();
    void addNewAssignment();
};

#endif // DEMO_H_INCLUDED

