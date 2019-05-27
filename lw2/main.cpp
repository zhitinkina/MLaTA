#include <iostream>
#include <vector>

int main()
{
	unsigned M, N;
	std::cin >> M >> N;

	std::vector<std::vector<bool>> m(M + 2);
	for (unsigned i = 0; i < M + 2; ++i)
	{
		for (unsigned j = 0; j < N + 2; ++j)
		{
			m[i].emplace_back(N + 2);
			if (j == 0 || j == N + 1)
			{
				m[i][j] = false;
				continue;
			}

			char ch;
			std::cin >> ch;

			m[i][j] = ch == '*';
		}
	}
	std::rotate(m.rbegin(), m.rbegin() + 1, m.rend());
	for (unsigned j = 0; j < N + 2; ++j)
	{
		m[0][j] = m.back()[j] = false;
	}

	for (unsigned i = 1; i < M + 1; ++i)
	{
		for (unsigned j = 1; j < N + 1; ++j)
		{
			if (m[i][j])
			{
				std::cout << '*';
				continue;
			}
			std::cout << m[i + 1][j] + m[i][j + 1] + m[i + 1][j + 1] + m[i - 1][j] + m[i][j - 1] + m[i - 1][j - 1] + m[i - 1][j + 1] + m[i + 1][j - 1];
		}
		std::cout << std::endl;
	}
}
