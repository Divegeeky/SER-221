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
static int score1, score2;

//Define the rules function
void rules(){
	//Define the selection
	int selection;
	//Tell the user what to input
	cout << "Before we begin do you require instructions? Select 1 for yes and 2 for no: ";
	//Get the input from the user
	cin >> selection;
	//If the selection is invalid
	if (!selection){
		//Tell the user what they did
		cout << "\n " << "You did not enter anything, try again. \n";
		//Clear out and redo
		cin.clear();
		cin.ignore();
		rules();
	}
	//If the user needs instructions list the instructions
	else if (selection == 1){
		cout << "The rules are relatively easy to understand. \n";
		cout << "\n";
		cout << "\n";
		cout << "You will select either Rock, Paper, Scissors, Lizard, or Spock. \n";
		cout << "Your opponent will do the same \n";
		cout << "\n";
		cout << "Scissors cut paper, Paper covers rock, Rock crushes Lizard, Lizard poisons Spock";
		cout << "Spock smashes Scissors, Scissors decapitate lizard, Lizard eats paper \n";
		cout << "Paper disproves Spock, Spock vaporizes rock, and Rock crushes scissors \n";
		rules();
	}
	//If the user inputs that they do not need instructions
	else if (selection == 2){
		//Continue on
		cout << "\n" <<"Very well let's begin. \n";
		//Clear out the cin for future use
		cin.clear();
		cin.ignore();
	}
	//If there is anything else entered
	else {
		//Invalid
		cout << "\n" << "That was an invalid input, please try again. \n";
		//Clear
		cin.clear();
		cin.ignore();
		rules();
	}

}

//Define the player select function
int playerselect(){
	//Define the local variable
	int gameselect;
	//Request information
	cout << "Do you wish to play a one player or two player game? \n" <<  "Input 1 for one player 2 for two player:";
	//Get the seleciton
	cin >> gameselect;
	
	//Input Validation
	if (!gameselect){
		cout << "\n " << "You did not enter anything, try again. \n";
		//Clear out cin for future use
		cin.clear();
		cin.ignore();
		//Start function again
		playerselect();
	}
	// If the user chooses one
	else if (gameselect == 1){
		//Clear out cin for future use
		cin.clear();
		cin.ignore();
		//Return a 1
		return 1;
	}
	else if (gameselect == 2){
		//Clear out cin for future use
		cin.clear();
		cin.ignore();
		//Return a 2
		return 2;
	}
	else {
		cout << "\n" << "That was an invalid input, please try again. \n";
		//Clear out cin for future use
		cin.clear();
		cin.ignore();
		//Start function again
		playerselect();
	}
	
}

//Define the chooseweapon function
int chooseweapon(){
	//define the local variable
	string selection;
	//Tell the user what to input
	cout << "Please select your weapon. R for Rock, P for Paper, Sc for Scissors, L for Lizard, Sp for Spock: ";
	//Get the user input
	getline(cin, selection);
	//If user input Rock
	if ((selection == "r") || (selection == "R")){
		cout << "Rock, a strong choice, one with earth. \n";
		//Return a 1
		return 1;
	}	
	//If user input Paper
	else if ((selection == "p") || (selection == "P")){
		cout << "Paper, ahhh intellectual, imaginative, trickery is afoot. \n";
		//Return a 2
		return 2;
	}
	//If user input Scissors
	else if ((selection == "Sc") || (selection == "SC") || (selection == "sc") || (selection == "sC")){
		cout << "Scissors, yes metal, strong and unbendable are you. \n";
		//Return a 3
		return 3;
	}
	//If user input Lizard
	else if ((selection == "l") || (selection == "L")){
		cout << "Lizard, master of camoflague and venom. \n";
		//Return a 4
		return 4;
	}
	//If user input Spock
	else if ((selection == "Sp") || (selection == "SP") || (selection == "sp") || (selection == "sP")){
		cout << "Spock, Kirk's right hand man, master of logic. \n";
		//Return a 5
		return 5;
	}
	//If user messed up the input
	else {
		cout << "Lets try this again. \n";
		chooseweapon();
	}


}

//Define the computer choose function
int computerchoose(){
	//Define the local variable
	int compchoose;
	//Get a have the computer choose a random weapon
	compchoose = rand() % 5 + 1;
	//If the comp chooses 1
	if (compchoose == 1){
		cout << "Fear the Wrath of my......ROCK! \n";
	}
	//If the comp chooses 2
	else if (compchoose == 2){
		cout << "Fear the Wrath of my......PAPER! \n";
	}
	//If the comp chooses 3
	else if (compchoose == 3){
		cout << "Fear the Wrath of my......SCISSORS! \n";
	}
	//If the comp chooses 4
	else if (compchoose == 4){
		cout << "Fear the Wrath of my......LIZARD! \n";
	}
	//If the comp chooses 5
	else if (compchoose == 5){
		cout << "Fear the Wrath of my......SPOCK! \n";
	}
	//Return the choice
	return compchoose;
}

