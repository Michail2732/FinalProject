#include "ChatException.h"

namespace FinalProject
{
	const char* ChatException::what() const noexcept
	{
		return "Chat exception";
	}
}

