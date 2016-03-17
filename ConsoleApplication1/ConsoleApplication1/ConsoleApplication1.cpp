// ConsoleApplication1.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
using namespace std;

void thread1(int i)
{
	srand(time(NULL));
	for (int i = 0; i < 2; i++);
	{
		int time = (int)(abs(rand())) % 10;
		cerr << i << " time : " << time << endl;
		Sleep(time*1e3);
		
	}
}



class stack
{
	int m_tab[100];
	int m_pos;

public:
	stack() 
	{
		m_pos = 0;
	}
	void push(int i)
	{
		m_tab[m_pos] = i;
		m_pos++;
	}
	int& top()
	{
		return(m_tab[m_pos-1]);
	}
	int& pop()
	{
		m_pos--;
		return(m_tab[m_pos+1]);
	}

	void dump()
	{
		cout << "stack dump : " << m_pos << endl;
		for (int i = m_pos - 1; i >= 0; i--)
		{
			cout << m_tab[i] << endl;
			
		}
		cout << "end dump\n";
	}

};

stack s;





















int main()
{
	s.push(10);
	s.push(5);
	s.push(1);

	s.dump();

	s.top() = 42;

	s.dump();

	char c;
	cin >> c;

    return 0;
}