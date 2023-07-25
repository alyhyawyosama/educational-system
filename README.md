# Simple educational System Project

![Project Logo](link_to_your_project_logo.png)

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Contact](#contact)

## Introduction
This is a simple educational system project developed as a personal learning project to review C++ basics and some data structure concepts. The project is designed to provide functionalities for doctors and students, allowing them to interact with courses, assignments, and solutions. It does not incorporate object-oriented programming concepts.

## Features
The educational system project includes the following features:

1. **Login and Sign Up**: Users can log in and sign up as doctors or students.

2. **Doctor Features**:
   - Add and manage courses.
   - Create assignments for each course, along with a maximum mark for solutions.
   - View students' submitted solutions for assignments.
   - Enter marks for each student's solution.

3. **Student Features**:
   - Register for courses they have not enrolled in before.
   - Submit solutions for assignments in registered courses.
   - View their grade reports, including the mark received for each solution and the number of submitted solutions for each course.

## Getting Started
### Prerequisites
To run the educational system project, you will need the following installed on your system:
- C++ compiler (supporting C++11 or later).

### Installation
1. Clone the repository to your local machine using the following command:
```bash
git clone https://github.com/alyhyawyosama/educational-system.git
```
2. Navigate to the project directory:
```bash
cd educational-system
```

3. Compile the source code using the C++ compiler:
   ```bash
   g++ main.cpp -o educational_system
   ```
4. Run the executable:
   ```bash
   ./educational_system
   ```




## Usage
After running the educational system, follow the on-screen instructions to log in as a doctor or student and start using the system's features.

## Project Structure
The project is structured as follows:
- `main.cpp`: The main source code file containing the entry point of the program.
- `doctor.h`, `doctor.cpp`: Header and source files for the doctor-related functionalities.
- `student.h`, `student.cpp`: Header and source files for the student-related functionalities.
- `course.h`, `course.cpp`: Header and source files for the course-related functionalities.
- `assignment.h`, `assignment.cpp`: Header and source files for the assignment-related functionalities.
- `assignmentSolution.h`, `assignmentSolution.cpp`: Header and source files for the solution-related functionalities.
- `helper.h`, `helper.cpp`: Header and source files containing utility functions.


## Contact
For any questions or feedback, please feel free to contact me at [alyhyawyosama@gmail.com](mailto:alyhyawyosama@gmail.com). Happy coding! 😊

