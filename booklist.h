#ifndef BOOKLIST_H_INCLUDED
#define BOOKLIST_H_INCLUDED

#include "book.h"

class BookList{
private:
    Book* books;
    int capacity;
    int booksCount;
public:
    BookList(const BookList& anotherList);
    BookList(int capacity);
    Book& searchBook(string name);
    Book& searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    Book* getBooksForUser(User);
    Book& operator[](int position);
    friend ostream& operator<<(ostream& output, BookList& bookList);
    ~BookList();
    void addBook(Book book); ///function to add a new book and don't care about the position
    friend void setIds(BookList& bookList);///to handle ids of the users
    bool hasBook(int id);///to ensure that there is a user with a given id
    bool hasBook(string name);///to ensure that there is a user with a given name(title)
    int userBooks(User);///return number of books for a given user
    int allBooks();///return number of all available books
    BookList operator=(BookList& book);///overload the = operator
};

#endif // BOOKLIST_H_INCLUDED
