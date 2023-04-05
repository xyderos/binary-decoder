#pragma once

#include "../helpers/helpers.h"
#include "contact_model.h"

#include <array>
#include <utility>

namespace contacts {

template <size_t M, size_t N> class contact_parser {

	std::vector<std::array<char, M>> main;
	std::string main_input, details_input, final_output;

	std::vector<std::array<char, N>> details;

	std::vector<contacts::contact<M, N>> records;

    public:
	contact_parser(std::string main_input_, std::string details_input_)
	    : main_input(std::move(main_input_))
	    , details_input(std::move(details_input_))
	    , final_output(
		  main_input.substr(0, main_input.find('.')).append(".txt"))

	{
	}
	void parse()
	{

		for (std::array<char, M> e :
		    helpers::parse_file<M>(main_input)) {
			this->main.emplace_back(e);
		}

		for (std::array<char, N> e :
		    helpers::parse_file<N>(details_input)) {
			this->details.emplace_back(e);
		}

		for (size_t i = 0; i < this->main.size(); i++) {
			this->records.emplace_back(
			    contacts::contact<M, N>(this->main.at(i),
				this->details.at(i)));
		}
	}

	void write()
	{

		std::ofstream out(final_output);

		for (const contact<M, N> &contact : this->records) {
			out << " NAME OF CONTACT: " << contact.get_name()
			    << " TELEPHONE OF CONTACT: " << contact.get_tel()
			    << " HOME PHONE NUMBER: " << contact.get_home()
			    << " WORK PHONE NUMBER: " << contact.get_work()
			    << " FAX  PHONE NUMBER: " << contact.get_fax()
			    << " ORG PHONE NUMBER:  " << contact.get_org()
			    << " EMAIL:" << contact.get_email()
			    << " DELETED: " << contact.get_deleted()
			    << std::endl;
		}

		out.close();
	}
};

}
