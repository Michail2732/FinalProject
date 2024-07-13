#pragma once
#include <string>

using namespace std;

namespace FinalProject
{
	/// <summary>
	/// Класс для входа в чат
	/// </summary>
	class UserLogin
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
		public:
			/// <summary>
			/// Конструктор
			/// </summary>
			/// <param name="login">Логин</param>
			/// <param name="password">Пароль</param>
			UserLogin(string login, string password);
			/// <summary>
			/// Геттер логина
			/// </summary>
			/// <returns></returns>
			const string& GetLogin() const noexcept;
			/// <summary>
			/// Геттер пароля
			/// </summary>
			/// <returns></returns>
			const string& GetPassword() const noexcept;
	};
}

