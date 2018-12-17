/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

 /**
 * this file contains all datatypes of the application
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
    string level;
    string sex;
    string department;
    string status;
    string index_number;
    string pin;

};

struct student_course{
    std::string student_index;
	std::string course_code;
    std::string course_title;
    std::string student_mark_IA = "NA";
    std::string student_mark_EXAM = "NA";
    std::string student_grade = "NA";
};

struct staff_course{
    std::string course_code;
	std::string course_title;
    std::string course_lecturer;
};

#endif //DATATYPES_H