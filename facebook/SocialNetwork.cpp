#include "SocialNetwork.H"
#include <iostream>


Follower* SocialNetwork::FindUserByEmail(string email)
{
	
	Follower* curFollower = listFollower_.SetIteratorFirst();
	// Loop over all followers in network
	for (int i = 0; curFollower!=NULL; ++i)
	{
		? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
			if (curFollower->GetName().find(partialName) != string::npos)
				cout << i + 1 << ") " << curFollower->GetName() << ": " << curFollower->GetEmail() << endl;
		curFollower = listFollower_.Set
	}

	cout << "Leaders:" << endl;
	// Loop over all leaders in network
	for (int i = 0; ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ; ++i)
	{
		? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
			if (curLeader->GetName().find(partialName) != string::npos)
				cout << i + 1 << ") " << curLeader->GetName() << ": " << curLeader->GetEmail() << endl;
		? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	}

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
Result CreateFollower(string name, string email, string password, Follower* currentUser, int typeCurrentUser);

void SendFriendRequest(string friendEmail)
{

	if (typeCurrentUser == 0 || currentUser->email_ == email) {
		std::cout << SEND_FRIEND_REQUEST_FAIL;
		return FAILURE;
	}
	Follower *curFriend = curFollower.SetIteratorFirst();
	int i = 0;
	while (curFriend != NULL) //loop for folllowers with the same email
	{
		if (curFriend->email_ != email_ && curFriend->email_ == email) {
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
void AcceptFriendRequest(string friendEmail) {

	if (currentUser == NULL)
		return FAILURE;
	connectedUser->friendRequest_
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





