#include <iostream>
#include "Message.H"

//************************************************************************
//*  Function name: Message
//*  Description: Message constructor
//*  Paramters: source- sender of the message
//*				subject- subject of the message
//*				content- content of the message
//*  Return value: constructed message with the input values.
//************************************************************************
Message::Message(string source, string subject, string content) : source_(source), subject_(subject), content_(content), read_(false) {}

//************************************************************************
//*  Function name: Display
//*  Description: Prints the message info.
//*  Paramters: num of the messsage to be printed.
//*  Return value: None.
//************************************************************************
void Message::Display(int num) const
{
	cout << num << ") " << (read_ ? "" : "(Unread) ") << "From: " << source_ << endl;
	cout << "Subject: " << subject_ << endl;
}

//************************************************************************
//*  Function name: Read.
//*  Description: marks the message as read and prints its information 
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
void Message::Read()
{
	read_ = true;
	cout << "From: " << source_ << endl;
	cout << "Subject: " << subject_ << endl;
	cout << "Content: " << content_ << endl;
}

//************************************************************************
//*  Function name: isRead
//*  Description: checks if the message was read
//*  Paramters: None.
//*  Return value: true if already read, false if not.
//************************************************************************
bool Message::isRead()
{
	return read_;
}

//************************************************************************
//*  Function name: ListRemove
//*  Description: Removes a node from the list who called the function.
//*  Paramters: None.
//*  Return value: SUCCESS if worked FAILURE otherwise
//************************************************************************
Result ListMessage::ListRemove() {
	while (firstNode_ != NULL) {
		MessageBox* tmp = firstNode_;
		firstNode_ = firstNode_->next_;
		delete tmp->message_;
		delete tmp;
	}
	return SUCCESS;
}

//************************************************************************
//*  Function name: Add
//*  Description: Adds a messageBox to the message list
//*  Paramters: newMessage- message to be added
//*  Return value: None.
//************************************************************************
void ListMessage::Add(Message* newMessage) {
	MessageBox* messageBox;
	messageBox = new MessageBox;
	messageBox->message_ = newMessage;
	messageBox->next_ = firstNode_;
	firstNode_ = messageBox;
	currentSize_++;
}

//************************************************************************
//*  Function name: Size
//*  Description: returns the size of the given list.
//*  Paramters: None.
//*  Return value: size of the given list.
//************************************************************************
int ListMessage::Size() const {
	return currentSize_;
}

//************************************************************************
//*  Function name: UnreadSize
//*  Description: checks the number of unread messages
//*  Paramters: None.
//*  Return value: count- number of unread messages
//************************************************************************
int ListMessage::UnreadSize() const {
	int count = 0;
	MessageBox* messageBox = firstNode_;
	while (messageBox)
	{
		if (messageBox->message_->isRead() == false)
			count++;
		messageBox = messageBox->next_;
	}
	return count;
}

//************************************************************************
//*  Function name: Print
//*  Description: Prints the messages in the given list
//*  Paramters: None.
//*  Return value: None.
//************************************************************************
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

//************************************************************************
//*  Function name: ReadMessage
//*  Description: marks the wanted messages as read.
//*  Paramters: messageNum-number of the message we want to read.
//*  Return value: return SUCCESS if worked FAILURE if didnt.
//************************************************************************
Result ListMessage::ReadMessage(int messageNum) {
	MessageBox* messageBox = firstNode_;
	while (messageBox)
	{
		messageNum--;
		Message *curMessage = messageBox->message_;
		//If messageNum is 0, we get to the desired messege which should be read
		if (messageNum == 0) { //check this!!!!
			READ_MESSAGE_SUCCESS;
			//curMessage->Read=true;
		}
		messageBox = messageBox->next_;
	}
	return SUCCESS;
}