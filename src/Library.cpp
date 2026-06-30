#include "Library.h"
#include <iostream>
#include <algorithm>
using namespace std;

Library::Library() {}

	void Library::addBook(const Book& book) {
	    books.push_back(book);
	}
	
	void Library::removeBook(const string& isbn) {
	    auto it = find_if(books.begin(), books.end(),
	        [&](const Book& b) { return b.getIsbn() == isbn; });
	    if (it != books.end()) {
	        books.erase(it);
	    }
	}
	
	Book* Library::searchBook(const string& isbn) {
	    for (auto& b : books) {
	        if (b.getIsbn() == isbn) {
	            return &b;
	        }
	    }
	    return nullptr;
	}
	
	void Library::addMember(const MemberRecord& member) {
	    members.push_back(member);
	}
	
	MemberRecord* Library::searchMember(int id) {
	    for (auto& m : members) {
	        if (m.getId() == id) {
	            return &m;
	        }
	    }
	    return nullptr;
	}
	
	void Library::displayAllBooks() const {
	    for (const auto& b : books) {
	        b.display();
	    }
	}
	
	void Library::displayAllMembers() const {
	    for (const auto& m : members) {
	        m.display();
	    }
	}
	
	bool Library::issueBook(const string& isbn, int memberId) {
    Book* book = searchBook(isbn);
    MemberRecord* member = searchMember(memberId);

    if (book == nullptr || member == nullptr) {
        return false;
    }
    if (!book->isAvailable()) {
        return false;
    }

    book->setAvailable(false);
    member->borrowBook(isbn);
    return true;
}

	bool Library::returnBookByMember(const string& isbn, int memberId) {
	    Book* book = searchBook(isbn);
	    MemberRecord* member = searchMember(memberId);
	
	    if (book == nullptr || member == nullptr) {
	        return false;
	    }
	
	    book->setAvailable(true);
	    member->returnBook(isbn);
	    return true;
	}
