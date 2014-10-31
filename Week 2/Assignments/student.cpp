/* This Program was developed by Jason Pototsky
10/25/2014 for Week 2 Assignment
For SER221 Programming and Their Execution Environment - 88915
Instructor: Jeffrey Buck
*/

//Preprocessor Directives
#include<iostream>
#include<string>
using namespace std;
class Student{
	private:
		string name;
		int numClasses;
		string* classList;
	public:
		Student(){
			this->name = "";
			this->numClasses = 0;
			this->classList = new string[numClasses];
		}
		Student(string input_name, int input_numClasses){
			this->name = input_name;
			this->numClasses = input_numClasses;
			this->classList = new string[numClasses];
		}
		string getname(){
			return this->name;
		}
		string* getClassList(){
			return this->classList;
		}
		int getnumClasses(){
			return this->numClasses;
		}
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
		void setName(string input){
			this->name = input;
		}
		void setNumClasses(int input){
			this->numClasses = input;
		}
		void setClassList(string* input_classList){
			int length = sizeof(input_classList);
			if (sizeof(this->classList)>0){
				this->classList = new string[length];
				for (int i = 0; i < length; ++i){
					this->classList[i] = input_classList[i];
				}
			}
			else {
				std::cout << "There is data in the class list right now: do you want me to reset it? y/n";
				string decision = getstring();
				if (decision == "y" || decision == "Y"){
					this->classList = new string[length];
					for (int i = 0; i < length; ++i){
						this->classList[i] = input_classList[i];
					}
				}
				else if (decision == "n" || decision == "N"){
					std::cout << "Ok returning you to the loop. \n";
				}
				else {
					std::cout << "Y or N....sigh, returning you back. \n";
				}
			}
		}
		void outputClassList(){
			if (this->numClasses > 0){
				for (int i = 0, length = sizeof(this->classList); i < length; ++i){
					std::cout << this->classList[i] << ' ';
				}
			}
			else {
				std::cout << "There are no registered classes.";
			}
		}
		void outputStudentInfo(){
			std::cout << " This student's name is: " << this->name << "\n ";
			std::cout << "The number of classes the student is enrolled in is: " << this->numClasses << "\n ";
			std::cout << "The classes that the student is enrolled in is as follows: \n";
			outputClassList();
			std::cout << " \n";
		}
		void inputStudentInfo(){
			string* templist;
			string tempname;
			int tempclassnum;
			std::cout << "Please input the student's name: ";
			tempname = getstring();
			std::cout << " \n";
			std::cout << "How many classes is this student enrolled in: ";
			tempclassnum = getint();
			std::cout << "\n";
			templist = new string[tempclassnum];
			for (int i = 0; i < tempclassnum; ++i){
				std::cout << "Please input class number " << i << ": ";
				templist[i] = getstring();
				std::cout << " \n";
			}
			setClassList(templist);
			setName(tempname);
			setNumClasses(tempclassnum);
		}
		void clearList(){
			int length = sizeof(this->classList);
			this->numClasses = 0;
			for (int i = 0; i < length; ++i){
				this->classList[i] = "";
			}
		}

};
int main(){
	cout << "Hello and Welcome to the student class list creator. \n";
	Student myStudent;
	bool cont = true;
	while (cont == true){
		myStudent.inputStudentInfo();
		myStudent.outputStudentInfo();
		cout << "Do you want to enter the data again? y or n : ";
		string decision = myStudent.getstring();
		cout << "\n";
		if (decision == "n" || "N"){
			system("exit");
			break;
		}
		else if (decision == "Y" || decision == "y"){
			myStudent.clearList();
		}
		else {
			myStudent.clearList();
		}
	}
	system("Pause");
	return 0;
}