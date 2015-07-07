/*
 * main.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: rudolpharaujo
 */
#include <stack>
#include <iostream>

using namespace std;

template <class T>
class MinStack
{
	private:
		stack<T> m_min;
		stack<T> m_data;
//		T m_least;

	public:
		void push (T element)
		{
			m_data.push (element);

			if (m_min.empty() || (element < m_min.top()))
				m_min.push (element);
		}

		bool pop ()
		{
			if (m_data.empty())
				return false;

			if (m_data.top() == m_min.top())
				m_min.pop();

			m_data.pop();

			return true;
		}

		bool min (T &element)
		{
			if (m_min.empty())
				return false;
			else
			{
				element = m_min.top();
				return true;
			}
		}
};

int main ()
{
	MinStack<int> objMinStack;

	objMinStack.push (-7);
	objMinStack.push (10);
	objMinStack.push (15);
	objMinStack.push (-2);
	objMinStack.push (-4);

	int min;

	objMinStack.min (min);
	cout << "Min=" << min << "\n";

	objMinStack.pop ();

	objMinStack.min (min);
	cout << "Min=" << min << "\n";


}
