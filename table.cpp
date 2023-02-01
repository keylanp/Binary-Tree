//Keylan Petty, CS163, Assignment4
//
//This is my implementation file for the table class. It includes function
//definitions that are declared in my .h file.

#include "tree.h"

//constructor
table::table()
{
	root = nullptr;
}

//destructor and wrapper function
table::~table()
{
	if(!root)
		return;
	 destruct(root);
	 return;
}

//recursive destructor 
int table::destruct(node *& root)
{
	if(!root) 
		return 0;
    	int num = destruct(root->left);
    	num += destruct(root->right);
	if(root->data)
		delete root->data;
    	delete root;
    	root = nullptr;
	++num;
	return num;
}

int table::retrieve(char terms[], terminology & passing)
{
	if(!root)
		return 0;
	return retrieve(root, terms, passing);
}

int table::retrieve(node * root, char terms[], terminology & passing)
{
	if(!root)
		return 0;
	if(root->data->compare_term(terms))
		return root->data->copy(passing);
	if(!root->data->getN(terms))
		return retrieve(root->left, terms, passing);
	return retrieve(root->right, terms, passing);

}
//Wrapper function for my insert function, calls add with the added parameter of root.
int table::add(char names[], char topics[], char def[])
{
	return add(root, names, topics, def);

}

//Function for inserting into my binary tree. Should return a 1 when successful.
int table::add(node *& root, char names[], char topics[], char def[])
{
	if(!root)
	{
		root = new node;	
		root->data = new terminology;
		root->data->set(names, topics, def);
		root->left = nullptr;
		root->right = nullptr;
		return 1;
	}
	//function returns 1 if the stored name is greater than the parameter, otherwise 0
	if(root->data->getN(names))
		return add(root->right, names, topics, def);
	return add(root->left, names, topics, def);
}

//Wrapper function for my recursive remove function in my binary tree, checks to see if my 
//root is null then calls the recursive functio. Returns 0 if the tree was empty and 
//1 if there were things to delete
int table::remove(char toremove[])
{
	if(!root)
		return 0;
	return remove(root, toremove);
}

//Function for removing within my binary search tree
int table::remove(node *& root, char toremove[])
{
	if(!root) return 0; 
	if(root->data->compare_term(toremove))
		return remove(root); 
	if(root->data->getN(toremove))
		return remove(root->right, toremove);	
	return remove(root->left, toremove);	
}


int table:: remove(node *& root)
{
	if(!root->left && !root->right)
	{
		if(root->data)
			delete root->data; 
		delete root; 
		root = nullptr; 
		return 1; 
	}
	if(root->right && root->left)
		return ios(*(root->data), root->right);
	if(root->left)
	{
		node * temp = root;
		root = root->left; 
		
		if(temp->data)
			delete temp->data; 
		delete temp; 
		return 1; 
	}

	node * temp = root;
	root = root->right; 

	if(temp->data)
		delete temp->data; 
	delete temp; 
	return 1;
}

int table:: ios(terminology & to_update, node *& root)
{
	if(!root) return 0; 
	if(root->left)
		return ios(to_update, root->left); 
	root->data->copy(to_update);

	if(root->right)
	{
		node * temp = root; 
		root = root->right; 

		if(temp->data)
			delete temp->data; 
		delete temp; 
		return 1;
	}

	if(root->data)
		delete root->data; 
	delete root;
	root = nullptr;
	return 1;
}

//Wrapper function for displaying all of a given topic
int table::display_by_topic(char topic[])
{
	if(!root)
		return 0;
	return display_by_topic(root, topic);
}

//Recursive display by topic, returns number of topics found(for testing)
int table::display_by_topic(node * root, char topic[])
{
	if(!root)
		return 0;
	int num = display_by_topic(root->left, topic);
	if(root->data->compare_topic(topic))
	{
		++num;
		root->data->display();
	}
	return num + display_by_topic(root->right, topic);
}

//Wapper function for my display all function. Returns 0 if there was nothing to print and
//anything 1 or above if there was- to count number of items.
int table::display_all()
{
	if(!root)
		return 0;
	return display_all(root);
}

//Recursive function for my display all function. Returns 1 when finished.
int table::display_all(node * root)
{
	if(!root)
		return 0;
	int num = display_all(root->left);
	root->data->display();
	++num;
	return num + display_all(root->right);
}
