#include<iostream>
#include "Leader.H"

Result Leader::AddFollower(Follower* newFollower)
{
	if(followList_.ListAdd(newFollower)==FAILURE)
		return FAILURE;
	return SUCCESS;
}
