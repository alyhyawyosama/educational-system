#ifndef  ASSIGNMENT
#define  ASSIGNMENT

#include "course.h"
#include "assignmentSolution.h"
#include "student.h"

using std::vector;
using std::string;
using std::shared_ptr;
using std::cin;
using std::cout;

struct Course;
struct AssignmentSolution;
struct Student;;

struct Assignment
{
    int id_ ;
    static int count ;
    int maxGrade_;
    string title_;
    shared_ptr<Course> course_;
    vector<shared_ptr<AssignmentSolution>>solutions_;
public:
    Assignment()
    {
        id_ = ++count;
    };
    void enrollAssignmentSolution(shared_ptr<AssignmentSolution> & solution,shared_ptr<Student> & student);
    void addSolution(Student * stud);
    //showSolution used to show the solutions of students
    void showSolution();
};
#endif // DEMO_H_INCLUDED


