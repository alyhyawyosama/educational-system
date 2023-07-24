#include "../include/course.h"

void Course::printInfo()
{
    cout<<setw(15)<<(this->title_)<<setw(10)<<this->code_<<"\n";
}
int Course::count = 0;

//This method is used to print the assignments of course ;

void  Course::printAssignments()
{
    int count = 1;
    cout<<setw(10)<<"Title"<<setw(15)<<"Max grade\n";
    for(shared_ptr<Assignment> & assignment :  this->assignments_  )
    cout<<" "<<count++ <<" - "<<setw(10)<<assignment->title_<<setw(10)<<assignment->maxGrade_<<endl;
}


void  Course::addNewAssignment()
{
    shared_ptr<Assignment>assignment = make_shared<Assignment>();
    cin.get();
    cout<<"Title : ";getline(cin,assignment->title_);
    cout<<"Max grade:";cin>>assignment->maxGrade_;
    while(cin.fail() || assignment->maxGrade_ < 1 || assignment->maxGrade_ > 100  )
    {
        cout<<"Error there is an error occur. Your grade must be between 1 - 100\n";
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"Max grade:";cin>>assignment->maxGrade_;
    }
    this->assignments_.push_back(assignment);
}
