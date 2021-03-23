#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED

#include "user.h"

class UserList{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    UserList(int capacity);
    void addUser(User user);
    User& searchUser(string name);
    User& searchUser(int id);
    void deleteUser(int id);
    friend ostream& operator<<(ostream& output, UserList& userList);
    ~UserList();
    friend void setIds(UserList& userList);///to handle ids of the users
    bool hasUser(int id);///to ensure that there is a user with a given id
    bool hasUser(string name);///to ensure that there is a user with a given name
};

#endif // USERLIST_H_INCLUDED
