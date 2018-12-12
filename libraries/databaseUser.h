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
    // counter to check the  entering of the data
    int count;

  public:
    Database_User();
    ~Database_User();
    bool create(User);
};

/**
 * constructor handles opening the file for read and write
 */

Database_User::Database_User()
{
    // opening the file for writing
    afile.open(("Database files/databaseUser.txt"), ios::app | ios::in);
    cout << "File opened for reading and writing\n";
}

/**
 * deconstrcutor handles closing the file
 */

Database_User::~Database_User()
{
    // closing the file in the deconstructor
    afile.close();
    cout << "File closed\n";
}

bool Database_User::create(User user)
{
    string data[6];
    data[0] = "First Name: " + user.first_name;
    data[1] = "Last Name: " + user.last_name;
    data[2] = "Index Number: " + user.index_number;
    data[3] = "Pin: " + user.pin;
    data[4] = "Department: " + user.department;
    data[5] = "Level: " + user.level;

    for (int i = 0; i < 6; i++)
    {
        afile << data[i] << endl;
    }
    cout << "Written to file" << endl;
    count++;
    afile << count << endl;
    return true;
}
#endif //DATABASE_USER_H