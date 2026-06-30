#include "Admin.h"
#include <iostream>
using namespace std;

	Admin::Admin(string username, string password) : User(username, password) {}
	
	void Admin::displayMenu() const {
	    cout << "--- Admin Menu ---" << endl;
	    cout << "1. Add Book" << endl;
	    cout << "2. Remove Book" << endl;
	    cout << "3. View All Members" << endl;
	}
