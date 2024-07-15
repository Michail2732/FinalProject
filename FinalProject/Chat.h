#pragma once
#include <vector>
#include "User.h"
#include "UserLogin.h"
#include "Message.h"
#include "UserAccount.h"
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
			/// Список аккаунтов пользователя
			/// </summary>
			vector<UserAccount*> _userAccounts;
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
			/// Возвращает колличество аккаунтов пользователя
			/// </summary>
			/// <returns></returns>
			int GetUserAccountsSize() const noexcept;
			/// <summary>
			/// индексатор аккаунтов пользователя
			/// </summary>
			/// <param name="index">индекс</param>
			/// <returns></returns>
			const UserAccount* operator[](int index) const throw();
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
			/// <summary>
			/// Возвращает  текущего 
			/// </summary>
			/// <returns></returns>
			UserAccount* GetCurrentUserAccount() throw();
	};

}

