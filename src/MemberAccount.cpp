#include "MemberAccount.h"
#include <iostream>
using namespace std;

	MemberAccount::MemberAccount(string username, string password) : User(username, password) {}
	
	void MemberAccount::displayMenu() const {
	    cout << "--- Member Menu ---" << endl;
	    cout << "1. Search Book" << endl;
	    cout << "2. Borrow Book" << endl;
	    cout << "3. Return Book" << endl;
	}
