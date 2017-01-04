#include "SocialNetwork.H"
#include <iostream>


Follower* SocialNetwork::FindUserByEmail(string email)
{
	Follower* curFollower = listFollower_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower!=NULL; ++i)
	{
		if (curFollower->GetEmail() == email)
			return curFollower;
		curFollower = listFollower_.SetIteratorNext();
	}

	Leader* curLeader = listLeader_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curLeader != NULL; ++i)
	{
		if (curLeader->GetEmail() == email)
			return curLeader;
		curLeader = listLeader_.SetIteratorNext();
	}
	return NULL;
}

if (currentUser.checkNoEmailExists(email) == false || curLeader.checkNoEmailExists(email) == false) {
	std::cout << CREATE_FOLLOWER_FAIL;
	return FAILURE;
} //to be inserted in Create follower
if (typeCurrentUser == NOT_CONNECTED || typeCurrentUser == FOLLOWER) {
	std::cout << CREATE_FOLLOWER_FAIL;
	return FAILURE;
}
Follower* newFollower = new Follower(name, email, password);
if (currentUser.ListAdd(newFollower)) {
	std::cout << CREATE_FOLLOWER_FAIL;
	return FAILURE;
}
return SUCCESS;
void SocialNetwork::CreateFollower(string name, string email, string password)
{
	if (typeCurrentUser_ != ADMIN) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << CREATE_LEADER_FAIL;
		return;
	}
	Follower *followerToCheck = FindUserByEmail(email); 
	if (followerToCheck!=NULL) { //CHECK THAT THIS NOT THE ACCURATE MESSEGE
		cout << CREATE_LEADER_FAIL;
		return;
	}
	Follower* newFollower = new Follower(name, email, password);
	listFollower_.ListAdd(newFollower);

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
	// Loop over all followers in network
	for (int i = 0; ???????????????; ++i)
	{
		???????????????
		if (curFollower->GetName().find(partialName) != string::npos)
			cout << i + 1 << ") " << curFollower->GetName() << ": " << curFollower->GetEmail() << endl;
		???????????????
	}

	cout << "Leaders:" << endl;
	// Loop over all leaders in network
	for (int i = 0; ???????????????; ++i)
	{
		???????????????
		if (curLeader->GetName().find(partialName) != string::npos)
			cout << i + 1 << ") " << curLeader->GetName() << ": " << curLeader->GetEmail() << endl;
		???????????????
	}
}





