#include "SocialNetwork.H"
#include <iostream>

//************************************************************************
//*  Function name: ~SocialNetwork
//*  Description: deconstructor of the Social network
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
SocialNetwork::~SocialNetwork()
{
	//need to deal with listFollower_,listLeader_
	Follower* curFollower = listFollower_.SetIteratorFirst();
	typeCurrentUser_ = EXIT;
	while (curFollower != NULL) {
		DeleteUser(curFollower->GetEmail());
		curFollower = listFollower_.SetIteratorFirst();
	}
	Leader* curLeader = listLeader_.SetIteratorFirst();
	while (curLeader != NULL) {
		DeleteUser(curLeader->GetEmail());
		curLeader = listLeader_.SetIteratorFirst();
	}
}

//************************************************************************
//*  Function name: AdminLogin
//*  Description: allows the Admin to login to the system
//*  Paramters: password- the password of the admin.
//*  Return value: None
//************************************************************************
void SocialNetwork::AdminLogin(string password) {
	if (password != netPass_) {
		cout << ADMIN_LOGIN_FAIL;
		return;
	}
	cout << ADMIN_LOGIN_SUCCESS;
	typeCurrentUser_ = ADMIN;
}

//************************************************************************
//*  Function name: Login
//*  Description: allows the user to login to the system
//*  Paramters: password- the password of the user.
//*  Return value: None
//************************************************************************
void SocialNetwork::Login(string email, string password) {
	Leader *activeFollower = (Leader*)FindUserByEmail(email);
	if (activeFollower == NULL) {
		cout << LOGIN_FAIL;
		return;
	}
	if (activeFollower->GetPassword() == password) {
		cout << LOGIN_SUCCESS;
		if (activeFollower->isLeader() == true)
			typeCurrentUser_ = LEADER;
		else
			typeCurrentUser_ = FOLLOWER;
		//What with ADMIN?!
		userConnected_ = activeFollower;
	}
}

//************************************************************************
//*  Function name: Logout
//*  Description: Allows the user to logout from the system
//*  Paramters: None.
//*  Return value: None
//************************************************************************
void SocialNetwork::Logout() {
	if (typeCurrentUser_ == NOT_CONNECTED) {
		cout << LOGOUT_FAIL;
		return;
	}
	userConnected_ = NULL;
	typeCurrentUser_ = NOT_CONNECTED;
	cout << LOGOUT_SUCCESS;
}

//************************************************************************
//*  Function name: DeleteUser
//*  Description: deletes a user from the system
//*  Paramters: email- the email of the user we want to remove
//*  Return value: None
//************************************************************************
void SocialNetwork::DeleteUser(string email) {
	if (typeCurrentUser_ != ADMIN && typeCurrentUser_ != EXIT) {//we used this func in d'tor
		cout << DELETE_USER_FAIL;
		return;
	}
	Follower *followerToDelete = FindUserByEmail(email);
	if (followerToDelete == NULL) {
		cout << DELETE_USER_FAIL;
		return;
	}

	Follower* curFollower = listFollower_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->CheckIfFriendRequest(followerToDelete) == SUCCESS) {
			curFollower->RemoveFriendRequest(followerToDelete);
			followerToDelete->RemoveFriendRequest(curFollower);
		}

		if (curFollower->CheckIfFriend(followerToDelete) == SUCCESS) {
			curFollower->RemoveFriend(followerToDelete);
			followerToDelete->RemoveFriend(curFollower);

		}

		curFollower = listFollower_.SetIteratorNext();
	}

	Leader* curLeader = listLeader_.SetIteratorFirst();
	// Loop over all leaders in network
	for (int i = 0; curLeader != NULL; ++i)
	{
		if (curLeader->CheckIfFriendRequest(followerToDelete) == SUCCESS) {
			curLeader->RemoveFriendRequest(followerToDelete);
			followerToDelete->RemoveFriendRequest(curLeader);
		}

		if (curLeader->CheckIfFriend(followerToDelete) == SUCCESS) {
			curLeader->RemoveFriend(followerToDelete);
			followerToDelete->RemoveFriend(curLeader);
		}
		if (curLeader->CheckIfFollowing(followerToDelete) == SUCCESS)
			curLeader->RemoveFollower(followerToDelete);
		curLeader = listLeader_.SetIteratorNext();
	}

	followerToDelete = FindUserByEmail(email);
	if (followerToDelete->isLeader() == true) {
		Leader* tmp = (Leader *)followerToDelete;
		tmp->RemoveAllFollowers();
		listLeader_.ListRemove();//Remove from the main lists
	}
	else
		listFollower_.ListRemove();//Remove from the main lists
								   //Now deleting the messege list:
	followerToDelete->helperDeleteMessages();
	//finaly the follower itself:
	delete followerToDelete;
	if (typeCurrentUser_ != EXIT)//we used this func in d'tor and don't want output
		cout << DELETE_USER_SUCCESS;
	return;
}

