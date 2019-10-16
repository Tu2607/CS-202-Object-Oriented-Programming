//Tu Vu CS202
//Program 2
//October 23, 2018
//Purpose of the file: The implementation for the company class and the node class, this file set up the so called company.


#include "general.h"

/******************************************************************/
company::company():head(NULL), tail(NULL)
{ 
}
//Destructor
company::~company()
{
	if (head)
	{
		delete head;
		head = NULL;
		tail = NULL;
	}
}
/******************************************************************/
node::node():vehicle(NULL), next(NULL), previous(NULL)
{

}
node::node(const scooter & to_add):next(NULL), previous(NULL) //This is where the upcasting happens
{
	vehicle = new scooter(to_add); //A base class pointer with scooter type.
}
node::node(const zipCar & to_add):next(NULL), previous(NULL)
{
	vehicle = new zipCar(to_add); //A base class pointer with zipCar type.
}
node::node(const bicycle & to_add):next(NULL), previous(NULL)
{
	vehicle = new bicycle(to_add); //A base class pointer with bicycle type.
}
node::~node()
{
	if (next)
		delete next;
	if (vehicle)
		delete vehicle;
}

/******************************************************************/
//Setters and Getters
node*& node::getNext()
{
	return next;
}
void node::setNext(node * set_to)
{
	next = set_to;
}
node* node::getPrevious()
{
	return previous;
}
void node::setPrevious(node * set_to)
{
	previous = set_to;
}
int node::getID()
{
	return vehicle -> getID();
}
int node::getType()
{
	return vehicle -> getType();
}

int node::getCost()
{
	return vehicle -> getCost();
}
/******************************************************************/

int company::addVehicle(const scooter & to_add)
{
	node * temp = new node(to_add); //Call the constructor
	addVehicle(temp);
}

int company::addVehicle(const zipCar & to_add)
{
	node * temp = new node(to_add); //Call the constructor
	addVehicle(temp);
}
int company::addVehicle(const bicycle & to_add)
{
	node * temp = new node(to_add); //Call the constructor
	addVehicle(temp);
}

int company::addVehicle(node *& temp) //This is where you set the pointers to the right node.  I add at the tail pointer
{
	if (!head)
	{
		head = temp;
		tail = head;
	}
	else //Using the tail pointer to add on to the end of the DLL
	{
		tail -> setNext(temp);	//Set the tail -> next to that new node;
		temp -> setPrevious(tail); 	//Set the previous pointer of that new node to point to tail; 
		tail = temp; 		//Move tail up to that node
	}
}
/******************************************************************/
int company::display_vehicle()
{
	return display_vehicle(head);
}

int company::display_vehicle(node * head) //Recursively display through the DLL
{
	if (!head)
	{
		cout << "We don't have any vehicle out!" << endl;
		return 0;
	}
	else	
		head -> display_vehicle();
	return display_vehicle(head -> getNext());
}

int node::display_vehicle()
{
	vehicle -> display_all();		 //Used dynamic binding and upcasting
}
/******************************************************************/
int company::remove_specific(int v_id)
{
	return remove_specific(head,v_id);
}

int company::remove_specific(node *& head ,int v_id) //Single instance of deletion, not the whole list.
{
	if (!head)
		return 0;
	
	if (head -> getID() == v_id) //3 special cases for removal, at the head, at the tail and anywhere in between
	{
		if (!head -> getPrevious()) //1st Case: Removal at the head. This works!!!
		{
			node * current = head -> getNext();
			if (!current)
			{
				delete head;
				head = NULL;
			}
			else
			{
				delete head;
				head = current;
				head -> setPrevious(NULL);
			}
			return 1;
		}
		else if (head == tail) //2nd Case: Removal at the tail. This works!!!!
		{
			node * temp = head -> getPrevious();
			delete head;
			head = temp;
			head -> setNext(NULL);
			tail = head;
			return 1;
		}
		else if (head -> getPrevious() && head -> getNext()) //3rd Case: Removal anywhere between head and tail
		{
			node * temp1 = head -> getNext();
			node * temp2 = head -> getPrevious();
			head -> setNext(NULL);
			head -> setPrevious(NULL);
			delete head;
			head = NULL;
			temp1 -> setPrevious(temp2);
			temp2 -> setNext(temp1);
			return 1;
		}
	}	
	return remove_specific(head -> getNext(),v_id);
}

/*******************************************************************/
//To display the company income. Using a getters and passed in an interger by reference to increment as you go.
int company::company_income()
{
	int scoot = 0;
	int zippy = 0;
	int bikey = 0;
	company_income(head,scoot,zippy,bikey);
	cout << "The income from scooter is: " << scoot << endl;

	cout << "The income from zip car is: " << zippy << endl;

	cout << "The income from bicycle is: " << bikey << endl;

	cout << "The total income is: " << scoot + zippy + bikey << endl << endl;
}
int company::company_income(node * head, int & scoot, int & zippy, int & bikey)
{
	if (!head)
		return 0;	

	if (head -> getType() == 1)
		scoot += head -> getCost(); //increment 
	else if (head -> getType() == 2)
		zippy += head -> getCost();
	else if (head -> getType() == 3)
		bikey += head -> getCost();

	return company_income(head -> getNext(),scoot,zippy,bikey);
}
/*******************************************************************/
//Remove all the node function
int company::remove_all()
{
	return remove_all(head);
}

int company::remove_all(node *& head)
{
	if (!head)
		return 0;
	remove_all(head -> getNext());	
	if (head)
	{
		delete head;
		head = NULL;
		return 1;
	}
}
