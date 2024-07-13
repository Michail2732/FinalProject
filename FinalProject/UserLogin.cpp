#include "UserLogin.h"
#include "exception"
#include <stdexcept>


using namespace std;

FinalProject::UserLogin::UserLogin(string login, string password)
{
    if (login.empty() || password.empty())
        throw invalid_argument("Incorrect login data");
    _login = login;
    _password = password;
}

const string& FinalProject::UserLogin::GetLogin() const noexcept
{
    return _login;
}

const string& FinalProject::UserLogin::GetPassword() const noexcept
{
    return _password;
}
