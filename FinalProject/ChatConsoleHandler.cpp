#include "ChatConsoleHandler.h"


namespace FinalProject
{
	void ChatConsoleHandler::RegisterUserHandle()
	{
		char needBreak;
		string login, password, name;		
		cout << "Введите имя пользователя: ";
		cin >> name;
		cout << "Введите логин пользователя: ";
		cin >> login;
		cout << "Введите пароль пользователя: ";
		cin >> password;		

		User* newUser = new User(login, password, name);
		_chat->RegisterUser(newUser);
		
	}

	void ChatConsoleHandler::UnregisterUserHandle()
	{

		string userName;
		cout << "Введите имя пользователя: ";
		cin >> userName;
		
		_chat->UnregisterUser(userName);		
	}

	void ChatConsoleHandler::SendMessageHandle()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "Для отправки сообщений нужно войти в чат" << endl;
			return;
		}			
		string to, text, from;
		cout << "Введите имя получателя (all - для отправки всем)";
		cin >> to;
		cout << "Введите текст сообщения: " << endl;
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
		cout << "Введите логин: ";
		cin >> login;
		cout << "Введите пароль: ";
		cin >> password;
		UserLogin us{ login, password };
		_chat->SignIn(us);
	}

	void ChatConsoleHandler::SignOutHandle()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "Вы не вошли в чат!" << endl;
			return;
		}
		_chat->SignOut();
	}

	void ChatConsoleHandler::GetUsersHandle()
	{
		cout << "Список пользователей" << endl;		
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
		cout << "Добро пожаловать в чат!" << endl;
		cout << "help - список команд" << endl;
		cout << "exit - выйти из программы" << endl;
		while (true)
		{
			string command;
			try
			{
				cin >> command;
				if (command == "help")
				{
					cout << "\tusers - Вывести список пользователей" << endl;
					cout << "\treg - зарегистрировать пользователя" << endl;
					cout << "\tunreg - удалить пользователя" << endl;
					cout << "\tsignin - войти в чат" << endl;
					cout << "\tsignout - выйти из чата" << endl;
					cout << "\tsend - отправить сообщение" << endl;
				}
				else if (command == "exit")
				{
					cout << "Досвидания" << endl;
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
					cout << "Неизвестная команда!" << endl;
			}
			catch (const ChatException& e)
			{
				cout << e.what();
			}
			catch (const std::exception& e)
			{
				cout << "Произошла непредвиденная ошибка!" << endl;
				cout << e.what();
			}
		}

	}


}

