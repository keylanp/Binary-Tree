//Keylan Petty, CS163, Assignment4
//
//This is the implementation file for my terminology class. It inlcudes all the
//declarations for the terminology class member functions.

#include "tree.h"

//class constructor
terminology::terminology()
{
	topic = nullptr;
	name = nullptr;
	definition = nullptr;
}

//class destructor
terminology::~terminology()
{
	if(topic)
		delete [] topic;
	if(name)
		delete [] name;
	if(definition)
		delete [] definition;
	topic = nullptr;
	name = nullptr;
	definition = nullptr;
}

//This is a function for setting a passed in terminology to the current terminology
int terminology::copy(terminology & passing)
{
	if(passing.name)
	{
		delete [] passing.name;
		passing.name = nullptr;
	}
	if(passing.topic)
	{
		delete [] passing.topic;
		passing.topic = nullptr;
	}
	if(passing.definition)
	{
		delete [] passing.definition;
		passing.definition = nullptr;
	}

	passing.name = new char[strlen(this->name)+1];
	passing.topic = new char[strlen(this->topic)+1];
	passing.definition = new char[strlen(this->definition)+1];

	strcpy(passing.name, name);
	strcpy(passing.topic, topic);
	strcpy(passing.definition, definition);

	return !strcmp(passing.name, name);
}




//This function first check to see that the private data mebers are empty, then
// it takes in three different character arrays and sets the private data
//members of terminology. Should return 1 if successful.
int terminology::set(char names[], char topics[], char def[])
{

	if(topic)
	{
		delete [] topic;
		topic = nullptr; 
	}
	if(name)
	{
		delete [] name;
		name = nullptr; 
	}
	if(definition)
	{
		delete [] definition;
		definition = nullptr; 
	}

	topic = new char[strlen(topics) + 1];
	strcpy(topic, topics);

	name = new char[strlen(names) + 1];
	strcpy(name, names);

	definition = new char[strlen(def) + 1];
	strcpy(definition, def);

	return !strcmp(name, names);
}

//This function does something but i havent decided what
int terminology::retrieve_term(char key[], terminology & found) const
{
	if(!strcmp(name, found.name))
		return 1;

	return 0;
}

//This function does something but i havent decided what
int terminology::retrieve_topic(char key[], terminology & found) const
{
	if(!strcmp(topic, found.topic))
		return 1;

	return 0;
}

//This function compares a character pointer to the character array stored in terminology
//under name.
int terminology::compare_term(char key[])
{
	if(!strcmp(key, name))
		return 1;
	return 0;
}

//This function compares a character pointer to the character array stored in terminology
//under name.
int terminology::compare_topic(char key[])
{
	if(!strcmp(key, topic))
		return 1;
	return 0;
}

//This is my display function
int terminology::display() const
{
	if(!topic || !definition || !name)
		return 0;
	cout << "Name: " << name << endl;
	cout << "Topic: " << topic << endl;
	cout << "Definition: " << definition << endl;
	cout << endl; 

	return 1;
}

//This is my get name function, returns the term name stored in terminology. returns 1
//if name is greater than and a 0 if it's less than or equal to.
int terminology::getN(char names[])
{
	if(strcmp(name,names) <= 0)
		return 1;
	else 
		return 0;
}
