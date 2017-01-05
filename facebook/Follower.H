#ifndef _FOLLOWER_H_
#define _FOLLOWER_H_
#include "Lists.H"
#include "Message.H"
#include <string>

using std::string;
class Follower {
public:
	Follower(string name, string email, string password);
	~Follower();
	
	int NumUnreadMessages() const;
	int NumFriendRequests() const;
	string GetPassword() const;
    string GetName() const;
	string GetEmail() const;
	bool isPassword(string password) const;
	Result ShowFriendRequests();
	Result ShowFriendList();
	Result RemoveFriendRequest(Follower* toBeRemoved);
	Result RemoveFriend(Follower* toBeRemoved);
	Result AddUserToFriendList(Follower* toBeInserted);
	Result AddUserToFriendRequest(Follower* toBeInserted);
	Result CheckIfFriend(Follower* toBeChecked);
	Result CheckIfFriendRequest(Follower* toBeChecked);
	void MessegeListHelper();
	void ReadMessegeListHelper(int num);
	void HelperSendMessage(string email, string subject, string content);
	void setLeader(bool isLeader);
	bool isLeader();
	string getPassword();

private:
	string name_;
	string email_;
	string password_;
	NodeFollower friendList_;
	NodeFollower friendRequst_;
	MessageBox messageList_;
	bool isLeader_;
};


// Aid Functions ?

#endif
