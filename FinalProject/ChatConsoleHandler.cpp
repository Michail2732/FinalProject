#include "ChatConsoleHandler.h"


namespace FinalProject
{
	void ChatConsoleHandler::RegisterUserHandle()
	{
		char needBreak;
		string login, password, name;		
		cout << "������� ��� ������������: ";
		cin >> name;
		cout << "������� ����� ������������: ";
		cin >> login;
		cout << "������� ������ ������������: ";
		cin >> password;		

		User* newUser = new User(login, password, name);
		_chat->RegisterUser(newUser);
		
	}

	void ChatConsoleHandler::UnregisterUserHandle()
	{

		string userName;
		cout << "������� ��� ������������: ";
		cin >> userName;
		
		_chat->UnregisterUser(userName);		
	}

	void ChatConsoleHandler::SendMessageHandle()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "��� �������� ��������� ����� ����� � ���" << endl;
			return;
		}			
		string to, text, from;
		cout << "������� ��� ���������� (all - ��� �������� ����)";
		cin >> to;
		cout << "������� ����� ���������: " << endl;
		cin >> text;
					
		from = _chat->GetCurrentUser()->GetName();
		if (to == "all")
		{
			Message m{ text, from };
			_chat->SendMessage(m);
		}
		else
		{
			Message m{ text, from, to };
			_chat->SendMessage(m);
		}					
	}

	void ChatConsoleHandler::SignInHandle()
	{
		string login, password;
		cout << "������� �����: ";
		cin >> login;
		cout << "������� ������: ";
		cin >> password;
		UserLogin us{ login, password };
		_chat->SignIn(us);
	}

	void ChatConsoleHandler::SignOutHandle()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "�� �� ����� � ���!" << endl;
			return;
		}
		_chat->SignOut();
	}

	void ChatConsoleHandler::GetUsersHandle()
	{
		cout << "������ �������������" << endl;		
		for (int i = 0; i < _chat->GetMailboxSize(); i++)
		{
			cout << *((*_chat)[i]->GetUser()) << endl;
		}
	}

	ChatConsoleHandler::ChatConsoleHandler(Chat* chat)
	{
		if (chat == nullptr)
			throw ChatException();
		_chat = chat;
	}	

	ChatConsoleHandler::~ChatConsoleHandler()
	{
		delete _chat;
	}	

	void ChatConsoleHandler::Start()
	{
		setlocale(LC_ALL, "");
		cout << "����� ���������� � ���!" << endl;
		cout << "help - ������ ������" << endl;
		cout << "exit - ����� �� ���������" << endl;
		while (true)
		{
			string command;
			try
			{
				cin >> command;
				if (command == "help")
				{
					cout << "\tusers - ������� ������ �������������" << endl;
					cout << "\treg - ���������������� ������������" << endl;
					cout << "\tunreg - ������� ������������" << endl;
					cout << "\tsignin - ����� � ���" << endl;
					cout << "\tsignout - ����� �� ����" << endl;
					cout << "\tsend - ��������� ���������" << endl;
				}
				else if (command == "exit")
				{
					cout << "����������" << endl;
					break;
				}
				else if (command == "users")
					GetUsersHandle();
				else if (command == "reg")
					RegisterUserHandle();
				else if (command == "unreg")
					UnregisterUserHandle();
				else if (command == "signin")
					SignInHandle();
				else if (command == "signout")
					SignOutHandle();
				else if (command == "send")
					SendMessageHandle();
				else
					cout << "����������� �������!" << endl;
			}
			catch (const ChatException& e)
			{
				cout << e.what();
			}
			catch (const std::exception& e)
			{
				cout << "��������� �������������� ������!" << endl;
				cout << e.what();
			}
		}

	}


}

