/*****************************************************************************************************
Title:		Assignment - M5
Author:		Calvin Tam
Objective:	To understand the importance of redefing methods for derived classes. In this assignment,
a game jam database is created dynamically by allowing the user to enter information about
participants of a game jam and display the information by overriding a Report function 
(from the base class).
*****************************************************************************************************
/*****************************************************************************************************
									Object Description/Pseudo Code:
*****************************************************************************************************

CLASS #1 ~ Participant CLASS
	Variables
		age (age of the participants)
	Functions
		Constructor
			ask user for age
		Report
			prints: age (this function requires additional code from the child classes)

CLASS #2 ~ Programmer CLASS
	Variables
		num_proLang (number of programming languages)
		yrs_exp (years of experience)
	Functions
		Constructor
			ask user for number of programming languages + years of experience
		Report
			prints: age, num_proLang, yrs_exp

CLASS #3 ~ Artist CLASS
	Variables
		yrs_exp (years of experience)
	Functions
		Constructor
			ask user for years of experience
		Report
			prints: age, yrs_exp

CLASS #4 ~ Designer CLASS
	Functions
		Report
			prints: age

MAIN FUNCTION
	Variables
		LIMIT (limit of participants)
		end (boolean to determine the end of the main loop)
		Participant* p[LIMIT] (create participants dynamically)

		pCount (counter for number of programmers)
		aCount (counter for number of artists)
		dCount (counter for number of designers)

		input (a variable that allows the user to navigate through the main menu)
		input2 (a variable that allows the user to navigate through the second menu)

		proArray (dynamic array used to hold info about the programmer, used for the report function)
		artArray (dynamic array used to hold info about the artist, used for the report function)
		desArray (dynamic array used to hold info about the designer, used for the report function)

		numPar (number of participants)
		numPro (value used to keep track of where the info is stored within the proArray)
		numArt (value used to keep track of where the info is stored within the artArray)
		numDes  (value used to keep track of where the info is stored within the desArray)

	Forever (while) loop
		display main menu

			if user presses 1
				display second menu
					if user presses 1
						add programmer
						increment counters
					if user presses 2
						add artist
						increment counters
					if user presses 3
						add designer
						increment counters

			if user presses 2
				display database
				display programmers/artists/designers

			if user presses 3
				delete dynamic arrays that were created
				end program

************************************************************************************************
************************************************************************************************/

#include "string"
#include "stdio.h"
#include "iostream"
using namespace std;

// PARTICIPANTS CLASS //////////////////////////////////////////////////////////////////////
class Participant {
public:
	int age;

	// ask for info: age
	Participant() {
		cout << "\n\nHow old is this participant? ";
		cin >> age;
	}

	virtual void Report() {
		printf("This participant is: %d year(s) old\n", age); // info gets overridden due to virtual function
	}
};

// PROGRAMER CLASS //////////////////////////////////////////////////////////////////////
class Programmer : public Participant {
public:
	int num_proLang; // number of programming langauges
	int yrs_exp; // years of exp

	// ask for info: # of langauges + exp
	Programmer() {
		// ask for lang
		cout << "How many programming languages does this programmer know? ";
		cin >> num_proLang;

		// ask for exp
		cout << "How many years of experience does this programmer have? ";
		cin >> yrs_exp;
		cout << "\n\n";
	}
	// display info
	void Report() {
		printf("\nThis participant is: %d year(s) old\n", age);
		printf("This participant knows: %d programming language(s)\n", num_proLang);
		printf("This participant has: %d year(s) of experience\n\n", yrs_exp);
	}
};

// ARTIST CLASS //////////////////////////////////////////////////////////////////////
class Artist : public Participant {
public:
	int yrs_exp;

	// ask for info: exp
	Artist() {
		// ask for years of exp
		// ask for exp
		cout << "How many years of experience does this artist have? ";
		cin >> yrs_exp;
		cout << "\n\n";
	}
	// display info
	void Report() {
		printf("\nThis participant is: %d year(s) old\n", age);
		printf("This participant has: %d year(s) of experience\n\n", yrs_exp);
	}
};

