#ifndef _DEFS_H_
#define _DEFS_H_

// Admin login
#define ADMIN_LOGIN_SUCCESS "Hi, Administrator. Welcome to "
#define ADMIN_LOGIN_FAIL "Failed to login as admin"

// Login
#define LOGIN_SUCCESS "Hi, " << activeFollower->GetName() << ". Welcome to " << name_ << endl << "Notifications: " << activeFollower->NumUnreadMessages() << " unread messages, " << activeFollower->NumFriendRequests() << " friend requests."
#define LOGIN_FAIL "User name or password incorrect"

// Logout
#define LOGOUT_SUCCESS "Goodbye"
#define LOGOUT_FAIL "Not logged in"

// Create Leader
#define CREATE_LEADER_SUCCESS "Leader successfully created"
#define CREATE_LEADER_FAIL "Not logged in as admin or user already exists"

// DeleteUser
#define DELETE_USER_SUCCESS "User deleted"
#define DELETE_USER_FAIL "Not logged in as admin or user does not exists"

// BroadcastMessage
#define BROADCAST_MESSAGE_SUCCESS "Messages sent to all followers"
#define BROADCAST_MESSAGE_FAIL "Not logged in or not leader"

// CreateFollower
#define CREATE_FOLLOWER_SUCCESS "Follower successfully created"
#define CREATE_FOLLOWER_FAIL "User already exists"

// ShowFriendRequests (On success put this line in a loop. the variable "i" starts from 0)
#define SHOW_FRIEND_REQUESTS_SUCCESS i + 1 << ") " << curRequest->name_ << ": " << curRequest->email_
#define SHOW_FRIEND_REQUESTS_FAIL "Not logged in"

// ShowFriendList (On success put this line in a loop. the variable "i" starts from 0)
#define SHOW_FRIEND_LIST_SUCCESS i + 1 << ") " << curFriend->name_ << ": " << curFriend->email_
#define SHOW_FRIEND_LIST_FAIL "Not logged in"

// SendFriendRequest
#define SEND_FRIEND_REQUEST_SUCCESS "Request Sent"
#define SEND_FRIEND_REQUEST_FAIL "Not logged in ,or user does not exist, or cannot befriend self, or already friends"

// AcceptFriendRequest
#define ACCEPT_FRIEND_REQUEST_SUCCESS "Request accepted"
#define ACCEPT_FRIEND_REQUEST_FAIL "Not logged in or no such request"

// RemoveFriend
#define REMOVE_FRIEND_SUCCESS "Friend removed"
#define REMOVE_FRIEND_FAIL "Not logged in or no such friend"

// ShowMessageList (On success put this line in a loop. the variable "numMessage" starts from 1)
#define SHOW_MESSAGE_LIST_SUCCESS curMessage->Display(numMessage); // Use without cout
#define SHOW_MESSAGE_LIST_FAIL "Not logged in"

// ReadMessage
#define READ_MESSAGE_SUCCESS curMessage->Read(); // Use without cout
#define READ_MESSAGE_FAIL "Not logged in or invalid message number"

// SendMessage
#define SEND_MESSAGE_SUCCESS "Message sent"
#define SEND_MESSAGE_FAIL "Not logged in or no such friend"

// Follow
#define FOLLOW_SUCCESS "Added as follower"
#define FOLLOW_FAIL "Not logged in, or no such leader, or already following"


enum Result {FAILURE, SUCCESS};

#endif
