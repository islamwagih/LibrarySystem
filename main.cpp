#include <iostream>
#include "user.h"
#include "book.h"
#include "userlist.h"
#include "booklist.h"
using namespace std;

void displayMainMenuChoices(){
    cout<<"Select one of the following choices:\n";
    cout<<"1- Books Menu\n";
    cout<<"2- Users Menu\n";
    cout<<"3- Exit\n";
    cout<<">>";
}

void displayUserMenu(){
    cout<<"USERS MENU\n";
    cout<<"1- Create a USER and add it to the list\n";
    cout<<"2- Search for a user\n";
    cout<<"3- Display all users\n";
    cout<<"4- Back to main menu\n";
}

void displaySearchForUser(){
    cout<<"SEARCH FOR A USER\n";
    cout<<"1- Search by name\n";
    cout<<"2- Search by id\n";
    cout<<"3- Return to Users Menu\n";
    cout<<">>";
}

void displayUserInfo(){
    cout<<"Enter the user information in this order\n";
    cout<<"Name Age Email Password (space separated)\n>>";
}

void displayBookMenu(){
    cout<<"BOOKS MENU\n";
    cout<<"1- Create a book and add it to the list\n";
    cout<<"2- Search for a book\n";
    cout<<"3- Display all books (with book rating)\n";
    cout<<"4- Get the highest rating book\n";
    cout<<"5- Get all books of a user\n";
    cout<<"6- copy the current Book List to a new Book List and switch to it\n";
    cout<<"7- Back to the main menu\n>>";
}

void displayBookInfo(){
    cout<<"Enter the book information in this order\n";
    cout<<"Title  ISBN   Category(space separated)\n>>";
}

void displaySearchForBook(){
    cout<<"SEARCH FOR A BOOK\n";
    cout<<"1- Search by name\n";
    cout<<"2- Search by id\n";
    cout<<"3- Return to Books Menu\n";
    cout<<">>";
}

void displayUpdationOfBook(){
    cout<<"1- Update author\n";
    cout<<"2- Update name\n";
    cout<<"3- Update Category\n";
    cout<<"4- Delete Book\n";
    cout<<"5- Rate book\n";
    cout<<"6- Get back to books menu\n>>";
}

