#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
	protected:
	    string username;
	    string password;
	
	public:
	    User(string username, string password);
	    virtual ~User(); 
	
	    string getUsername() const;
	
	    virtual void displayMenu() const = 0; 
};

#endif
