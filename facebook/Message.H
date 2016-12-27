#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "defs.H"
#include <string>

using namespace std;

class Message {
public:
    Message(string source, string subject, string content);
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
	MessageBox();
	~MessageBox();
	void Add(Message newMessage);
	int Size()const;
	int UnreadSize()const;
	void Print()const;
	Result ReadMessage(int messageNum);

private:
	Message message_;
	MessageBox* next_;
	//static MessageBox* iterator;
	static int currentSize_;
	static MessageBox* firstNode_;
};

#endif
