// ConsoleApplication2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "PrimeNumberList.h"
#include <chrono>


int f(int i)
{
	std::cout << "lol\n";
	return i;
}

int main()
{
	for (auto i = 1; i < 8; i++)
	{
		PrimeNumberList lol(100);
		std::chrono::time_point<std::chrono::system_clock> start, end;

		start = std::chrono::system_clock::now();
		std::cout << "start : " << i << " threads"<< std::endl;
		lol.process(i);
		end = std::chrono::system_clock::now();

		auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>
			(end - start).count();

		std::cout << "elapsed time: " << elapsed_seconds << "s\n";
		system("PAUSE");
	}
	return 0;
}

