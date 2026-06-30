#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "MemberRecord.h"
using namespace std;

class Library {
	private:
	    vector<Book> books;
	    vector<MemberRecord> members;
	
	public:
	    Library();
	
	    void addBook(const Book& book);
	    void removeBook(const string& isbn);
	    Book* searchBook(const string& isbn);
	
	    void addMember(const MemberRecord& member);
	    MemberRecord* searchMember(int id);
	
	    void displayAllBooks() const;
	    void displayAllMembers() const;
	    
	    bool issueBook(const string& isbn, int memberId);
		bool returnBookByMember(const string& isbn, int memberId);
		void saveToFile(const string& filename) const;
		void loadFromFile(const string& filename);
};

#endif
