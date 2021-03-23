#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include <cstring>
#include <iostream>

using namespace std;

class User{
private:
    string name;
    string password;
    string email;
    int age;
    int id;
public:
    static int total; /// Instead of name count because it's reserved word in C++
    User();
    User(string name, int age, string email, string password);
    User(const User& user);
    ~User();/// Customize the destructor to decrease total by 1
    bool operator==(const User& user);
    User& operator=(const User& user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword() const;
    void setEmail(string email);
    string getEmail() const;
    void setAge(int age);
    int getAge() const;
    void setId(int id);
    int getId() const;
    friend ostream& operator<<(ostream& output, const User& user);
    friend istream& operator>>(istream& input, User& user);
};



#endif // USER_H_INCLUDED
