//Keylan Petty, CS163, Assignment4
//
//This is my header file for my classes related to my binary tree

#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;


class terminology
{
	public:
		terminology();
		~terminology();
		int copy(terminology & passing);
		int set(char names[], char topics[], char def[]);
		int retrieve_term(char key[], terminology & found) const;
		int retrieve_topic(char key[], terminology & found) const;
		int compare_term(char key[]);
		int compare_topic(char key[]);
		int display() const;
		int getN(char names[]);
	private:
		char * name;
		char * topic;
		char * definition;

};

struct node
{
	terminology * data;
	node * left;
	node * right;
};

class table
{
	public:
		table();
		~table();
		int retrieve(char terms[], terminology & passing);
		int add(char names[], char topics[], char def[]);
		int remove(char toremove[]);
		int display_by_topic(char topic[]);
		int display_all();

	private:
		node * root;

		int ios(terminology &, node *&);
		int remove(node *&);
		int retrieve(node * root, char terms[], terminology & passing);
		int destruct(node *& root);
		int add(node *& root, char names[], char topics[], char def[]);
		int remove(node *& root, char[]);
		int display_by_topic(node * root, char topic[]);
		int display_all(node * root);
};

//Function declarations for my main file
void caseA(char term[], table & tree);
void caseB(char term[], char topic[], char definition[], table & tree);
void caseC(char topic[], table & tree);
void caseD(char term[], table & tree);
void caseE(table & tree);
