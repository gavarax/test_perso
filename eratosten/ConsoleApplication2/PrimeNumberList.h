#pragma once
#include <mutex>
class PrimeNumberList :
	public std::list<int>
{
private : 
	iterator bigestPrimerNumber;
	const int largest;
	const int max_thread;
	int sharedCurrentThreadNumber;
	int idleThreadNumber;
	void thread_lauch();
	void threadClear();
	std::mutex lastPrimNumberMutex;
	std::mutex idleNotificationMutex;
	std::mutex cleaningMutex;
	std::condition_variable idleNotification;
	std::condition_variable cleaning;

public:
	PrimeNumberList(int Nmax);
	void process(int nb_threads);
	virtual ~PrimeNumberList();
	// trouve et suprime tout les nombres multiple du nombre donne en entree
	void markMultipleOf(int baseNumber);
	template<class Predicate>
	void remove_if_t(Predicate _Pred);
};

