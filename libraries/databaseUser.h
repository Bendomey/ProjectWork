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
#include "datatypes.h"
using namespace std;

class Database_User
{
    // creating both an output and input stream to the file
    fstream afile;
    // creating an output to a file when read  from previous file
    ofstream outfile;

  public:
    bool createUser(User);
    bool readUser(string);
    bool udpdateUser(User,string);
    bool compareUser(string,string);
    string returnStatus(string);
    string returnName(string);
    string returnFirstName(string);
    string returnLastName(string);
    string returnLevel(string);
    string returnSex(string);
    string returnDepartment(string);
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

bool Database_User::readUser(string search_id)
{
    afile.open("Database files/databaseUser.txt",ios::in);
    outfile.open("output_file.txt", ios::out);
    User user;
    string data[6];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.sex;
    data[3] = user.index_number;
    data[4] = user.department;
    data[5] = user.level;
    
    if (search_id == user.index_number) {
        cout <<"User found\n";
        outfile << "DETAILS OF " << user.first_name << " " << user.last_name << endl;
        for (int i = 0; i < 7; i++)
        {
            afile >> data[i];
            outfile << data[i] << endl;

        }
        afile.close();
        outfile.close();

        return true;
    }

        cout << "user not found" << endl;

    return false;
}

bool Database_User::udpdateUser(User user,string user_id)
{
    afile.open("Database files/databaseUser.txt", ios::out);

    string data[8];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.sex;
    data[3] = user.index_number;
    data[4] = user.department;
    data[5] = user.level;
    data[6] = user.index_number;
    data[7] = user.pin;

    if (user_id == user.index_number) {
        cout << "User found\n";
        for (int i = 0; i < 8; i++)
        {
            afile << data[i] << "    ";
        }
        afile << endl;
        afile.close();

        cout << "Updated successfully;" << endl;
        return true;
    }


    cout << "Student bearing this id " << user_id << " is not available\n";
    return false;
}

bool Database_User::compareUser(string id, string pin)
{
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
        if(pin == data[7])
        {
            return true;
        }
    }
    afile.close();

    return false;
}

string Database_User::returnStatus(string id){

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
        return data[5];
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