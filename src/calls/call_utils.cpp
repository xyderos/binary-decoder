#include "call_utils.h"

#include <cctype>

#define NUMERIC_LIMIT 10

namespace calls::utils {

auto
is_valid(char ch) -> bool
{
	return isdigit(ch) || isalpha(ch);
}

auto
hex2int(char hex) -> int
{

	int val = 0;

	if (hex >= '0' && hex <= '9') {
		val = hex - '0';

	} else if (hex >= 'a' && hex <= 'f') {
		val = hex - 'a' + NUMERIC_LIMIT;

	} else if (hex >= 'A' && hex <= 'F') {
		val = hex - 'A' + NUMERIC_LIMIT;
	}

	return val;
}

}
