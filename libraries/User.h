/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */



#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

/**
 * this file is the core for the users(admin, students, staff)
 */

class UserType {
    public:
        UserType();
        ~UserType();

    protected:
        string first_name;
        string last_name;
        string sex;
        string index_number;
        string pin;
};


#endif //USER_H