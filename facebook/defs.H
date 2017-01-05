#ifndef _DEFS_H_
#define _DEFS_H_

// Admin login (name_ is the social network name)
#define ADMIN_LOGIN_SUCCESS "Hi, Administrator. Welcome to " << netName_  << endl//we changed the name
#define ADMIN_LOGIN_FAIL "Failed to login as admin" << endl

// Login
#define LOGIN_SUCCESS "Hi, " << activeFollower->GetName() << ". Welcome to " << netName_ << endl << "Notifications: " << activeFollower->NumUnreadMessages() << " unread messages, " << activeFollower->NumFriendRequests() << " friend requests." << endl
#define LOGIN_FAIL "User name or password incorrect" << endl

// Logout
#define LOGOUT_SUCCESS "Goodbye" << endl
#define LOGOUT_FAIL "Not logged in" << endl

// Create Leader
#define CREATE_LEADER_SUCCESS "Leader successfully created" << endl
#define CREATE_LEADER_FAIL "Not logged in as admin or user already exists" << endl

// DeleteUser
#define DELETE_USER_SUCCESS "User deleted" << endl
#define DELETE_USER_FAIL "Not logged in as admin or user does not exists" << endl

// BroadcastMessage
#define BROADCAST_MESSAGE_SUCCESS "Messages sent to all followers" << endl
#define BROADCAST_MESSAGE_FAIL "Not logged in or not leader" << endl

// CreateFollower
#define CREATE_FOLLOWER_SUCCESS "Follower successfully created" << endl
#define CREATE_FOLLOWER_FAIL "User already exists" << endl

// ShowFriendRequests (On success put this line in a loop. the variable "i" starts from 0)
#define SHOW_FRIEND_REQUESTS_SUCCESS i + 1 << ") " << curRequest->name_ << ": " << curRequest->email_ << endl
#define SHOW_FRIEND_REQUESTS_FAIL "Not logged in" << endl

// ShowFriendList (On success put this line in a loop. the variable "i" starts from 0)
#define SHOW_FRIEND_LIST_SUCCESS i + 1 << ") " << curFriend->name_ << ": " << curFriend->email_ << endl
#define SHOW_FRIEND_LIST_FAIL "Not logged in" << endl

// SendFriendRequest
#define SEND_FRIEND_REQUEST_SUCCESS "Request Sent" << endl
#define SEND_FRIEND_REQUEST_FAIL "Not logged in ,or user does not exist, or cannot befriend self, or already friends" << endl

// AcceptFriendRequest
#define ACCEPT_FRIEND_REQUEST_SUCCESS "Request accepted" << endl
#define ACCEPT_FRIEND_REQUEST_FAIL "Not logged in or no such request" << endl

// RemoveFriend
#define REMOVE_FRIEND_SUCCESS "Friend removed" << endl
#define REMOVE_FRIEND_FAIL "Not logged in or no such friend" << endl

// ShowMessageList (On success put this line in a loop. the variable "numMessage" starts from 1)
#define SHOW_MESSAGE_LIST_SUCCESS curMessage->Display(numMessage); // Use without cout
#define SHOW_MESSAGE_LIST_FAIL "Not logged in" << endl

// ReadMessage
#define READ_MESSAGE_SUCCESS curMessage->Read(); // Use without cout
#define READ_MESSAGE_FAIL "Not logged in or invalid message number" << endl

// SendMessage
#define SEND_MESSAGE_SUCCESS "Message sent" << endl
#define SEND_MESSAGE_FAIL "Not logged in or no such friend" << endl

// Follow
#define FOLLOW_SUCCESS "Added as follower" << endl
#define FOLLOW_FAIL "Not logged in, or no such leader, or already following" << endl


enum Result {FAILURE, SUCCESS};

#endif
