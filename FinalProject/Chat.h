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
	/// ����� ����
	/// </summary>
	class Chat
	{
		private:
			/// <summary>
			/// ������ ��������� ������������
			/// </summary>
			vector<UserAccount*> _userAccounts;
			/// <summary>
			/// ������� ������������
			/// </summary>
			User* _currentUser;
		public:
			/// <summary>
			/// �����������
			/// </summary>
			Chat();
			/// <summary>
			/// ����������� �����������
			/// </summary>
			Chat(const Chat& chat) = delete;			
			/// <summary>
			/// ����������
			/// </summary>
			~Chat();
			/// <summary>
			/// ���������� ����������� ��������� ������������
			/// </summary>
			/// <returns></returns>
			int GetUserAccountsSize() const noexcept;
			/// <summary>
			/// ���������� ��������� ������������
			/// </summary>
			/// <param name="index">������</param>
			/// <returns></returns>
			const UserAccount* operator[](int index) const throw();
			/// <summary>
			/// ���������������� ������������ � ����
			/// </summary>
			/// <param name="user"></param>
			/// <returns></returns>
			void RegisterUser(User* user) throw();
			/// <summary>
			/// ������� ������������ �� ����
			/// </summary>
			/// <param name="user"></param>
			/// <returns></returns>
			void UnregisterUser(string& username) throw();
			/// <summary>
			/// ����� � ���
			/// </summary>
			/// <param name="login"></param>
			/// <returns></returns>
			bool SignIn(UserLogin& login);
			/// <summary>
			/// ��������� ���������
			/// </summary>
			/// <param name="message"></param>
			void SendMessage(Message& message);
			/// <summary>
			/// ����� �� ����
			/// </summary>
			/// <returns></returns>
			void SignOut() throw();			
			/// <summary>
			/// �������� �������� ������������
			/// </summary>
			/// <returns></returns>
			User* GetCurrentUser() const noexcept;
			/// <summary>
			/// ����������  �������� 
			/// </summary>
			/// <returns></returns>
			UserAccount* GetCurrentUserAccount() throw();
	};

}

