#pragma once
#include <exception>

using namespace std;

namespace FinalProject
{
	/// <summary>
	/// ���������� ����
	/// </summary>
	class ChatException: public exception
	{
		public:
			virtual const char* what() const noexcept override;
	};
}

