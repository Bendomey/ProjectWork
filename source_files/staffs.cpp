#include <iostream>
#include <string>
#include "../libraries/staffs.h"
using namespace std;

namespace staffs
{

    staff::staff()
    {
        this->set_status();
    }

    // setters
    void staff::set_status()
    {
        this->status = 2;
    }

    void staff::set_department(string dept)
    {
        this->department = dept;
    }

    // getters
    string staff::get_status()
    {
        return this->status;
    }

    string staff::get_department()
    {
        return this->department;
    }

} // namespace staffs