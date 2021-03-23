#include "user.h"

/// Initialize the static variable to count number of object
int User::total = 0;

/// Default constructor that set every variable to initial value
User::User(){
    this->name = "";
    this->password = "";
    this->email = "";
    this->age = 0;
    total++;
    this->id = total;
}

/// Parameterized constructor to set the attributes of an object
User::User(string name, int age, string email, string password){
    this->name = name;
    this->age = age;
    this->email = email;
    this->password = password;
    total++;
    this->id = total;
}

/// Copy Constructor to copy an object at the time of creation new object
User::User(const User& user){
    this->name = user.name;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->id = user.id;
}

/// If destructor called with a pointer for example we need to decrease the total number of users by 1 because this user is no longer available
User::~User(){
    total--;
}

/// Overload == operator to make it easy for us to check if two users are equal
bool User::operator==(const User& user){
    bool sameName = (this->name == user.name);
    bool sameAge = (this->age == user.age);
    bool sameId = (this->id == user.id);
    bool sameEmail = (this->email == user.email);
    /// If both objects have sameAge and sameName and sameEmail and sameId then return true
    if(sameAge && sameName && sameEmail && sameId){
        return true;
    }
    /// Return false otherwise
    return false;
}

/// Overload the copy assignment operator (=) to copy objects after creation if needed
User& User::operator=(const User& user){
    this->name = user.name;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->id = user.id;
    /// Return new updates into the current object
    return *this;

};

/// Setters and Getter for the attributes of the object
void User::setName(string name){
    this->name = name;
}

string User::getName() const{
    return this->name;
}

void User::setPassword(string password){
    this->password = password;
}

string User::getPassword() const{
    return this->password;
}

void User::setEmail(string email){
    this->email = email;
}

string User::getEmail() const{
    return this->email;
}

void User::setAge(int age){
    this->age = age;
}

int User::getAge() const{
    return this->age;
}

void User::setId(int id){
    this->id = id;
}

int User::getId() const{
    return this->id;
}

/// Overload << operator to make it easy for us to display any user to the console
ostream& operator<<(ostream& output, const User& user){
    output<<endl;
    output<<"====================== User "<<user.id<<" info ===============================\n";
    output<<"Name: "<<user.name<<"\nAge: "<<user.age<<"\nId: "<<user.id<<"\nEmail: "<<user.email<<endl;
    output<<"==================================================================";
    output<<endl;
    return output;
}

/// Overload >> operator to make it easy for us to take input for the attributes from the console
istream& operator>>(istream& input,User& user){
    input>>user.name>>user.age>>user.email>>user.password;
    return input;
}

