#pragma once

#include <array>
#include <fstream>
#include <iostream>
#include <vector>

namespace helpers {

static const std::string BINARIES = std::string("binaries");

static const std::string BIN = std::string(".bin");

static const std::string TXT = std::string(".txt");

static const std::string CALLS = std::string("data/Calls.bin");

static const std::string DETAILS = std::string("data/Phonebook_Details.bin");

static const std::string MAIN = std::string("data/Phonebook_Main.bin");

static const size_t CALLS_RECORD_SIZE = 106;

static const size_t PHONEBOOK_RECORD_SIZE = 232;

static const size_t PHONEBOOK_MAIN_SIZE = 86;

template <size_t N>
auto
parse_file(const std::string &file_name) -> std::vector<std::array<char, N>>
{
	std::ifstream in(file_name, std::ios::in | std::ios::binary);

	std::vector<std::array<char, N>> result;

	std::array<char, N> arr {};

	char ch = 0;

	size_t counter = 0;

	while (in.get(ch)) {

		if (counter == N) {

			result.emplace_back(arr);

			counter = 0;
		}
		arr.at(counter++) = ch;
	}

	in.close();

	return result;
}
template <size_t N, class T>
void
write_result(const std::vector<T> &data, const std::string &file_name)
{
	std::string newName = file_name.substr(0, file_name.find('.'));

	newName.append(".txt");

	std::ofstream out(newName);

	for (const auto &e : data) {
		T::write(e, &out);
	}

	out.close();
}

}
