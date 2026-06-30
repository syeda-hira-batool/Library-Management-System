#include "Book.h"
#include "MemberRecord.h"
#include "Library.h"
#include "Admin.h"
#include "MemberAccount.h"

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
    
    
	User* u1 = new Admin("admin1", "pass123");   //poly
	User* u2 = new MemberAccount("hira", "pass456");
	
	u1->displayMenu(); 
	u2->displayMenu(); 

	delete u1;
	delete u2;
	
	lib.saveToFile("data/books.txt");
	cout << "Saved to file." << endl;
	
	Library lib2;
	lib2.loadFromFile("data/books.txt");
	cout << "Loaded into new Library object:" << endl;
	lib2.displayAllBooks();
	
	
    return 0;
}
