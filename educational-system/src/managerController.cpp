
#include"../include/managerController.h"

shared_ptr<ManagerController>  manager( new ManagerController());

shared_ptr<Student> ManagerController::getStudent(string username,string password)
{
    for(shared_ptr<Student> student : this->students )
    {
        if(student->isAuthInfo(username,password) )
        {
            return student ;
        }
    }
    return nullptr;
}

shared_ptr<Doctor> ManagerController::getDoctor(string username,string password)
{
    for(shared_ptr<Doctor> doctor : this->doctors )
    {
        if(doctor->isAuthInfo(username,password) )
        {
            return doctor ;
        }
    }
    return nullptr;
}

void ManagerController::studentLogin()
{
    cout<<"\nPlease enter user name and password:\n";
    string username;
    string password;
    cout<<"User Name: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    shared_ptr<Student> student = getStudent(username,password);

    if( student != nullptr )
    {
        return student->studentGui(this->courses);
    }
    else
    {
        cout<<"\n\nYour username or password is not true:\n";
        cout<<"\t Do you want to:\n";
        cout<<"\t1 - Try again\n";
        cout<<"\t2 - Back \n";
        cout<<"\tEnter Choice: ";
        int choose =  Helper::ReadInt(1, 3);
        if(choose == 1)
           studentLogin();
        else if(choose == 2)
          return;
        else
          assert(false);
    }
}void ManagerController::doctorLogin()
{
    cout<<"\nPlease enter user name and password:\n";
    string username;
    string password;
    cout<<"User Name: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;
    shared_ptr<Doctor> doctor = getDoctor(username,password);

    if( doctor != nullptr )
    {
        return doctor->doctorGui(this->courses);
    }
    else
    {
        cout<<"\n\nYour username or password is not true:\n";
        cout<<"\t Do you want to:\n";
        cout<<"\t1 - Try again\n";
        cout<<"\t2 - Back \n";
        cout<<"\tEnter Choice: ";
        int choose =  Helper::ReadInt(1, 3);
        if(choose == 1)
          return doctorLogin();
        else if(choose == 2)
          return;
        else
          assert(false);  // Shouldn't happen or code bug!
    }
}

void ManagerController::userLogin()
{
    cout<<"\n\nPlease make a choice:\n";
    cout<<"\t Are you:\n";
    cout<<"\t1 - Doctor\n";
    cout<<"\t2 - Student\n";
    cout<<"\t3 - Back \n";
    cout<<"\tEnter Choice: ";
    int choose =  Helper::ReadInt(1, 3);
    if(choose == 2)
      studentLogin();
    else if(choose == 1)
      doctorLogin();
    else if(choose == 3)
      return;
    else
      assert(false);
}


bool ManagerController::isExist(string username,string userType)
{
    if(userType == "student")
    {
        for(shared_ptr<Student> & stud:manager->students)
        {
            if(stud->username_ == username)
            {
              cout << "\n Error user name already exist .Try again\n\n";
              return true;
            }
        }
    }
    else if(userType == "doctor")
    {
        for(shared_ptr<Doctor> & doctor:manager->doctors)
        {
            if(doctor->username_ == username)
            {
              cout << "\n Error user name already exist .Try again\n\n";
              return true;
            }
        }
    }
    return false;
}

bool ManagerController::isEmailExist(string email,string userType)
{
    if(userType == "student")
    {
        for(shared_ptr<Student> & stud:manager->students)
        {
            if(stud->email_ == email)
            {
              cout << "\n Error email already exist .Try again\n\n";
              return true;
            }
        }
    }

    else if(userType == "doctor")
    {
        for(shared_ptr<Doctor> & doctor:manager->doctors)
        {
            if(doctor->email_ == email)
            {
              cout << "\n Error email already exist .Try again\n\n";
              return true;
            }
        }
    }
    return false;
}



/*
Email validation methods => is_valid_email ,isDigit,isChar
*/
bool ManagerController::isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

// Function to check the character
// is an digit or not
bool ManagerController::isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

// Function to check email id is
// valid or not
bool ManagerController::is_valid_email(string email)
{
	// Check the first character
	// is an alphabet or not
	if (!isChar(email[0])) {

		// If it's not an alphabet
		// email id is not valid
		return 0;
	}
	// Variable to store position
	// of At and Dot
	int At = -1, Dot = -1;
    int countAt = 0,countDot = 0;
	// Traverse over the email id
	// string to find position of
	// Dot and At
	for (int i = 0;
		i < email.length(); i++) {

		// If the character is '@'
		if (email[i] == '@') {
            countAt++;
			At = i;
		}

		// If character is '.'
		else if (email[i] == '.') {
          countDot++;
			Dot = i;
		}
	}

	// If At or Dot is not present
	if (At == -1 || Dot == -1)
		return 0;

	// If Dot is present before At
	if (At > Dot)
		return 0;
	//If Dot or At is present more than one  .
     if(countAt > 1 || countDot > 1 ){
         return 0;
     }
	// If Dot is present at the end
	return !(Dot >= (email.length() - 1));
}

