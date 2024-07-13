#pragma once
#include "Chat.h"
#include "ChatException.h"

namespace FinalProject
{
	/// <summary>
	/// ���������� ���������� ����
	/// </summary>
	class ChatConsoleHandler
	{
		private:
			/// <summary>
			/// ��������� �� ���
			/// </summary>
			Chat* _chat;
			/// <summary>
			/// ���������� ����������� ������������
			/// </summary>
			void RegisterUserHandle();
			/// <summary>
			/// ���������� �������� ������������
			/// </summary>
			void UnregisterUserHandle();
			/// <summary>
			/// ���������� �������� ���������
			/// </summary>
			void SendMessageHandle();
			/// <summary>
			/// ���������� ����� � ���
			/// </summary>
			void SignInHandle();
			/// <summary>
			/// ���������� ������ �� ����
			/// </summary>
			void SignOutHandle();
			/// <summary>
			/// ������� ������ �������������
			/// </summary>
			void GetUsersHandle();
		public:
			/// <summary>
			/// �����������
			/// </summary>
			/// <param name="chat">��������� �� ���</param>
			ChatConsoleHandler(Chat* chat);
			/// <summary>
			/// ����������� �����������
			/// </summary>
			/// <param name="consoleHandler"></param>
			ChatConsoleHandler(const ChatConsoleHandler& consoleHandler) = delete;
			/// <summary>
			/// ����������
			/// </summary>
			~ChatConsoleHandler();
			/// <summary>
			/// ������ ����������� ����������� ����
			/// </summary>
			void Start();
	};
}
