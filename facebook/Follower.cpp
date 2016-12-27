#include <iostream>
#include "Follower.H"

Follower::Follower(string name, string email, string password) : name_(name), email_(email), password_(password), friendList_(NULL),friendRequst_(NULL),messageList_(NULL) {}

Result Follower::CreateFollower(string name, string email, string password) {
	if (curFollower.checkNoEmailExists(email) == false || curLeader.checkNoEmailExists(email) == false) {
		std::cout << CREATE_FOLLOWER_FAIL;
		return FAILURE;
	}
	Follower* newFollower = new Follower(name, email, password);
	if (currFollower.ListAdd(newFollower)) {
		std::cout << CREATE_FOLLOWER_FAIL;
		return FAILURE;
	}
	return SUCCESS;
}

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
Result Follower::SendFriendRequest(string email) {
	if (/*connectedUser == NULL || connectedUser->*/email_ == email) {
		std::cout << SEND_FRIEND_REQUEST_FAIL;
		return FAILURE;
	}
	Follower *curFriend = curFollower.SetIteratorFirst();
	int i = 0;
	while (curFriend != NULL) //loop for folllowers with the same email
	{
		if (curFriend->email_!= email_ && curFriend->email_ == email) {
			if (curFriend->friendList_.CheckNoEmailExist(email_) == false) {
				std::cout << SEND_FRIEND_REQUEST_FAIL;
				return FAILURE;
			}

			curFriend->friendRequst_.ListAdd(connectedUser);
			std::cout << SEND_FRIEND_REQUEST_SUCCESS;
			return SUCCESS;
		}
		curFriend.SetIteratorNext();
	}
	curFriend = curLeader.SetIteratorFirst(); //loop for leaders with the same email
	while (curFriend != NULL)
	{
		if (curFriend->email_ != connectedUser->email && curFriend->email_ == email) {
			if (curFriend->friendList_.CheckNoEmailExist(connectedUser->email) == false) {
				std::cout << SEND_FRIEND_REQUEST_FAIL;
				return FAILURE;
			}
			curFriend->friendRequst_.ListAdd(connectedUser);
			std::cout << SEND_FRIEND_REQUEST_SUCCESS;
			return SUCCESS;
		}
		curFriend.SetIteratorNext();
	}
	std::cout << SEND_FRIEND_REQUEST_FAIL;
	return FAILURE;
}

Result Follower::AcceptFriendRequest(string email) {
	if (currentUser == NULL)
		return FAILURE;
	connectedUser->friendRequest_
}
Result Follower::RemoveFriend(string email);
Result Follower::ShowFriendRequests();
Result Follower::ReadMessage(int messageNumber);
Result Follower::SendMessage(string email, string subject, string content);
void Destroy();
Follower* Copy();
