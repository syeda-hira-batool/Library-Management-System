#ifndef MEMBERRECORD_H
#define MEMBERRECORD_H

#include <string>
#include <vector>
using namespace std;

class MemberRecord {
	private:
	    int id;
	    string name;
	    vector<string> borrowedBooks; 

	public:
	    MemberRecord(int id, string n);
	
	    int getId() const;
	    string getName() const;
	    vector<string> getBorrowedBooks() const;
	
	    void setName(const string& newName);

	    void borrowBook(const string& isbn);
	    void returnBook(const string& isbn);

    	void display() const;
};

#endif
