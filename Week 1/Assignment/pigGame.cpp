/* This Program was developed by Jason Pototsky
10/19/2014 for Week 1 Assignment
For SER221 Programming and Their Execution Environment - 88915
Instructor: Jeffrey Buck
*/

//Preprocessor Directives
#include<iostream>
#include<string>
#include<time.h>
//Define the namespace
using namespace std;
//Define the static variables
static int computer_score, player_score;
//Define the rolldice function
int rolldice(){
	//Create a "Random" number from 1-6
	int roll = rand() % 6 + 1;
	//Return the value
	return roll;
}

//Define the getstring function to get input from the user with validation
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
		// If the user correctly input the values
		else if (input == "h" || input == "H" || input == "R" || input == "r"){
			break;
		}
		//If there is a string value in the input other then H or R
		else{
			//Inform the user of the failure
			cout << "Please input the correct value into the field, H for hold R for Roll. \n";
			//Clear and ignore the input
			cin.clear();
			cin.ignore();
		}
		//The loop value is arbitrary
	} while (cont == true);
	//Return the input
	return input;
}

//Define the computer round function
int computerround(){
	//Define the loop boolean
	bool cont = true;
	//define and initialize the local variables
	int round_score=0, roll=0;
	//define the control statement
	while (cont == true){
		//Roll the dice and store in a variable
		roll = rolldice();
		//Tell the user what the computer has rolled
		cout << "I rolled a: " << roll << "\n";
		//If the computer rolls a one
		if (roll == 1){
			//Output to let the user know what is going on
			cout << "Gimme? Oh Fine then.... \n";
			//Return Nothing
			return 0;
			//Set the loop parameter to false
			cont = false;
		}
		//If the computer rolls a 2 of 6 logic must be performed
		else if (roll == 2 || roll == 6){
			//Define and initialize what the round_score will be
			round_score = round_score + roll;
			//If the round_score is greater then 20
			if (round_score >= 20){
				//Tell the user what is going on
				cout << "I'm going to hold. \n";
				//Return the round_score
				return round_score;
				//Set the loop parameter to false
				cont = false;
			}
			//If the round score is less then 20 but will allow the computer to win
			else if (round_score + computer_score >= 100){
				//Tell the user what is going on
				cout << "I'm going to hold. \n";
				//Return the round score
				return round_score;
				//Set the loop parameter to false
				cont = false;
			}
		}
		//If the computer rolls something other then 1,2,or 6
		else{
			//increment the round score by the roll and beging the loop over
			round_score = round_score + roll;
		}
	}
	//After exiting the loop set the loop parameter back to true for the next loop
	cont = true;
}

//Define the player round function
int playerround(){
	//Define the loop boolean
	bool cont = true;
	//define and initialize the local variables
	int round_score = 0, roll = 0;
	//define the control statement
	while (cont == true){
		//Roll the dice and store in a variable
		roll = rolldice();
		//Tell the user what the player has rolled
		cout << "You have rolled a: " << roll << " \n";
		//If the player rolls a one
		if (roll == 1){
			//Tell the user what is happening
			cout << "Ouch.... \n";
			//Return nothing back
			return 0;
			//Set the loop Parameter to false
			cont = false;
		}
		//If the player rolls a 2 or 6 logic must be performed
		else if (roll == 2 || roll == 6){
			//Tally the round_score
			round_score = round_score + roll;
			//Output information for the user to make a decision
			cout << "Your Round Score so far is: " << round_score << " \n";
			cout << "Your Total Score so far is: " << player_score << " \n";
			cout << "Your Total Score with this round would be: " << round_score + player_score << " \n";
			cout << "Do you want to Roll again or Hold? R for Roll / H for Hold: ";
			//Get the user's decision with input validation
			string decision = getstring();
			//If the user decided to hold
			if (decision == "H" || decision == "h"){
				//Tell the user what is happening
				cout << "Playing it safe, lets see how it plays out for you. \n";
				return round_score;
				//Set the loop Parameter to false
				cont = false;
			}
		}
		//If the player rolls anything other then a 1,2, or 6
		else{
			//increment the round score by the roll and beging the loop over
			round_score = round_score + roll;
			//Tell the user what is happening
			cout << "Rolling again, your score so far is: " << round_score << " \n";
		}
	}
	cont = true;
}

//define the playgame function
void playgame(){
	//Define the loop variabled
	bool cont = true;
	//Define the control statement
	while (cont == true){
		//Perform the player round and receive the return
		int tempscore = playerround();
		//Add up the total player score
		player_score = player_score + tempscore;
		//If the player scores 100 or higher
		if (player_score >= 100){
			//Player wins
			cout << "Congratulations Player, you win with a total score of : " << player_score << "\n";
			//Exit the loop
			break;
		}
		//Perform the computer round and receive the return
		int comptempscore = computerround();
		//Add up the total computer score
		computer_score = computer_score + comptempscore;
		//If the computer score 100 or higher
		if (computer_score >= 100){
			//Computer wins
			cout << "Too bad Player, I win.....now bask in my awesomeness. I Scored: " << computer_score << "\n";
			//Exit the loop
			break;
		}
	}
}

//Define the main function
int main(){
	//Seed the random with the system time
	srand(time(NULL));
	//Play the game
	playgame();
	//Pause so I can see the output
	system("Pause");
	//All is well
	return 0;
}