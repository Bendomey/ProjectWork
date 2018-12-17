#include <iostream>
#include <string>
#include "../libraries/auth.h"
using namespace std;




namespace auth{

    bool Auth::signIn(string id, string pin)
    {
        Database_User db;
        if(db.compareUser(id,pin) == true)
        {
            return true;
        }else
            return false;
        
    }
}