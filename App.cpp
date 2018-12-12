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
    admin::Admin ben;
    ben.set_first_name("Ben");
    cout << ben.get_first_name();
    cout << ben.get_status();
    return 0;
}
