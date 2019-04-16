#include "pch.h"

#include "../lw1/Impl.hpp"

BOOST_AUTO_TEST_SUITE(FindMaxValue_)

BOOST_AUTO_TEST_CASE(_)
{
	{
		std::vector<Dice> dominos = {
			{1, 6},
			{0, 0},
			{2, 5}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "61");
	}

	{
		std::vector<Dice> dominos = {
			{6, 6},
			{3, 6}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "6663");
	}

	{
		std::vector<Dice> dominos = {
			{1, 5},
			{3, 4},
			{4, 1},
			{1, 6},
			{1, 0}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "611443");
	}

	{
		std::vector<Dice> dominos = {
			{1, 1},
			{0, 5},
			{0, 5},
			{2, 5},
			{1, 4}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "500552");
	}

	{
		std::vector<Dice> dominos = {
			{0, 0},
			{1, 0},
			{1, 0},
			{0, 0},
			{4, 2},
			{2, 3}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "10000001");
	}

	{
		std::vector<Dice> dominos = {
			{0, 2},
			{0, 0},
			{5, 5},
			{4, 4},
			{2, 2},
			{2, 2},
			{4, 6},
			{1, 3},
			{5, 5},
			{2, 4},
			{5, 5},
			{3, 5},
			{1, 5}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "64444222222000");
	}

	{
		std::vector<Dice> dominos = {
			{3, 4},
			{0, 4},
			{3, 3},
			{0, 2},
			{4, 6},
			{2, 2},
			{0, 6},
			{0, 1},
			{0, 6},
			{6, 6},
			{0, 5},
			{6, 6},
			{1, 5},
			{4, 5},
			{4, 6},
			{1, 1}
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "333446666664400660055111100222");
	}

	{
		std::vector<Dice> dominos = {
			{0, 0},
			{0, 0},
			{0, 0},
			{0, 0},
			{0, 0},
		};
		BOOST_CHECK_EQUAL(FindMax(dominos), "0");
	}
}

BOOST_AUTO_TEST_SUITE_END()
