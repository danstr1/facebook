#include<iostream>
#include "Lists.H"
#include "defs.H"
NodeFollower::NodeFollower(){
	CurrentSize = 0;
	iterator = NULL;
	firstNode = NULL;
}
NodeFollower::~NodeFollower() {

}

Follower* NodeFollower::SetIteratorFirst() {
	iterator = firstNode;
	return iterator->follower_;
}

Follower* NodeFollower::SetIteratorNext() {
	if (iterator == NULL || iterator->next == NULL)
		return NULL;
	iterator = iterator->next;
	return iterator->follower_;
}

Result NodeFollower::ListAdd(Follower* follower) {
	if (follower == NULL)
		return FAILURE;
	Follower newFollower = new Follower;

}

NodeFollower::Follower* ReturnIteratorData() {

}
NodeFollower::Result ListRemove() {

}
NodeFollower::int ListSize() {

}