#include "Chat.h"
#include "ChatException.h"

namespace FinalProject
{
	Chat::Chat()
	{
		_userAccounts = vector<UserAccount*>();
		_currentUser = nullptr;
	}	

	Chat::~Chat()
	{
		for (int i = 0; i < _userAccounts.size(); i++)
		{
			delete _userAccounts[i];
		}
		_userAccounts.clear();		
	}

	int Chat::GetUserAccountsSize() const noexcept
	{
		return _userAccounts.size();
	}

	const UserAccount* Chat::operator[](int index) const throw()
	{
		if (index < 0 || index >= _userAccounts.size())
			throw out_of_range("Выход за пределы списка почтовых ящиков");
		return _userAccounts[index];
	}


	void Chat::RegisterUser(User* user) throw()
	{
		for (int i = 0; i < _userAccounts.size(); i++)
		{
			if ((*_userAccounts[i]).GetUser()->GetName() == user->GetName())
				throw ChatException();
		}
		_userAccounts.push_back(new UserAccount(user));		
	}

	void Chat::UnregisterUser(string& username) throw()
	{

		for (auto iter { _userAccounts.begin()}; iter != _userAccounts.end(); ++iter)
		{
			if ((*iter)->GetUser()->GetName() == username)
			{
				_userAccounts.erase(iter);
				return;
			}				
		}
		throw ChatException();		
	}

	bool Chat::SignIn(UserLogin& login)
	{				
		for (int i = 0; i < _userAccounts.size(); i++)
		{			
			if (_userAccounts[i]->GetUser()->TryLogin(login))
			{				
				_currentUser = (User*)_userAccounts[i]->GetUser();
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
			for (int i = 0; i < _userAccounts.size(); i++)			
				_userAccounts[i]->AddMessage(message);										
		}
		else
		{
			for (int i = 0; i < _userAccounts.size(); i++)
			{
				if (_userAccounts[i]->GetUser()->GetName() == message.GetTo())
					_userAccounts[i]->AddMessage(message);
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

	UserAccount* Chat::GetCurrentUserAccount() throw()
	{
		if (_currentUser == nullptr)
			return nullptr;
		for (int i = 0; i < _userAccounts.size(); i++)
		{
			if (_userAccounts[i]->IsAccountOwner(_currentUser))
				return _userAccounts[i];
		}
		throw logic_error("Ошибка логики работы программы");
	}

}
