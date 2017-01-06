#ifndef _LEADER_H_
#define _LEADER_H_
#include "Follower.H"
class Leader : public Follower{


public:
	Leader(string name, string email, string password) : Follower(name, email, password), followList_( ) { setLeader(true); }
	~Leader();
	Result CheckIfFollowing(Follower* follower);
	Result AddFollower(Follower* newFollower);
	Result RemoveFollower(Follower* followerToDelete);
	Result HelperBroadcastMessage(string subject, string content);
	void RemoveAllFollowers();
private:
	ListFollower followList_;



};

#endif
