#pragma once
#include <string>

using namespace std;

namespace FinalProject
{
	class User
	{
		private:
			string _login;
			string _password;
			string _name;
			bool _isSignIn;
		public:
			User(string login, string password, string name);
			const string& GetLogin() const noexcept;
			const string& GetName() const noexcept;
			bool GetIsSignIn() const noexcept;
			void SetIsSignIn(bool isSignIn) noexcept;
	};
}

