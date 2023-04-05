#pragma once

#include <array>
#include <cstddef>

namespace calls::utils {

static const std::array<char, 8> DIALED_NOT_SAVED = { static_cast<char>(0xFF),
	0x00, static_cast<char>(0xFF), static_cast<char>(0xFF), 0x00, 0x00,
	0x00, 0x00 };

static const std::array<char, 8> MISSED_NOT_SAVED = { static_cast<char>(0xFF),
	0x02, static_cast<char>(0xFF), static_cast<char>(0xFF), 0x40, 0x00,
	0x04, 0x00 };

static const std::array<char, 8> RECEIVED_NOT_SAVED = { static_cast<char>(0xFF),
	0x02, static_cast<char>(0xFF), static_cast<char>(0xFF),
	static_cast<char>(0x80), 0x00, 0x00, 0x00 };

static const std::array<char, 2> DIALED_SAVED = { 0x06, 0x00 };

static const size_t TYPE_SIZE = 8;

static const size_t TYPE_OFFSET = 4;

static const size_t NAME_SIZE = 42;

static const size_t NAME_IN_CALLS_OFFSET = 16;

static const size_t DURATION_SIZE = 30;

static const size_t DURATION_OFFSET = 68;

static const size_t NUMBER_SIZE = 22;

static const size_t NUMBER_IN_CALLS_OFFSET = 58;

static const char SPACE = ' ';

auto is_valid(char ch) -> bool;

auto hex2int(char hex) -> int;

}
