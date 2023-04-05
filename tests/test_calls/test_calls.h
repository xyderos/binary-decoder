#include <cppunit/extensions/HelperMacros.h>

class test_calls : public CPPUNIT_NS::TestCase {

    private:
	CPPUNIT_TEST_SUITE(test_calls);
	CPPUNIT_TEST(test_reading_calls);
	CPPUNIT_TEST_SUITE_END();

    public:
	void setUp() override { }
	void tearDown() override { }

    protected:
	void test_reading_calls();
};

CPPUNIT_TEST_SUITE_REGISTRATION(test_calls);
