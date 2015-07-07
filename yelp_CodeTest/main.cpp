/*
 * main.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: shilpadharmadhikari
 */

/* Using State Design Pattern:
- 	class Order serves as the "state machine" from the client's perspective. That class is the "wrapper" class.
- 	State base class replicates the methods of the state machine interface. Each method takes one additional
	parameter: an instance of the wrapper class. The State base class specifies any useful "default" behavior.
-  	There are classes derived from State class for each Order state. These derived classes only override the methods they need to override.
-  	The wrapper Order class maintains a "current" State object.
-   All client requests to Order class are delegated to the current State object, and the wrapper object's this pointer is passed.
-   The State methods change the "current" state in the wrapper object as appropriate.
*/

#include <iostream>
#include <set>
#include "json.hh"

using namespace std;
using namespace JSON;

class Order;

class State
{
	public:
		virtual ~State () {};

		virtual bool newOrder (Order *order);
		virtual bool cooking (Order *order);
		virtual bool delivering (Order *order);
		virtual bool delivered (Order *order);
		virtual bool refunded (Order *order);
		virtual bool canceled (Order *order);
};

class Order
{
	private:
		State *m_ptrCurrentState;

		int noOfNewOrders;
		int noOfOrdersDelivered;
		int noOfOrdersDelivering;
		int noOfOrdersCooking;
		int noOfOrdersRefunded;
		int noOfOrdersCanceled;
		int amount;

		set<int>  updateIds;
		string status;

	public:
		Order ();
		void cleanUp ();

		bool process (Value v, bool bAmount);
		void setCurrentState (State *s);

		bool newOrder ();
		bool cooking ();
		bool delivering ();
		bool delivered ();
		bool refunded ();
		bool canceled ();

		bool isValid (int updateId);

		// getters and setters
		void incrNewOrders () {++noOfNewOrders;}
		void decrNewOrders () {--noOfNewOrders;}
		int getNewOrders () { return noOfNewOrders;}

		void incrCooking () {++noOfOrdersCooking;}
		void decrCooking () {--noOfOrdersCooking;}
		int getCooking () {return noOfOrdersCooking;}

		void incrDelivering () {++noOfOrdersDelivering;}
		void decrDelivering () {--noOfOrdersDelivering;}
		int getDelivering () {return noOfOrdersDelivering;}

		void incrDelivered () {++noOfOrdersDelivered;}
		void decrDelivered () {--noOfOrdersDelivered;}
		int getDelivered () {return noOfOrdersDelivered;}

		void incrRefunded () {++noOfOrdersRefunded;}
		void decrRefunded () {--noOfOrdersRefunded;}
		int getRefunded () { return noOfOrdersRefunded;}

		void incrCanceled () {++noOfOrdersCanceled;}
		void decrCanceled () {--noOfOrdersCanceled;}
		int getCanceled () {return noOfOrdersCanceled;}

		double getAmount () {return amount;}
		string getStatus () {return status;}
};

bool State::newOrder (Order *order)
{
	cerr << " already new" << endl;
	return false;
}

bool State::cooking (Order *order)
{
	cerr << " already Cooking" << endl;
	return false;
}

bool State::delivering (Order *order)
{
	cerr << " already Delivering" << endl;
	return false;
}

bool State::delivered (Order *order)
{
	cerr << " already Delivered" << endl;
	return false;
}

bool State::refunded (Order *order)
{
	cerr << " already Refunded" << endl;
	return false;
}

bool State::canceled (Order *order)
{
	cerr << " already Canceled" << endl;
	return false;
}

class Canceled: public State
{
	public:
		virtual ~Canceled () {};
};

class Refunded: public State
{
	public:
		virtual ~Refunded() {};

		bool canceled (Order *order)
		{
			cerr << "Err: Cannot go to state Canceled from state Refunded!\n";
			return false;
		}
};

class Delivered: public State
{
	public:
		virtual ~Delivered () {};

		bool refunded (Order *order)
		{
			order->decrDelivered();
			order->incrRefunded();
			order->setCurrentState(new Refunded());
			delete this;
			return true;
		}

		bool canceled (Order *order)
		{
			cerr << "Err: Cannot go to state Canceled from state Delivered!\n";
			return false;
		}
};

class Delivering: public State
{
	public:
		virtual ~Delivering() {};
		bool delivered (Order *order)
		{
			order->decrDelivering();
			order->incrDelivered();
			order->setCurrentState(new Delivered());
			delete this;
			return true;
		}

		bool canceled (Order *order)
		{
			order->incrCanceled();
			order->decrDelivering();
			order->setCurrentState (new Canceled());
			delete this;
			return true;
		}

		bool refunded (Order *order)
		{
			cerr << "Err: Cannot go to state refunded from state Delivering!\n";
			return false;
		}
};

class Cooking: public State
{
	public:
		virtual ~Cooking () {};

