#include<iostream>
#include "Lists.H"
NodeFollower::NodeFollower(int i=NULL){
	currentSize_ = 0;
	iterator_ = NULL;
	firstNode_ = NULL;
}
NodeFollower::~NodeFollower() {
	while (firstNode_ != NULL) {
		delete follower_;
		NodeFollower* tmpNodeFollower = firstNode_;
		firstNode_ = firstNode_->next_;
		delete tmpNodeFollower;
	}
	return;
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
	newFollowerNode->follower_ = follower;
	newFollowerNode->next_ = firstNode_;
	firstNode_ = newFollowerNode;
	currentSize_++;
	return SUCCESS;
}

Follower* NodeFollower::ReturnIteratorData() const{
	return iterator_->follower_;
}

Result NodeFollower::ListRemove() { //removes the first element in the list
	if (currentSize_ > 0 && firstNode_ == iterator_) {
		NodeFollower* newFollowerNode = iterator_->next_;
		delete iterator_->follower_;
		delete iterator_;
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
	delete iterator_->follower_;
	delete iterator_;
	iterator_ = NULL;
	currentSize_--;
	return SUCCESS;
}

int NodeFollower::ListSize() const{
	return currentSize_;
}

NodeLeader::NodeLeader(int i = NULL) {
	currentSize_ = 0;
	iterator_ = NULL;
	firstNode_ = NULL;
}

NodeLeader::~NodeLeader() {
	//write this!!!!!!!!!!!!!!!!!!!!!
}

Leader* NodeLeader::SetIteratorFirst() {
	iterator_ = firstNode_;
	return iterator_->leader_;
}

Leader* NodeLeader::SetIteratorNext() {
	if (iterator_ == NULL || iterator_->next_ == NULL)
		return NULL;
	iterator_ = iterator_->next_;
	return iterator_->leader_;
}

Result NodeLeader::ListAdd(Leader* leader) {
	if (leader == NULL)
		return FAILURE;
	NodeLeader* newLeaderNode = new NodeLeader;
	Leader *newLeader = leader.Copy();
	newLeaderNode->leader_ = newLeader;
	newLeaderNode->next_ = firstNode_;
	firstNode_ = newLeaderNode;
	currentSize_++;
	return SUCCESS;
}

Leader* NodeLeader::ReturnIteratorData() const{
	return iterator_->leader_;
}

Result NodeLeader::ListRemove() {
	if (currentSize_ > 0 && firstNode_ == iterator) {
		NodeLeader* newLeaderNode = iterator->next_;
		iterator->leader_.Destroy();
		delete iterator;
		iterator_ = NULL;
		firstNode_ = newLeaderNode;
		currentSize_--;
		return SUCCESS;
	}
	NodeLeader* newLeaderNode = firstNode_;
	while (currentSize_ > 1 && newLeaderNode->next_ != iterator_)
		newLeaderNode = newLeaderNode->next_;
	if (newLeaderNode->next_ != NULL)
		newLeaderNode->next_ = newLeaderNode->next_->next_;
	iterator_->leader_.Destroy();
	delete iterator_;
	iterator_ = NULL;
	currentSize_--;
	return SUCCESS;
}

int NodeLeader::ListSize() const{
	return currentSize_;
}

