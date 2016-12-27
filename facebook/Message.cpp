#include <iostream>
#include "Message.H"


Message::Message(string source, string subject, string content) : source_(source), subject_(subject), content_(content), read_(false) {}

void Message::Display(int num) const
{
	cout << num << ") "<< (read_ ? "" : "(Unread) ") << "From: " << source_ << endl;
	cout << "Subject: " << subject_ << endl;
}

void Message::Read()
{
    read_ = true;
	cout << "From: " << source_ << endl;
	cout << "Subject: " << subject_ << endl;
	cout << "Content: " << content_ << endl;
}

bool Message::isRead()
{
	return read_;
}

MessageBox::MessageBox(){
	currentSize = 0;
	firstNode = NULL;
}
MessageBox::~MessageBox() {
	return;
}

void MessageBox::Add(Message newMessage) {
	MessageBox* messageBox;
	messageBox = new MessageBox;
	messageBox->message_ = newMessage;
	messageBox->next = firstNode;
	firstNode = messageBox;
	currentSize++;
}

int MessageBox::Size() {
	return currentSize
}
int MessageBox::UnreadSize();
void MessageBox::Print();
Result MessageBox::ReadMessage(int messageNum);