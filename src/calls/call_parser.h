#pragma once

#include "../helpers/helpers.h"
#include "call_model.h"

#include <array>
#include <cstddef>
#include <ostream>
#include <utility>
#include <vector>

namespace calls {
template <size_t N> class call_parser {

	std::string input_file, output_file;
	std::vector<std::array<char, N>> calls;
	std::vector<call<N>> records;

	auto extract_records(const std::vector<std::array<char, N>> &data)
	    -> std::vector<calls::call<N>>
	{
		std::vector<calls::call<N>> result;

		for (auto e : data) {
			result.emplace_back(calls::call<N>(e));
		}

		return result;
	}

    public:
	explicit call_parser(std::string file_name_)
	    : input_file(std::move(file_name_))
	    , output_file(
		  input_file.substr(0, input_file.find('.')).append(".txt"))
	{
	}
	void parse()
	{

		this->calls = helpers::parse_file<N>(input_file);

		this->records = this->extract_records(this->calls);
	}

	void write()
	{

		std::ofstream out(output_file);

		for (const call<N> &e : records) {
			out << "Phone number: " << e.get_number()
			    << " Type of call: " << e.get_type()
			    << "Name of call: " << e.get_name() << std::endl;
		}

		out.close();
	}
};

}
