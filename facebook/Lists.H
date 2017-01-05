#ifndef _LISTS_H_
#define _LISTS_H_
#include <string>
#include "defs.H"

using std::string;

class Follower;
class Leader;

class NodeFollower {
public:
	Follower* follower_;
	NodeFollower* next_;
	NodeFollower() : follower_(NULL), next_(NULL) {};
};
class ListFollower {
private:
	 NodeFollower* iterator_;
	 int currentSize_;
	 NodeFollower* firstNode_;
public:
	ListFollower() :iterator_(NULL), currentSize_(0), firstNode_(NULL) {};
	Follower* SetIteratorFirst();
	Follower* SetIteratorNext();
	Result ListAdd(Follower* follower);
	Follower* ReturnIteratorData()const;
	Result ListRemove();
	int ListSize()const;
};
class NodeLeader {
public:
	Leader* leader_;
	NodeLeader* next_;
	NodeLeader() : leader_(NULL), next_(NULL) {};
};
class ListLeader {
private:
	NodeLeader* iterator_;
	int currentSize_;
	NodeLeader* firstNode_;
public:
	ListLeader() :iterator_(NULL), currentSize_(0), firstNode_(NULL) {};
	Leader* SetIteratorFirst();
	Leader* SetIteratorNext();
	Result ListAdd(Leader* leader);
	Leader* ReturnIteratorData()const;
	Result ListRemove();
	int ListSize()const;
};

#endif
