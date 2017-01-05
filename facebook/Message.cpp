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

ListMessage::~ListMessage() {
	while (firstNode_ != NULL) {
		delete firstNode_->message_;
		MessageBox* tmpMessageBox = firstNode_;
		firstNode_ = firstNode_->next_;
		delete tmpMessageBox;
	}
	return;
}

void ListMessage::Add(Message* newMessage) {
	MessageBox* messageBox;
	messageBox = new MessageBox;
	messageBox->message_ = newMessage;
	messageBox->next_ = firstNode_;
	firstNode_ = messageBox;
	currentSize_++;
}

int ListMessage::Size() const {
	return currentSize_;
}

int ListMessage::UnreadSize() const {
	int count = 0;
	MessageBox* messageBox=firstNode_;
	while (messageBox)
	{
		if (messageBox->message_->isRead() == false)
			count++;
		messageBox = messageBox->next_;
	}
	return count;
}

void ListMessage::Print() const {
	int count = 1; //check if 1?
	MessageBox* messageBox = firstNode_;
	while (messageBox)
	{
		messageBox->message_->Display(count);
		count++;
		messageBox = messageBox->next_;
	}
}

Result ListMessage::ReadMessage(int messageNum) {
	MessageBox* messageBox = firstNode_;
	while (messageBox)
	{
		messageNum--;
		Message *curMessage = messageBox->message_;
		//If messageNum is 0, we get to the desired messege which should be read
		if (messageNum == 0) //check this!!!!
			READ_MESSAGE_SUCCESS
		messageBox = messageBox->next_;
	}
	return SUCCESS;
}