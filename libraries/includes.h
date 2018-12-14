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
#include "../source_files/courses.cpp"
#include "../source_files/User.cpp"
#include "../source_files/students.cpp"
#include "../source_files/staffs.cpp"
#include "../source_files/admin.cpp"
#include "../source_files/auth.cpp"

// namespaces
using namespace std;
using namespace course;
using namespace auth;

// Function prototypes
void start_application();
void checkInt(int);
void login_screen();
void start_screen();
void start_screen_for_admin();
void start_screen_for_staff();
void start_screen_for_student();

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
            // login_screen();
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
    if(login.signIn(user.index_number,user.pin))
    {
        if(db.returnStatus(user.index_number) == "1"){
            // return screen for admin
            start_screen_for_admin();
        }else 
        if(db.returnStatus(user.index_number) == "2"){
            // return screen for staff
            start_screen_for_staff();
        }else 
        if(db.returnStatus(user.index_number) == "3"){
            // return screen for student
        }
    }else{
        cout << "Invalid details!!\n";
    }

}

void start_screen_for_admin()
{
    User user;
    cout << "Welcome " << user.last_name << " " << user.last_name;
}

void start_screen_for_staff()
{
    User user;
    cout << "Welcome " << user.last_name << " " << user.last_name;
}

void start_screen_for_student()
{
    User user;
    cout << "Welcome " << user.last_name << " " << user.last_name;
}

#endif //INCLUDES_H