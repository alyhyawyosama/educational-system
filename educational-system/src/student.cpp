#include "../include/student.h"
#include "../include/helper.h"
int Student::count = 0;

//enrollCourseStudent function used to enroll course and student
void Student::enrollCourseStudent(shared_ptr<Course>course)
{
    this->courses_.push_back(course);
    shared_ptr<Student> student(this) ;
    course->registeredStudents_.push_back(student);
}

void Student::listCoursesGui(string title)
{
    system("cls");
    int count=1;
    cout<<"------------- "<<title<<" -----------"<<endl;
    if(this->courses_.size() > 0)
    {
        cout<<"  - "<<setw(15)<<"Title"<<setw(10)<<"code\n";
        for(shared_ptr<Course> & crs: this->courses_ )
        {
                cout<<" " <<count++<<" - ";crs->printInfo();
        }
    }else {cout<<"There is no any course yet\n" ;};
}



bool Student::compareCourses(shared_ptr<Course> &crs1,shared_ptr<Course> &crs2)
{
    return crs1->id_ < crs2->id_;
}

//findDeifferentCourses() ->
//          Is used to return vector of courses,courses that student is not register in.
//          It makes different between two vector .
//          For
/*
   * Given vector of courses.
   *
   * @param a set of all courses that exist on our system
   * @param a set of courses in which the user is registered
   *
   * @return: a set of courses in which the user is not registered
   * Example numbers={1,2,3,4,5,6,7,8,9},subnum = {4,5,6,7,8,9}
                => (numbers- subnum) = findDeifferentCourses(number,subnum) = {1,2,3}
   */
vector<shared_ptr<Course>> Student::findDeifferentCourses(vector<shared_ptr<Course>> & crs1 ,vector<shared_ptr<Course>> &crs2  )
{
    vector<shared_ptr<Course>> differentCourses ;
    vector<shared_ptr<Course>> sorted1 = crs1;
    vector<shared_ptr<Course>> sorted2 = crs2;
    sort(sorted1.begin(),sorted1.end(),this->compareCourses);
    sort(sorted2.begin(),sorted2.end(),this->compareCourses);
    set_difference(crs1.begin(),crs1.end(),crs2.begin(),crs2.end(),back_inserter(differentCourses),compareCourses) ;
    return differentCourses;
}

void Student::registerInCourseGui(vector<shared_ptr<Course>>& courses )
{
    vector<shared_ptr<Course>> differentCourses = findDeifferentCourses(courses,this->courses_);
    int count = 0,choice ;

   if(differentCourses.size() > 0)
   {
        cout<<" - "<<setw(5)<<"Id"<<setw(20)<<"Title"<<setw(10)<<"Code\n";

        for( shared_ptr<Course>& crs : differentCourses)
        {
            cout<<" "<<++count<<"-"<<setw(5)<<crs->id_<<setw(20)<<crs->title_<<setw(10)<<crs->code_<<endl;
        }
        cout<<"Enter number of course : ";
        choice = Helper::ReadInt(1,differentCourses.size());
        shared_ptr<Course> & crs = differentCourses.at(choice - 1);
        enrollCourseStudent(crs);
   }else { cout<<"There is no any course yet,to register into. Thanks ^_^\n" ;system("pause") ;};
}


 //erase :
//                    Time Complexity: O(N)
//                    Auxiliary Space: O(1)
void Student::unregisterFromCourse(int crsPosition)
{
    vector<shared_ptr<Course>>::iterator it =this->courses_.begin()+crsPosition;
    this->courses_.erase(it);
}


