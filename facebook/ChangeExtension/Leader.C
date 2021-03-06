#include<iostream>
#include "Leader.H"
Leader::~Leader() {
	//need to deal with followList_ and the original follower (will run follower de'tor after leader de'tor)
	Follower* curFollower = followList_.SetIteratorFirst();
	while (curFollower != NULL) {
		delete curFollower;
		curFollower = followList_.SetIteratorNext();
	}
}

Result Leader::AddFollower(Follower* newFollower)
{
	if(followList_.ListAdd(newFollower)==FAILURE)
		return FAILURE;
	return SUCCESS;
}

Result Leader::CheckIfFollowing(Follower* follower)
{
	Follower* curFollower = followList_.SetIteratorFirst();
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->GetEmail() == follower->GetEmail())
			return SUCCESS;
		curFollower = followList_.SetIteratorNext();
	}
	return FAILURE;
}

Result Leader::RemoveFollower(Follower* followerToDelete) {
	Follower* curFollower = followList_.SetIteratorFirst();
	for (int i = 0; curFollower != NULL; ++i)
	{
		if (curFollower->GetEmail() == followerToDelete->GetEmail()) {
			followList_.ListRemove();
			return SUCCESS;
		}
		curFollower = followList_.SetIteratorNext();
	}
	return FAILURE;
}

Result Leader::HelperBroadcastMessage(string subject, string content)
{
	Follower* curFollower = followList_.SetIteratorFirst();
	for (int i = 0; curFollower != NULL; ++i)
	{
		curFollower->HelperSendMessage(this->GetEmail(), subject, content);
		curFollower = followList_.SetIteratorNext();
	}
	return SUCCESS;
}

void Leader::RemoveAllFollowers() {
	Follower* following = followList_.SetIteratorFirst();
	for (int i = 0; following!=NULL; ++i)
	{
		followList_.ListRemove();
		following = followList_.SetIteratorFirst();
	}
}