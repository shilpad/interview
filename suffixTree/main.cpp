/*
 * main.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class SuffixTreeNode
{
	private:
		unordered_map <char, SuffixTreeNode> children;
		char value;
		list<int> indexes;

	public:
		SuffixTreeNode() {};
		void insertString (string str, int index)
		{
			indexes.push_back (index);
			if (str.length() > 0)
			{
				value = str [0];
				SuffixTreeNode child;
				if (children.find (value) == children.end()) // not found in map
				{
					//child = new SuffixTreeNode();
					children [value] = child;
				}
				else
				{
					child = children [value];
				}

				string remainder = str.substr (1);
				insertString (remainder, index);
			}
		}

		list<int> search (string &str)
		{
			if (str.length() == 0)
				return indexes;
			else
			{
				char first = str[0];
				if (children.find (first) != children.end())
				{
					string remainder = str.substr (1);
					return (children[first].search(remainder));
				}
			}

			return list<int>();
		}
};

class SuffixTree
{
	private:
		SuffixTreeNode root;
	public:
		SuffixTree(string s)
		{
			for (int i = 0; i < s.length(); ++i)
			{
				string suffix = s.substr (i);
				root.insertString (suffix, i);
			}
		}

		list<int> search (string str);
};

list<int> SuffixTree::search (string str)
{
	return (root.search (str));
}

int main ()
{
	SuffixTree tree ("bibs");
	list<int> indexes = tree.search ("ib");

	for (list<int>::iterator it = indexes.begin(); it != indexes.end(); it++)
	{
		cout << *it << endl;
	}
}



