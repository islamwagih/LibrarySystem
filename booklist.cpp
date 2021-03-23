#include "booklist.h"

///Copy constructor of bookList
BookList::BookList(const BookList& anotherList){
    capacity = anotherList.capacity;
    booksCount = anotherList.booksCount;
    ///deep copy of the array
    books = new Book[capacity];
    for(int i=0;i<anotherList.booksCount;i++){
        books[i] = anotherList.books[i];
    }
}

///Default parameter of BookList
BookList::BookList(int capacity){
    ///to make sure capacity is always a positive number
    if(capacity > 0){
        this->capacity = capacity;
        books = new Book[capacity];
    }else{
        ///if the capacity is negative so by default make it = 10
        this->capacity = 10;
        books = new Book[10];
    }
    booksCount = 0;
}

///function to search for a book by name
Book& BookList::searchBook(string name){
    for(int i=0;i<booksCount;i++){
        if(books[i].getTitle() == name){
            return books[i];
        }
    }
    ///will never happen duo to the use of hasBook but just to get rid of the warning of non void function
    return books[0];
}

///function to search for a book by name
Book& BookList::searchBook(int id){
    for(int i=0;i<booksCount;i++){
        if(books[i].getId() == id){
            return books[i];
        }
    }
    ///will never happen duo to the use of hasBook but just to get rid of the warning of non void function
    return books[0];
}

///function to handle the deletion of a book
void BookList::deleteBook(int id){
    ///get the book index in the list
    int targetIdx = -1;
    for(int i=0;i<booksCount;i++){
        if(books[i].getId() == id){
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
        for(int i=targetIdx;i<booksCount-1;i++){
            ///shift all elements from that index to the end by one
            books[i] = books[i+1];
        }
        ///reduce the count of existing books
        booksCount--;
    }
}

///function to get the hight rated book
Book BookList::getTheHighestRatedBook(){
    int targetIdx = 0;
    for(int i=0;i<booksCount;i++){
        if(books[i].getRating() > books[targetIdx].getRating()){
            targetIdx = i;
        }
    }
    return books[targetIdx];
}

///function to get the books of a user
Book* BookList::getBooksForUser(User user){
    int numBooks = userBooks(user);
    Book* arr = new Book[numBooks];
    int innerIdx = 0;
    for(int i=0;i<booksCount;i++){
        if(books[i].getAuthor() == user){
            arr[innerIdx++] = books[i];
        }
    }
    return arr;

}

///overload the operator[]
Book& BookList::operator[](int position){
    ///make sure that is a valid index to use
    if(position >= 0 && position < booksCount){
        return books[position];
    }
}

///overload the ostream operator
ostream& operator<<(ostream& output, BookList& bookList){
    for(int i=0;i<bookList.booksCount;i++){
        output<<bookList.books[i]<<'\n';
    }
    return output;
}

///release the memory allocated
BookList::~BookList(){
    delete[] books;
}

///function to add a book to the list of books and if the list if full create a new list with double the previous capacity
void BookList::addBook(Book book){
    ///There is still a free space
    if(booksCount < capacity){
        books[booksCount++] = book;

    }else{
        ///here the list is full of books we can handle this with the help of dynamic allocation
        ///create a new array with double the size of the previous one
        Book* newBookList = new Book[2*capacity];
        for(int i=0;i<booksCount;i++){
            ///copy the content of the previous list
            newBookList[i] = books[i];
        }
        ///add the new user to the new list and increase the usersCount by 1
        newBookList[booksCount++] = book;
        ///now capacity is doubled
        capacity*=2;
        ///delete the previous list
        delete[] books;
        ///Point to our new list
        books = newBookList;
    }
    ///call setIds function to handle books ids
    setIds(*this);
}

///function to handle the ids of the books
void setIds(BookList& bookList){
    for(int i=0;i<bookList.booksCount;i++){
        bookList.books[i].setId(i+1);
    }
}

///to ensure that there is a book with a specific id to call the searchBook function safely
bool BookList::hasBook(int id){
    for(int i=0;i<booksCount;i++){
        if(books[i].getId() == id){
            return true;
        }
    }
    return false;
}

///to ensure that there is a book with a specific name to call the searchBook function safely
bool BookList::hasBook(string name){
    for(int i=0;i<booksCount;i++){
        if(books[i].getTitle() == name){
            return true;
        }
    }
    return false;
}

///function to return the number of books for a given user
int BookList::userBooks(User user){
    int numBooks = 0;
    for(int i=0;i<booksCount;i++){
        if(books[i].getAuthor() == user){
            numBooks++;
        }
    }
    return numBooks;
}

///function to return all available books
int BookList::allBooks(){
    return booksCount;
}

///overload the operator =
BookList BookList::operator=(BookList& book){
    capacity = book.capacity;
    booksCount = book.booksCount;
    ///deep copy of the array
    books = new Book[capacity];
    for(int i=0;i<book.booksCount;i++){
        books[i] = book.books[i];
    }
}





