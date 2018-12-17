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
#include <cstdlib>
#include <ctime>
#include "datatypes.h"
#include "databaseUser.h"
#include "databaseCourse.h"
// #include "../source_files/studentCourse.cpp"
#include "../source_files/auth.cpp"

// namespaces
using namespace std;
using namespace auth;

// Function prototypes
void start_application();
void checkInt(int);
void login_screen();
void start_screen_for_admin(string);
void add_or_remove_staff(string);
void add_staff(string);
void remove_staff(string);
void add_or_remove_student(string);
void add_student(string);
void remove_student(string);
void add_admin(string);
void edit_account(string);
void start_screen_for_staff(string);
void start_screen_for_student(string,string);
void view_student_courses(string,string);
void edit_student_details(string,string);
void add_courses_student(string,string);
void remove_course_student(string,string);
void checkForStudent(int);
void checkForStaff(int);
void checkForScores(int);
void checkForAdmin(int);
void validateToContinue(int);
void add_course(string);
void edit_course(string);
void remove_course(string);
void add_course_grades(string);
void add_IA(string);
void add_scores_and_grades(string indexNumber);
string index_number_generator();
string pin_generator();

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
    switch(choice)
    {
        case 1: 
            login_screen();
            break;
        case 2:
            cout << "Have a nice day :)\n";
            exit(1);
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
    system("clear");
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
    system("clear");
    Database_User db; 
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db.returnName(indexNumber) << endl;
    cout << "1. Add or Remove Staff\n2. Add or Remove Student\n3. Add Admin\n4. Edit Account\n5. Logout\n";
    int choice;
    cout << "Please select: ";
    cin >> choice;
    checkForStudent(choice);

    if(choice == 1){
        // add or remove staff
        add_or_remove_staff(indexNumber);
    }else
    if(choice == 2){
        // add or remove student
        add_or_remove_student(indexNumber);
    }else
    if(choice == 3){
        // add admin
        add_admin(indexNumber);
    }else 
    if(choice == 4)
    {
        // edit account
        edit_account(indexNumber);
    }
    if(choice == 5){
        // logout
        start_application();
    }
}

void add_admin(string indexNumber)
{
    User user;
    Database_User db;
    cout << "Enter first name: ";
    cin >> user.first_name;
    cout << "Enter last name: ";
    cin >> user.last_name;
    user.level = "admin";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    user.department = "no-department";
    user.status = "2";
    // generate index and pin here;
    user.index_number = index_number_generator();
    user.pin = pin_generator();
    // calling the create user from database class
    db.createUser(user);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        start_screen_for_admin(indexNumber);
    }
}

void edit_account(string indexNumber)
{
    User user;
    Database_User db;
    cout << "Enter first name: ";
    cin >> user.first_name;
    cout << "Enter last name: ";
    cin >> user.last_name;
    user.level = "admin";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    user.department = "no-department";
    user.status = 1;
    user.index_number = indexNumber;
    user.pin = db.returnPin(indexNumber);
    // calling the create user from database class
    db.udpdateUser(user);    

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        start_screen_for_admin(indexNumber);
    }
}

void add_or_remove_staff(string indexNumber)
{
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "1. Add Staff\n2. Remove Staff\n3. Go back\n";
    int choice;
    cout << "Please select: ";
    cin >> choice;
    checkForScores(choice);
    if(choice == 1){
        // add staff
        add_staff(indexNumber);
    }else
    if(choice == 2){
        // add or remove student
        remove_staff(indexNumber);
    }else
    if(choice == 3){
        // Go back
        start_screen_for_admin(indexNumber);
    }

}

void add_staff(string indexNumber)
{
    User user;
    Database_User db_user;
    cout << "Please enter first name: ";
    cin >> user.first_name;
    cout << "Please enter last name: ";
    cin >> user.last_name;
    user.level = "staff";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    user.department = "no-department";
    user.status = "2";
    // generate id and pin
    user.index_number = index_number_generator();
    user.pin = pin_generator();
    // calling the create database method
    db_user.createUser(user);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        add_or_remove_staff(indexNumber);
    }
}

