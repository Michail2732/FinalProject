#include "Mailbox.h"

namespace FinalProject
{
	Mailbox::Mailbox(User* user)
	{
		if (user == nullptr)
			throw ChatException();
		_user = user;

	}

	Mailbox::~Mailbox()
	{
		delete _user;
	}

	const User* Mailbox::GetUser() const noexcept
	{
		return _user;
	}

	void Mailbox::AddMessage(Message& message) throw()
	{
		_messages.push_back(message);
	}

	int Mailbox::MessagesCount() const noexcept
	{
		return _messages.size();
	}

	const Message& Mailbox::operator[](int index) const throw()
	{
		if (index < 0 || index >= _messages.size())
			throw out_of_range("Выход за пределы списка сообщений");
		return _messages[index];
	}
}
