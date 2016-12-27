#ifndef _LISTS_H_
#define _LISTS_H_

#include "defs.H"

class Follower;
class Leader;

class NodeFollower {
private:
	Follower follower_;
	NodeFollower* next;
	static NodeFollower* iterator;
	static int CurrentSize;
	static NodeFollower* firstNode;

public:
	NodeFollower();
	~NodeFollower();
	Result SetIteratorFirst();
	NodeFollower* SetIteratorNext();
	Result ListAdd(Follower follower);
	Follower* ReturnIteratorData();
	Result ListRemove();
	int ListSize();
};






#endif
