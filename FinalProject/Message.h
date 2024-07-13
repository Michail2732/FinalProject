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
	/// ����� ���������
	/// </summary>
	class Message
	{
		private:
			/// <summary>
			/// ����� ���������
			/// </summary>
			string _text;
			/// <summary>
			/// ��� ����������� 
			/// </summary>
			string _from;
			/// <summary>
			/// ��� ����������
			/// </summary>
			string _to;
			/// <summary>
			/// ��������� ���������
			/// </summary>
			MessageState _state;
			/// <summary>
			/// ������� ������������������ ���������
			/// </summary>
			bool _isToAll;
		public:
			/// <summary>
			/// ����������� ��� ������������������ ���������
			/// </summary>
			/// <param name="text">����� ���������</param>
			/// <param name="from">��� �����������</param>
			Message(string& text, string& from);
			/// <summary>
			/// ����������� ��� p2p ���������
			/// </summary>
			/// <param name="text">����� ���������</param>
			/// <param name="from">�����������</param>
			/// <param name="to">����������</param>
			Message(string& text, string& from, string& to);
			/// <summary>
			/// ������ ������ ���������
			/// </summary>
			/// <returns></returns>
			const string& GetText() const noexcept;
			/// <summary>
			/// ������ �����������
			/// </summary>
			/// <returns></returns>
			const string& GetFrom() const noexcept;
			/// <summary>
			/// ������ ����������
			/// </summary>
			/// <returns></returns>
			const string& GetTo() const noexcept;
			/// <summary>
			/// ������ �������� ������������������ ���������
			/// </summary>
			/// <returns></returns>
			bool GetIsToAll() const noexcept;
			/// <summary>
			/// ������ ��������� ���������
			/// </summary>
			/// <returns></returns>
			MessageState GetState() const noexcept;
			/// <summary>
			/// ��������� ��������� �������� � ���������
			/// </summary>
			void AsRead();
			/// <summary>
			/// �������� ������ ��������� �� �������
			/// </summary>
			/// <param name="os"></param>
			/// <param name="message"></param>
			/// <returns></returns>
			friend ostream& operator<<(ostream& os, const Message& message);
	};
}

