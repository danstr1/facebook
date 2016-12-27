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

Message::Message() {
	return;
}

MessageBox::MessageBox(){
	message_ = NULL;
	currentSize = 0;
	firstNode = NULL;
	next_ = NULL;
}

MessageBox::~MessageBox() {
	return;
}

void MessageBox::Add(Message newMessage) {
	MessageBox* messageBox;
	messageBox = new MessageBox;
	messageBox->message_ = newMessage;
	messageBox->next_ = firstNode_;
	firstNode_ = messageBox;
	currentSize++;
}

int MessageBox::Size() const {
	return currentSize_;
}

int MessageBox::UnreadSize() const {
	int count = 0;
	MessageBox* messageBox=firstNode;
	while (messageBox)
	{
		if (messageBox->message_.isRead() == false)
			count++;
		messageBox = messageBox->next;
	}
	return count;
}

void MessageBox::Print() const {
	int count = 0; //check if 1?
	MessageBox* messageBox = firstNode;
	while (messageBox)
	{
		messageBox->message_.Display(count);
		count++;
		messageBox = messageBox->next;
	}
}

Result MessageBox::ReadMessage(int messageNum) {
	MessageBox* messageBox = firstNode;
	while (messageBox)
	{
		messageBox--;
		//If messageNum is 0, we get to the desired messege which should be read
		if (messageNum == 0) //check this!!!!
			messageBox->message_.Read();
		messageBox = messageBox->next;
	}
}