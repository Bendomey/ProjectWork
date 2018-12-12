/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

 /**
 * this file contains the all datatypes of the application
 */

#ifndef DATATYPES_H
#define DATATYPES_H

#include <iostream>
#include <string>
using namespace std;

/**
 * Struct handles the properties of items the users have
 */

struct User{
    string first_name;
    string last_name;
    string sex;
    string index_number;
    string pin;
    string level;
    string department;

};


#endif //DATATYPES_H