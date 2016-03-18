#include "stdafx.h"
#include "PrimeNumberList.h"
#include <algorithm>
#include <thread>
#include <Windows.h>


using namespace std;
PrimeNumberList::PrimeNumberList(int Nmax) : std::list<int>(), largest(Nmax), max_thread(8), sharedCurrentThreadNumber(0),idleThreadNumber(0)
{
	for (int current = 2; current <= Nmax; current++)
	{
		push_back(current);
	}
	bigestPrimerNumber = begin();
}

void PrimeNumberList::thread_lauch()
{
	auto processed_number = -1;
	while (bigestPrimerNumber != end())
	{
		{
			unique_lock<mutex> l1(lastPrimNumberMutex); 
			if (bigestPrimerNumber != end())
			{
				processed_number = *bigestPrimerNumber;
				this->bigestPrimerNumber++;
			}
		}
	}
}

void PrimeNumberList::threadClear()
{
	
}

void PrimeNumberList::process(int nb_thread)
{
	thread threadArray[8];
	sharedCurrentThreadNumber = nb_thread;
	for (auto i = 0; i < nb_thread; i++)
	{
		threadArray[i] = thread{ &PrimeNumberList::thread_lauch, this };
	}

	for (auto i = 0; i < nb_thread; i++)
	{
		threadArray[i].join();
	}
	for_each(begin(), end(), [](auto i) {cout << i << endl; });
}



PrimeNumberList::~PrimeNumberList()
{

}

void PrimeNumberList::markMultipleOf(int baseNumber)
{
	if (baseNumber > 1)
	{
		remove_if_t([baseNumber](auto current)
		{return (current%baseNumber == 0 && current != baseNumber); });
	}
	
}


template<class Predicate>
void PrimeNumberList::remove_if_t(Predicate _Pred)
{
	for (auto current = bigestPrimerNumber; current != end() && *current <= largest; current++)
	{
		if (*current > 1 && _Pred(*current)) {
			*current = -1;
		}
	}
}