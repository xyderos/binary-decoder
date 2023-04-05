#include "contact_utils.h"

#include <cctype>

#define DOT 0x2e

#define AT 40

static auto
is_dot(char ch) -> bool
{
	return ch == static_cast<char>(DOT);
}

static auto
is_at(char ch) -> bool
{
	return ch == static_cast<char>(AT);
}

namespace contacts::utils {

auto
is_email(char ch) -> bool
{
	return is_valid(ch) || is_dot(ch) || is_at(ch);
}

auto
is_valid(char ch) -> bool
{
	return isdigit(ch) || isalpha(ch);
}

}
