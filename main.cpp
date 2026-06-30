#include "Book.h"
#include "MemberRecord.h"
#include "Library.h"
#include <iostream>
using namespace std;

int main() {
    
    Book b1("The Hobbit", "J.R.R. Tolkien", "12345");
    b1.display();

    b1.setAvailable(false);
    b1.display();

    
    MemberRecord m1(1, "Hira");
    m1.borrowBook("12345");
    m1.display();

   
    Library lib;
    lib.addBook(Book("The Hobbit", "J.R.R. Tolkien", "12345"));
    lib.addMember(MemberRecord(1, "Hira"));

    cout << "Initial state:" << endl;
    lib.displayAllBooks();
    lib.displayAllMembers();

    
    lib.issueBook("12345", 1);
    cout << "After issuing:" << endl;
    lib.displayAllBooks();
    lib.displayAllMembers();

    lib.returnBookByMember("12345", 1);
    cout << "After returning:" << endl;
    lib.displayAllBooks();
    lib.displayAllMembers();

    return 0;
}
