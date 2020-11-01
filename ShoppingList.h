/*version 1.0
*11/01/2020
* 
* Header file ShoppingList.h: This is the interface for the ShoppingList class (ShoppingList.cpp). Values of this type are
* empty linked lists
*/

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <string>

using namespace std;

class ShoppingList
{
public:
	struct Node
	{
		string data;
		Node* next;
	};

	// Constructor - sets all node values to null
	ShoppingList();

	// Copy Constructor
	ShoppingList(const ShoppingList& listToCopy);

	// Destructor
	~ShoppingList();

	/* Inserts a new node. If this is the first node in the list, the node will become the head of the list. Otherwise, it
	will be added to the end of the list.
	*/
	void listAdd(string data);

	// Will remove a node containing the passed in string in their data section
	void listRemove(string itemToFind);

	//Deletes the contents of the list
	void listClear();

	/*Searches the list for searchTerm (case sensitive), and returns a pointer to the item if it's found. If the item is not found, the function
	will return a pointer to null
	*/
	Node* listSearch(string searchTerm);

	// Prints out the value of the list to the console
	void print();

	/*Exports contents of a linked list to a text file at the file path of the user's choice. If "true" is passed in
	for the append parameter, the new contents will be appended to the end of the file; otherwise, the file will be overwritten.

	If the user only specifies a filename, the export file will be located in the same directory as the program files.
	*/
	void exportToFile(string filePath, bool append);

	// Reads a text file located at filepath, and reads its contents into a linked list
	void importFromFile(string filePath);

	//Overloaded copy assignment operator
	ShoppingList operator = (const ShoppingList& objectToCopy);

private:
	Node* head;
	Node* previous;
	Node* temp;
	Node* current;
};
#endif