int main()
{
    BookList* bookList = nullptr;///initialize bookList
    UserList* userList = nullptr;///initialize userList
    bool firstTimeToCreateBook = 1;
    bool firstTimeToCreateUser = 1;
    ///Main Menu
    while(true){
        displayMainMenuChoices();
        int choice;cin>>choice;
        if(choice == 3){
            ///Exit and release the memory
            if(bookList!=nullptr){
                ///if userList point to something except nullptr then release it
                delete bookList;
            }
            if(userList!=nullptr){
                ///if userList point to something except nullptr then release it
                delete userList;
            }
            break;
        }else if(choice == 2){
            ///User Menu
            if(firstTimeToCreateUser){
                cout<<"How many users will be added?\n>>";
                int n;cin>>n;
                userList = new UserList(n);
                firstTimeToCreateUser = 0;
            }
            while(true){
                displayUserMenu();
                cout<<">>";
                int userChoice;cin>>userChoice;
                if(userChoice == 4){
                    ///back to main menu
                    break;
                }
                else if(userChoice == 3){
                    ///display all users
                    cout<<*userList<<endl;
                }
                else if(userChoice == 2){
                    while(true){
                            displaySearchForUser();
                            int searchChoice;cin>>searchChoice;
                            if(searchChoice == 3){
                                ///return to users menu
                                break;
                            }else if(searchChoice == 1){
                                ///search by name
                                cout<<"Enter a Name\n>>";
                                string name;cin>>name;
                                if(userList->hasUser(name)){
                                   cout<<userList->searchUser(name)<<endl;
                                   ///option to delete or return to users menu
                                   cout<<"1- Delete user\n";
                                   cout<<"2- Return to Users Menu\n>>";
                                   int innerChoice;cin>>innerChoice;
                                   if(innerChoice == 1){
                                        ///delete that user
                                        userList->deleteUser(userList->searchUser(name).getId());
                                   }else{
                                       ///return to Users menu
                                       break;
                                   }

                                }else{
                                    cout<<"There is no user with the name: "<<name<<endl;
                                }
                            }else{
                                ///search by id
                                cout<<"Enter an Id\n>>";
                                int id;cin>>id;
                                if(userList->hasUser(id)){
                                    cout<<userList->searchUser(id)<<endl;
                                }else{
                                    cout<<"There is no user with the id: "<<id<<endl;
                                }
                            }
                    }
                }
                else{
                    ///Create a USER and add it to the list
                    displayUserInfo();
                    User u;cin>>u;
                    userList->addUser(u);
                }

            }
        }else{
            ///Book menu
            if(firstTimeToCreateBook){
                cout<<"How many books will be added?\n>>";
                int n;cin>>n;
                bookList = new BookList(n);
                firstTimeToCreateBook = 0;
            }
            while(true){
                displayBookMenu();
                int bookChoice;cin>>bookChoice;
                if(bookChoice == 1){
                        ///create a book and add it to the list
                        displayBookInfo();
                        Book b;cin>>b;
                        while(true){
                            cout<<"1- Assign author\n";
                            cout<<"2- continue\n>>";
                            int inChoice;cin>>inChoice;
                            if(inChoice == 1){
                                ///assign author
                                cout<<"Enter author (user) id:\n>>";
                                int currId;cin>>currId;
                                if(userList->hasUser(currId)){
                                    b.setAuthor(userList->searchUser(currId));
                                    break;
                                }else{
                                    cout<<"No Author Found with id: "<<currId<<'\n';
                                }
                            }else{
                                ///break
                                break;
                            }
                        }
                        bookList->addBook(b);
                }else if(bookChoice == 2){
                    ///search for a given book
                    while(true){
                        displaySearchForBook();
                        int bookSearchChoice;cin>>bookSearchChoice;
                        if(bookSearchChoice == 1){
                            ///search by name
                            cout<<"Enter Name:\n>>";
                            string name;cin>>name;
                            if(bookList->hasBook(name)){
                                ///book exist
                                cout<<bookList->searchBook(name)<<endl;
                                bool goToBooksMenu = false;
                                while(true){
                                    displayUpdationOfBook();
                                    int updateChoice;cin>>updateChoice;
                                    if(updateChoice == 1){
                                        ///Update author
                                        cout<<"Enter author id\n>>";
                                        int id;cin>>id;
                                        if(userList->hasUser(id)){
                                            bookList->searchBook(name).setAuthor(userList->searchUser(id));
                                        }else{
                                            cout<<"\nNo USER with that given id\n";
                                        }
                                    }else if(updateChoice == 2){
                                        ///Update name
                                        cout<<"Enter new Name:\n>>";
                                        string bookName;cin>>bookName;
                                        bookList->searchBook(name).setTitle(bookName);
                                    }else if(updateChoice == 3){
                                        ///Update category
                                        cout<<"Enter new Category:\n>>";
                                        string cat;cin>>cat;
                                        bookList->searchBook(name).setCategory(cat);
                                    }else if(updateChoice == 4){
                                        ///Delete book
                                        int id = bookList->searchBook(name).getId();
                                        bookList->deleteBook(id);
                                        cout<<"\nBOOK HAS BEEN DELETED\n\n";
                                        break;
                                    }else if(updateChoice == 5){
                                        ///rate book
                                        cout<<"Enter Rating Value:\n>>";
                                        int rating;cin>>rating;
                                        bookList->searchBook(name).rateBook(rating);
                                    }else{
                                        ///get back to books menu
                                        goToBooksMenu = true;
                                        break;
                                    }
                                }
                                if(goToBooksMenu){
                                    break;
                                }

                            }else{
                                ///book not found
                                cout<<"\nNo Book has been found with that NAME\n\n";
                            }
                        }else if(bookSearchChoice == 2){
                            ///search by id
                            cout<<"Enter book id\n>>";
                            int bookId;cin>>bookId;
                            if(bookList->hasBook(bookId)){
                                ///book exist
                                cout<<bookList->searchBook(bookId)<<endl;
                                bool goToBooksMenu = false;
                                while(true){
                                    displayUpdationOfBook();
                                    int updateChoice;cin>>updateChoice;
                                    if(updateChoice == 1){
                                        ///Update author
                                        cout<<"Enter author id\n>>";
                                        int id;cin>>id;
                                        if(userList->hasUser(id)){
                                            bookList->searchBook(bookId).setAuthor(userList->searchUser(id));
                                        }else{
                                            cout<<"\nNo USER with that given id\n";
                                        }
                                    }else if(updateChoice == 2){
                                        ///Update name
                                        cout<<"Enter new Name:\n>>";
                                        string bookName;cin>>bookName;
                                        bookList->searchBook(bookId).setTitle(bookName);
                                    }else if(updateChoice == 3){
                                        ///Update category
                                        cout<<"Enter new Category:\n>>";
                                        string cat;cin>>cat;
                                        bookList->searchBook(bookId).setCategory(cat);
                                    }else if(updateChoice == 4){
                                        ///Delete book
                                        bookList->deleteBook(bookId);
                                        cout<<"\nBOOK HAS BEEN DELETED\n\n";
                                        break;
                                    }else if(updateChoice == 5){
                                        ///rate book
                                        cout<<"Enter Rating Value:\n>>";
                                        int rating;cin>>rating;
                                        bookList->searchBook(bookId).rateBook(rating);
                                    }else{
                                        ///get back to books menu
                                        goToBooksMenu = true;
                                        break;
                                    }
                                }
                                if(goToBooksMenu){
                                    break;
                                }

                            }else{
                                ///book not found
                                cout<<"\nNo Book has been found with that ID\n\n";
                            }
                        }else{
                            ///return to Books Menu
                            break;
                        }

                    }
                }else if(bookChoice == 3){
                    ///display all books
                    cout<<*bookList<<endl;
                }else if(bookChoice == 4){
                    ///get the highest rating book
                    cout<<bookList->getTheHighestRatedBook()<<endl;
                }else if(bookChoice == 5){
                    ///get all books of a user
                    cout<<"Enter User ID\n>>";
                    int userId;cin>>userId;
                    if(userList->hasUser(userId)){
                        ///user exist
                        User u = userList->searchUser(userId);
                        int numBooks = bookList->userBooks(u);
                        Book* arr = bookList->getBooksForUser(u);
                        for(int i=0;i<numBooks;i++){
                            cout<<arr[i]<<endl;
                        }
                    }else{
                        ///user not found
                        cout<<"\nNo such user with the given ID\n\n";
                    }
                }else if(bookChoice == 6){
                    ///copy the current book list to a new book list and switch to it
                    BookList* newBookList = new BookList(*bookList);
                    ///switch to it
                    bookList = newBookList;
                    cout<<"Copied current list ("<<bookList->allBooks()<<" books) to a new List and switched to it\n";
                }else{
                    ///back to main menu
                    break;
                }
            }
        }
    }

    return 0;
}
