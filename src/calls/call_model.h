#pragma once

#include "call_utils.h"

#include <array>
#include <cstddef>
#include <string>

namespace calls {
template <size_t N> class call {

	const std::array<char, N> record;

	std::string type;

	auto parse_type() -> std::string
	{
		std::array<char, calls::utils::TYPE_SIZE> temp {};

		std::array<char, 2> dialedAndSaved {};

		for (size_t i = 0; i < calls::utils::TYPE_SIZE; i++) {
			temp.at(i) = record.at(calls::utils::TYPE_OFFSET + i);
		}
		dialedAndSaved.at(0) = temp.at(0);
		dialedAndSaved.at(1) = temp.at(1);

		if (temp == calls::utils::DIALED_NOT_SAVED) {
			return { "WAS DIALED BUT NOT SAVED:" };
		} else if (temp == calls::utils::MISSED_NOT_SAVED) {
			return { "WAS MISSED BUT NOT SAVED:     " };
		} else if (temp == calls::utils::RECEIVED_NOT_SAVED) {
			return { "WAS RECEIVED BUT NOT SAVED:   " };
		} else if (dialedAndSaved == calls::utils::DIALED_SAVED) {
			return { "WAS DIALED AND SAVED AS:      " };
		} else {
			return { " " };
		}
	}

	std::string name;

	auto parse_name() -> std::string
	{
		std::array<char, calls::utils::NAME_SIZE> result {};

		for (size_t i = 0; i < calls::utils::NAME_SIZE; i++) {

			if (!calls::utils::is_valid(record.at(
				calls::utils::NAME_IN_CALLS_OFFSET + i))) {
				result.at(i) = calls::utils::SPACE;

			} else {
				result.at(i) = record.at(
				    calls::utils::NAME_IN_CALLS_OFFSET + i);
			}
		}
		return { std::begin(result), std::end(result) };
	}

	std::string number;

	auto parse_number() -> std::string
	{
		std::array<char, calls::utils::NUMBER_SIZE> result {};

		for (size_t i = 0; i < calls::utils::NUMBER_SIZE; i++) {

			if (!std::isdigit(record.at(
				calls::utils::NUMBER_IN_CALLS_OFFSET + i))) {
				result.at(i) = calls::utils::SPACE;

			} else {
				result.at(i) = record.at(
				    calls::utils::NUMBER_IN_CALLS_OFFSET + i);
			}
		}

		if (std::string(std::begin(result), std::end(result))
			.find(calls::utils::SPACE) != std::string::npos) {
			for (auto i = std::string(std::begin(result),
					  std::end(result))
					  .find(calls::utils::SPACE) +
				 1;
			     i < result.size(); i++) {
				result.at(i) = calls::utils::SPACE;
			}
		}

		return { std::begin(result), std::end(result) };
	}

	std::string duration;

	auto parse_duration() -> std::string
	{
		std::array<char, calls::utils::DURATION_SIZE + 1> result {};

		for (size_t i = 0; i <= calls::utils::DURATION_SIZE; i++) {
			result.at(i) = calls::utils::hex2int(
			    record.at(calls::utils::DURATION_OFFSET + i));
		}

		return { std::begin(result), std::end(result) };
	}

    public:
	explicit call(const std::array<char, N> &call_)
	    : record(call_)
	{
		this->name = parse_name();

		this->type = parse_type();

		this->duration = parse_duration();

		this->number = parse_number();
	}

	[[nodiscard]] auto get_type() const -> std::string
	{
		return this->type;
	}

	[[nodiscard]] auto get_name() const -> std::string
	{
		return this->name;
	}

	[[nodiscard]] auto get_number() const -> std::string
	{
		return this->number;
	}

	[[nodiscard]] auto get_duration() const -> std::string
	{
		return this->duration;
	}
};

}
