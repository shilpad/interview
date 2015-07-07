/*
 * main.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: rudolpharaujo
 */
#include <stack>
#include <iostream>
using namespace std;

template <class T>
class Queue
{
	private:
		stack<T>	s_inbox;
		stack<T>	s_outbox;

	public:
		void my_enqueue (T data)
		{
			s_inbox.push(data);
		}

		T my_dequeu ()
		{
			T popped_val = 0;

			// pop from outbox
			// check if outbox is empty
			if (s_outbox.empty())
			{
				while (!s_inbox.empty())
				{
					int n = s_inbox.top();
					s_inbox.pop();
					s_outbox.push(n);
				}
			}

			if (!s_outbox.empty())
			{
				popped_val = s_outbox.top();
				s_outbox.pop();
			}

			return popped_val;
		}
};

int main ()
{
	Queue<int> objQ;
	objQ.my_enqueue(1);
	objQ.my_enqueue(2);
	objQ.my_enqueue(3);
	objQ.my_enqueue(4);
	objQ.my_enqueue(5);

	cout << "dequeue " << objQ.my_dequeu() << "\n";
	cout << "dequeue " << objQ.my_dequeu() << "\n";
	cout << "dequeue " << objQ.my_dequeu() << "\n";
	cout << "dequeue " << objQ.my_dequeu() << "\n";
	cout << "dequeue " << objQ.my_dequeu() << "\n";
	cout << "dequeue " << objQ.my_dequeu() << "\n";

}

