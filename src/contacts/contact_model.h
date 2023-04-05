#pragma once

#include "contact_utils.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <string>
#include <vector>

namespace contacts {
template <size_t M, size_t N> class contact {

	std::array<char, M> main;
	const std::array<char, N> detail;

	std::string name;
	auto parse_name() -> std::string
	{
		std::array<char, contacts::utils::NAME_IN_CONTACTS_SIZE>
		    result {};

		for (size_t i = 0; i < contacts::utils::NAME_IN_CONTACTS_SIZE;
		     i++) {

			if (!contacts::utils::is_valid(main.at(
				contacts::utils::NAME_IN_CONTACTS_OFFSET +
				i))) {
				result.at(i) = contacts::utils::SPACE;

			} else {
				result.at(i) = main.at(
				    contacts::utils::NAME_IN_CONTACTS_OFFSET +
				    i);
			}
		}
		return { std::begin(result), std::end(result) };
	}

	std::string tel;
	auto parse_tel() -> std::string
	{
		std::array<char, contacts::utils::NUMBER_SIZE> result {};

		for (size_t i = 0; i < contacts::utils::NUMBER_SIZE; i++) {

			if (!contacts::utils::is_valid(
				main.at(contacts::utils::TEL_OFFSET + i))) {
				result.at(i) = contacts::utils::SPACE;

			} else {
				result.at(i) = main.at(
				    contacts::utils::TEL_OFFSET + i);
			}
		}

		if (std::string(std::begin(result), std::end(result))
			.find(contacts::utils::SPACE) != std::string::npos) {
			for (auto i = std::string(std::begin(result),
					  std::end(result))
					  .find(contacts::utils::SPACE) +
				 1;
			     i < result.size(); i++) {
				result.at(i) = contacts::utils::SPACE;
			}
		}

		return { std::begin(result), std::end(result) };
	}

	std::string fax;
	auto parse_fax() -> std::string
	{
		std::array<char, contacts::utils::NUMBER_SIZE> result {};

		for (size_t i = 0; i < contacts::utils::NUMBER_SIZE; i++) {

			if (!contacts::utils::is_valid(
				detail.at(contacts::utils::FAX_OFFSET + i))) {
				result.at(i) = contacts::utils::SPACE;

			} else {
				result.at(i) = detail.at(
				    contacts::utils::FAX_OFFSET + i);
			}
		}

		if (std::string(std::begin(result), std::end(result))
			.find(contacts::utils::SPACE) != std::string::npos) {
			for (auto i = std::string(std::begin(result),
					  std::end(result))
					  .find(contacts::utils::SPACE) +
				 1;
			     i < result.size(); i++) {
				result.at(i) = contacts::utils::SPACE;
			}
		}

		return { std::begin(result), std::end(result) };
	}

	std::string home;
	auto parse_home() -> std::string
	{
		std::array<char, contacts::utils::NUMBER_SIZE> result {};

		for (size_t i = 0; i < contacts::utils::NUMBER_SIZE; i++) {

			if (!contacts::utils::is_valid(
				detail.at(contacts::utils::HOME_OFFSET + i))) {
				result.at(i) = contacts::utils::SPACE;

			} else {
				result.at(i) = detail.at(
				    contacts::utils::HOME_OFFSET + i);
			}
		}

		if (std::string(std::begin(result), std::end(result))
			.find(contacts::utils::SPACE) != std::string::npos) {
			for (auto i = std::string(std::begin(result),
					  std::end(result))
					  .find(contacts::utils::SPACE) +
				 1;
			     i < result.size(); i++) {
				result.at(i) = contacts::utils::SPACE;
			}
		}

		return { std::begin(result), std::end(result) };
	}

	std::string work;
	auto parse_work() -> std::string
	{
		std::array<char, contacts::utils::NUMBER_SIZE> result {};

		for (size_t i = 0; i < contacts::utils::NUMBER_SIZE; i++) {

			if (!contacts::utils::is_valid(
				detail.at(contacts::utils::WORK_OFFSET + i))) {
				result.at(i) = contacts::utils::SPACE;

			} else {
				result.at(i) = detail.at(
				    contacts::utils::WORK_OFFSET + i);
			}
		}

		if (std::string(std::begin(result), std::end(result))
			.find(contacts::utils::SPACE) != std::string::npos) {
			for (auto i = std::string(std::begin(result),
					  std::end(result))
					  .find(contacts::utils::SPACE) +
				 1;
			     i < result.size(); i++) {
				result.at(i) = contacts::utils::SPACE;
			}
		}

		return { std::begin(result), std::end(result) };
	}

	std::string email;
	auto parse_email() -> std::string
	{
		std::array<char, contacts::utils::MAIL_SIZE> result {};

		for (size_t i = 0; i < contacts::utils::MAIL_SIZE; i++) {
			result.at(i) = detail.at(
			    contacts::utils::MAIL_OFFSET + i);
		}

		if (std::string(std::begin(result), std::end(result))
			.find(".com") != std::string::npos) {
			return { std::begin(result), std::end(result) };

		} else if (std::string(std::begin(result), std::end(result))
			       .find('.') != std::string::npos) {

			auto found = std::string(std::begin(result),
					 std::end(result))
					 .find('.') +
			    3;

			for (auto i = found; i < result.size(); i++) {
				result.at(i) = ' ';
			}
		}

		else if (std::string(std::begin(result), std::end(result))
			     .find('@') == std::string::npos) {
			for (auto &el : result) {
				el = ' ';
			}
		}

		//std::replace(std::begin(result), std::end(result), '\0', ' ');

		return { std::begin(result), std::end(result) };
	}

	std::string org;
	auto parse_org() -> std::string
	{

		std::array<char, contacts::utils::ORG_SIZE> result {};

		for (size_t i = 0; i < contacts::utils::ORG_SIZE; i++) {

			if (!contacts::utils::is_valid(
				detail.at(contacts::utils::ORG_OFFSET + i))) {
				result.at(i) = contacts::utils::SPACE;

			} else {
				result.at(i) = detail.at(
				    contacts::utils::ORG_OFFSET + i);
			}
		}
		return { std::begin(result), std::end(result) };
	}

	std::string deleted;
	auto parse_deleted() -> std::string
	{
		std::array<char, 1> result {};

		result.at(0) = main.at(contacts::utils::DELETED_OFFSET);

		return result.at(0) ==
			static_cast<char>(contacts::utils::DELETED) ?
		    "deleted" :
		    "not deleted";
	}

    public:
	contact(const std::array<char, M> &main_,
	    const std::array<char, N> &detail_)
	    : main(main_)
	    , detail(detail_)
	{
		this->tel = parse_tel();
		this->name = parse_name();
		this->email = parse_email();
		this->fax = parse_fax();
		this->home = parse_home();
		this->org = parse_org();
		this->work = parse_work();
		this->deleted = parse_deleted();
	}

	[[nodiscard]] auto get_name() const -> std::string
	{
		return this->name;
	}

	[[nodiscard]] auto get_tel() const -> std::string { return this->tel; }

	[[nodiscard]] auto get_home() const -> std::string
	{
		return this->home;
	}

	[[nodiscard]] auto get_work() const -> std::string
	{
		return this->work;
	}

	[[nodiscard]] auto get_fax() const -> std::string { return this->fax; }

	[[nodiscard]] auto get_org() const -> std::string { return this->org; }

	[[nodiscard]] auto get_email() const -> std::string
	{
		return this->email;
	}

	[[nodiscard]] auto get_deleted() const -> std::string
	{
		return this->deleted;
	}
};
}