void Student::viewCourses()
{
    int choice ;
    if(this->courses_.size() < 1)
    {
        system("cls");
        cout<<"There is no any course yet\n\n\n";
        system("pause");
        return;
    }
    system("cls");
    this->listCoursesGui("View courses page");
    cout<<"Enter number of course : ";
    choice = Helper::ReadInt(1,this->courses_.size());

    int crsPosition = choice -1;
    shared_ptr<Course> crs = this->courses_.at(choice - 1);

    if(crs->assignments_.size() > 0)
    {
        //crs->printAssignments();
        this->studentPrintAssignment(crs);
        menu.clear();
        menu = {"Unregister from course" ,"Submit solution","Back" };
////        cout<<"\n\n\t"<<"1- Unregister from course\n\t2- Submit solution \n\t3- Back \n\tEnter:";cin>>
        choice = Helper::RunMenu(menu) ;
        switch(choice)
        {
            case 1:
//                    erase :
//                    Time Complexity: O(N)
//                    Auxiliary Space: O(1)
                unregisterFromCourse(crsPosition);
            break;
            case 2:
                {
                    cout<<"Enter number of assignment : ";
                    choice = Helper::ReadInt(1,crs->assignments_.size());
                    shared_ptr<Assignment>  assignment = crs->assignments_.at(choice - 1);

                    for(shared_ptr<AssignmentSolution> submittedSolution :AssignmentSolutions_ )
                    {
                        //Address comparetion
                        if(submittedSolution->assignment_ == assignment )
                        {
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout<<"Solution : ";
                            getline(cin,submittedSolution->answer_);

                            return;
                        }
                    }

                    shared_ptr<AssignmentSolution> solution = make_shared<AssignmentSolution>();
                    cout<<"Solution : ";
                    cin.get();
                        getline(cin,solution->answer_);
                        shared_ptr<Student>student (this);
                        solution->student_ = student;
                        solution->assignment_ = assignment;
                        assignment->solutions_.push_back(solution);
                        this->AssignmentSolutions_.push_back(solution);
                        system("pause");
                   ;break;
                };
            case 3:
                return;

            default:break;
        };
    }else
    {
        cout<<"There is no any assignment for this course";
        system("pause");
    }

}


bool Student::isAuthInfo(string username,string password)
{
    return (this->username_ == username) && (this->password_ == password) ;
}


void::Student::gradeReport()
{
    if(this->courses_.size() < 1)
    {
        cout<<"There is no any course yet\n\n\n";
        return ;
    }
    int count =0,grade = 0,maxGrade = 0;
    for(shared_ptr<Course>crs : this->courses_)
    {
         count =0;grade = 0;maxGrade = 0;
        for(shared_ptr<AssignmentSolution>sol : this->AssignmentSolutions_)
        {
            if(sol->assignment_->course_->id_ == crs->id_)
            {
                count++;
                grade    += sol->grade_;
                maxGrade += sol->assignment_->maxGrade_ ;
            }
        }
        cout<<"Course code "<<crs->code_<<" - Total submitted "<<count<<" assignment - Grade "<<grade<<" / "<<maxGrade<<"\n";

    }

}

bool Student::compareAssignment(shared_ptr<Assignment> &assin1,shared_ptr<Assignment> &assin2)
{
    return assin1->id_ < assin2->id_;
}

void Student::studentPrintAssignment(shared_ptr<Course>crs)
{
    cout<<setw(10)<<"Title"<<setw(15)<<"State"<<setw(15)<<"Grade\n";
    vector<shared_ptr<Assignment>>submittedAssignment ;
    vector<shared_ptr<Assignment>>unSubmittedAssignment ;
    int count = 1;
    for(shared_ptr<AssignmentSolution>solution : this->AssignmentSolutions_)
    {
        if( (solution->assignment_->course_->id_) == crs->id_ )
        {
            submittedAssignment.push_back(solution->assignment_);
            cout<<count++<<") "<<setw(15)<<(solution->assignment_->title_)<<setw(15)<<" submitted "<<setw(10)<<(solution->grade_)<<"/"<<(solution->assignment_->maxGrade_)<<"\n";;
        }
    }

    vector<shared_ptr<Assignment>>assignment = crs->assignments_ ;
    sort(submittedAssignment.begin(),submittedAssignment.end(),this->compareAssignment);
    sort(assignment.begin(),assignment.end(),this->compareAssignment);
    set_difference(assignment.begin(),assignment.end(),submittedAssignment.begin(),submittedAssignment.end(),back_inserter(unSubmittedAssignment),compareAssignment) ;

    for(shared_ptr<Assignment>assignment : unSubmittedAssignment)
    {
        cout<<count++<<") "<<setw(15)<<(assignment->title_)<<setw(15)<<"        "<<setw(10)<<" 0 / "<<(assignment->maxGrade_)<<"\n";;
    }

//        set_difference(assignment.begin(),assignment.end(),submittedAssignment.begin(),submittedAssignment.end(),back_inserter(unSubmittedAssignment));
}
void Student::studentGui(vector<shared_ptr<Course>>& courses){
    int choice ;
    while(true)
    {
        system("cls");
        menu = {"Register in Course","List my courses","View Coourse","Grade report","Log out"};
        choice = Helper::RunMenu(menu);
        switch(choice)
        {
            case  1:this->registerInCourseGui(courses) ; break;
            case  2:this->listCoursesGui();system("pause"); break;
            case  3:this->viewCourses();; ; break;
            case  4:this->gradeReport() ;system("pause");; break;
            case  5: return;
            default :break ;
        };
    };
}


