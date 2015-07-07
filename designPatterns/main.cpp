/*
 * main.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <stddef.h>
using namespace std;

class Singleton
{
private:
	static Singleton *ptr;
protected:
	Singleton () {};
public:
	static Singleton* getInstance ();
};

Singleton *Singleton::ptr = NULL;

Singleton* Singleton::getInstance ()
{
	if (ptr == NULL)
		ptr = new Singleton ();

	return ptr;
}

class Shape
{
private:
	int height;
	int width;
public:
	virtual void getArea () = 0;
};

class Square: public Shape
{
private:
public:
	Square ()
	{
		cout << "Square constructor\n";
	}

	void getArea ()
	{
		cout << "In Square Area \n";
	}

};

enum CardType {POKER, BLACKJACK};

class CardGame
{
	public:
		CardGame () {};
		void deal() {};
};

class Poker: public CardGame
{
	public:
		Poker ()
		{
			cout << "In Poker !\n";
		};

		void deal ()
		{
			cout << "Dealing cards for Poker\n";
		};
};

class BlackJack: public CardGame
{
	public:
		BlackJack ()
		{
			cout << "In BlackJack !\n";
		};

		void deal ()
		{
			cout << "Dealing cards for BlackJack\n";
		};
};

class CardGameFactory
{
public:
	 CardGame *createCardGame (CardType type)
	{
		if (type == POKER)
			return (new Poker());
		else if (type == BLACKJACK)
			return (new BlackJack());
	}
};


int main ()
{
	//Singleton *ptr = Singleton::getInstance ();

	// Abstract class
	Square objSq;
	Shape *obj = &objSq;
	obj->getArea ();

	// Factory method
	CardGameFactory factory;
	factory.createCardGame (BLACKJACK);
}

