/* This Program was developed by Jason Pototsky
10/25/2014 for Week 2 Assignment
For SER221 Programming and Their Execution Environment - 88915
Instructor: Jeffrey Buck
*/

//Preprocessor Directives
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
class BoxofProduce{
private:
	string optionlist[ 5 ]; 
	string boxContents[ 3 ];
public:
	static int numofBoxes;
	static int getNumOfBoxes(){
		return numofBoxes;
	}
	BoxofProduce(){
		optionlist[0] = "Brocoli";
		optionlist[1] = "Tomato";
		optionlist[2] = "Kiwi";
		optionlist[3] = "Kale";
		optionlist[4] = "Tomatillo";
		for (int i = 0; i < 3; ++i){
			int temp = rand() % 5 + 1;
			boxContents[i] = optionlist[temp];
		}

		numofBoxes++;
	}
		
	string* getOptionList(){
		return this->optionlist;
	}
	string* getBoxContents(){
		return this->boxContents;
	}
	void setboxContents(string* input_Boxcontents){
		for (int i = 0, length = sizeof(input_Boxcontents); i < length; ++i){
			this->boxContents[i] = input_Boxcontents[i];
		}
	}
	void outputBoxContents(){
		std::cout << "The Contents of the box are: ";
		for (int i = 0; i < 3; ++i){
			std::cout << this->boxContents[i] << " ";
		}
		std::cout << "\n";
	}
	void outputOptionList(){
		std::cout << "The Options are: \n";
		for (int i = 0; i < 5 ; ++i){
			std::cout << i << ". " << this->optionlist[i] << "\n";
		}
	}
	
};
int BoxofProduce::numofBoxes = 0;
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
		else if (input < 0 || input > 5){
			//Inform the user of the failure
			cout << "Please only select options that are available 0 - 5. \n";
			//Clear and ignore the input
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
int main(){
	//Seed the random with the system time
	srand(time(NULL));
	bool cont = true;
	cout << "Welcome to the CSA farm delivery program! \n";
	do {
		cout << "Making your produce box now....beep boop beep boop. \n";
		BoxofProduce mybox = BoxofProduce();
		mybox.outputBoxContents();
		cout << "Do you want to change any of these? y for yes : ";
		string decision = getstring();
		if (decision == "y" || decision == "Y"){
			string* templist = mybox.getBoxContents();
			string* tempoptions = mybox.getOptionList();
			for (int i = 0; i < 3; ++i){
				cout << "Item " << i << " is a : " << templist[i] << "\n";
				mybox.outputOptionList();
				cout << "Please select a number corresponding to your option: ";
				int selection = getint();
				templist[i] = tempoptions[selection];
			}
			mybox.outputBoxContents();
		}
		else {
			cout << "Since you cannot follow instructions....You will get what you get. \n";
		}
		cout << "The number of boxes created so far: " << BoxofProduce::getNumOfBoxes() << " \n";
		cout << "Do you want to create another box? y / n : ";
		string quitnow = getstring();
		if (quitnow == "n" || quitnow == "N"){
			break;
		}
	} while (cont == true);
	//Pause so I can see the output
	system("Pause");
	//All is well
	return 0;
}