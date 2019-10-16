//Tu Vu CS202
//October 23, 2018
//Program 2
//Purpose of the file: The header file for the company which has a 'has a' relationship with a node which in turn 'has a' transport pointer.


#include "specific.h"

class node 
{
	public:
		node();
		node(const scooter & to_copy); //A specific copy constructor for scooter
		node(const zipCar & to_copy); //A specific copy constructor for zip car
		node(const bicycle & to_copy); //A specific copy constructor for bicycle
		~node ();
		
		//Setters and Getters
		node*& getNext();
		void setNext(node * set_to);
		void setPrevious(node * set_to);
		node* getPrevious();
		int getID (); //return the id
		int getType(); //return the type
		int getCost(); //return the cost

		int display_vehicle();
		int addVehicle(int flag, char * location1, char * location2, int id, int cost);


	protected:
		transport * vehicle; //Node has a vehicle. A base class pointer
		node * next;
		node * previous;
};

class company
{
	public:
		company();
		company (const company & to_copy);
		~company();
		
		int addVehicle(const scooter & to_add); //One for each kind of vehicle to add into the DLL
		int addVehicle(const zipCar & to_add); //
		int addVehicle(const bicycle & to_add); //

		//wrappers
		int display_vehicle();
		int remove_specific(int v_id);
		int company_income();
		int remove_all();

	protected:		
		int addVehicle(node *& temp);
		int display_vehicle(node * head);
		int remove_specific(node *& head, int v_id);
		int company_income(node * head, int & scoot, int & zippy, int & bikey);
		int remove_all(node *& head);
		
		node * head; //Company has a node
		node * tail;
};

		
