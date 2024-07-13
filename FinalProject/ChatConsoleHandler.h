#pragma once
#include "Chat.h"
#include "ChatException.h"

namespace FinalProject
{
	/// <summary>
	/// Консольный обработчик чата
	/// </summary>
	class ChatConsoleHandler
	{
		private:
			/// <summary>
			/// Указатель на чат
			/// </summary>
			Chat* _chat;
			/// <summary>
			/// Обработчик регистрации пользователя
			/// </summary>
			void RegisterUserHandle();
			/// <summary>
			/// Обработчик удаления пользователя
			/// </summary>
			void UnregisterUserHandle();
			/// <summary>
			/// Обработчик отправки сообщения
			/// </summary>
			void SendMessageHandle();
			/// <summary>
			/// Обработчик входа в чат
			/// </summary>
			void SignInHandle();
			/// <summary>
			/// Обработчик выхода из чата
			/// </summary>
			void SignOutHandle();
			/// <summary>
			/// Выводит список пользователей
			/// </summary>
			void GetUsersHandle();
		public:
			/// <summary>
			/// Конструктор
			/// </summary>
			/// <param name="chat">указатель на чат</param>
			ChatConsoleHandler(Chat* chat);
			/// <summary>
			/// Конструктор копирования
			/// </summary>
			/// <param name="consoleHandler"></param>
			ChatConsoleHandler(const ChatConsoleHandler& consoleHandler) = delete;
			/// <summary>
			/// Диструктор
			/// </summary>
			~ChatConsoleHandler();
			/// <summary>
			/// Запуск консольного обработчика чата
			/// </summary>
			void Start();
	};
}
