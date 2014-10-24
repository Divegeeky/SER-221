/* This Program was developed by Jason Pototsky
10/19/2014 for Week 1 Assignment
For SER221 Programming and Their Execution Environment - 88915
Instructor: Jeffrey Buck
*/

//Preprocessor Directives
#include<iostream>
#include<string>
//Define the namespace
using namespace std;
//Define the get int function
int getint(){
	//define the input variable
	int input;
	//define the boolean variable
	bool cont = true;
	//begin the do loop
	do {
		//get the user input
		cin >> input;
		//If the cin fails due to string input
		if (!cin){
			//Inform the user of the failure
			cout << "That was not an integer, please try again. \n";
			//Clear and ignore the input
			cin.clear();
			cin.ignore();
		}
		//If the input is not between 100 - 120
		else if (!(input >= 100 && input <= 120)){
			//Inform the user of the failure
			cout << "Please try again, input a number between 100-120. \n";
			//Clear and ignore in the input
			cin.clear();
			cin.ignore();
		}
		//If everything is good
		else {
			//Clear and ignore the input so I can input strings in the future
			cin.clear();
			cin.ignore();
			//Exit the loop
			break;
		}
	//The loop value is arbitrary
	} while (cont == true);
	//Return the input
	return input;
}
//Define the getstring function
string getstring(){
	//define the input variable
	string input;
	//define the boolean variable
	bool cont = true;
	//begin the do loop
	do {
		//Get the line from user input...only up to the whitespace due to the getline functionality
		getline(cin, input);
		//If input is empty
		if (input.empty()){
			//Inform the user of the failure
			cout << "Please input something into the field. \n";
			//Clear and ignore the input
			cin.clear();
			cin.ignore();
		}
		//If there is a string value in the input
		else {
			//exit the loop
			break;
		}
	//The loop value is arbitrary
	} while (cont == true);
	//Return the input
	return input;
}
//Define the main fucntion
void main(){
	//Define the string variables
	string inst_name, your_firstname, your_lastname, food, adjective, color, animal;
	//Define the integer variable
	int number;
	//Welcome
	cout << "Welcome to my MadLib program, I hope you enjoy hilarity and amusement. \n";
	//Prompt user for input
	cout << "Please input the first or last name of your instructor: \n";
	//Get the user input with input validation
	inst_name = getstring();
	//Prompt user for input
	cout << "Please input your first name: \n";
	//Get the user input with input validation
	your_firstname = getstring();
	//Prompt user for input
	cout << "Please input your last name: \n";
	//Get the user input with input validation
	your_lastname = getstring();
	//Prompt user for input
	cout << "Please input the name of a food: \n";
	//Get the user input with input validation
	food = getstring();
	//Prompt user for input
	cout << "Please input a number between 100 and 120: \n";
	//Get the user input with input validation
	number = getint();
	//Prompt user for input
	cout << "Please input the name of an adjective: \n";
	//Get the user input with input validation
	adjective = getstring();
	//Prompt user for input
	cout << "Please input the name of a color: \n";
	//Get the user input with input validation
	color = getstring();
	//Prompt user for input
	cout << "Please input the name of an animal: \n";
	//Get the user input with input validation
	animal = getstring();
	//Begin the output of the madlib
	cout << "Your Madlib is as follows: \n";
	cout << "Dear Professor " << inst_name << ",  \n";
	cout << "\n";
	cout << "I am sorry that I am unable to turn in my homework at this time. \n";
	cout << "First, I ate a rotten " << food << ", which made me turn " << color << " and \n";
	cout << "extemely ill. I came down with a fever of " << number << ". \n";
	cout << "Next, my " << adjective << " pet " << animal << " must have smelled the remains \n";
	cout << "of the " << food << " on my homework, because he ate it. I am currently \n";
	cout << "rewriting my homework and hope you will accept it late. \n";
	cout << "\n";
	cout << "Sincerely, \n";
	cout << your_firstname << " " << your_lastname << "\n";
	//Pause to see the console
	system("Pause");
}