		bool delivering (Order *order)
		{
			order->decrCooking();
			order->incrDelivering();
			order->setCurrentState(new Delivering());
			delete this;
			return true;
		}

		bool canceled (Order *order)
		{
			order->incrCanceled();
			order->decrCooking();
			order->setCurrentState (new Canceled());
			delete this;
			return true;
		}

		bool delivered (Order *order)
		{
			cerr << "Err: Cannot go to state delivered from state Cooking!\n";
			return false;
		}

		bool refunded (Order *order)
		{
			cerr << "Err: Cannot go to state refunded from state Cooking!\n";
			return false;
		}
};

class NewOrder: public State
{
	public:
		virtual ~NewOrder () {};

		bool cooking (Order *order)
		{
			order->decrNewOrders ();
			order->incrCooking();
			order->setCurrentState(new Cooking());
			delete this;
			return true;
		}

		bool canceled (Order *order)
		{
			order->incrCanceled();
			order->decrNewOrders ();
			order->setCurrentState (new Canceled());
			delete this;
			return true;
		}

		bool delivering (Order *order)
		{
			cerr << "Err: Cannot go to state delivering from state New!\n";
			return false;
		}

		bool delivered (Order *order)
		{
			cerr << "Err: Cannot go to state delivered from state New!\n";
			return false;
		}

		bool refunded (Order *order)
		{
			cerr << "Err: Cannot go to state refunded from state New!\n";
			return false;
		}
};

class Start: public State
{
	public:
		virtual ~Start () {};

		bool newOrder (Order *order)
		{
			order->incrNewOrders ();
			order->setCurrentState (new NewOrder());
			delete this;
			return true;
		}

		bool cooking (Order *order)
		{
			cerr << "Err: Cannot go to state cooking without going to New!\n";
			return false;
		}

		bool delivering (Order *order)
		{
			cerr << "Err: Cannot go to state delivering without going to New!\n";
			return false;
		}

		bool delivered (Order *order)
		{
			cerr << "Err: Cannot go to state delivered without going to New!\n";
			return false;
		}

		bool refunded (Order *order)
		{
			cerr << "Err: Cannot go to state refunded without going to New!\n";
			return false;
		}

		bool canceled (Order *order)
		{
			cerr << "Err: Cannot go to state canceled without going to New!\n";
			return false;
		}
};


Order::Order () :noOfNewOrders (0), noOfOrdersDelivered(0), noOfOrdersDelivering(0), noOfOrdersCooking(0),
		noOfOrdersRefunded (0), noOfOrdersCanceled(0), amount(0)
{
	m_ptrCurrentState = new Start ();
}

void Order::cleanUp ()
{
	delete m_ptrCurrentState;
}
bool Order::newOrder ()
{
	return (m_ptrCurrentState->newOrder(this));
}

bool Order::process (Value v, bool bAmountPassed)
{
	Object obj = v.operator JSON::Object() ;

	int updateId = obj["updateId"].as_int();
	updateIds.insert (updateId);

	// route order
	status = obj["status"].as_string();
	bool bSuccess = false;

	if (status == "NEW")
	{
		if (bAmountPassed)
			amount += obj["amount"].as_int();

		bSuccess = newOrder ();
	}
	else if (status == "COOKING")
		bSuccess = cooking ();
	else if (status == "DELIVERING")
		bSuccess = delivering ();
	else if (status == "DELIVERED")
		bSuccess = delivered ();
	else if (status == "CANCELED")
	{
		bSuccess = canceled();
		if (bSuccess)
			amount = 0;
	}
	else if (status == "REFUNDED")
		bSuccess = refunded ();

	if (bSuccess == false)
		updateIds.erase (updateId);

	return bSuccess;
}

void Order::setCurrentState (State *s)
{
	m_ptrCurrentState = s;
}

bool Order::cooking ()
{
	return (m_ptrCurrentState->cooking(this));
}

bool Order::delivering ()
{
	return (m_ptrCurrentState->delivering(this));
}

bool Order::delivered ()
{
	return (m_ptrCurrentState->delivered(this));
}

bool Order::refunded ()
{
	return (m_ptrCurrentState->refunded(this));
}

bool Order::canceled ()
{
	return (m_ptrCurrentState->canceled(this));
}

bool Order::isValid (int updateId)
{
	// check duplicate updateId
	if (updateIds.find (updateId) != updateIds.end())
		return false;

	// check if this updateId is greater than the previous
	if (!updateIds.empty())
	{
		int lastUpdateId = *updateIds.rbegin();
		if (updateId < lastUpdateId)
			return false;
	}

	return true;
}

