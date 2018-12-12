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

using namespace std;

/**
 * Struct handles the properties of items the users have
 */

struct User{
    string first_name;
    string last_name;
    string index_number;
    string pin;
    int level;
    string department;

};

class Database_User{
    // creating an output stream to the file
    ofstream infile;
    // counter to check the  entering of the data
    int count; 
    public:
    Database_User();
    ~Database_User();
};

Database_User::Database_User(){
    
}


#endif //DATABASE_USER_H