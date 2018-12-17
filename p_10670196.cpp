/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by: root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */


/**
 * this file is the frontend of the application
 * It contains the start application which contains all the functions from the include function
 *  Whenever you are given a prompt please put the words together
 */

#include "libraries/includes.h"

main(int argc, char const *argv[])
{

    /**
     * Application starts here
     */

    // start_application();
    Database_course course;
    string hmm = course.readStaffCourse("En101","112233");
    cout << hmm.size();

    /**
     * Application ends here
     */
    return 0;
}
