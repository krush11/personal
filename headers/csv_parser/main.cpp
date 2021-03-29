#include <cstddef>
#include <string>
// #include <string_view>
#include <vector>
#include "parser.hpp"

#define BOOST_TEST_MODULE CSV competency
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first_test)
{
	csv parser;
	std::string raw_row;
	std::vector<std::string> row;
	std::size_t row_size;

	raw_row = "abc,def";
	row_size = parser.parse(raw_row, raw_row.size());
	BOOST_TEST(row_size == 0);

	raw_row = "abc,def,ghi\n1,2";
	row_size = parser.parse(raw_row, raw_row.size());
	BOOST_TEST(row_size == std::string("abc,def,ghi\n").size());

	row = parser.parse_columns(raw_row);

	BOOST_TEST(row == (std::vector<std::string>{"abc", "def", "ghi"}));
	raw_row = parser.remove_prefix(raw_row, row_size);

	row_size = parser.parse(raw_row.data(), raw_row.size());
	BOOST_TEST(row_size == 0);
	BOOST_TEST(raw_row == "1,2");
}
