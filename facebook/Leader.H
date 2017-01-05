#ifndef _LEADER_H_
#define _LEADER_H_
#include "Follower.H"

#include "defs.H"
class Leader : public Follower{


public:
	Leader(string name, string email, string password) : Follower(name, email, password), followList_( NULL) { setLeader(true); }
	~Leader();
	Result CheckIfFollowing(Follower* follower);
	Result AddFollower(Follower* newFollower);
	int NumFollowers();
	Result MessegeAll();
	Result RemoveFollower(Follower* followerToDelete);
	Result HelperBroadcastMessage(string subject, string content);

private:
	NodeFollower followList_;



};

#endif
