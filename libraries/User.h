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

class UserType
{
  public:
    UserType();
    ~UserType();
    // setters
    void set_first_name(string);
    void set_last_name(string);
    void set_sex(string);
    void set_index_number();
    void set_pin();

    // getters
    string get_first_name();
    string get_last_name();
    string get_sex();
    string get_index_number();
    string get_pin();

  protected:
    string first_name;
    string last_name;
    string sex;
    string index_number;
    string pin;
};

#endif //USER_H