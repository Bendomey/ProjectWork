/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

/**
 * this class inherits from the user class, it takes the admin-end
 */

namespace admin
{
    class Admin : public UserType
    {
        public:
            Admin();
            // setters
            void set_status();

            // getters
            int get_status();

        private:
            int status;
    };
} // namespace students

#endif //ADMIN_H
