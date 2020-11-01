/*version 1.0
* 11/01/2020
* 
* Implementation file ShoppingList.cpp. This is the implementation of the Shopping List class. The interface for this class is
* located in ShoppingList.h.
*/

#include <iostream>
#include <fstream>
#include "ShoppingList.h"

using namespace std;

// Constructor - sets all node values to null
ShoppingList::ShoppingList()
{
	Node* head = NULL;
	Node* current = NULL;
	Node* temp = NULL;
}

// Copy Constructor
ShoppingList::ShoppingList(const ShoppingList& listToCopy)
{
	Node* iterator = listToCopy.head;

	while (iterator != NULL)
	{
		this->listAdd(iterator->data);
		iterator = iterator->next;
	}
}

// Destructor
ShoppingList::~ShoppingList() {}

//Overloaded copy assignment operator
ShoppingList ShoppingList::operator = (const ShoppingList& listToCopy)
{
	ShoppingList copiedList;

	Node* iterator = listToCopy.head;

	while (iterator != NULL)
	{
		listAdd(iterator->data);
		iterator = iterator->next;
	}
	return copiedList;
}

/*Inserts a new node.If this is the first node in the list, the node will become the head of the list. Otherwise, it
will be added to the end of the list.
*/
void ShoppingList::listAdd(string data)
{
	Node* nodeToAdd = new Node;
	nodeToAdd->next = NULL; // make the new node the last node in the list.

	nodeToAdd->data = data; 

	if (head != NULL)
	{
		current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = nodeToAdd;
	}
	else
	{
		head = nodeToAdd;
	}
	cout << data << " has been added!\n\n";
}

// Will remove all node(s) containing the passed in string in their data section
void ShoppingList::listRemove(string itemToFind)
{
	Node* nodeToDelete = NULL;
	temp = head;
	current = head;

	while (current != NULL && current->data.compare(itemToFind) != 0)
	{
		temp = current;
		current = current->next;
	}
	if (current == NULL)
	{
		cout << itemToFind << " not found! Nothing was deleted.\n\n";
		delete nodeToDelete;
	}
	else
	{
		nodeToDelete = current;
		current = current->next;
		temp->next = current;
		if (nodeToDelete == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete nodeToDelete;
		cout << itemToFind << " has been deleted!\n\n";
	}
}
/*Searches the list for searchTerm (case sensitive), and returns a pointer to the item if it's found. If the item is not found, the function
will return a null pointer
*/
ShoppingList::Node* ShoppingList::listSearch(string searchTerm)
{
	Node* iterator = head;

	while (iterator != NULL && iterator->data.compare(searchTerm) != 0)
	{
		iterator = iterator->next;
	}
	if (iterator == NULL)
	{
		cout << "\n" << searchTerm << " not found!\n";
		return NULL;
	}
	else
	{
		cout << "\n\n" << searchTerm << " found!\n";
		return iterator;
	}
}

//Deletes the contents of the passed-in list
void ShoppingList::listClear()
{
	Node* iterator = head;
	Node* nodeToDelete = NULL;

	while (iterator != NULL)
	{
		nodeToDelete = iterator;
		iterator = iterator->next;
		delete nodeToDelete;
	}
	head = NULL;
}

// Prints out the value of the list to the console
void ShoppingList::print()
{
	if (head == NULL)
	{
		cout << "\n\nThe list is empty!\n\n";
	}
	
	else
	{
		Node* iterator = head;

		cout << "Here is your shopping list: \n";
		cout << "****************************\n\n";

		while (iterator != NULL)
		{
			cout << iterator->data << "\n";
			iterator = iterator->next;
		}
	}
}

/*Reads a text file located at filepath, and reads its contents into a linked list. If the user only specifies a filename, 
the export file will be located in the same directory as the program files.
*/
void ShoppingList::importFromFile(string filePath)
{
	string dataIn;
	fstream fileIn;

	do
	{
		fileIn.open(filePath);

		if (fileIn.fail())
		{
			cout << "\nError in opening file " << filePath << ". Double-check your file path and re-enter: ";
			cin >> filePath;
			fileIn.open(filePath);
		}

	} while (fileIn.fail());

	cout << "\nCreating linked list from file data . . . " << filePath << "\n\n";
		
	while (fileIn >> dataIn)
	{
		listAdd(dataIn);
	}
	cout << "Import Successful! \n\n";

	fileIn.close();
}

/*Exports contents of a linked list to a text file at the file path of the user's choice. If "true" is passed in 
for the append parameter, the new contents will be appended to the end of the file; otherwise, the file will be overwritten.

If the user only specifies a filename, the export file will be located in the same directory as the program files.
*/
void ShoppingList::exportToFile(string filePath, bool append)
{
	ofstream fileOut;
	Node* iterator;
	iterator = head;

	do
	{
		if (append)
		{
			fileOut.open(filePath, fileOut.app);
		}
		else
		{
			fileOut.open(filePath);
		}

		if (fileOut.fail())
		{
			cout << "Error in opening file " << filePath << ". Double-check your file path and re-enter: ";
			cin >> filePath;
			fileOut.open(filePath);
		}

	} while (fileOut.fail());

	while (iterator != NULL)
	{
		fileOut << iterator->data << "\n";
		iterator = iterator->next;
	}
	cout << "Export Successful!\n\n";


	fileOut.close();
}

