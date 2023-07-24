#ifndef ASSIGNMENTSOLUTION
#define ASSIGNMENTSOLUTION

#include <iostream>
#include <vector>
#include <memory>
#include<iomanip>
#include<algorithm>
#include "assignment.h"
#include "student.h"
using namespace std ;
struct Assignment;
struct Student;

struct AssignmentSolution
{
    int id_ ;
    static int count ;

    int grade_ = 0 ;
    string answer_;
    shared_ptr<Assignment> assignment_;
    shared_ptr<Student> student_;

    AssignmentSolution()
    {
        id_ = ++count;
    }
    void editGrade(int maxGrade)
    {
        int grade = 0 ,choice;
        cout<<"\t\tEnter grade : ";cin>>grade;
        while(cin.fail() || grade < 1 || grade > maxGrade  )
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Grade must be between [1-"<< maxGrade<<"]\n";
            cout<<"\t\tEnter grade : ";cin>>grade;
        }
        this->grade_=grade;
    }
};

#endif