// DESIGNER CLASS //////////////////////////////////////////////////////////////////////
class Designer : public Participant {
public:
	// constructor that asks for age (empty because age was asked in Participant constructor)
	Designer() {
	}
	// display info
	void Report() {
		printf("\nThis participant is: %d year(s) old\n\n", age);
	}
};


// MAIN FUNCTION //////////////////////////////////////////////////////////////////////
void main() {
	// variables
	const int LIMIT = 50;
	int pCount = 0;
	int aCount = 0;
	int dCount = 0;
	bool end = false; // determine end of program
	int input; // first input
	int input2; // second input
	
	// var for programmers
	int* proArray = new int[LIMIT];
	// var for artists
	int* artArray = new int[LIMIT];
	// var for designers
	int* desArray = new int[LIMIT];


	int numPar = 0;
	int numPro = 0;
	int numArt = 0;
	int numDes = 0;
	Participant* p[LIMIT];

	while (end == false) {

		// Display menu
		cout << "Welcome to the Game Jam Registration Program!\n";
		cout << "Please use numbers 1-3 to select the following options\n";
		cout << "1) Add a particiapant\n";
		cout << "2) Get the list of particiapants\n";
		cout << "3) End the program\n";

		cin >> input;


		// 1 add participant -------------------------------------------

		if (input == 1) {
			cout << "Please classify the field of the participant\n";
			cout << "Is the participant a...\n";
			cout << "1) Programmer\n";
			cout << "2) Artist\n";
			cout << "3) Designer\n";
			cin >> input2;

			// add programmer
			if (input2 == 1){
				p[numPar] = new Programmer();
				// store programmer info
				proArray[numPro] = numPar;
				numPar++;
				numPro++;
				pCount++;
			}
			// add artist
			if (input2 == 2) {
				p[numPar] = new Artist();
				// store artist info
				artArray[numArt] = numPar;
				numPar++;
				numArt++;
				aCount++;
			}
			// add designer
			if (input2 == 3) {
				p[numPar] = new Designer();
				// store designer info
				desArray[numDes] = numPar;
				numPar++;
				numDes++;
				dCount++;
			}
		}

		// end program if limit was reached
		if (numPar == LIMIT) {
			// delete dynamic arrays
			delete[] proArray;
			delete[] artArray;
			delete[] desArray;
			//delete[] p;

			cout << "Sorry! The game jam is full!\nPlease sign up for the next jam!\n";
			// end loop
			cout << "Thank you for using the Game Jam Registration Program\n";
			end = true;
		}

		// 2 get list of participants  --------------------------------
		if (input == 2) {
			// loop thats spits return function
			cout << "\n\nLIST OF PARTICIPANTS////////////////////////////////////////////\n";
			printf("There are: %d participant(s) in this game jam!\n", numPar);
			printf("There are: %d Programmer(s) \n", pCount);
			printf("There are: %d Artist(s)\n", aCount);
			printf("There are: %d Designer(s)\n", dCount);
			cout << "\n////////////////////////////////////////////////////////////////\n";

			// for programmers
			for (int i = 0; i < pCount; i++) {
				printf("\n\nPROGRAMMER %d////////////////////////////////\n", i+1);
				int value;
				int value2;
				value = pCount - pCount + i;
				value2 = proArray[value];
				p[value2]->Report();
				cout << "/////////////////////////////////////////////\n\n";
			}
			// for artists
			for (int i = 0; i < aCount; i++) {
				printf("\n\nARTIST %d////////////////////////////////////\n\n", i + 1);
				int value;
				int value2;
				value = aCount - aCount + i;
				value2 = artArray[value];
				p[value2]->Report();
				cout << "/////////////////////////////////////////////\n";
			}
			// for designers
			for (int i = 0; i < dCount; i++) {
				printf("\n\nDESIGNER %d////////////////////////////////////\n\n", i + 1);
				int value;
				int value2;
				value = dCount - dCount + i;
				value2 = desArray[value];
				p[value2]->Report();
				cout << "///////////////////////////////////////////////\n";
			}
		}


		// 3 end loop  ------------------------------------------------
		if (input == 3) {

			// delete dynamic arrays
			delete[] proArray;
			delete[] artArray;
			delete[] desArray;
			//delete[] p;

			// end loop
			cout << "Thank you for using the Game Jam Registration Program\n";
			end = true;
		}
	}
}