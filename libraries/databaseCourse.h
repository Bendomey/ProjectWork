/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

#ifndef DATABASE_COURSE_H
#define DATABASE_COURSE_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
using namespace std;

/**
 * creating methods for both the staff(thus they adding courses editing and removing) 
 * and the student(thus their marks and grades)
 */

    void returnStatus(string, User&);
class Database_course
{
    fstream afile;
    ofstream tmp_file;
    string user_line;
    string arr[10];

    public:

    // creating a course


};

#endif//DATABASE_COURSE_H