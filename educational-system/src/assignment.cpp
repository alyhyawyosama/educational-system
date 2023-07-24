#include "../include/assignment.h"


void Assignment::enrollAssignmentSolution(shared_ptr<AssignmentSolution> & solution,shared_ptr<Student> & student)
{
    this->solutions_.push_back(solution);
    solution->student_ = student ;
    shared_ptr<Assignment>assignment (this) ;
    solution->assignment_ = assignment;
//        student->assignmentSolutions_.push_back(solution);
}


void Assignment::addSolution(Student * stud)
{
        shared_ptr<Student>student(stud) ;
        shared_ptr<AssignmentSolution> solution = make_shared<AssignmentSolution>();
        cout<<"Solution : ";
        cin.get();
        getline(cin,solution->answer_);
        cout<<"Answer -> "<<solution->answer_<<endl;
        enrollAssignmentSolution(solution,student);

//            cout<<"Title:"<<assignment->title_<<endl;
//            cout<<"Title:"getline(cin,assignment->title_);

}
//showSolution used to show the solutions of students
void Assignment::showSolution()
{
    system("cls");
    int count = 1;
    cout<<"  "<<" Student name"<<setw(20)<<"Answer"<<setw(15)<<"Grade\n";
    for(shared_ptr<AssignmentSolution> solution :this->solutions_ )
    {
        cout<<count++<<") "<<solution->student_->name_<<setw(20)<<solution->answer_<<setw(15)<<solution->grade_<<"\n";
    }
}
int Assignment::count = 0;
int AssignmentSolution::count = 0;



