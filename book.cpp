#include "book.h"

/// Initialize the static variable to count number of object
int Book::total = 0;

/// Default constructor that set every variable to initial value
Book::Book(){
    total++;
    this->id = total;
    this->title = "";
    this->isbn = "";
    this->category = "";
    this->sumRates = 0;
    this->numRates = 0;
    this->averageRating = 0;
}

/// Parameterized constructor to set the attributes of an object
Book::Book(string title, string isbn, string category){
    total++;
    this->id = total;
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    this->sumRates = 0;
    this->numRates = 0;
    this->averageRating = 0;
}

/// Copy Constructor to copy an object at the time of creation new object
Book::Book(const Book& book){
    this->title = book.title;
    this->id = book.id;
    this->author = book.author;
    this->averageRating = book.averageRating;
    this->isbn = book.isbn;
    this->category = book.category;
    this->sumRates = book.sumRates;
    this->numRates = book.numRates;
}

/// If destructor called with a pointer for example we need to decrease the total number of books by 1 because this book is no longer available
Book::~Book(){
    total--;
}

/// Setters and Getters for the attributes of the object
void Book::setTitle(string title){
    this->title = title;
}

string Book::getTitle() const{
    return this->title;
}

void Book::setISBN(string isbn){
    this->isbn = isbn;
}

string Book::getISBN() const{
    return this->isbn;
}

void Book::setId(int id){
    this->id = id;
}

int Book::getId() const{
    return this->id;
}

void Book::setCategory(string category){
    this->category = category;
}

string Book::getCategory() const{
    return this->category;
}

void Book::setAuthor(User user){
    this->author = user;
}

User Book::getAuthor() const{
    return this->author;
}

double Book::getRating() const{
    return this->averageRating;
}

/// This function to deal with new ratings and recalculate the average rating
void Book::rateBook(int rating){
    this->sumRates += rating; /// Add the new rating to previous rating
    this->numRates++; /// Increase total number of rating by 1
    this->averageRating = (double)this->sumRates/this->numRates; /// Set the new average to averageRating
}

/// Overload the == operator to make it easy to check if two books are equal
bool Book::operator==(const Book& book){
    bool sameTitle = (this->title == book.title);
    bool sameISBN = (this->isbn == book.isbn);
    bool sameCategory = (this->category == book.category);
    bool sameId = (this->id == book.id);
    bool sameAuthor = (this->author == book.author);
    if(sameTitle && sameISBN && sameCategory && sameId && sameAuthor){
        return true;
    }
    return false;
}

/// Boolean function returns true if a book has a valid user or false otherwise
bool Book::hasValidAuthor() const{
    if(this->author.getName() != ""){
        return true;/// If the author name is not empty then it's a valid author so return true
    }
    /// Return false if no author has been entered name of author is empty(default author)
    return false;
}

/// Overload << operator to make it easy for us to display any book to the console
ostream& operator<<(ostream& output, const Book& book){
    output<<endl;
    output<<"====================== Book "<<book.id<<" info ===============================\n";
    output<<"Title: "<<book.title<<"\nISBN: "<<book.isbn<<"\nId: "<<book.id<<"\nCategory: "<<book.category<<"\nAvg Rating: "<<book.averageRating<<endl;
    /// If book has author then print him it as additional information
    if(book.hasValidAuthor()){
        output<<endl;
        output<<"====================== Author info ===============================\n";
        output<<"Name: "<<book.author.getName()<<"\nAge: "<<book.author.getAge()<<"\nId: "<<book.author.getId()<<"\nEmail: "<<book.author.getEmail()<<endl;
        output<<"==================================================================";
        output<<endl;

    }
    output<<"==================================================================";
    output<<endl;
    return output;
}

/// Overload >> operator to make it easy for us to take input for the attributes from the console
istream& operator>>(istream& input, Book& book){
    input>>book.title>>book.isbn>>book.category;
    return input;
}
