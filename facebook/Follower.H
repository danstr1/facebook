#ifndef _FOLLOWER_H_
#define _FOLLOWER_H_
#include "Lists.H"
#include "defs.H"
#include "Message.H"
#include <string>
#define NOT_CONNECTED 0
#define FOLLOWER 1
#define LEADER 2
using std::string;
class Follower {
public:
	Follower(string name, string email, string password);
	~Follower();
	
    string GetName() const;
	string GetEmail() const;
	bool isPassword(string password) const;
	Result ShowFriendRequests();
	Result ShowFriendList();
	Result ShowFriendRequests();
	void Destroy();
	Follower* Copy();

private:
	string name_;
	string email_;
	string password_;
	NodeFollower friendList_;
	NodeFollower friendRequst_;
	MessageBox messageList_;
};


// Aid Functions ?

#endif
