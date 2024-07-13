#pragma once
#include <string>
#include <iostream>
#include "UserLogin.h"
using namespace std;

namespace FinalProject
{
	/// <summary>
	/// Класс пользователя
	/// </summary>
	class User
	{
		private:
			/// <summary>
			/// логин
			/// </summary>
			string _login;
			/// <summary>
			/// Пароль
			/// </summary>
			string _password;
			/// <summary>
			/// Имя
			/// </summary>
			string _name;
			/// <summary>
			/// Признак входа пользователя в чат
			/// </summary>
			bool _isSignIn;
		public:
			/// <summary>
			/// Конструктор
			/// </summary>
			/// <param name="login">логин</param>
			/// <param name="password">пароль</param>
			/// <param name="name">имя</param>
			User(string login, string password, string name);
			/// <summary>
			/// Геттер логина
			/// </summary>
			/// <returns></returns>
			const string& GetLogin() const noexcept;
			/// <summary>
			/// Геттер имени
			/// </summary>
			/// <returns></returns>
			const string& GetName() const noexcept;
			/// <summary>
			/// Геттер признака входа в чат
			/// </summary>
			/// <returns></returns>
			bool GetIsSignIn() const noexcept;
			/// <summary>
			/// проверить данные входа на соответствие текущему пользователя
			/// </summary>
			/// <param name="logData"></param>
			/// <returns></returns>
			bool TryLogin(UserLogin& logData) const noexcept;
			/// <summary>
			/// Сеттер признака входа в чат
			/// </summary>
			/// <param name="isSignIn"></param>
			void SetIsSignIn(bool isSignIn) noexcept;
			/// <summary>
			/// Оператор вывода пользователя на консоль
			/// </summary>
			/// <param name="os"></param>
			/// <param name="message"></param>
			/// <returns></returns>
			friend ostream& operator<<(ostream& os, const User& user);
	};
}

