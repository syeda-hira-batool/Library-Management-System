#include "Library.h"
#include <iostream>
#include <algorithm>
#include<fstream>
#include<sstream>
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
	
	void Library::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: could not open file for saving." << endl;
        return;
    }
    for (const auto& b : books) {
        outFile << b.getTitle() << "|" << b.getAuthor() << "|"
                << b.getIsbn() << "|" << b.isAvailable() << endl;
    }
    outFile.close();
}

	void Library::loadFromFile(const string& filename) {
	    ifstream inFile(filename);
	    if (!inFile) {
	        cout << "Error: could not open file for loading." << endl;
	        return;
	    }
	
	    books.clear(); 
	
	    string line;
	    while (getline(inFile, line)) {
	        stringstream ss(line);
	        string title, author, isbn, availableStr;
	
	        getline(ss, title, '|');
	        getline(ss, author, '|');
	        getline(ss, isbn, '|');
	        getline(ss, availableStr, '|');
	
	        Book b(title, author, isbn);
	        b.setAvailable(availableStr == "1");
	        books.push_back(b);
	    }
	    inFile.close();
	}
