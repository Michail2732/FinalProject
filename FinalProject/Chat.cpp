#include "Chat.h"
#include "ChatException.h"

namespace FinalProject
{
	Chat::Chat()
	{
		_mailBoxes = vector<Mailbox*>();
		_currentUser = nullptr;
	}	

	Chat::~Chat()
	{
		for (int i = 0; i < _mailBoxes.size(); i++)
		{
			delete _mailBoxes[i];
		}
		_mailBoxes.clear();		
	}

	int Chat::GetMailboxSize() const noexcept
	{
		return _mailBoxes.size();
	}

	const Mailbox* Chat::operator[](int index) const throw()
	{
		if (index < 0 || index >= _mailBoxes.size())
			throw out_of_range("¬ыход за пределы списка почтовых €щиков");
		return _mailBoxes[index];
	}


	void Chat::RegisterUser(User* user) throw()
	{
		for (int i = 0; i < _mailBoxes.size(); i++)
		{
			if ((*_mailBoxes[i]).GetUser()->GetName() == user->GetName())
				throw ChatException();
		}
		_mailBoxes.push_back(new Mailbox(user));		
	}

	void Chat::UnregisterUser(string& username) throw()
	{

		for (auto iter { _mailBoxes.begin()}; iter != _mailBoxes.end(); ++iter)
		{
			if ((*iter)->GetUser()->GetName() == username)
			{
				_mailBoxes.erase(iter);
				return;
			}				
		}
		throw ChatException();		
	}

	bool Chat::SignIn(UserLogin& login)
	{				
		for (int i = 0; i < _mailBoxes.size(); i++)
		{			
			if (_mailBoxes[i]->GetUser()->TryLogin(login))
			{				
				_currentUser = (User*)_mailBoxes[i]->GetUser();
				return true;
			}
		}		
		return false;
	}

	void Chat::SendMessage(Message& message)
	{
		if (_currentUser == nullptr)
			throw ChatException();
		if (message.GetIsToAll())
		{
			for (int i = 0; i < _mailBoxes.size(); i++)			
				_mailBoxes[i]->AddMessage(message);										
		}
		else
		{
			for (int i = 0; i < _mailBoxes.size(); i++)
			{
				if (_mailBoxes[i]->GetUser()->GetName() == message.GetTo())
					_mailBoxes[i]->AddMessage(message);
			}
		}			
	}

	void Chat::SignOut() throw()
	{
		_currentUser = nullptr;
	}


	User* Chat::GetCurrentUser() const noexcept
	{
		return _currentUser;
	}

}
