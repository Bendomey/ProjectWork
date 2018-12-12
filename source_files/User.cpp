#include <iostream>
#include <string>
#include "../libraries/User.h"

// constructor
UserType::UserType()
{
}

// deconstructor
UserType::~UserType()
{
}

// setters
void UserType::set_first_name(string name)
{
    this->first_name = name;
}

void UserType::set_last_name(string name)
{
    this->last_name = name;
}

void UserType::set_sex(string sex)
{
    this->sex = sex;
}

void UserType::set_index_number()
{
    // generate for index number
}

void UserType::set_pin()
{
    // generate for pin
}

// getters

string UserType::get_first_name()
{
    return this->first_name;
}

string UserType::get_last_name()
{
    return this->last_name;
}

string UserType::get_sex()
{
    return this->sex;
}

string UserType::get_index_number()
{
    return this->index_number;
}

string UserType::get_pin()
{
    return this->pin;
}

