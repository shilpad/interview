/*
 * main.cpp
 *
 *  Created on: Jul 11, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <list>
using namespace std;

void print_list (list<int> lst)
{
	for (list<int>::const_iterator cit = lst.begin(); cit != lst.end(); cit++)
		cout << *cit << ",";
}

/* Time complexity : O(2 ^ N/2 * N):
 * Split into 2 arbitrary lists : N/2 and each has 2^N/2 subsets
 * We traverse N numbers, so -> O(2^N/2 * N)
 */
void subset_sum_recursive(list<int> numbers, int target, std::list<int> partial)
{
		cout << "numbers....";
		print_list(numbers);

		cout << "partial....";
		print_list(partial);

		cout << "\n";

        int s = 0;
        for (list<int>::const_iterator cit = partial.begin(); cit != partial.end(); cit++)
        {
            s += *cit;
        }

        if(s == target)
        {
                cout << "sum([";

                for (list<int>::const_iterator cit = partial.begin(); cit != partial.end(); cit++)
                {
                    cout << *cit << ",";
                }
                cout << "])=" << target << std::endl;
        }
        if(s >= target)
            return;
        int n;
        for (std::list<int>::const_iterator ai = numbers.begin(); ai != numbers.end(); ai++)
        {
            n = *ai;
            std::list<int> remaining;
            for(std::list<int>::const_iterator aj = ai; aj != numbers.end(); aj++)
            {
                if(aj == ai)continue;
                remaining.push_back(*aj);
            }

            std::list<int> partial_rec=partial;
            partial_rec.push_back(n);
            subset_sum_recursive(remaining,target,partial_rec);
        }
}

void subset_sum(std::list<int> numbers,int target)
{
    subset_sum_recursive(numbers,target,std::list<int>());
}
int main()
{
    std::list<int> a;
    a.push_back (3);
    a.push_back (9);
    a.push_back (8);
    a.push_back (4);
    a.push_back (5);
    a.push_back (7);
    a.push_back (10);
    int n = 15;
    //std::cin >> n;
    subset_sum(a, n);
    return 0;
}


