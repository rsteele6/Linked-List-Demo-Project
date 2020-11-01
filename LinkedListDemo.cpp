/*version 1.0
* 11/01/2020
* 
* Linked List Demo Program
*/

#include <iostream>
#include "ShoppingList.h"

using namespace std;

// Function Prototypes

// Displays a menu enabling the user to select from a series of choices
char displayMainMenu();

/* Allows the user to return to the main menu. If option 1 is selected, true is returned. If anything else is entered,
false is returned.
*/
bool returnToMain();

// Displays a submenu where users are able to select from various actions to perform on a linked list
void displayActionsSubMenu(ShoppingList& list);

// Performs the operation selected by the user in the submenu
void processSubMenu(ShoppingList& list, char option);

int main()
{
    // sentinel value for do-while loop
    bool quit = false;

    do
    {
        // used for storing user menu choice input
        char mainMenuOption, subMenuOption;
        string userInput;

        // Displays the main menu and allows the user to choose an option. The result is returned and stored in option.
        mainMenuOption = displayMainMenu();

        if (mainMenuOption == '1') // Option 1 = Create new list
        {
            ShoppingList newShoppingList;

            displayActionsSubMenu(newShoppingList);

            if (!returnToMain())
            {
                quit = true;
            }
        }
        else if (mainMenuOption == '2') // Option 2 = import from file
        {
            ShoppingList newShoppingList;

            cout << "Please enter the full file path: ";
            cin >> userInput;
            
            cout << "Attempting import from file at location " << userInput << "\n\n";
            newShoppingList.importFromFile(userInput);

            displayActionsSubMenu(newShoppingList);

            if (!returnToMain())
            {
                quit = true;
            }
        }
        else if (mainMenuOption == '3') // Option 3 - Quit
        {
            quit = true;
        }
        else // invalid selection
        {
            do
            {
                cout << "Invalid input; please re-enter: ";
                cin >> mainMenuOption;

            } while (mainMenuOption != '1' && mainMenuOption != '2' && mainMenuOption != '3');
        }

    } while (quit == false);

    cout << "\n\nExiting application . . . \n\n";

    system("pause");

    return 0;
}

// Main function definitions

// Displays a menu enabling the user to select numbered options 1-2, or any other character to exit the program
char displayMainMenu()
{
    char option; // used for storing the user's choice

    cout << "**********************************************************\n\n";
    cout << "Demo program for creating and using linked lists.\n\n";
    cout << "Please choose from the following options:\n\n";
    cout << "1. Create new list\n";
    cout << "2. Import existing list from file\n";
    cout << "3. Exit\n\n";
    cout << "***********************************************************\n\n";

    cout << "Your choice (1-3)? ";

    cin >> option;

    return option;
}

/*Gives the user the option to return to the main menu or quit the program. If false is returned, logic in the main method
will cause the program to quit.
*/
bool returnToMain()
{
    char returnToMain;

    cout << "\n\nEnter 1 to return to the main menu, or any other character to quit: ";
    cin >> returnToMain;

    if (returnToMain == '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void displayActionsSubMenu(ShoppingList &list)
{
    char option; // used for storing the user's choice

    cout << "**********************************************************\n\n";
    cout << "Actions Menu\n\n";
    cout << "Please choose from the following options:\n\n";
    cout << "1. Add a new item to your list\n";
    cout << "2. Delete an item from your list\n";
    cout << "3. Search for an item\n";
    cout << "4. Print your list\n";
    cout << "5. Create a copy of your list\n";
    cout << "6. Clear your list\n";
    cout << "7. Export your list to a text file\n";
    cout << "8. Exit\n";
    cout << "***********************************************************\n\n";

    cout << "Your choice (1-8)? ";

    cin >> option;

    processSubMenu(list, option);
}

void processSubMenu(ShoppingList &list, char option)
{
    string userInput;
    ShoppingList copyList;

    switch (option)
    {
        case '1': // Add new item
            cout << "\n\nEnter an item: ";
            cin >> userInput;
            list.listAdd(userInput);
            system("pause");
            displayActionsSubMenu(list);
            break;
        case '2': // Delete item
            cout << "\n\nEnter an item to delete: ";
            cin >> userInput;
            list.listRemove(userInput);
            system("pause");
            displayActionsSubMenu(list);
            break;
        case '3': // Search for item
            cout << "\n\nEnter an item to search for: ";
            cin >> userInput;
            list.listSearch(userInput);
            system("pause");
            displayActionsSubMenu(list);
            break;
        case '4': // Print list
            cout << "\n\nPrinting list to screen: \n\n";
            list.print();
            system("pause");
            displayActionsSubMenu(list);
            break;
        case '5': // Create a deep copy of the list using the overloaded = operator
            cout << "\n\nHere are the contents of the current list: \n\n";
            list.print();
            cout << "\n\n Performing deep copy using the overloaded = operator: \n\n";
            copyList = list;
            copyList.print();
            system("pause");
            displayActionsSubMenu(list);
            break;
        case'6': // Clear the list
            cout << "\n\nHere are the contents of the list before clearing it:\n\n";
            list.print();
            cout << "\n\nClearing the list . . . \n\n";
            list.listClear();
            cout << "\n\nThe list should now be empty:\n\n";
            list.print();
            system("pause");
            displayActionsSubMenu(list);
            break;
        case '7': // Export list to text file
            cout << "Enter an export path and filename: ";
            cin >> userInput;
            cout << "Attempting export to file at location " << userInput << "\n\n";
            list.exportToFile(userInput, false);
            system("pause");
            displayActionsSubMenu(list);
            break;
        case '8': // Exit from submenu
            break;
        default:
            break;
    }
}


