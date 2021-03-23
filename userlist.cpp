#include "userlist.h"

///Default parameter of UserList
UserList::UserList(int capacity){
    ///to make sure capacity is always a positive number
    if(capacity > 0){
        this->capacity = capacity;
        users = new User[capacity];
    }else{
        ///if the capacity is negative so by default make it = 10
        this->capacity = 10;
        users = new User[10];
    }
    usersCount = 0;
}

///function to add a user to the list of users and if the list if full create a new list with double the previous capcaity
void UserList::addUser(User user){
    ///There is still a free space
    if(usersCount < capacity){
        users[usersCount++] = user;

    }else{
        ///here the list is full of user we can handle this with the help of dynamic allocation
        ///create a new array with double the size of the previous one
        User* newUserList = new User[2*capacity];
        for(int i=0;i<usersCount;i++){
            ///copy the content of the previous list
            newUserList[i] = users[i];
        }
        ///add the new user to the new list and increase the usersCount by 1
        newUserList[usersCount++] = user;
        ///now capacity is doubled
        capacity*=2;
        ///delete the previous list
        delete[] users;
        ///Point to our new list
        users = newUserList;
    }
    ///call setIds function to handle users ids
    setIds(*this);
}

///function to search for a user by name
User& UserList::searchUser(string name){
    for(int i=0;i<usersCount;i++){
        if(users[i].getName() == name){
            return users[i];
        }
    }
    ///will never happen duo to the use of hasUser but just to get rid of the warning of non void function
    return users[0];
}

///function to search for a user by id
User& UserList::searchUser(int id){
    for(int i=0;i<usersCount;i++){
        if(users[i].getId() == id){
            return users[i];
        }
    }
    ///will never happen duo to the use of hasUser but just to get rid of the warning of non void function
    return users[0];
}

///function to handle the deletion of a user
void UserList::deleteUser(int id){
    ///get the user index in the list
    int targetIdx = -1;
    for(int i=0;i<usersCount;i++){
        if(users[i].getId() == id){
            ///this index we want to delete
            targetIdx = i;
            break;
        }
    }
    if(targetIdx == -1){
        ///no such book with that given id
        return;
    }else{
        ///valid index to delete
        for(int i=targetIdx;i<usersCount-1;i++){
            ///shift all elements from that index to the end by one
            users[i] = users[i+1];
        }
        ///reduce the count of existing users
        usersCount--;
    }
}

///release the memory
UserList::~UserList(){
    delete[] users;
}


///overload ostream operator
ostream& operator<<(ostream& output, UserList& userList){
    for(int i=0;i<userList.usersCount;i++){
        output<<userList.users[i]<<'\n';
    }
    return output;
}

///function to handle the ids of the users
void setIds(UserList& userList){
    for(int i=0;i<userList.usersCount;i++){
        userList.users[i].setId(i+1);
    }
}

///to ensure that there is a user with a specific id to call the searchUser function safely
bool UserList::hasUser(int id){
    for(int i=0;i<usersCount;i++){
        if(users[i].getId() == id){
            return true;
        }
    }
    return false;
}

///to ensure that there is a user with a specific name to call the searchUser function safely
bool UserList::hasUser(string name){
    for(int i=0;i<usersCount;i++){
        if(users[i].getName() == name){
            return true;
        }
    }
    return false;
}