//************************************************************************
//*  Function name: BroadcastMessage
//*  Description: allows a leader to send a message to all his followers
//*  Paramters: subject- the subject of the message
//*				content- the content of the message
//*  Return value: None
//************************************************************************
void SocialNetwork::BroadcastMessage(string subject, string content) {
	if (typeCurrentUser_ != LEADER) {
		cout << BROADCAST_MESSAGE_FAIL;
		return;
	}
	Leader* connectedUser = (Leader*)userConnected_;
	if (connectedUser->HelperBroadcastMessage(subject, content) == SUCCESS)
		cout << BROADCAST_MESSAGE_SUCCESS;
	else
		cout << BROADCAST_MESSAGE_FAIL;
}

//************************************************************************
//*  Function name: FindUserByEmail
//*  Description: Finds the follower with the given email 
//*  Paramters: email- email of the follower we want to find
//*  Return value: poiter to the follower with the wanted email
//************************************************************************
Follower* SocialNetwork::FindUserByEmail(string email)
{
	Follower* curFollower = listFollower_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->GetEmail() == email) {
			curFollower->setLeader(false);
			return curFollower;
		}
		curFollower = listFollower_.SetIteratorNext();
	}

	Leader* curLeader = listLeader_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curLeader != NULL; ++i)
	{
		if (curLeader->GetEmail() == email) {
			curLeader->setLeader(true);
			return curLeader;
		}
		curLeader = listLeader_.SetIteratorNext();
	}
	return NULL;
}

//************************************************************************
//*  Function name: CreateLeader
//*  Description: creates a new leader in the system
//*  Paramters: name- name of the new leader
//*				email- email of the new leader
//*				password- password of the new leader
//*  Return value: true if correct, false otherwise.
//************************************************************************
void SocialNetwork::CreateLeader(string name, string email, string password)
{
	if (typeCurrentUser_ != ADMIN) {
		cout << CREATE_LEADER_FAIL;
		return;
	}
	Follower *followerToCheck = FindUserByEmail(email);
	if (followerToCheck != NULL) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << CREATE_LEADER_FAIL;
		return;
	}
	Leader* newLeader = new Leader(name, email, password);
	listLeader_.ListAdd(newLeader);
	cout << CREATE_LEADER_SUCCESS;
}

//************************************************************************
//*  Function name: Follow
//*  Description: allows a user to follow a leader
//*  Paramters: leaderEmail- mail of the leader we want to follow.
//*  Return value: None
//************************************************************************
void SocialNetwork::Follow(string leaderEmail)
{
	if (typeCurrentUser_ == ADMIN || typeCurrentUser_ == NOT_CONNECTED) {
		cout << FOLLOW_FAIL;
		return;
	}
	//	if (userConnected_->GetEmail() == leaderEmail) {
	//		cout << FOLLOW_FAIL;
	//		return;
	//	}
	Leader *followerToFollow = (Leader*)FindUserByEmail(leaderEmail);
	if (followerToFollow == NULL) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << FOLLOW_FAIL;
		return;
	}
	if (followerToFollow->isLeader() == false) {
		cout << FOLLOW_FAIL;
		return;
	}
	if (followerToFollow->CheckIfFollowing(userConnected_) == SUCCESS) {
		cout << FOLLOW_FAIL;
		return;
	}
	followerToFollow->AddFollower(userConnected_);
	cout << FOLLOW_SUCCESS;
}

