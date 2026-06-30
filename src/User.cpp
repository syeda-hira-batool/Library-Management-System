#include "User.h"

	User::User(string username, string password)
	    : username(username), password(password) {}
	
	User::~User() {}
	
	string User::getUsername() const {
	    return username;
	}
