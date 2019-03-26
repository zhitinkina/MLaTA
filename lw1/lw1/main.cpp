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
#include <chrono>

std::vector<Dice> ReadDominos(const std::string & fileName)
{
	std::ifstream inputFile(fileName);
	if (!inputFile.is_open())
	{
		std::string exception = "File was not opened";
		std::cout << exception;
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

template <class T>
auto MeasureTime(T && fn)
{
	auto begin = std::chrono::high_resolution_clock::now();
	fn();
	auto end = std::chrono::high_resolution_clock::now();
	return (end - begin);
}

int main()
{
	std::ofstream outputFile("output.txt");
	if (!outputFile.is_open())
	{
		std::string exception = "File was not opened";
		std::cout << exception;
		return 1;
	}

	auto dominos = ReadDominos("input.txt");
	
	std::string result;
	auto time = MeasureTime([&result, &dominos]() {
		result = FindMax(dominos);
	});
	std::cerr << "runtime = "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(time).count()
		<< " ms" << std::endl;

	outputFile << result;
	
	return 0;
}
