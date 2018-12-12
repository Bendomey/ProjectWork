/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */


#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

/**
 * this class inherits from the user class, it takes the student-end
 */

namespace students{
    class student: public UserType {
        public:
            student();
        // setters
            void set_status();
            void set_level(string);
            void set_department(string);

        // getters
            int get_status(); 
            string get_level();
            string get_department();

        private:
            int status;
            string level;
            string department;
    };
}


#endif //STUDENT_H
