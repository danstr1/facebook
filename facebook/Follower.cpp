#include <iostream>
#include "Follower.H"

Follower::Follower(string name, string email, string password) : name_(name), email_(email), password_(password), friendList_(), friendRequst_(), messageList_(), isLeader_(false) {}

//************************************************************************
//*  Function name: NumUnreadMessages
//*  Description: Returns the number of unread messages of the current follower.
//*  Paramters: None.
//*  Return value: number of unread messages.
//************************************************************************
int Follower::NumUnreadMessages() const {
	return messageList_.UnreadSize();
}

//************************************************************************
//*  Function name: NumFriendRequests
//*  Description: Returns the number of friend requests of the current follower.
//*  Paramters: None.
//*  Return value: number of friend requests.
//************************************************************************
int Follower::NumFriendRequests() const {
	return friendRequst_.ListSize();
}

//************************************************************************
//*  Function name: GetPassword
//*  Description: Returns the password of the current follower.
//*  Paramters: None.
//*  Return value: password of the follower.
//************************************************************************
string Follower::GetPassword() const {
	return password_;
}

//************************************************************************
//*  Function name: GetName
//*  Description: Returns the name of the current follower.
//*  Paramters: None.
//*  Return value: name of the follower.
//************************************************************************
string Follower::GetName() const {
	return name_;
}

//************************************************************************
//*  Function name: GetEmail
//*  Description: Returns the email of the current follower.
//*  Paramters: None.
//*  Return value: email of the follower.
//************************************************************************
string Follower::GetEmail() const {
	return email_;
}

//************************************************************************
//*  Function name: isPassword
//*  Description: Checks if the password if correct.
//*  Paramters: password- password to compare
//*  Return value: true if correct, false otherwise.
//************************************************************************
bool Follower::isPassword(string password) const {
	if (password_ != password) {
		cout << LOGIN_FAIL; //might print fail twice
		return false;
	}
	return true;
}

//************************************************************************
//*  Function name: ShowFriendRequests
//*  Description: shows the friend requests of the follower/leader
//*  Paramters: None.
//*  Return value: SUCCESS if worked FAILURE otherwise
//************************************************************************
Result Follower::ShowFriendRequests() {
	//SHOW_FRIEND_REQUESTS_SUCCESS i + 1 << ") " << curRequest->name_ << ": " << curRequest->email_;
	Follower *curRequest = friendRequst_.SetIteratorFirst();
	for (int i = 0; curRequest != NULL; i++)
	{
		std::cout << SHOW_FRIEND_REQUESTS_SUCCESS;
		curRequest = friendRequst_.SetIteratorNext();
	}
	return SUCCESS;
}

//************************************************************************
//*  Function name: ShowFriendList
//*  Description: shows the friend list of the user
//*  Paramters: None.
//*  Return value: SUCCESS if worked FAILURE otherwise
//************************************************************************
Result Follower::ShowFriendList() {
	Follower *curFriend = friendList_.SetIteratorFirst();
	for (int i = 0; curFriend != NULL; i++)
	{
		std::cout << SHOW_FRIEND_LIST_SUCCESS;
		curFriend = friendList_.SetIteratorNext();
	}
	return SUCCESS;
}

//************************************************************************
//*  Function name: RemoveFriendRequest
//*  Description: removes the friend request
//*  Paramters: toBeRemoved- the follower to be removed
//*  Return value: SUCCESS if worked FAILURE otherwise
//************************************************************************
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

//************************************************************************
//*  Function name: RemoveFriend
//*  Description: removes the friend from both friend lists
//*  Paramters: pointer to the friend to be removed.
//*  Return value: SUCCESS if worked FAILURE otherwise
//************************************************************************
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

//************************************************************************
//*  Function name: AddUserToFriendList
//*  Description: Adds the user to the friend list
//*  Paramters: toBeInsertedpointer to the follower we want to check.
//*  Return value: SUCCESS if already added FAILURE otherwise
//************************************************************************
Result Follower::AddUserToFriendList(Follower* toBeInserted) {

	if (friendList_.ListAdd(toBeInserted) == FAILURE)
		return FAILURE;
	return SUCCESS;
}

//************************************************************************
//*  Function name: AddUserToFriendRequest
//*  Description: Adds the user to the friend request list
//*  Paramters: toBeInsertedpointer to the follower we want to check.
//*  Return value: SUCCESS if already added FAILURE otherwise
//************************************************************************
Result Follower::AddUserToFriendRequest(Follower* toBeInserted) {
	if (friendRequst_.ListAdd(toBeInserted) == FAILURE)
		return FAILURE;
	return SUCCESS;
}

//************************************************************************
//*  Function name: CheckIfFriend
//*  Description: Checks if already friends 
//*  Paramters: toBeChecked- pointer to the follower we want to check
//*  Return value: SUCCESS if already added FAILURE otherwise
//************************************************************************
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

//************************************************************************
//*  Function name: CheckIfFriendRequest
//*  Description: Checks if the friend request was already sent.
//*  Paramters: toBeChecked- pointer to the follower we want to check
//*  Return value: SUCCESS if already added FAILURE otherwise
//************************************************************************
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

//************************************************************************
//*  Function name: getPassword
//*  Description: gets the pass of the followers.
//*  Paramters: None.
//*  Return value: password_-the password of the follower
//************************************************************************
string Follower::getPassword()
{
	return password_;
}

//************************************************************************
//*  Function name: MessegeListHelper
//*  Description: Prints the list of messages
//*  Paramters: None.
//*  Return value: None
//************************************************************************
void Follower::MessegeListHelper()
{
	messageList_.Print();
}

//************************************************************************
//*  Function name: ReadMessegeListHelper
//*  Description: Reads the wanted message
//*  Paramters: num- number of the message we want to read
//*  Return value: None
//************************************************************************
void Follower::ReadMessegeListHelper(int num)
{
	int countMessegesFollower = messageList_.Size();
	if (num > countMessegesFollower || num <= 0) {
		cout << READ_MESSAGE_FAIL;
		return;
	}
	messageList_.ReadMessage(num);
}

//************************************************************************
//*  Function name: HelperSendMessage
//*  Description: Sends a message.
//*  Paramters: email- email of the message target
//*				subject - subject of the message
//*				content- content of the message
//*  Return value: true if correct, false otherwise.
//************************************************************************
void Follower::HelperSendMessage(string email, string subject, string content)
{
	Message* newMessage = new Message(email, subject, content);
	messageList_.Add(newMessage);

}

//************************************************************************
//*  Function name: setLeader
//*  Description: checks if a follower as a leader.
//*  Paramters: None.
//*  Return value: None
//************************************************************************
void Follower::setLeader(bool isLeader)
{
	if (isLeader == true)
		isLeader_ = true;
	else
		isLeader_ = false;
}

//************************************************************************
//*  Function name: isLeader
//*  Description: Checks if the follower is a leader.
//*  Paramters: None.
//*  Return value: true if leader, false if not.
//************************************************************************
bool Follower::isLeader()
{
	return isLeader_;
}

//************************************************************************
//*  Function name: helperDeleteMessages
//*  Description: removes all the messages of the follower
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
void Follower::helperDeleteMessages() {
	messageList_.ListRemove();
}


