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
	/// ����� ��������� �����
	/// </summary>
	class Mailbox
	{
		private:
			/// <summary>
			/// ������ ���������
			/// </summary>
			vector<Message> _messages;
			/// <summary>
			/// ������������
			/// </summary>
			User* _user;
		public:
			/// <summary>
			/// �����������
			/// </summary>
			/// <param name="user">������������</param>
			Mailbox(User* user);
			/// <summary>
			/// ����������� �����������
			/// </summary>
			/// <param name="user">������������</param>
			Mailbox(const Mailbox& mailbox) = delete;
			/// <summary>
			/// ����������
			/// </summary>
			~Mailbox();
			/// <summary>
			/// ������ ������������
			/// </summary>
			/// <returns></returns>
			const User* GetUser() const noexcept;
			/// <summary>
			/// �������� ��������� � ����
			/// </summary>
			/// <param name="message">���������</param>
			/// <returns></returns>
			void AddMessage(Message& message) throw();			
			/// <summary>
			/// ����������� ���������
			/// </summary>
			/// <returns></returns>
			int MessagesCount() const noexcept;
			/// <summary>
			/// ���������� ���������
			/// </summary>
			/// <param name="index"></param>
			/// <returns></returns>
			const Message& operator[](int index) const throw();
	};

}