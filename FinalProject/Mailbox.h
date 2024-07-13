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
	/// Класс почтового ящика
	/// </summary>
	class Mailbox
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
			Mailbox(User* user);
			/// <summary>
			/// Конструктор копирования
			/// </summary>
			/// <param name="user">Пользователь</param>
			Mailbox(const Mailbox& mailbox) = delete;
			/// <summary>
			/// Диструктор
			/// </summary>
			~Mailbox();
			/// <summary>
			/// Геттер пользователя
			/// </summary>
			/// <returns></returns>
			const User* GetUser() const noexcept;
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