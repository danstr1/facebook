#ifndef _SOCIALNETWORK_H
#define _SOCIALNETWORK_H
#include "Leader.H"
#include <string>
#define NOT_CONNECTED 0
#define FOLLOWER 1
#define LEADER 2
#define ADMIN 3
using namespace std;
class SocialNetwork {
public:
	SocialNetwork(string name, string password);
	~SocialNetwork();

	void AdminLogin(string password);
	void Login(string email, string password);
	void Logout();

	// Admin actions
	void CreateLeader(string name, string email, string password);
	void DeleteUser(string email);

	// Leader actions
	void BroadcastMessage(string subject, string content);

	// Follower actions (also leader actions)
	void CreateFollower(string name, string email, string password);

	void ShowFriendRequests();
	void ShowFriendList();
	void SendFriendRequest(string friendEmail);
	void AcceptFriendRequest(string friendEmail);
	void RemoveFriend(string friendEmail);

	void ShowMessageList();
	void ReadMessage(int messageNum);
	void SendMessage(string email, string subject, string content);

	void Follow(string leaderEmail);

	// General actions
	void FindUser(string partialName);
private:
	Follower* FindUserByEmail(string email);
	string netName_;
	string netPass_;
	NodeFollower listFollower_;
	NodeLeader listLeader_;
	Follower* userConnected_;
	int typeCurrentUser_;
};

#endif
