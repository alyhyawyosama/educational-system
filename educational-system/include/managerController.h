#ifndef MANAGERCONTROLLER_H_
#define MANAGERCONTROLLER_H_

#include <iostream>
#include <vector>
#include <memory>
#include<iomanip>
#include<algorithm>
#include<assert.h>
#include "course.h"
#include "doctor.h"
#include "student.h"
#include "helper.h"


using namespace std ;


struct ManagerController
{
public:
    vector<shared_ptr<Doctor>> doctors;
    vector<shared_ptr<Student>> students;
    vector<shared_ptr<Course>> courses;
    void coursesDoctorsDummy();
    void studentsDummy() ;
    void mainMenu()      ;
    shared_ptr<Student> getStudent(string username,string password);
    shared_ptr<Doctor> getDoctor(string username,string password);
    void studentLogin();
    void doctorLogin();
    void userLogin() ;
    void userSignUp() ;
    bool isExist(string username,string userType);
    bool isEmailExist(string email,string userType);
    void studentSignUp();
    void doctorSignUp();
    /*Email format validation methods*/
    bool isDigit(const char);
    bool isChar(char);
    bool is_valid_email(string email);
    /*End email format validation methods*/




};

extern shared_ptr<ManagerController>  manager;

#endif // DEMO_H_INCLUDED
