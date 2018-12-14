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
    user.first_name = "Benjamin";
    user.last_name = "Domey";
    user.level =  "200";
    user.sex = "Male";
    user.department = "Computer Science";
    user.index_number = "10670196";
    user.pin = "12345";

    Database_User db;
    db.createUser(user);
    // db.readUser(user,"10670196");
    return 0;
}
