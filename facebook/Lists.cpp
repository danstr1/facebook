#include<iostream>
#include "Lists.H"
#include "defs.H"
NodeFollower::NodeFollower(){
	currentSize_ = 0;
	iterator_ = NULL;
	firstNode_ = NULL;
}
NodeFollower::~NodeFollower() {
//write this!!!!!!!!!!!!!!!!!!!!!
}

Follower* NodeFollower::SetIteratorFirst() {
	iterator_ = firstNode_;
	return iterator_->follower_;
}

Follower* NodeFollower::SetIteratorNext() {
	if (iterator_ == NULL || iterator_->next_ == NULL)
		return NULL;
	iterator_ = iterator_->next_;
	return iterator_->follower_;
}

Result NodeFollower::ListAdd(Follower* follower) {
	if (follower == NULL)
		return FAILURE;
	NodeFollower* newFollowerNode = new NodeFollower;
	Follower *newFollower = follower.cpy();
	newFollowerNode->follower_ = newFollower;
	newFollowerNode->next_ = firstNode_;
	firstNode_ = newFollowerNode;
	currentSize_++;
}

Follower* NodeFollower::ReturnIteratorData() {
	return iterator_->follower_;
}

Result NodeFollower::ListRemove() {
	if (currentSize_ > 0 && firstNode_ == iterator) {
		NodeFollower* newFollowerNode = iterator->next_;
		iterator->follower_.Destroy();
		delete iterator;
		iterator_ = NULL;
		firstNode_ = newFollowerNode;
		currentSize_--;
		return SUCCESS;
	}
	NodeFollower* newFollowerNode = firstNode_;
	while (currentSize_ > 1 && newFollowerNode->next_ != iterator_)
		newFollowerNode = newFollowerNode->next_;
	if (newFollowerNode->next_ != NULL)
		newFollowerNode->next_ = newFollowerNode->next_->next_;
	iterator_->follower_.Destroy();
	delete iterator_;
	iterator_ = NULL;
	currentSize_--;
	return SUCCESS;
}

int NodeFollower::ListSize() {
	return currentSize_;
}