void remove_staff(string indexNumber)
{
    string search_id;
    Database_User db_user;
    cout << "Please enter the Staff's id you want to remove: ";
    cin >> search_id;
    // calling the deleteUser from database
    db_user.deleteUser(search_id);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        add_or_remove_staff(indexNumber);
    }
}
void add_or_remove_student(string indexNumber)
{
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "1. Add Student\n2. Remove Student\n3. Go back\n";
    int choice;
    cout << "Please select: ";
    cin >> choice;
    checkForScores(choice);
    if(choice == 1){
        // add staff
        add_student(indexNumber);
    }else
    if(choice == 2){
        // add or remove student
        remove_student(indexNumber);
    }else
    if(choice == 3){
        // logout
        start_screen_for_admin(indexNumber);
    }
}

void add_student(string indexNumber)
{
    User user;
    Database_User db_user;
    cout << "Please enter first name: ";
    cin >> user.first_name;
    cout << "Please enter last name: ";
    cin >> user.last_name;
    user.level = "100";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    cout << "Please enter deparment with all words together: ";
    cin >> user.department;
    user.status = "3";
    // generate id and pin
    user.index_number = index_number_generator();
    user.pin = pin_generator();
    // calling the create database method
    db_user.createUser(user);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        add_or_remove_student(indexNumber);
    }
}

void remove_student(string indexNumber)
{
    string search_id;
    Database_User db_user;
    cout << "Please enter the Student's id you want to remove: ";
    cin >> search_id;
    // calling the deleteUser from database
    db_user.deleteUser(search_id);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);
    if(choice == 1){
        add_or_remove_student(indexNumber);
    }
}

void start_screen_for_staff(string indexNumber)
{
    system("clear");
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
    system("clear");
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
    db_course.assign_IA_marks(course.student_index,course.course_code,course.student_mark_IA);
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
    system("clear");
    Database_User db;
    cout << "\t\t\t\t\t\t TEMA SECONDARY SCHOOL MANAGEMENT SYSTEM STUDENT PORTAL\n";
    cout << "\tWelcome " << db.returnName(indexNumber) << endl;
    cout << "1. Edit Student Profile\n2. View Courses\n3. Add courses\n4. Remove Course\n5. Logout\n";
    int choice;
    cout << "Please select: ";
    cin >> choice;
    checkForStudent(choice);

    if(choice == 1) {
        // edit student details
        edit_student_details(indexNumber,pin);

    }else
    if(choice == 2){
        // view courses
        view_student_courses(indexNumber,pin);
    }else
    if(choice == 3) {
        // add course
        add_courses_student(indexNumber,pin);
    }else 
    if(choice == 4) {
        // remove course
        remove_course_student(indexNumber,pin);
    }else
    if(choice == 5) {
        // logout redirect back to start_screen
        start_application();
    }

}

void view_student_courses(string indexNumber,string pin)
{
    Database_course course;
    if(!course.view_courses(indexNumber)){
        // cout << "No Courses registered for\n";
    }

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);

    if(choice == 1){
        start_screen_for_student(indexNumber,pin);
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
    Database_course course;
    cout << "Courses available\n";
    course.coursesAvailable();
    student_course std_course;
    std_course.student_index = indexNumber;
    cout << "Please enter the course code: ";
    cin >> std_course.course_code;
    cout  << "Please enter the course title: ";
    cin >> std_course.course_title;
    // calling the create function
    course.create(std_course);

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
    Database_course course;
    string course_code;
    cout << "Please enter your the corressponding course code of the course you want to remove: ";
    cin >> course_code;
    // calling remove method
    course.deleteCourse(course_code,id);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    validateToContinue(choice);

    if(choice == 1){
        start_screen_for_student(id,pin);
    }
    
}

void checkForAdmin(int a){
    while(cin.fail() || a > 2 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
}

void checkForStudent(int a){
    while(cin.fail() || a > 5 || a < 1){
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

string index_number_generator()
{
    srand(time(0));
    string pin = "10" + to_string(rand()%10000);
    return pin;
}

string pin_generator()
{
    srand(time(0));
    string pin = to_string(rand()%10000);
    return pin;
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