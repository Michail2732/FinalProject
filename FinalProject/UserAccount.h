#pragma once
#include <vector>
#include "Message.h"
#include "User.h"
#include "ChatException.h"
#include <exception>
#include <stdexcept>

using namespace std;

namespace FinalProject
{
	/// <summary>
	/// Класс аккаунта пользователя
	/// </summary>
	class UserAccount
	{
		private:
			/// <summary>
			/// Список сообщений
			/// </summary>
			vector<Message> _messages;
			/// <summary>
			/// Пользователь
			/// </summary>
			User* _user;
		public:
			/// <summary>
			/// Конструктор
			/// </summary>
			/// <param name="user">Пользователь</param>
			UserAccount(User* user);
			/// <summary>
			/// Конструктор копирования
			/// </summary>
			/// <param name="user">Пользователь</param>
			UserAccount(const UserAccount& mailbox) = delete;
			/// <summary>
			/// Диструктор
			/// </summary>
			~UserAccount();
			/// <summary>
			/// Геттер пользователя
			/// </summary>
			/// <returns></returns>
			const User* GetUser() const noexcept;
			/// <summary>
			/// Проверяет пренадлежит ли аккаунт пользователю
			/// </summary>
			/// <param name="user"></param>
			/// <returns></returns>
			bool IsAccountOwner(User* user);
			/// <summary>
			/// Добавить сообщение в ящик
			/// </summary>
			/// <param name="message">сообщение</param>
			/// <returns></returns>
			void AddMessage(Message& message) throw();			
			/// <summary>
			/// Колличество сообщений
			/// </summary>
			/// <returns></returns>
			int MessagesCount() const noexcept;
			/// <summary>
			/// Индексатор сообщений
			/// </summary>
			/// <param name="index"></param>
			/// <returns></returns>
			const Message& operator[](int index) const throw();
	};

}