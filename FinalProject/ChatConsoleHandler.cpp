#include "ChatConsoleHandler.h"


namespace FinalProject
{
	void ClearConsoleBuffer()
	{
		if (std::cin.fail()) 		
			std::cin.clear();		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	void ChatConsoleHandler::RegisterUserHandle()
	{		
		ClearConsoleBuffer();
		string login, password, name;		
		cout << "������� ��� ������������: ";
		cin >> name;		
		ClearConsoleBuffer();
		cout << "������� ����� ������������: ";
		cin >> login;		
		ClearConsoleBuffer();
		cout << "������� ������ ������������: ";
		cin >> password;				

		User* newUser = new User(login, password, name);
		_chat->RegisterUser(newUser);
		cout << "������������ '" << name << "' ��������������� � ����!" << endl<<endl;
	}

	void ChatConsoleHandler::UnregisterUserHandle()
	{
		ClearConsoleBuffer();
		string userName;
		cout << "������� ��� ������������: ";
		cin >> userName;		
		
		_chat->UnregisterUser(userName);		
		cout << "������������ ������� �����!" << endl << endl;
	}

	void ChatConsoleHandler::SendMessageHandle()
	{		
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "�� �� ����� � ���!" << endl << endl;
			return;
		}			
		string to, text, from;
		cout << "������� ��� ���������� (all - ��� �������� ����): ";
		cin >> to;		
		ClearConsoleBuffer();
		cout << "������� ����� ��������� (�� ����� 100 ��������): " << endl;		
		getline(cin, text, '\n');
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
		cout << "��������� ������� ����������!" << endl << endl;
	}

	void ChatConsoleHandler::GetMessagesHandler()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "�� �� ����� � ���!" << endl << endl;
			return;
		}
		cout << "���������:" << endl;
		UserAccount* userAccount = _chat->GetCurrentUserAccount();
		for (int i = 0; i < userAccount->MessagesCount(); i++)
		{
			cout << (*userAccount)[i];
		}
		cout << endl;
	}

	void ChatConsoleHandler::GetCurrentUserHandler()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "�� �� ����� � ���!" << endl;
			return;
		}
		cout << "������� ������������: " << endl;
		cout << *_chat->GetCurrentUser() << endl;
	}

	void ChatConsoleHandler::SignInHandle()
	{
		ClearConsoleBuffer();
		string login, password;
		cout << "������� �����: ";
		cin >> login;		
		cout << "������� ������: ";
		cin >> password;		
		UserLogin us{ login, password };
		if (_chat->SignIn(us))
			cout << "�� ������� ����� � ���!" << endl << endl;
		else
			cout << "�������� ����� ��� ������!" << endl << endl;
	}

	void ChatConsoleHandler::SignOutHandle()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "�� �� ����� � ���!" << endl << endl;
			return;
		}
		_chat->SignOut();
		cout << "�� ������� ����� �� ����!" << endl << endl;
	}

	void ChatConsoleHandler::GetUsersHandle()
	{
		cout << "������ �������������:" << endl;		
		for (int i = 0; i < _chat->GetUserAccountsSize(); i++)
		{
			cout << *((*_chat)[i]->GetUser());
		}
		cout << endl;
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
		system("chcp 1251");
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
					cout << "\tmsgs - ������ ��������� ������������" << endl;
					cout << "\tcrntu - ������� ������������" << endl;
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
				else if (command == "msgs")
					GetMessagesHandler();
				else if (command == "crntu")
					GetCurrentUserHandler();
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

