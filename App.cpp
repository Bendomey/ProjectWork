/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */


/**
 * this file is the frontend of the application
 */

#include "libraries/includes.h"

main(int argc, char const *argv[])
{
    cout << "Hello world\n";
    User user;
    Database_User kofi;
    user.first_name = "Ben";
    user.last_name = "Domey";
    user.index_number = "10670196";
    user.pin = "59779";
    user.department = "Comp Science";
    user.level = "200";
    kofi.create(user);
    return 0;
}
