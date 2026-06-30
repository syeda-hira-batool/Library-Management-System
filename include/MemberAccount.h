#ifndef MEMBERACCOUNT_H
#define MEMBERACCOUNT_H

#include "User.h"

class MemberAccount : public User {
		public:
		    MemberAccount(string username, string password);
		
		    void displayMenu() const override;
};

#endif
