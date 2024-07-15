#include "UserAccount.h"

namespace FinalProject
{
	UserAccount::UserAccount(User* user)
	{
		if (user == nullptr)
			throw ChatException();
		_user = user;

	}

	UserAccount::~UserAccount()
	{
		delete _user;
	}

	const User* UserAccount::GetUser() const noexcept
	{
		return _user;
	}

	bool UserAccount::IsAccountOwner(User* user)
	{
		if (user == nullptr)
			return false;
		return _user->GetName() == user -> GetName();
	}

	void UserAccount::AddMessage(Message& message) throw()
	{
		_messages.push_back(message);
	}

	int UserAccount::MessagesCount() const noexcept
	{
		return _messages.size();
	}

	const Message& UserAccount::operator[](int index) const throw()
	{
		if (index < 0 || index >= _messages.size())
			throw out_of_range("Выход за пределы списка сообщений");
		return _messages[index];
	}
}
