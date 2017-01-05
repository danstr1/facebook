#include <iostream>
#include "Follower.H"

Follower::Follower(string name, string email, string password) : name_(name), email_(email), password_(password), friendList_(), friendRequst_(), messageList_(), isLeader_(false) {}
//Follower::~Follower() {
	//need to deal with friendList_,friendRequst_,messageList_
	/*Follower* curFollower = friendList_.SetIteratorFirst();
	while (curFollower != NULL) {
		delete curFollower;
		curFollower = friendList_.SetIteratorNext();
	}
	curFollower = friendRequst_.SetIteratorFirst();
	while (curFollower != NULL) {
		delete curFollower;
		curFollower = friendRequst_.SetIteratorNext();
	}
	*/
//}

int Follower::NumUnreadMessages() const {
	return messageList_.UnreadSize();
}

int Follower::NumFriendRequests() const {
	return friendRequst_.ListSize();
}

string Follower::GetPassword() const {
	return password_;
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
	for (int i=0; curRequest!= NULL ; i++)
	{
		std::cout << SHOW_FRIEND_REQUESTS_SUCCESS;
		curRequest=friendRequst_.SetIteratorNext();
	}
	return SUCCESS;
}

Result Follower::ShowFriendList() {
	Follower *curFriend = friendList_.SetIteratorFirst();
	for (int i = 0; curFriend != NULL; i++)
	{
		std::cout << SHOW_FRIEND_LIST_SUCCESS;
		curFriend = friendList_.SetIteratorNext();
	}
	return SUCCESS;
}

Result Follower::RemoveFriendRequest(Follower* toBeRemoved)
{
	Follower* curFollower = friendRequst_.SetIteratorFirst();
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->email_ == toBeRemoved->email_) {
			this->friendRequst_.ListRemove();
			return SUCCESS;
		}
		curFollower = friendRequst_.SetIteratorNext();
	}
	return FAILURE;
}
Result Follower::RemoveFriend(Follower* toBeRemoved)
{
	Follower* curFollower = friendList_.SetIteratorFirst();
	// Loop over all friendlist in of the follower
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->email_ == toBeRemoved->email_) {
			friendList_.ListRemove();
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
string Follower::getPassword()
{
	return password_;
}

void Follower::MessegeListHelper()
{
	messageList_.Print();
}
void Follower::ReadMessegeListHelper(int num)
{
	int countMessegesFollower = messageList_.Size();
	if (num > countMessegesFollower || num <= 0) {
		cout << READ_MESSAGE_FAIL;
		return;
	}
	messageList_.ReadMessage(num);
	
}
void Follower::HelperSendMessage(string email, string subject, string content)
{
	Message* newMessage = new Message(email, subject, content);
	messageList_.Add(newMessage);

}

void Follower::setLeader(bool isLeader)
{
	if (isLeader == true)
		isLeader_ = true;
	else
		isLeader_ = false;
}
bool Follower::isLeader()
{
	return isLeader_;
}


