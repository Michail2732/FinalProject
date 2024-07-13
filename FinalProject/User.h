#pragma once
#include <string>
#include <iostream>
#include "UserLogin.h"
using namespace std;

namespace FinalProject
{
	/// <summary>
	/// ����� ������������
	/// </summary>
	class User
	{
		private:
			/// <summary>
			/// �����
			/// </summary>
			string _login;
			/// <summary>
			/// ������
			/// </summary>
			string _password;
			/// <summary>
			/// ���
			/// </summary>
			string _name;
			/// <summary>
			/// ������� ����� ������������ � ���
			/// </summary>
			bool _isSignIn;
		public:
			/// <summary>
			/// �����������
			/// </summary>
			/// <param name="login">�����</param>
			/// <param name="password">������</param>
			/// <param name="name">���</param>
			User(string login, string password, string name);
			/// <summary>
			/// ������ ������
			/// </summary>
			/// <returns></returns>
			const string& GetLogin() const noexcept;
			/// <summary>
			/// ������ �����
			/// </summary>
			/// <returns></returns>
			const string& GetName() const noexcept;
			/// <summary>
			/// ������ �������� ����� � ���
			/// </summary>
			/// <returns></returns>
			bool GetIsSignIn() const noexcept;
			/// <summary>
			/// ��������� ������ ����� �� ������������ �������� ������������
			/// </summary>
			/// <param name="logData"></param>
			/// <returns></returns>
			bool TryLogin(UserLogin& logData) const noexcept;
			/// <summary>
			/// ������ �������� ����� � ���
			/// </summary>
			/// <param name="isSignIn"></param>
			void SetIsSignIn(bool isSignIn) noexcept;
			/// <summary>
			/// �������� ������ ������������ �� �������
			/// </summary>
			/// <param name="os"></param>
			/// <param name="message"></param>
			/// <returns></returns>
			friend ostream& operator<<(ostream& os, const User& user);
	};
}

