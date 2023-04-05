#include "../../src/calls/call_parser.h"
#include "test_calls.h"

void
test_calls::test_reading_calls()
{
	calls::call_parser<helpers::CALLS_RECORD_SIZE> parser(helpers::CALLS);

	parser.parse();
	parser.write();
}
