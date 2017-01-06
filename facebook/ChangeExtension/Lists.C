#include<iostream>
#include "Lists.H"
#include "Leader.H"


Follower* ListFollower::SetIteratorFirst() {
	if (firstNode_ == NULL)
		return NULL;
	iterator_ = firstNode_;
	return iterator_->follower_;
}

Follower* ListFollower::SetIteratorNext() {
	if (iterator_ == NULL || iterator_->next_ == NULL)
		return NULL;
	iterator_ = iterator_->next_;
	return iterator_->follower_;
}

Result ListFollower::ListAdd(Follower* follower) {
	if (follower == NULL)
		return FAILURE;
	NodeFollower* newFollowerNode = new NodeFollower;
	newFollowerNode->follower_ = follower;
	newFollowerNode->next_ = firstNode_;
	firstNode_ = newFollowerNode;
	iterator_ = NULL;
	currentSize_++;
	return SUCCESS;
}

Follower* ListFollower::ReturnIteratorData() const{
	return iterator_->follower_;
}

Result ListFollower::ListRemove() { //removes the first element in the list
	if (currentSize_ > 0 && firstNode_ == iterator_) {
		NodeFollower* newFollowerNode = iterator_->next_;
		//delete iterator_->follower_;
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
	//delete iterator_->follower_;
	delete iterator_;
	iterator_ = NULL;
	currentSize_--;
	return SUCCESS;
}

int ListFollower::ListSize() const{
	return currentSize_;
}
// **************************  LEADER ********************//

Leader* ListLeader::SetIteratorFirst() {
	if (firstNode_ == NULL)
		return NULL;
	iterator_ = firstNode_;
	return iterator_->leader_;
}

Leader* ListLeader::SetIteratorNext() {
	if (iterator_ == NULL || iterator_->next_ == NULL)
		return NULL;
	iterator_ = iterator_->next_;
	return iterator_->leader_;
}

Result ListLeader::ListAdd(Leader* leader) {
	if (leader == NULL)
		return FAILURE;
	NodeLeader* newLeaderNode = new NodeLeader;
	newLeaderNode->leader_ = leader;
	newLeaderNode->next_ = firstNode_;
	firstNode_ = newLeaderNode;
	iterator_ = NULL;
	currentSize_++;
	return SUCCESS;
}

Leader* ListLeader::ReturnIteratorData() const {
	return iterator_->leader_;
}

Result ListLeader::ListRemove() { //removes the first element in the list
	if (currentSize_ > 0 && firstNode_ == iterator_) {
		NodeLeader* newLeaderNode = iterator_->next_;
		//delete iterator_->leader_;
		delete iterator_;
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
	//delete iterator_->leader_;
	delete iterator_;
	iterator_ = NULL;
	currentSize_--;
	return SUCCESS;
}

int ListLeader::ListSize() const {
	return currentSize_;
}