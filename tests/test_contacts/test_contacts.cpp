#include "../../src/contacts/contact_parser.h"
#include "../../src/helpers/helpers.h"
#include "test_contacts.h"

void
test_contacts::test_reading_contacts()
{
	contacts::contact_parser<helpers::PHONEBOOK_MAIN_SIZE,
	    helpers::PHONEBOOK_RECORD_SIZE>
	    parser(helpers::MAIN, helpers::DETAILS);

	parser.parse();
	parser.write();
}
