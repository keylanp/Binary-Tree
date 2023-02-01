//Keylan Petty, CS163, Assingment3
//
//This is my main implentation file. It has a switch function for all user options
//and takes in all the data from my .o file

#include "tree.h"

int main() 
{ 
    char userchoice = 'A';
    char term[100];
    char topic[100];
    char definition[200];
   
    table tree;

    cout << "Welcome to my binary tree program!" << endl;

    while(userchoice != 'Q')
    {
        cout << "Please select and option below!\n" << endl;

        cout << "A: Retrieve information about a given term(not display)" << endl;
        cout << "B: Manually insert term, topic, and definition" << endl;
        cout << "C: Display by topic name" << endl;
        cout << "D: Remove by term name" << endl;
        cout << "E: Display all of everything!" << endl;
        cout << "Q: Quit program" << endl; 
        cout << "What would you like to do?" << endl;

        cin >> userchoice;
        cin.ignore(100,'\n');
        cin.clear();
        userchoice = toupper(userchoice);

        switch(userchoice)
        {
            case 'A': caseA(term, tree);
                      break;
            case 'B': caseB(term, topic, definition, tree);
                      break;
            case 'C': caseC(topic, tree);
                      break;
            case 'D': caseD(term, tree);
                      break;
            case 'E': caseE(tree);
                      break;
            case 'Q': break;
            default: break;
        }
    }


    return 0;
}

