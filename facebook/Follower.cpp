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
	for (int i=0; curRequest!= NULL ; i++)
	{
		std::cout << SHOW_FRIEND_REQUESTS_SUCCESS;
		curRequest=friendRequst_.SetIteratorNext();
	}
	return SUCCESS;
}

Result Follower::ShowFriendList() {
	Follower *curFriend = friendRequst_.SetIteratorFirst();
	for (int i = 0; curFriend != NULL; i++)
	{
		std::cout << SHOW_FRIEND_LIST_SUCCESS;
		curFriend = friendRequst_.SetIteratorNext();
	}
	return SUCCESS;
}

Result Follower::RemoveFriendRequest(Follower* toBeRemoved)
{
	Follower* curFollower = friendRequst_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->email_ == toBeRemoved->email_) {
			curFollower->friendRequst_.ListRemove();
			return SUCCESS;
		}
		curFollower = friendRequst_.SetIteratorNext();
	}
	return FAILURE;
}
Result Follower::RemoveFriend(Follower* toBeRemoved)
{
	Follower* curFollower = friendList_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->email_ == toBeRemoved->email_) {
			curFollower->friendList_.ListRemove();
			return SUCCESS;
		}
		curFollower = friendList_.SetIteratorNext();
	}
	return FAILURE;
}
Result Follower::AddUserToFriendList(Follower* toBeInserted) {

	if (friendList_.ListAdd(toBeInserted) == FAILURE)
		return FAILURE;
	return SUCCESS;

}
Result Follower::AddUserToFriendRequest(Follower* toBeInserted) {
	if (friendRequst_.ListAdd(toBeInserted) == FAILURE)
		return FAILURE;
	return SUCCESS;
}
Result Follower::CheckIfFriend(Follower* toBeChecked) {
	Follower* curFollower = friendList_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->email_ == toBeChecked->email_)
			return SUCCESS;
		curFollower = friendList_.SetIteratorNext();
	}
	return FAILURE;

}
Result Follower::CheckIfFriendRequest(Follower* toBeChecked) {
	Follower* curFollower = friendRequst_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->email_ == toBeChecked->email_)
			return SUCCESS;
		curFollower = friendRequst_.SetIteratorNext();
	}
	return FAILURE;

}

void Destroy();
Follower* Copy();