//************************************************************************
//*  Function name: CreateFollower
//*  Description: Creates a new follower to the meta list of followers
//*  Paramters: name- the name of the new follower
//*				email- the email of the new follower
//*				password- the password of the new follower
//*  Return value: None
//************************************************************************
void SocialNetwork::CreateFollower(string name, string email, string password)
{
	//if (typeCurrentUser_ == NOT_CONNECTED) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
	//	cout << CREATE_FOLLOWER_FAIL;
	//	return;
	//}
	Follower *followerToCheck = FindUserByEmail(email);
	if (followerToCheck != NULL) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << CREATE_FOLLOWER_FAIL;
		return;
	}
	Follower* newFollower = new Follower(name, email, password);
	listFollower_.ListAdd(newFollower);
	cout << CREATE_FOLLOWER_SUCCESS;
}

//************************************************************************
//*  Function name: ShowFriendRequests
//*  Description: shows the friend requests of the connected user
//*  Paramters: None.
//*  Return value: None
//************************************************************************
void SocialNetwork::ShowFriendRequests()
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		cout << SHOW_FRIEND_REQUESTS_FAIL;
		return;
	}
	userConnected_->ShowFriendRequests();
}

//************************************************************************
//*  Function name: ShowFriendList
//*  Description: shows the friend list of the connected user
//*  Paramters: None.
//*  Return value: None
//************************************************************************
void SocialNetwork::ShowFriendList()
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		cout << SHOW_FRIEND_LIST_FAIL;
		return;
	}
	userConnected_->ShowFriendList();
}

//************************************************************************
//*  Function name: RemoveFriend
//*  Description: removes the friend from the connected users friend list
//*  Paramters: friendEmail- the email of the friend we want to remove.
//*  Return value: None
//************************************************************************
void SocialNetwork::RemoveFriend(string friendEmail)
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN || userConnected_->GetEmail() == friendEmail) {
		std::cout << REMOVE_FRIEND_FAIL;
		return;
	}
	Follower *friendToRemove = FindUserByEmail(friendEmail); //find the mail of the person that we will send him the request
	if (friendToRemove == NULL) {
		std::cout << REMOVE_FRIEND_FAIL;
		return;
	}
	if (userConnected_->CheckIfFriend(friendToRemove) == FAILURE) {
		std::cout << REMOVE_FRIEND_FAIL;
		return;
	}
	if (userConnected_->RemoveFriend(friendToRemove) == FAILURE
		|| friendToRemove->RemoveFriend(userConnected_) == FAILURE)
	{
		std::cout << REMOVE_FRIEND_FAIL;
		return;
	}
	std::cout << REMOVE_FRIEND_SUCCESS;
}

//************************************************************************
//*  Function name: ShowMessageList
//*  Description: Prints the message list
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
void SocialNetwork::ShowMessageList()
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		std::cout << SHOW_MESSAGE_LIST_FAIL;
		return;
	}
	userConnected_->MessegeListHelper();
}

//************************************************************************
//*  Function name: ReadMessage
//*  Description: Reads the wanted message.
//*  Paramters: messageNum- number of the message we want to read
//*  Return value: None
//************************************************************************
void SocialNetwork::ReadMessage(int messageNum)
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		std::cout << READ_MESSAGE_FAIL;
		return;
	}
	userConnected_->ReadMessegeListHelper(messageNum);
}

