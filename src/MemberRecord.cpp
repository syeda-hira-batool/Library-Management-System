#include "MemberRecord.h"
#include <iostream>
#include <algorithm> //built in fucntions to make code easier
using namespace std;

	MemberRecord::MemberRecord(int id, string n) : id(id), name(n) {}

	int MemberRecord::getId() const {
	    return id;
	}

	string MemberRecord::getName() const {
	    return name;
	}

	vector<string> MemberRecord::getBorrowedBooks() const {
	    return borrowedBooks;
	}

	void MemberRecord::setName(const string& newName) {
	    name = newName;
	}

	void MemberRecord::borrowBook(const string& isbn) {
	    borrowedBooks.push_back(isbn);
	}

	void MemberRecord::returnBook(const string& isbn) {
	    auto it = find(borrowedBooks.begin(), borrowedBooks.end(), isbn);
	    if (it != borrowedBooks.end()) {
	        borrowedBooks.erase(it);
	    }
	}

	void MemberRecord::display() const {
	    cout << "ID: " << id << " | Name: " << name
	         << " | Borrowed Books: " << borrowedBooks.size() << endl;
	}
