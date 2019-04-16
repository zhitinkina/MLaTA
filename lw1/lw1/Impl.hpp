#include <string>
#include <vector>
#include <fstream>
#include <optional>

struct Dice
{
	Dice(int first, int second)
		:first(first)
		,second(second)
	{}

	Dice() = default;
	int first = 0;
	int second = 0;
	bool isProcessed = false;
};

std::string FindMaxImpl(std::vector<Dice> & dominos, std::optional<int> last);

void ProcessDiceImpl(std::vector<Dice> & dominos, const int & first, const int & second, bool & isProcessed, std::string & result) {
	auto tmp = std::to_string(first) + std::to_string(second);

	isProcessed = true;
	tmp += FindMaxImpl(dominos, second);
	isProcessed = false;

	if (result.size() == tmp.size() ? result < tmp : result.size() < tmp.size())
	{
		result = move(tmp);
	}
}

void ProcessDice(std::vector<Dice> & dominos, const int & first, const int & second, bool & isProcessed, std::string & result, const std::optional<int> & last)
{
	if (!isProcessed && (!last.has_value() || first == last))
	{
		ProcessDiceImpl(dominos, first, second, isProcessed, result);
	}
}

std::string FindMaxImpl(std::vector<Dice> & dominos, std::optional<int> last = std::nullopt)
{
	std::string result;
	for (auto & dice : dominos)
	{
		ProcessDice(dominos, dice.first, dice.second, dice.isProcessed, result, last);
		ProcessDice(dominos, dice.second, dice.first, dice.isProcessed, result, last);
	}
	
	return result;
}

std::string FindMax(std::vector<Dice> & dominos, std::optional<int> last = std::nullopt)
{
	return [](const std::string & str) {
		std::string result;
		result.reserve(str.size());
		bool needProcessZero = false;

		for (auto ch : str)
		{
			if (ch == '0' && !needProcessZero)
			{
				continue;
			}
			needProcessZero = true;
			result += ch;
		}
		return result.empty() ? "0" : result;
	}(FindMaxImpl(dominos, last));
}
