#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <cstring>
#include "user.h"

using namespace std;

class Book{
private:
    string title;
    string isbn;
    string category;
    int id;
    double averageRating;
    User author;
    int sumRates;/// Contains the summation of all coming rates to be used in rateBook function
    int numRates;/// Contains the total number of all coming rates to be used in rateBook function
public:
    static int total;/// Instead of count because count is reserved word in C++
    Book();
    Book(string title, string isbn, string category);
    Book(const Book& book);
    ~Book();/// Customize the destructor to decrease total by 1
    void setTitle(string title);
    string getTitle() const;
    void setISBN(string isbn);
    string getISBN() const;
    void setId(int id);
    int getId() const;
    void setCategory(string category);
    string getCategory() const;
    void setAuthor(User user);
    User getAuthor() const;
    void rateBook(int rating);
    double getRating()const;
    bool hasValidAuthor() const;/// Boolean function to ensure that the book has an author
    bool operator==(const Book& book);
    friend ostream& operator<<(ostream& output, const Book& book);
    friend istream& operator>>(istream& input, Book& book);
};


#endif // BOOK_H_INCLUDED
