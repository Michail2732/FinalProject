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
		cout << "Введите имя пользователя: ";
		cin >> name;		
		ClearConsoleBuffer();
		cout << "Введите логин пользователя: ";
		cin >> login;		
		ClearConsoleBuffer();
		cout << "Введите пароль пользователя: ";
		cin >> password;				

		User* newUser = new User(login, password, name);
		_chat->RegisterUser(newUser);
		cout << "Пользователь '" << name << "' зарегистрирован в чате!" << endl<<endl;
	}

	void ChatConsoleHandler::UnregisterUserHandle()
	{
		ClearConsoleBuffer();
		string userName;
		cout << "Введите имя пользователя: ";
		cin >> userName;		
		
		_chat->UnregisterUser(userName);		
		cout << "Пользователь успешно удалён!" << endl << endl;
	}

	void ChatConsoleHandler::SendMessageHandle()
	{		
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "Вы не вошли в чат!" << endl << endl;
			return;
		}			
		string to, text, from;
		cout << "Введите имя получателя (all - для отправки всем): ";
		cin >> to;		
		ClearConsoleBuffer();
		cout << "Введите текст сообщения (Не более 100 символов): " << endl;		
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
		cout << "Сообщение успешно отправлено!" << endl << endl;
	}

	void ChatConsoleHandler::GetMessagesHandler()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "Вы не вошли в чат!" << endl << endl;
			return;
		}
		cout << "Сообщения:" << endl;
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
			cout << "Вы не вошли в чат!" << endl;
			return;
		}
		cout << "Текущий пользователь: " << endl;
		cout << *_chat->GetCurrentUser() << endl;
	}

	void ChatConsoleHandler::SignInHandle()
	{
		ClearConsoleBuffer();
		string login, password;
		cout << "Введите логин: ";
		cin >> login;		
		cout << "Введите пароль: ";
		cin >> password;		
		UserLogin us{ login, password };
		if (_chat->SignIn(us))
			cout << "Вы успешно вошли в чат!" << endl << endl;
		else
			cout << "Неверный логин или пароль!" << endl << endl;
	}

	void ChatConsoleHandler::SignOutHandle()
	{
		if (_chat->GetCurrentUser() == nullptr)
		{
			cout << "Вы не вошли в чат!" << endl << endl;
			return;
		}
		_chat->SignOut();
		cout << "Вы успешно вышли из чата!" << endl << endl;
	}

	void ChatConsoleHandler::GetUsersHandle()
	{
		cout << "Список пользователей:" << endl;		
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
					cout << "\tmsgs - список сообщений пользователя" << endl;
					cout << "\tcrntu - текуший пользователь" << endl;
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
				else if (command == "msgs")
					GetMessagesHandler();
				else if (command == "crntu")
					GetCurrentUserHandler();
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

