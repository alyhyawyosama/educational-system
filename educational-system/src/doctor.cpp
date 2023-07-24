#include "../include/doctor.h"
#include "../include/helper.h"

void Doctor::drListCoursesGui()
{
    system("cls");
    int count=1;
    cout<<"------------- List courses page -----------"<<endl;
    if(this->teaching_.size() > 0)
    {
        cout<<" - "<<setw(5)<<"Id"<<setw(15)<<"Title"<<setw(10)<<"Code\n";
        for(shared_ptr<Course> & crs: this->teaching_ )
        {
//                    cout<<" " <<count++<<" - ";crs->printInfo();
                cout<<" "<<count++<<"-"<<setw(5)<<crs->id_<<setw(15)<<crs->title_<<setw(10)<<crs->code_<<endl;

        }
    }else {cout<<"There is no any course yet\n";system("pause");};

}

//enrollCourseDoctor function used to enroll course and doctor
void Doctor::enrollCourseDoctor(vector<shared_ptr<Course>>&courses, shared_ptr<Course>course)
{
    courses.push_back(course);
    this->teaching_.push_back(course);
    shared_ptr<Doctor> doctor(this) ;
    course->doctor_ = doctor;
}

bool Doctor::isAuthInfo(string username,string password)
{
    return (this->username_ == username) && (this->password_ == password) ;
}


void Doctor::createCourseGui(vector<shared_ptr<Course>>&courses)
{
    system("cls");
    cout<<"------------- Create course page -----------"<<endl;
    cin.clear();
    cin.ignore(1000,'\n');
    shared_ptr<Course> course = make_shared<Course>();
    //            cout <<"course id:" ;cin>>course.id;
    cout <<"name:" ;getline(cin,course->title_);
    cout <<"code:" ;getline(cin,course->code_);
    enrollCourseDoctor(courses,course);
}


/*
    -List my courses ->Enter num
    -List the chosen cours's assignments ->
        - Show solutions -> Enter num of assignment
        - Add new assignment



*/

void Doctor::getCourseAssignments()
{
    cout<<"Enter number of course : ";
    int choice =  Helper::ReadInt(1,this->teaching_.size());
    shared_ptr<Course> crs = this->teaching_.at(choice - 1);
    if(crs->assignments_.size() > 0)
        crs->printAssignments();
    else
        cout<<"There is no any assignment for this course";
        vector<string> menu = {"Show solutions","Add new assignment","Back"};
    choice =  Helper::RunMenu(menu);
    if(choice ==2 )
    {
        crs->addNewAssignment();
        system("pause");
    }else if(choice == 1)
    {
        if(crs->assignments_.size() < 1)
        {
            cout<<"There is no any assignment for this course\n";
            system("pause");
            return this->drViewCourses();
        }

        cout<<"Enter number of assignment:";
        choice =  Helper::ReadInt(1, crs->assignments_.size() );
        shared_ptr <Assignment>assignment = crs->assignments_.at(choice-1);
        if(assignment->solutions_.size()<1)
        {
            cout<<"There is no any solution for this assignment\n";
            system("pause");
            return  this->drViewCourses();
        }
        assignment->showSolution();
        menu = {"Edit grade","Back"};
        choice = Helper::RunMenu(menu);
        if(choice == 1)
        {
            int grade = 0;
            cout<<"\t\t Enter number of solution:";
            choice =  Helper::ReadInt(1,assignment->solutions_.size() );
            shared_ptr<AssignmentSolution>solution = assignment->solutions_.at(choice-1);
            solution->editGrade(assignment->maxGrade_);
            system("pause");
        }
        else return this->drViewCourses();
    }
    else return ;

}

void Doctor::drViewCourses()
{
    int choice ;
    this->drListCoursesGui();
    if(this->teaching_.size() < 1) return;
    getCourseAssignments();

}
void Doctor::doctorGui(vector<shared_ptr<Course>>&courses)
{
    char choice;
    while(true)
    {
        system("cls");
        menu = {"List Courses","Create course","View Courses","Log out"} ;
        choice = Helper::RunMenu(menu);
        switch(choice)
        {
            case  1: this->drListCoursesGui();system("pause"); break;
            case  2: this->createCourseGui(courses); break;
            case  3: this->drViewCourses(); break;
            case  4:  return ; break;
        }
    }
}

int Doctor::count = 0;

