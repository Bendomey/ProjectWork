#include <iostream>
#include <string>
#include "../libraries/admin.h"
using namespace std;

namespace admin
{

    Admin::Admin()
    {
        this->set_status();
    }

    // setters
    void Admin::set_status()
    {
        this->status = 1;
    }

    // getters
    string Admin::get_status()
    {
        return this->status;
    }
} // namespace admin