void aggregateSummary (map <int, Order> mapOrders)
{
	int noOfNewOrders = 0;
	int noOfOrdersDelivered = 0;
	int noOfOrdersDelivering = 0;
	int noOfOrdersCooking = 0;
	int noOfOrdersRefunded = 0;
	int noOfOrdersCanceled = 0;
	int totalAmount = 0;

	map <int, Order>::iterator it = mapOrders.begin ();
	for (; it != mapOrders.end(); ++it)
	{
		noOfNewOrders += (it->second).getNewOrders();
		noOfOrdersDelivered += (it->second).getDelivered();
		noOfOrdersDelivering += (it->second).getDelivering();
		noOfOrdersCooking += (it->second).getCooking();
		noOfOrdersCanceled += (it->second).getCanceled();
		noOfOrdersRefunded += (it->second).getRefunded();

		if ((it->second).getStatus() != "NEW" && (it->second).getStatus() != "REFUNDED" && (it->second).getStatus() != "CANCELED")
			totalAmount += (it->second).getAmount ();
	}

	cout << "New: " << noOfNewOrders << endl;
	cout << "Cooking: " << noOfOrdersCooking << endl;
	cout << "Delivering: " << noOfOrdersDelivering << endl;
	cout << "Delivered: " << noOfOrdersDelivered << endl;
	cout << "Canceled: " << noOfOrdersCanceled << endl;
	cout << "Refunded: " << noOfOrdersRefunded << endl;
	cout << "Total amount charged: $" << totalAmount << endl;
}

bool validateOrder (Object obj, bool &bAmount)
{
	// Check number of fields
	if (obj.size () < 3)
	{
		cerr << "Err: Skipping order since it is not valid - does not have the orderId, status and updateId mandatory fields!\n";
		return false;
	}

	int reqdFields = 0;
	bool bNew = false;

	map<string, Value>::iterator it = obj.begin ();
	for (; it != obj.end(); ++it)
	{
		if (it->first == "orderId" || it->first == "updateId" || it->first == "status")
		{
			++reqdFields;

			if (it->first == "status")
			{
				Value status = it->second;
				if (status.as_string() == "NEW")
					bNew = true;
			}
			else if (it->first == "orderId")
			{
				// This will also take care of cases where orderId is alphanumeric
				int id = (it->second).as_int();
				if (id == 0)
				{
					cerr << "Err: Skipping order since it is not valid - invalid orderId !\n";
					return false;
				}
			}
			else if (it->first == "updateId")
			{
				// This will also take care of cases where updateId is alphanumeric
				int id = (it->second).as_int();
				if (id == 0)
				{
					cerr << "Err: Skipping order since it is not valid - invalid updateId !\n";
					return false;
				}
			}
		}

		if (it->first == "amount")
		{
			// amount cannot be negative
			if ((it->second).as_int() < 0)
			{
				cerr << "Err: Skipping order since it is not valid - negative amount !\n";
				return false;
			}

			bAmount = true;
		}
	}

	// Check for reqd 3 keys
	if (reqdFields != 3)
	{
		cerr << "Err: Skipping order since it is not valid - does not have the 3 mandatory fields!\n";
		return false;
	}

	if (bNew == true && bAmount == false)
	{
		cerr << "Err: Skipping order since it is not valid - 'NEW' order does not have Amount!\n";
		return false;
	}

	return true;
}

void validateAndProcess (map<int, Order> &mapOrders, Value v)
{
	Object obj = v.operator JSON::Object() ;

	bool bAmount = false;
	if (validateOrder (obj, bAmount) == false)
		return;

	int orderId = obj["orderId"].as_int();
	int updateId = obj["updateId"].as_int();

	map<int, Order>::iterator itMap = mapOrders.find (orderId);
	if (itMap == mapOrders.end ())
	{
		// New Order
		Order order;
		if (order.process (v, bAmount))
			mapOrders [orderId] = order;
	}
	else
	{
		// Process order after validating updateId
		if ((itMap->second).isValid(updateId))
			(itMap->second).process(v, bAmount);
		else
			cerr << "Err: Skipping orderId=" <<  orderId << " updateId=" << updateId << " since it is not valid - updateId does not follow rules!\n";
	}
}

void cleanUp (map <int, Order> mapOrders)
{
	map <int, Order>::iterator itMap = mapOrders.begin();
	for (; itMap != mapOrders.end(); ++itMap)
		(itMap->second).cleanUp ();
}

int main ()
{
	string str;
	map <int, Order> mapOrders; // try with pointer to Order

	while (getline (cin, str))
	{
		if (feof(stdin))
			break;

		// Remove white spaces from the string
		std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
		str.erase(end_pos, str.end());

		try
		{
			Value v = parse_string (str);
			validateAndProcess (mapOrders, v);
		}
		catch (...)
		{
			cerr << "JSON Parse Error\n";
		}
	}

	//Aggregate the summary after user enters ^D i.e. eof
	aggregateSummary (mapOrders);

	cleanUp (mapOrders);

	return 0;
}
