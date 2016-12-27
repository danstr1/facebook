#ifndef _LISTS_H_
#define _LISTS_H_

#include "defs.H"

class Follower;
class Leader;

class NodeFollower {
private:
	Follower follower_;
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
	Follower* ReturnIteratorData()const;
	Result ListRemove();
	int ListSize()const;
};


class NodeLeader {
private:
	Leader leader_;
	NodeLeader* next_;
	static NodeLeader* iterator_;
	static int currentSize_;
	static NodeLeader* firstNode_;

public:
	NodeLeader();
	~NodeLeader();
	Leader* SetIteratorFirst();
	Leader* SetIteratorNext();
	Result ListAdd(Leader* leader);
	Leader* ReturnIteratorData()const;
	Result ListRemove();
	int ListSize()const;
};



#endif
