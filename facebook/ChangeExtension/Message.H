#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "defs.H"
#include <string>

using namespace std;

class Message {
public:
    Message(string source, string subject, string content);
	Message();
    void Display(int num) const;
    void Read();
	bool isRead();
private:
    string source_;
	string subject_;
    string content_;
    bool   read_;
};



class MessageBox
{
public:
	MessageBox() :message_(NULL), next_(NULL) {};
	Message* message_;
	MessageBox* next_;
};

class ListMessage {
private:
	int currentSize_;
	MessageBox* firstNode_;
public:
	ListMessage() : currentSize_(0), firstNode_(NULL) {};
	//~ListMessage();
	void Add(Message* message);
	Result ListRemove();
	int Size()const;
	int UnreadSize()const;
	void Print()const;
	Result ReadMessage(int messageNum);
};



#endif
