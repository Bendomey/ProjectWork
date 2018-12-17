/**
 * @Author: domey
 * @Date:   2018-12-11T17:34:25-05:00
 * @Last modified by:   root
 * @Last modified time: 2018-12-11T20:22:31-05:00
 */

#ifndef DATABASE_USER_H
#define DATABASE_USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
using namespace std;

class Database_User
{
    fstream afile;
    ofstream tmp_file;
    string user_line;
    string arr[10];

  public:
    bool createUser(User);
    string readUser(string);
    void udpdateUser(User);
    void deleteUser(string);
    bool compareUser(string,string);
    string returnStatus(string);
    string returnName(string);
    string returnFirstName(string);
    string returnLastName(string);
    string returnLevel(string);
    string returnSex(string);
    string returnDepartment(string);
    
    template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}
};


bool Database_User::createUser(User user)
{
    afile.open("Database files/databaseUser.txt", ios::out | ios::app);

    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for (int i = 0; i < 8; i++)
    {   
        afile << data[i] << "  ";
    }
    afile << endl;
    afile.close();

    cout << "Written to file successfully" << endl;
    return true;
}

string Database_User::readUser(string search_id)
{
    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == search_id){
            break;
        }
    }
    afile.close();
    return user_collect;
}

// update user

void Database_User::udpdateUser(User user)
{
   string exist_user;
   string new_user;
   string temp_user;
   exist_user = this->readUser(user.index_number);
   cout << "Existing data of user: " << exist_user << endl;
    new_user = user.first_name + " " + user.last_name + " " + user.level + " " + user.sex + " " + user.department + " " + user.status + " " + user.index_number + " " + user.pin;
    cout << "New data of user: " << endl;
    afile.open("Database files/databaseUser.txt");
    tmp_file.open("Database files/tmp_file.txt");
    while(!afile.eof())
    {
        getline(afile,temp_user);
        if(temp_user == exist_user){
            temp_user = new_user;
        }
        tmp_file << temp_user << endl;
    }
    tmp_file.close();
    afile.close();
    remove("Database files/databaseUser.txt");
    rename("Database files/tmp_file.txt", "Database files/databaseUser.txt");
    cout << "Updated success\n";
}

// delete user

void Database_User::deleteUser(string search_id)
{
    string user_collect = this->readUser(search_id);
    string exist_user;
    afile.open("Database files/databaseUser.txt");
    tmp_file.open("Database files/tmp_file.txt");
    while(!afile.eof())
    {
        getline(afile,exist_user);
        if(exist_user == user_collect){
            continue;
        }else{
            tmp_file << exist_user << endl;
        }
    }
    tmp_file.close();
    afile.close();
    remove("Database files/databaseUser.txt");
    rename("Database files/tmp_file.txt", "Database files/databaseUser.txt");
    // cout << "user updated successfully";
}

// for the authentication class
bool Database_User::compareUser(string id, string pin)
{
    string user_collect;
    afile.open("Database files/databaseuser.txt");
    while(afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id && arr[7] == pin){
            return true;
            break;
        }
    }
    afile.close();
    // return false;
}

string Database_User::returnStatus(string id){
    User user;
    string user_collect;
    afile.open("Database files/databaseuser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user.first_name = arr[0];
            user.last_name = arr[1];
            user.level = arr[2];
            user.sex = arr[3];
            user.department = arr[4];
            user.status = arr[5];
            user.index_number = arr[5];
            user.pin = arr[6];
            break;   
        }
    }

    afile.close();

}


string Database_User::returnName(string id){

    afile.open("Database files/databaseUser.txt");
    User user;
    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for(int i = 0; i < 8; i++){
        afile >> data[i];
    }

    if(id == data[6]){
        return data[1] + " " + data[0];
    }

    afile.close();
}


string Database_User::returnFirstName(string id){

    afile.open("Database files/databaseUser.txt");
    User user;
    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for(int i = 0; i < 8; i++){
        afile >> data[i];
    }

    if(id == data[6]){
        return data[0];
    }

    afile.close();
}

string Database_User::returnLastName(string id){

    afile.open("Database files/databaseUser.txt");
    User user;
    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for(int i = 0; i < 8; i++){
        afile >> data[i];
    }

    if(id == data[6]){
        return data[1];
    }

    afile.close();
}

string Database_User::returnLevel(string id){

    afile.open("Database files/databaseUser.txt");
    User user;
    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for(int i = 0; i < 8; i++){
        afile >> data[i];
    }

    if(id == data[6]){
        return data[2];
    }

    afile.close();
}

string Database_User::returnSex(string id){

    afile.open("Database files/databaseUser.txt");
    User user;
    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for(int i = 0; i < 8; i++){
        afile >> data[i];
    }

    if(id == data[6]){
        return data[3];
    }

    afile.close();
}

string Database_User::returnDepartment(string id){

    afile.open("Database files/databaseUser.txt");
    User user;
    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;
    data[7] = user.pin;

    for(int i = 0; i < 8; i++){
        afile >> data[i];
    }

    if(id == data[6]){
        return data[4];
    }

    afile.close();
}



#endif //DATABASE_USER_H