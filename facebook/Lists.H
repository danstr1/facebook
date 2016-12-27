#ifndef _LISTS_H_
#define _LISTS_H_

#include "defs.H"

class Follower;
class Leader;

class NodeFollower {
private:
	int follower_;
	NodeFollower* next_;
	static NodeFollower* iterator_;
	static int currentSize_;
	static NodeFollower* firstNode_;

public:
	NodeFollower();
	~NodeFollower();
	Follower* SetIteratorFirst();
	Follower* SetIteratorNext();
	Result ListAdd(Follower* follower);
	Follower* ReturnIteratorData();
	Result ListRemove();
	int ListSize();
};






#endif
