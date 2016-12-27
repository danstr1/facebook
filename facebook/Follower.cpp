#include <iostream>
#include "Follower.H"

Follower::Follower(string name, string email, string password) {
	curFollower,email

}
~Follower();
string GetName() const;
string GetEmail() const;
bool isPassword(string password) const;
Result ShowFriendRequests() const;
Result ShowFriendList() const;
Result SendFriendRequest(string email);
Result AcceptFriendRequest(string email);
Result	RemoveFriend(string email);
Result	ShowFriendRequests();
Result	ReadMessage(int messageNumber);
Result	SendMessage(string email, string subject, string content);
void Destroy();
Follower* Copy();
