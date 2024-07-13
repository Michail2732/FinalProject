#pragma once
#include <string>

using namespace std;

namespace FinalProject
{
	/// <summary>
	/// ����� ��� ����� � ���
	/// </summary>
	class UserLogin
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
		public:
			/// <summary>
			/// �����������
			/// </summary>
			/// <param name="login">�����</param>
			/// <param name="password">������</param>
			UserLogin(string login, string password);
			/// <summary>
			/// ������ ������
			/// </summary>
			/// <returns></returns>
			const string& GetLogin() const noexcept;
			/// <summary>
			/// ������ ������
			/// </summary>
			/// <returns></returns>
			const string& GetPassword() const noexcept;
	};
}

