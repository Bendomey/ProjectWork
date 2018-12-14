/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

#ifndef DATABASE_USER_H
#define DATABASE_USER_H

#include <iostream>
#include <string>
#include <fstream>
#include "datatypes.h"
using namespace std;

class Database_User
{
    // creating both an output and input stream to the file
    fstream afile;
    // creating an output to a file when read  from previous file
    ofstream outfile;

  public:
    Database_User();
    ~Database_User();
    bool createUser(User);
    bool readUser(User,string);
};

/**
 * constructor handles opening the file for read and write
 */

Database_User::Database_User()
{
    // opening the file for writing
    afile.open("Database files/databaseUser.txt", ios::app | ios::in);
    outfile.open("output_file.txt", ios::out);
}

/**
 * deconstrcutor handles closing the file
 */

Database_User::~Database_User()
{
    // closing the file in the deconstructor
    outfile.close();
    afile.close();
}

bool Database_User::createUser(User user)
{
        // counter to check the  entering of the data
    int count = 0;
    string data[7];
    data[0] = "First Name: " + user.first_name;
    data[1] = "Last Name: " + user.last_name;
    data[2] = "Sex: " + user.sex;
    data[3] = "Index Number: " + user.index_number;
    data[4] = "Pin: " + user.pin;
    data[5] = "Department: " + user.department;
    data[6] = "Level: " + user.level;

    afile << "Student " << count+1 << endl;
    for (int i = 0; i < 7; i++)
    {   
        afile << data[i] << endl;
    }
    cout << "Written to file" << endl;
    count++;
    afile << count << endl;
    return true;
}

bool Database_User::readUser(User user, string search_id)
{
    
    string data[6];
    data[0] = "First Name: " + user.first_name;
    data[1] = "Last Name: " + user.last_name;
    data[2] = "Sex: " + user.sex;
    data[3] = "Index Number: " + user.index_number;
    data[4] = "Pin: " + user.pin;
    data[5] = "Department: " + user.department;
    data[6] = "Level: " + user.level;
    
    if (search_id == user.index_number) {
        cout <<"User found\n";
        return true;
    //     outfile << "DETAILS OF " << user.first_name << " " << user.last_name << endl;
    // for (int i = 0; i < 7; i++)
    // {
    //     afile >> data[i];
    //     outfile << data[i] << endl;

    // }
    }

        cout << "user not found";
    
    
    return false;
}
#endif //DATABASE_USER_H