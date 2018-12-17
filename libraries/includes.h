/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

#ifndef INCLUDES_H
#define INCLUDES_H

/**
 * this includes header file that contains all files from the whole program
 */

#include <iostream>
#include <string>
#include "datatypes.h"
#include "databaseUser.h"
#include "databaseCourse.h"
// #include "../source_files/studentCourse.cpp"
#include "../source_files/User.cpp"
#include "../source_files/students.cpp"
#include "../source_files/staffs.cpp"
#include "../source_files/admin.cpp"
#include "../source_files/auth.cpp"

// namespaces
using namespace std;
using namespace auth;

// Function prototypes
void start_application();
void checkInt(int);
void login_screen();
void start_screen_for_admin(string);
void start_screen_for_staff(string);
void start_screen_for_student(string,string);
void edit_student_details(string,string);
void add_courses_student(string,string);
void remove_course_student(string,string);
void checkForStudent(int);
void checkForStaff(int);
void checkForScores(int);
void validateToContinue(int);
void add_course(string);
void edit_course(string);
void remove_course(string);
void add_course_grades(string);
void add_IA(string);
void add_scores_and_grades(string indexNumber);

// ************FUNCTIONS FOR THE APPLICATION*************************


void start_application()
{
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM\n";
    cout << "Welcome ...\n";
    cout << "1. Start Application \n2. Exit Application\n";
    cout << "Please select: ";
    int choice;
    cin >> choice;
    checkInt(choice);
    cout << endl;
    switch(choice)
    {
        case 1: 
            login_screen();
            break;
        case 2:
            cout << "Have a nice day :)\n";
            // exit(1);
            break;

    }
}

void checkInt(int a)
{
    while(cin.fail() || a > 2 || a < 1)
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter correct valid input: ";
        cin >> a;
    }
}

void login_screen()
{
    // system("cls");
    User user;
    Database_User db;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM\n";
    cout << "\t\t\t\tLOGIN\n\n";
    cout << "Index Number: ";
    cin >> user.index_number;
    cout << "Pin: ";
    cin >> user.pin;
    cout << endl; 
    Auth login;
    string status;
    if(login.signIn(user.index_number,user.pin))
    {
        status = db.returnStatus(user.index_number);
        if(status == "1"){
            // return screen for admin
            start_screen_for_admin(user.index_number);
        }else 
        if(status == "2"){
            // return screen for staff
            start_screen_for_staff(user.index_number);
        }else 
        if(status == "3"){
            // return screen for student
            start_screen_for_student(user.index_number,user.pin);
        }
    }else{
        cout << "Invalid details!!\n";
    }

}

void start_screen_for_admin(string indexNumber)
{
    Database_User db; 
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db.returnName(indexNumber) << endl;
}

void start_screen_for_staff(string indexNumber)
{
    Database_User db_user;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM STAFF PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "1. Add Course\n2. Edit Course\n3. Remove Course\n4. Add Course Grades And Marks\n5. Logout\n";
    int choice;
    cout << "Please select: ";
    cin >> choice;
    checkForStaff(choice);

    if(choice == 1) {
        // add new course
        add_course(indexNumber);
    }else
    if(choice == 2){
        // edit course
        edit_course(indexNumber);
    }else
    if(choice == 3) {
        // remove course
        remove_course(indexNumber);
    }else 
    if(choice == 4){
        // add course grades and marks

        add_scores_and_grades(indexNumber);
        
    }else
    if(choice == 5){
        // logout
        start_application();
    }
}

void add_scores_and_grades(string indexNumber)
{
    Database_User db_user;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM STAFF PORTAL\n";
        cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
        cout << "1. Add IA marks\n2. Add Exam Score and Grade\n3. Go back\n";
        int choice;
        cout << "Please select: ";
        cin >> choice;
        checkForScores(choice);
        
        if(choice == 1){
            // Add IA marks
            add_IA(indexNumber);
        }else 
        if(choice == 2) {
            // add exams and grade
            add_course_grades(indexNumber);
        }else
        if(choice == 3){
            // go back
            start_screen_for_staff(indexNumber);
        }
}

