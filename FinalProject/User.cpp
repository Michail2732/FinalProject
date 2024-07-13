#include "User.h"
#include "UserLogin.h"

namespace FinalProject
{
    User::User(string login, string password, string name)
    {
        _login = login;
        _password = password;
        _name = name;
        _isSignIn = false;
    }

    const string& User::GetLogin() const noexcept
    {
        return _login;
    }

    const string& User::GetName() const noexcept
    {
        return _name;
    }

    bool User::GetIsSignIn() const noexcept
    {
        return _isSignIn;
    }

    bool User::TryLogin(UserLogin& logData) const noexcept
    {
        return _login == logData.GetLogin() && _password == logData.GetPassword();
    }

    void User::SetIsSignIn(bool isSignIn) noexcept
    {
        _isSignIn = isSignIn;                                                                                                                                                                     
    }
    ostream& operator<<(ostream& os, const User& user)
    {
        os << "Логин: " << user.GetLogin() << ", Имя: " << user.GetName()<<endl;
        return os;
    }
}
