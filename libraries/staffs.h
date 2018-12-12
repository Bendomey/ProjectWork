/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

/**
 * this class inherits from the user class, it takes the student-end
 */

namespace staffs
{
    class staff : public UserType
    {
        public:
            staff();
            // setters
            void set_status();
            void set_department(string);

        // getters
            int get_status();
            string get_department();

        private:
            int status;
            string department;
    };
} // namespace staffs

#endif //STAFF_H
