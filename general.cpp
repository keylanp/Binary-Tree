//Keylan Petty, CS163, Assignment3
//
//This is my general file. It has all the function prototypes listed in main.

#include "tree.h"

//This is my function for retrieving infromation about a given term - not a display
//just sets the local table to the found value
void caseA(char term[], table & tree)
{
	terminology huh;
	
	cout << "What term would you like to get?" << endl;
	cin.getline(term, 100, '\n');	

	if(!tree.retrieve(term, huh))
	{
		cout << "\n" << term << " could not be found." << endl;
		return;
	}

	huh.display();
	return;
}

//This function manually inserts a node in my binary tree using three character arrays
//that all become the set values of private data members in my terminology class
void caseB(char term[], char topic[], char definition[], table & tree)
{
	
	cout << "What is the name of the term?: ";
	cin.getline(term, 100, '\n');

	cout << "\nWhat is the topic?: ";
	cin.getline(topic, 100, '\n');

	cout << "\nWhat is the definition(200 letters or less): ";
	cin.getline(definition, 200, '\n');

	tree.add(term, topic, definition);

	cout << "\nSuccessfully added!" << endl;
	return;
}

//This function displays all the nodes with a certain topic
void caseC(char topic[], table & tree)
{
	cout << "\nWhat topic would you like displayed?: ";
	cin.getline(topic, 100, '\n');

	if(tree.display_by_topic(topic) > 0)
		cout << endl;
	else
		cout << "Could not find anything in that topic." << endl;
		
	return;
}

//This function removes a node in the binary tree by the term name
void caseD(char term[], table & tree)
{
	cout << "\nWhat topic would you like removed?: ";
	cin.getline(term, 100, '\n');

	if(tree.remove(term) > 0)
		cout << endl;
	else
		cout << "Could not find that term." << endl;
		
	return;
}


//This function displays all of the binary tree
void caseE(table & tree)
{
	if(tree.display_all() > 0)
		cout << endl;
	else
		cout << "\nNothing in the list!" << endl;
	return;
}