//Perform the combat validation with weapon 1 and 2 input
void combat(int weapon1, int weapon2){

	//All resulting rules are as described in rules
	//Will increment the winning "player's" score
	if (weapon1 == weapon2){
		cout << "You have tied, this isn't hockey! \n";
		score1++;
		score2++;
	}
	else if (weapon1 == 1 && weapon2 == 2){
		cout << "Paper Covers Rock! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 1 && weapon2 == 3){
		cout << "Rock Crushes Scissors! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 1 && weapon2 == 4){
		cout << "Rock Crushes Lizard! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 1 && weapon2 == 5){
		cout << "Spock Vaporizes Rock! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 2 && weapon2 == 1){
		cout << "Paper Covers Rock! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 2 && weapon2 == 3){
		cout << "Scissors Cut Paper! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 2 && weapon2 == 4){
		cout << "Lizard Eats Paper! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 2 && weapon2 == 5){
		cout << "Paper Disproves Spock! \n";
		cout << "Player 1 Wins. \n";
		score1++;

	}
	else if (weapon1 == 3 && weapon2 == 1){
		cout << "Rock Crushes Scissors! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 3 && weapon2 == 2){
		cout << "Scissors Cut Paper! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 3 && weapon2 == 4){
		cout << "Scissors Decapitate Lizard! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 3 && weapon2 == 5){
		cout << "Spock Smashes Scissors! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 4 && weapon2 == 1){
		cout << "Rock Crushes Lizard! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 4 && weapon2 == 2){
		cout << "Lizard Eats Paper! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 4 && weapon2 == 3){
		cout << "Scissors Decapitate Lizard! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 4 && weapon2 == 5){
		cout << "Lizard Poisons Spock! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}
	else if (weapon1 == 5 && weapon2 == 1){
		cout << "Spock Vaporizes Rock! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}		
	else if (weapon1 == 5 && weapon2 == 2){
		cout << "Paper Disproves Spock! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
	else if (weapon1 == 5 && weapon2 == 3){
		cout << "Spock Smashes Scissors! \n";
		cout << "Player 1 Wins. \n";
		score1++;
	}	
	else if (weapon1 == 5 && weapon2 == 4){
		cout << "Lizard Poisons Spock! \n";
		cout << "Player 2 Wins. \n";
		score2++;
	}
}

//Define the 1 Player function
void play1P(){
	//Define the local variables
	int playerweapon, compweapon;
	//Define the loop parameter
	bool cont = true;
	//Define the sel string
	string sel;
	//Define the control statement
	while (cont == true){
		//Have the player select their weapon
		playerweapon = chooseweapon();
		//Have the computer select weapon
		compweapon = computerchoose();
		//Perform Combat....MOOOOORTAL COMBAT!
		combat(playerweapon, compweapon);
		//Round scores
		cout << "Scores after this round: \n";
		cout << "     Player 1: " << score1 << "\n";
		cout << "     Player 2: " << score2 << "\n";
		cout << "\n";
		cout << "Thanks!!\n";
		cout << "\n";
		cout << "Play again? Y/y continues, other quits: ";
		//Determine if the user wants to play again
		getline(cin, sel);
		if (sel == "Y" || sel == "y"){
			//If they select yes
			cout << "Here we go again. \n";
		}
		else {
			//If not, exit the loop
			break;
		}
	}
}

//Define the 2 Player function
void play2P(){
	//Define the local variables
	int playerweapon, player2weapon;
	//Define the loop parameter
	bool cont = true;
	//Define the selection
	string sel;
	//Define the control statement
	while (cont == true){
		//Player1 weapon select
		playerweapon = chooseweapon();
		//Player 2 weapon select
		player2weapon = chooseweapon();
		//Perform Combat...Johnny Cage wins!
		combat(playerweapon, player2weapon);
		//Round resutls
		cout << "Scores after this round: \n";
		cout << "     Player 1: " << score1 << "\n";
		cout << "     Player 2: " << score2 << "\n";
		cout << "\n";
		cout << "Thanks!!\n";
		cout << "\n";
		cout << "Play again? Y/y continues, other quits: ";
		//Determine if they want to play again
		getline(cin, sel);
		//If yes
		if (sel == "Y" || sel == "y"){
			//Continue
			cout << "Here we go again. \n";
		}
		//If anything else
		else {
			//If they select no exit the loop
			break;
		}
	}
}

//Control function to determine which function to run 1p or 2P
void gameplay(int gameselect){
	//If the 1 is returned on select game
	if (gameselect == 1){
		//Start the 1P game
		play1P();
	}
	//If 2 is returned
	else if (gameselect == 2){
		//Start the 2P game
		play2P();
	}
}

//Define the main function
int main(){
	//Welcome the user
	cout << "Hello and welcome to the Rock, Paper, Scissors, Lizard, Spock game. \n";
	//Seed the random 
	srand(time(NULL));
	//Perform the rules function
	rules();
	//Determine and beging the game
	gameplay(playerselect());
	//Pause
	system("Pause");
	// Uh, everything's under control. Situation normal. 
	return 0;
}