//************************************************************************
//*  Function name: SendMessage
//*  Description: sends a message 
//*  Paramters: email- the user we want to send a message to
//*				subject- the subject of the mail we want to send
//*				content- the content of the message we want to send
//*  Return value: true if correct, false otherwise.
//************************************************************************
void SocialNetwork::SendMessage(string email, string subject, string content)
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		std::cout << SEND_MESSAGE_FAIL;
		return;
	}
	Follower *friendToSend = FindUserByEmail(email); //find the mail of the person that we will send him the messege
	if (friendToSend == NULL) {
		std::cout << SEND_MESSAGE_FAIL;
		return;
	}
	if (userConnected_->CheckIfFriend(friendToSend) == FAILURE) {
		std::cout << SEND_MESSAGE_FAIL;
		return;
	}
	friendToSend->HelperSendMessage(userConnected_->GetEmail(), subject, content);
	cout << SEND_MESSAGE_SUCCESS;
}

//************************************************************************
//*  Function name: SendFriendRequest
//*  Description: Send Friend Request to the given email
//*  Paramters: friendEmail- the email of the user we want to add as a friend.
//*  Return value: None.
//************************************************************************
void SocialNetwork::SendFriendRequest(string friendEmail)
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN || userConnected_->GetEmail() == friendEmail) {
		std::cout << SEND_FRIEND_REQUEST_FAIL;
		return;
	}
	Follower *friendToAdd = FindUserByEmail(friendEmail); //find the mail of the person that we will send him the request
	if (friendToAdd == NULL) {
		std::cout << SEND_FRIEND_REQUEST_FAIL;
		return;
	}
	if (friendToAdd->CheckIfFriend(userConnected_) == SUCCESS
		|| friendToAdd->CheckIfFriendRequest(userConnected_) == SUCCESS
		|| friendToAdd->AddUserToFriendRequest(userConnected_) == FAILURE) {

		cout << SEND_FRIEND_REQUEST_FAIL;
		return;
	}
	std::cout << SEND_FRIEND_REQUEST_SUCCESS;
}

//************************************************************************
//*  Function name: AcceptFriendRequest
//*  Description: accept a friend request from the given email
//*  Paramters: friendEmail- the mail of the friend we want to accept
//*  Return value: None
//************************************************************************
void SocialNetwork::AcceptFriendRequest(string friendEmail) {
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		cout << ACCEPT_FRIEND_REQUEST_FAIL;
		return;
	}
	Follower* friendToAccept = FindUserByEmail(friendEmail);

	if (friendToAccept == NULL || userConnected_->RemoveFriendRequest(friendToAccept) == FAILURE) {
		cout << ACCEPT_FRIEND_REQUEST_FAIL;
		return;
	}
	friendToAccept->RemoveFriendRequest(userConnected_); //will remove if both users sent a friend request
	userConnected_->AddUserToFriendList(friendToAccept);
	friendToAccept->AddUserToFriendList(userConnected_);
	cout << ACCEPT_FRIEND_REQUEST_SUCCESS;
}

// General actions
//************************************************************************
//*  Function name: FindUser
//*  Description: Prints the users whose name contains a given string
//*  Paramters: partialName- the string we want in the user name
//*  Return value: None.
//************************************************************************
void SocialNetwork::FindUser(string partialName)
{
	cout << "Followers:" << endl;
	Follower* curFollower = listFollower_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->GetName().find(partialName) != string::npos)
			cout << i + 1 << ") " << curFollower->GetName() << ": " << curFollower->GetEmail() << endl;
		curFollower = listFollower_.SetIteratorNext();
	}

	cout << "Leaders:" << endl;
	Leader* curLeader = listLeader_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curLeader != NULL; ++i)
	{
		if (curLeader->GetName().find(partialName) != string::npos)
			cout << i + 1 << ") " << curLeader->GetName() << ": " << curLeader->GetEmail() << endl;
		curLeader = listLeader_.SetIteratorNext();
	}
}





