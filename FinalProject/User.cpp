#include "User.h"

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

    void User::SetIsSignIn(bool isSignIn) noexcept
    {
        _isSignIn = isSignIn;                                                                                                                                                                     
    }
}
