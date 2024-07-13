#pragma once
#include <vector>
#include "User.h"
#include "UserLogin.h"
#include "Message.h"
#include "Mailbox.h"
#include "ChatException.h"

using namespace std;

namespace FinalProject
{
	/// <summary>
	/// Класс чата
	/// </summary>
	class Chat
	{
		private:
			/// <summary>
			/// Список почтовых ящиков
			/// </summary>
			vector<Mailbox*> _mailBoxes;
			/// <summary>
			/// Текущий пользователь
			/// </summary>
			User* _currentUser;
		public:
			/// <summary>
			/// Конструктор
			/// </summary>
			Chat();
			/// <summary>
			/// Конструктор копирования
			/// </summary>
			Chat(const Chat& chat) = delete;			
			/// <summary>
			/// Диструктор
			/// </summary>
			~Chat();
			/// <summary>
			/// Возвращает колличество почтовых ящиков
			/// </summary>
			/// <returns></returns>
			int GetMailboxSize() const noexcept;
			/// <summary>
			/// индексатор почтовых ящиков
			/// </summary>
			/// <param name="index">индекс</param>
			/// <returns></returns>
			const Mailbox* operator[](int index) const throw();
			/// <summary>
			/// Зарегистрировать пользователя в чате
			/// </summary>
			/// <param name="user"></param>
			/// <returns></returns>
			void RegisterUser(User* user) throw();
			/// <summary>
			/// Удалить пользователя из чата
			/// </summary>
			/// <param name="user"></param>
			/// <returns></returns>
			void UnregisterUser(string& username) throw();
			/// <summary>
			/// Войти в чат
			/// </summary>
			/// <param name="login"></param>
			/// <returns></returns>
			bool SignIn(UserLogin& login);
			/// <summary>
			/// Отправить сообщение
			/// </summary>
			/// <param name="message"></param>
			void SendMessage(Message& message);
			/// <summary>
			/// Выйти из чата
			/// </summary>
			/// <returns></returns>
			void SignOut() throw();			
			/// <summary>
			/// Получить текущего пользователя
			/// </summary>
			/// <returns></returns>
			User* GetCurrentUser() const noexcept;
	};

}

