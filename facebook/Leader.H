#ifndef _LEADER_H_
#define _LEADER_H_
#include "Follower.H"

#include "defs.H"
class Leader : public Follower{


public:
	Leader(string name, string email, string password) : Follower(name, email, password), followList_(NULL) { setLeader(true); }

	Result AddFollower();
	Result RemoveFollower();
	int NumFollowers();
	Result MessegeAll();

private:
	NodeFollower followList_;



};

#endif
