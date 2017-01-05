#include "SocialNetwork.H"
#include <iostream>

SocialNetwork::~SocialNetwork()
{
	//need to deal with listFollower_,listLeader_
	Follower* curFollower = listFollower_.SetIteratorFirst();
	while (curFollower != NULL) {
		delete curFollower;
		curFollower = listFollower_.SetIteratorNext();
	}
	Leader* curLeader = listLeader_.SetIteratorFirst();
	while (curLeader != NULL) {
		delete curLeader;
		curLeader = listLeader_.SetIteratorNext();
	}
}

void SocialNetwork::AdminLogin(string password) {
	if (password != netPass_) {
		cout << ADMIN_LOGIN_FAIL;
		return;
	}
	cout << ADMIN_LOGIN_SUCCESS;
	typeCurrentUser_ = ADMIN;
}

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

void SocialNetwork::Logout() {
	if (typeCurrentUser_ == NOT_CONNECTED) {
		cout << LOGOUT_FAIL;
		return;
	}
	userConnected_ = NULL;
	typeCurrentUser_ = NOT_CONNECTED;
	cout << LOGOUT_SUCCESS;
}

void SocialNetwork::DeleteUser(string email) {
	if (typeCurrentUser_ != ADMIN) {
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
		if (curFollower->CheckIfFriendRequest(followerToDelete) == SUCCESS)
			curFollower->RemoveFriendRequest(followerToDelete);
		
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
		if (curLeader->CheckIfFriendRequest(followerToDelete) == SUCCESS)
			curLeader->RemoveFriendRequest(followerToDelete);
		
		if (curLeader->CheckIfFriend(followerToDelete) == SUCCESS) {
			curLeader->RemoveFriend(followerToDelete);
			followerToDelete->RemoveFriend(curLeader);
		}
		if (curLeader->CheckIfFollowing(followerToDelete) == SUCCESS) 
			curLeader->RemoveFollower(followerToDelete);
		curLeader = listLeader_.SetIteratorNext();
	}
	//delete followerToDelete;
	followerToDelete = FindUserByEmail(email);
	if (followerToDelete->isLeader() == true)
		listLeader_.ListRemove();
	else
		listFollower_.ListRemove();
	cout << DELETE_USER_SUCCESS;
	return;
}

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

Follower* SocialNetwork::FindUserByEmail(string email)
{
	Follower* curFollower = listFollower_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower!=NULL; ++i)
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

void SocialNetwork::CreateLeader(string name, string email, string password)
{
	if (typeCurrentUser_ != ADMIN)	{
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
void SocialNetwork::Follow(string leaderEmail)
{
	if (typeCurrentUser_ == ADMIN|| typeCurrentUser_ == NOT_CONNECTED) {
		cout << FOLLOW_FAIL;
		return;
	}
	Leader *followerToFollow = (Leader*)FindUserByEmail(leaderEmail);
	if (followerToFollow == NULL) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << FOLLOW_FAIL;
		return;
	}
	if (followerToFollow->isLeader() == false) {
		cout << FOLLOW_FAIL;
		return;
	}
	followerToFollow->AddFollower(userConnected_);
	cout << FOLLOW_SUCCESS;
}

void SocialNetwork::CreateFollower(string name, string email, string password)
{
	if (typeCurrentUser_ != ADMIN) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << CREATE_FOLLOWER_FAIL;
		return;
	}
	Follower *followerToCheck = FindUserByEmail(email); 
	if (followerToCheck!=NULL) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << CREATE_FOLLOWER_FAIL;
		return;
	}
	Follower* newFollower = new Follower(name, email, password);
	listFollower_.ListAdd(newFollower);
	cout << CREATE_FOLLOWER_SUCCESS;
}
void SocialNetwork::ShowFriendRequests()
{
	if (typeCurrentUser_ == NOT_CONNECTED|| typeCurrentUser_==ADMIN) {
		cout << SHOW_FRIEND_REQUESTS_FAIL;
		return;
	}
	userConnected_->ShowFriendRequests();
}
void SocialNetwork::ShowFriendList()
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		cout << SHOW_FRIEND_LIST_FAIL;
		return;
	}
	userConnected_->ShowFriendList();
}
void SocialNetwork::RemoveFriend(string friendEmail)
{
	if (typeCurrentUser_ == 0 || userConnected_->GetEmail() == friendEmail) {
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
void SocialNetwork::ShowMessageList()
{
	if (typeCurrentUser_ == NOT_CONNECTED|| typeCurrentUser_== ADMIN) {
		std::cout << SHOW_MESSAGE_LIST_FAIL;
		return;
	}
	userConnected_->MessegeListHelper();
}

void SocialNetwork::ReadMessage(int messageNum)
{
	if (typeCurrentUser_ == NOT_CONNECTED || typeCurrentUser_ == ADMIN) {
		std::cout << READ_MESSAGE_FAIL;
		return;
	}
	userConnected_->ReadMessegeListHelper(messageNum);
}

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

void SocialNetwork::SendFriendRequest(string friendEmail)
{
	if (typeCurrentUser_ == 0 || userConnected_->GetEmail() == friendEmail) {
		std::cout << SEND_FRIEND_REQUEST_FAIL;
		return;
	}
	Follower *friendToAdd=FindUserByEmail(friendEmail); //find the mail of the person that we will send him the request
	if (friendToAdd==NULL ){
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

void SocialNetwork::AcceptFriendRequest(string friendEmail) {
	if (userConnected_ == NULL) {
		cout << ACCEPT_FRIEND_REQUEST_FAIL;
		return;
	}
	Follower* friendToAccept = FindUserByEmail(friendEmail);
	
	if (friendToAccept == NULL|| userConnected_->RemoveFriendRequest(friendToAccept) == FAILURE) {
		cout << ACCEPT_FRIEND_REQUEST_FAIL;
		return;
	}
	userConnected_->AddUserToFriendList(friendToAccept);
	friendToAccept->AddUserToFriendList(userConnected_);
	cout << ACCEPT_FRIEND_REQUEST_SUCCESS;
		
}

// General actions
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





