#include<iostream>
#include "Leader.H"

//************************************************************************
//*  Function name: Leader
//*  Description: Leader deconstructor.
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
Leader::~Leader() {
	//need to deal with followList_ and the original follower (will run follower de'tor after leader de'tor)
	Follower* curFollower = followList_.SetIteratorFirst();
	while (curFollower != NULL) {
		delete curFollower;
		curFollower = followList_.SetIteratorNext();
	}
}

//************************************************************************
//*  Function name: AddFollower
//*  Description: adds a follower to a leader follower list.
//*  Paramters: pointer to the follower we want to add.
//*  Return value: SUCCESS if worked, FAILURE otherwise.
//************************************************************************
Result Leader::AddFollower(Follower* newFollower)
{
	if (followList_.ListAdd(newFollower) == FAILURE)
		return FAILURE;
	return SUCCESS;
}

//************************************************************************
//*  Function name: CheckIfFollowing
//*  Description: Checks if the follower is already following
//*  Paramters: pointer to the follower we want to check
//*  Return value: SUCCESS if worked, FAILURE otherwise.
//************************************************************************
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

//************************************************************************
//*  Function name: RemoveFollower
//*  Description: removes a follower from the follower list
//*  Paramters: pointer to the follower we want to remove
//*  Return value: SUCCESS if worked, FAILURE otherwise.
//************************************************************************
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

//************************************************************************
//*  Function name: HelperBroadcastMessage
//*  Description: broadcasts the message to all the followers
//*  Paramters: subject- subject of the message
//*				content- content of the message
//*  Return value: SUCCESS if worked, FAILURE otherwise.
//************************************************************************
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

//************************************************************************
//*  Function name: RemoveAllFollowers
//*  Description: Removes all the followers
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
void Leader::RemoveAllFollowers() {
	Follower* following = followList_.SetIteratorFirst();
	for (int i = 0; following != NULL; ++i)
	{
		followList_.ListRemove();
		following = followList_.SetIteratorFirst();
	}
}