void add_IA(string indexNumber)
{
    Database_course db_course;
    student_course course;
    cout << "Please enter the id of the user: ";
    cin >> course.student_index;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout << "Please enter the mark of the student: ";
    cin >> course.student_mark_IA;
    // calling the assign ia mark method
    if(db_course.assign_IA_marks(course.student_index,course.course_code,course.student_mark_IA)){
        cout << "Successfully updated the record of " << course.student_index << endl;
    }
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        add_scores_and_grades(indexNumber);
    }

}

void add_course_grades(string indexNumber)
{
    Database_course db_course;
    student_course course;
    cout << "Please enter the id of the user: ";
    cin >> course.student_index;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout << "Please enter the mark of the student: ";
    cin >> course.student_mark_EXAM;
    // calling the assign exam mark and exam grade
    if(db_course.assign_EXAM_marks(course.student_index,course.course_code,course.student_mark_EXAM)){
        cout << "Successfully Updated the record of " << course.student_index << endl;
    }
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        add_scores_and_grades(indexNumber);
    }
}

void add_course(string indexNumber)
{
    Database_course db_course;
    staff_course course;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout  << "Please enter course title: ";
    cin >> course.course_title;
    cout << "Please enter course lecturer: ";
    cin >> course.course_lecturer;
    // calling the create method
    db_course.create(course);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        start_screen_for_staff(indexNumber);
    }
}

void edit_course(string indexNumber)
{
    Database_course db_course;
    staff_course course;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout  << "Please enter course title: ";
    cin >> course.course_title;
    cout << "Please enter course lecturer: ";
    cin >> course.course_lecturer;
    // calling the update method
    db_course.updateCourse(course);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        start_screen_for_staff(indexNumber);
    }
}

void remove_course(string indexNumber)
{
    Database_course db_course;
    string course_code;
    cout << "Please type in the corresponding course code you want to delete: ";
    cin >> course_code;
    // calling the delete method
    db_course.deleteCourse(course_code);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        start_screen_for_staff(indexNumber);
    }
}


void start_screen_for_student(string indexNumber,string pin)
{
    Database_User db;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM STUDENT PORTAL\n";
    cout << "\tWelcome " << db.returnName(indexNumber) << endl;
    cout << "1. Edit Student Profile\n2. Add courses\n3. Remove Course\n4. Logout\n";
    int choice;
    cout << "Please select: ";
    cin >> choice;
    checkForStudent(choice);

    if(choice == 1) {
        // edit student details
        edit_student_details(indexNumber,pin);

    }else
    if(choice == 2) {
        // add course
        add_courses_student(indexNumber,pin);
    }else 
    if(choice == 3) {
        // remove course
        remove_course_student(indexNumber,pin);
    }else
    if(choice == 4) {
        // logout redirect back to start_screen
        start_application();
    }

}

void edit_student_details(string indexNumber,string pin)
{
    Database_User db;
    cout << "Student Details\n";
    cout << "Please enter new set of details: \n";
    User student;
    cout << "First Name: ";
    cin >> student.first_name;
    cout  << "Last Name: ";
    cin >> student.last_name;
    cout << "Sex: ";
    cin >> student.sex;
    student.level = db.returnLevel(indexNumber);
    student.department = db.returnDepartment(indexNumber);
    student.status = db.returnStatus(indexNumber);
    student.index_number = indexNumber;
    student.pin = pin;
    // updating
    db.udpdateUser(student);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);

    if(choice == 1){
        start_screen_for_student(indexNumber,pin);
    }
}

void add_courses_student(string indexNumber,string pin)
{
    //course function should be here to show all courses added by the staff 
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);

    if(choice == 1){
        start_screen_for_student(indexNumber,pin);
    }

}

void remove_course_student(string id, string pin)
{
    // course function be here to delete a course
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);

    if(choice == 1){
        start_screen_for_student(id,pin);
    }
    
}

void checkForStudent(int a){
    while(cin.fail() || a > 4 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
}

void checkForStaff(int a){
    while(cin.fail() || a > 5 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
}


void checkForScores(int a){
    while(cin.fail() || a > 3 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
}

void validateToContinue(int a)
{
    while(cin.fail() || a!=1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter 1: ";
        cin >> a;
    }
}

#endif //INCLUDES_H