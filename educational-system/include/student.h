#ifndef STUDENT
#define STUDENT
#include <iostream>
#include <vector>
#include <memory>
#include<iomanip>
#include<algorithm>
#include "course.h"
#include "assignmentSolution.h"
using namespace std ;

struct Student
{
    int id_;
    static int count ;
    string
        username_,
        password_,
        name_ ,
        email_   ;
//Student(){};
    vector<string>menu;
    vector<shared_ptr<Course>>courses_;
    vector<shared_ptr<AssignmentSolution>>AssignmentSolutions_;
public:
    Student()
    {
        id_ = ++count;
    };
//»”„ «·—Õ„‰ «·—ÕÌ„ ﬁ· «⁄Ê– »—» «·‰«” „·ﬂ «·‰«” «·Â «·‰«” „‰ ‘— «·Ê”Ê«” «·Œ‰«” «·–Ì ÌÊ” Ê” ›Ì ’œÊ— «·‰«” „‰ «·Ã‰… Ê «·‰«”

    //enrollCourseStudent function used to enroll course and student
    void enrollCourseStudent(shared_ptr<Course>course);
    void listCoursesGui(string title="List courses page");
    static bool compareCourses(shared_ptr<Course> &crs1,shared_ptr<Course> &crs2);
    vector<shared_ptr<Course>> findDeifferentCourses(vector<shared_ptr<Course>> & crs1 ,vector<shared_ptr<Course>> &crs2  );
    void registerInCourseGui(vector<shared_ptr<Course>>& courses );

     //erase :
//                    Time Complexity: O(N)
//                    Auxiliary Space: O(1)
    void unregisterFromCourse(int crsPosition);
    void viewCourses();
    bool isAuthInfo(string username,string password) ;
    void gradeReport();
    static bool compareAssignment(shared_ptr<Assignment> &assin1,shared_ptr<Assignment> &assin2);
    void studentPrintAssignment(shared_ptr<Course>crs);
    void studentGui(vector<shared_ptr<Course>>& courses);

};
extern vector<shared_ptr<Student> > students;

#endif // DEMO_H_INCLUDED

