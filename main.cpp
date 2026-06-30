#include "Book.h"
#include <iostream>
#include<string>
using namespace std;


	Book::Book(string t, string a, string i)
	    : title(t), author(a), isbn(i), available(true) {
		}

	string Book::getTitle() const {
	    return title;
	}
	
	string Book::getAuthor() const {
	    return author;
	}

	string Book::getIsbn() const {
	    return isbn;
	}
	
	bool Book::isAvailable() const {
	    return available;
	}

	void Book::setTitle(const string& newTitle) {
	    title = newTitle;
	}
	
	void Book::setAuthor(const string& newAuthor) {
	    author = newAuthor;
	}

	void Book::setAvailable(bool status) {
	    available = status;
	}

	void Book::display() const {
    	cout << "Title: " << title
              	<< " | Author: " << author
              	<< " | ISBN: " << isbn
              	<< " | Available: " << (available ? "Yes" : "No")
              	<< std::endl;
	}