void ManagerController::doctorSignUp()
{
    shared_ptr<Doctor> doctor(new Doctor());
    while (true)
    {
        cout << "Enter user name: ";
        cin >> doctor->username_;
        cout << "Enter password: ";
        cin >> doctor->password_;
        if(!isExist(doctor->username_,"doctor"))break;
    }
    cout << "Enter Full Name: ";
    do {
    getline(cin, doctor->name_);
    } while (doctor->name_.size() == 0);

    cout << "Enter Email: ";
    getline(cin, doctor->email_);

    while (doctor->email_.size() == 0 || !is_valid_email(doctor->email_)|| isEmailExist(doctor->email_,"doctor") )
    {
        cout<<"Error,try again either your email is not valid or already exist\n";
        cout << "Enter Email: ";
        getline(cin, doctor->email_);
    }

    manager->doctors.push_back(doctor);
}

/*End email validation methods*/

void ManagerController::studentSignUp()
{
shared_ptr<Student> student(new Student());
bool exist = 0;
while (true)
{
    cout << "Enter user name: ";
    cin >> student->username_;
    cout << "Enter password: ";
    cin >> student->password_;
    cout<<"Exist : "<<exist<<"\n";
    if(!isExist(student->username_,"student"))break;
}
  cout << "Enter Full Name: ";
  do {
    getline(cin, student->name_);
  } while (student->name_.size() == 0);

    cout << "Enter Email: ";
    getline(cin, student->email_);


    while (student->email_.size() == 0 || !is_valid_email(student->email_)|| isEmailExist(student->email_,"student") )
    {
        cout<<"Error,try again either your email is not valid or already exist\n";
        cout << "Enter Email: ";
        getline(cin, student->email_);
    }

  manager->students.push_back(student);
}


void ManagerController::userSignUp()
{
    cout<<"\n\nPlease make a choice:\n";
    cout<<"\t Are you:\n";
    cout<<"\t1 - Doctor\n";
    cout<<"\t2 - Student\n";
    cout<<"\t3 - Back \n";
    cout<<"\tEnter Choice: ";
    int choose =  Helper::ReadInt(1, 3);
    if(choose == 2)
      studentSignUp();
    else if(choose == 1)
      doctorSignUp();
    else if(choose == 3)
      return;
    else
      assert(false);  // Shouldn't happen or code bug!

}



void  ManagerController:: mainMenu()
{
    while(true)
    {
        cout<<"\n\nPlease make a choice:\n";
        cout<<"\t1 - Login\n";
        cout<<"\t2 - Sign up\n";
        cout<<"\t3 - Shutdown system\n";
        cout<<"\tEnter Choice: ";
        int option =  Helper::ReadInt(1, 3);
        if(option == 1)
          userLogin();
        else if(option == 2)
          userSignUp();
        else if(option == 3)
          return;
        else
          assert(false);
    }
}
void  ManagerController::studentsDummy()
{
    string arr[5] ={"Ali","Abdh","Mohammed","Saeed","Mahmod"};
    int size = 5;
    for(int i = 0;i<size;i++)
    {
        shared_ptr<Student> st = make_shared<Student>();
        char c = char(49+i);

        st->name_ = arr[ rand()% size ];;
        st->name_+= " "+ arr[ rand()% size ];
        st->username_="st";
        st->username_+= arr[ rand()% size ]+c;;
        st->password_="ss";
        st->email_ =  st->username_;
        st->email_ += "@gmail.com";
        manager->students.push_back(st);
    }
    cout<<"\t\t\t--------------- Students ----------------------\n\n";
    int count = 1;
    for(shared_ptr<Student>st:manager->students)
    {
        cout<<count++<<")Name : "<<st->name_<<" - Username : "<<st->username_<<" - Password :"<<st->password_<<" - Email : "<<st->email_<<" \n ";
    }
}


void ManagerController::coursesDoctorsDummy()
{
    int size = 5;
    string arr[5] ={"Ali","Abdh","Mohammed","Saeed","Mahmod"};
    for(int i = 0;i<size;i++)
    {
        char c = char(49+i);
        shared_ptr<Doctor> dr = make_shared<Doctor>();
        dr->name_ = arr[ rand()% size ];;
        dr->name_+=" "+arr[ rand()% size ];
        dr->username_="dr";
        dr->username_+=arr[ rand()% size]+c;;
        dr->password_="rr";
        dr->email_ = dr->username_;
        dr->email_ += "@gmail.com";

        manager->doctors.push_back(dr);
        for(int j = 0;j<size;j++)
        {
            shared_ptr<Course> course = make_shared<Course>();
            course->title_="Course ";
            course->title_+=dr->username_;
            course->title_+=char(49+j);;
            course->code_="Co-";;
            course->code_+=char(49+j);;
            //Enroll Doctor and courses;
            course->doctor_ = dr;
            dr->teaching_.push_back(course);
            manager->courses.push_back(course);
            for(int x = 0;x<size;x++)
            {
                shared_ptr<Assignment> assignment = make_shared<Assignment>();
                assignment->title_ = "Assignment";
                assignment->title_ += (char)49+j;
                assignment->title_ += (char)49+x;
                assignment->maxGrade_ = 50 ;
                assignment->course_ = course;
                course->assignments_.push_back(assignment);
            }
        }
    }

    cout<<"\t\t\t--------------- Doctotrs ----------------------\n\n";
    int count = 1;
    for(shared_ptr<Doctor>dr:manager->doctors)
    {
        cout<<count++<<")Name : "<<dr->name_<<" - Username : "<<dr->username_<<" - Password :"<<dr->password_<<" - Email : "<<dr->email_<<" \n ";
    }
}
