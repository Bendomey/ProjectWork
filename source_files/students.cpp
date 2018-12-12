#include <iostream>
#include <string>
#include "../libraries/students.h"
using namespace std;




namespace students{

    student::student()
    {
        this->set_status();
    }

    // setters
    void student::set_status()
    {
        this->status = 3;
    }

    void student::set_level(string level)
    {
        this->level = level;
    }
    
    void student::set_department(string dept) 
    {
        this->department = dept;
    }


    // getters
    int student::get_status()
    {
        return this->status;
    }

    string student::get_level()
    {
        return this->level;
    }

    string student::get_department()
    {
        return this->department;
    }
    
}