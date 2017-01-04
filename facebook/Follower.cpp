#include <iostream>
#include "Follower.H"

Follower::Follower(string name, string email, string password) : name_(name), email_(email), password_(password), friendList_(NULL),friendRequst_(NULL),messageList_(NULL) {}

string Follower::GetName() const {
	return name_;
}

string Follower::GetEmail() const {
	return email_;
}

bool Follower::isPassword(string password) const {
	if (password_ != password) {
		cout << LOGIN_FAIL; //might print fail twice
		return false;
	}
	return true;
}

Result Follower::ShowFriendRequests() {
	//SHOW_FRIEND_REQUESTS_SUCCESS i + 1 << ") " << curRequest->name_ << ": " << curRequest->email_;
	Follower *curRequest = friendRequst_.SetIteratorFirst();
	int i = 0;
	while (curRequest != NULL)
	{
		std::cout << SHOW_FRIEND_REQUESTS_SUCCESS;
		friendRequst_.SetIteratorNext();
	}
	return SUCCESS;
}

Result Follower::ShowFriendList() {
	Follower *curFriend = friendList_.SetIteratorFirst();
	int i = 0;
	while (curFriend != NULL)
	{
		std::cout << SHOW_FRIEND_LIST_SUCCESS;
		friendRequst_.SetIteratorNext();
	}
	return SUCCESS;
}
void AcceptFriendRequest(Follower* follweToBeAccept) {

}
void Destroy();
Follower* Copy();
