#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace FinalProject
{
	enum class MessageState
	{
		New,
		Read,
	};

	/// <summary>
	/// Класс сообщения
	/// </summary>
	class Message
	{
		private:
			/// <summary>
			/// Текст сообщения
			/// </summary>
			string _text;
			/// <summary>
			/// Имя отправителя 
			/// </summary>
			string _from;
			/// <summary>
			/// Имя получателя
			/// </summary>
			string _to;
			/// <summary>
			/// Состояние сообщения
			/// </summary>
			MessageState _state;
			/// <summary>
			/// Признак широковещательного сообщения
			/// </summary>
			bool _isToAll;
		public:
			/// <summary>
			/// Конструктор для широковещательного сообщения
			/// </summary>
			/// <param name="text">Текст сообщения</param>
			/// <param name="from">Имя отправителя</param>
			Message(string& text, string& from);
			/// <summary>
			/// Конструктор для p2p сообщения
			/// </summary>
			/// <param name="text">Текст сообщения</param>
			/// <param name="from">Отправитель</param>
			/// <param name="to">Получатель</param>
			Message(string& text, string& from, string& to);
			/// <summary>
			/// Геттер текста сообщения
			/// </summary>
			/// <returns></returns>
			const string& GetText() const noexcept;
			/// <summary>
			/// Геттер отправителя
			/// </summary>
			/// <returns></returns>
			const string& GetFrom() const noexcept;
			/// <summary>
			/// Геттер получателя
			/// </summary>
			/// <returns></returns>
			const string& GetTo() const noexcept;
			/// <summary>
			/// Геттер признака широковещательного сообщения
			/// </summary>
			/// <returns></returns>
			bool GetIsToAll() const noexcept;
			/// <summary>
			/// Геттер состояния сообщения
			/// </summary>
			/// <returns></returns>
			MessageState GetState() const noexcept;
			/// <summary>
			/// Перевести состояние собщения в прочтённое
			/// </summary>
			void AsRead();
			/// <summary>
			/// Оператор вывода сообщения на консоль
			/// </summary>
			/// <param name="os"></param>
			/// <param name="message"></param>
			/// <returns></returns>
			friend ostream& operator<<(ostream& os, const Message& message);
	};
}

