#include "Message.h"

namespace FinalProject
{
	Message::Message(string& text, string& from)
	{
		_text = text;
		_from = from;
		_to = "";
		_state = MessageState::New;
		_isToAll = true;
	}

	Message::Message(string& text, string& from, string& to)
	{
		_text = text;
		_from = from;
		_to = to;
		_state = MessageState::New;
		_isToAll = false;
	}

	const string& Message::GetText() const noexcept
	{
		return _text;
	}

	const string& Message::GetFrom() const noexcept
	{
		return _from;
	}

	const string& Message::GetTo() const noexcept
	{
		return _to;
	}

	bool Message::GetIsToAll() const noexcept
	{
		return _isToAll;
	}

	MessageState Message::GetState() const noexcept
	{
		return _state;
	}

	void Message::AsRead()
	{
		_state = MessageState::Read;
	}

	ostream& operator<<(ostream& os, const Message& message)
	{
		os << "------------------------"<<endl;
		os << "Отправитель: " << message.GetFrom() << endl << "Получатель: " << message.GetTo() << endl
			<< "Сообщение: " << endl << message.GetText() << endl;
		os << "------------------------" << endl;
		return os;
	}

}