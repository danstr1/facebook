#include "SocialNetwork.H"
#include <iostream>







// General actions
void SocialNetwork::FindUser(string partialName)
{
	cout << "Followers:" << endl;
	// Loop over all followers in network
	for (int i = 0; ???????????????; ++i)
	{
		???????????????
		if (curFollower->GetName().find(partialName) != string::npos)
			cout << i + 1 << ") " << curFollower->GetName() << ": " << curFollower->GetEmail() << endl;
		???????????????
	}

	cout << "Leaders:" << endl;
	// Loop over all leaders in network
	for (int i = 0; ???????????????; ++i)
	{
		???????????????
		if (curLeader->GetName().find(partialName) != string::npos)
			cout << i + 1 << ") " << curLeader->GetName() << ": " << curLeader->GetEmail() << endl;
		???????????????
	}
}




