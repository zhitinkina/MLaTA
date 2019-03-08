/*1.6. Домино (7)
Имеется N костей игры домино. На каждой кости имеется два числа (каждое от 0 до 6).
Требуется написать программу, которая будет определять максимальное число,
составленное из цифр на костях цепочки, составленной по правилам домино из имеющихся костей.
Ввод. Первая строка входного файла содержит целое число N – количество костей (2 £ N £ 20).
Следующие N строк содержат два целых числа X и Y (0 £ X, Y £ 6), разделенные пробелом.
Вывод. В выходной файл необходимо вывести максимальное целое число,
цифры которого соответствуют значению костей в цепочке.

Житинкина Анна, ПС-21
*/

#include "Impl.hpp"

#include <iostream>

std::vector<Dice> ReadDominos(const std::string & fileName)
{
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		throw std::exception("File was not opened");
	}

	int diceNumber = 0;
	inputFile >> diceNumber;

	std::vector<Dice> dominos(diceNumber);
	for (auto & field : dominos)
	{
		inputFile >> field.first >> field.second;
	}
	return dominos;
}

int main()
{
	try
	{
		std::ofstream outputFile("output.txt");
		if (!outputFile.is_open())
		{
			throw std::exception("File was not opened");
		}

		auto dominos = ReadDominos("input.txt");
		outputFile << FindMax(dominos);
	}
	catch (const std::exception & ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
