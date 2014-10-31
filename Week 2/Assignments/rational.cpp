/* This Program was developed by Jason Pototsky
10/25/2014 for Week 2 Assignment
For SER221 Programming and Their Execution Environment - 88915
Instructor: Jeffrey Buck
*/

//Preprocessor Directives
#include<iostream>
using namespace std;
class Rational{
	public:
		int numerator;
		int denominator;
		Rational(){
			this->numerator = 0;
			this->denominator = 1;
			normalize();
		}
		Rational(int input_num, int input_dem){
			this->numerator = input_num;
			this->denominator = input_dem;
			normalize();
		}
		Rational(int wholenumber){
			this->numerator = wholenumber;
			this->denominator = 1;
			normalize();
		}
		
		int gcd(){
			int tempnum = this->numerator;
			int tempdem = this->denominator;
			int temp;
			while (tempdem){
				temp = tempdem;
				tempdem = tempnum % tempdem;
				tempnum = temp;
			}
			return temp;
		}
		void normalize(){
			int gcd = this->gcd();
			if (gcd != 0){
				this->numerator = this->numerator / gcd;
				this->denominator = this->denominator / gcd;
			}
			if (this->denominator < 0 ){
				this->denominator = this->denominator * -1;
				this->numerator = this->numerator  * -1;
			}
			
		}
		friend ostream &operator<<(ostream &output, const Rational& number1)
		{
			output << number1.numerator << "/" << number1.denominator;
			return output;
		}
		friend istream &operator>>(istream  &input, Rational &number1)
		{
			input >> number1.numerator >> number1.denominator;
			return input;
		}
		friend bool operator ==(const Rational& number1, const Rational& number2);
		friend bool operator <(const Rational& number1, const Rational& number2);
		friend bool operator <=(const Rational& number1, const Rational& number2);
		friend bool operator >(const Rational& number1, const Rational& number2);
		friend bool operator >=(const Rational& number1, const Rational& number2);
		friend Rational operator +(const Rational& number1, const Rational& number2);
		friend Rational operator -(const Rational& number1, const Rational& number2);
		friend Rational operator *(const Rational& number1, const Rational& number2);
		friend Rational operator /(const Rational& number1, const Rational& number2);
};
bool operator ==(const Rational& number1, const Rational& number2){
	return (number1.numerator * number2.denominator == number1.denominator * number2.numerator);
}
bool operator <(const Rational& number1, const Rational& number2){
	return (number1.numerator * number2.denominator < number1.denominator * number2.numerator);
}
bool operator >(const Rational& number1, const Rational& number2){
	return (number1.numerator * number2.denominator > number1.denominator * number2.numerator);
}
bool operator <=(const Rational& number1, const Rational& number2){
	return (number1.numerator * number2.denominator < number1.denominator * number2.numerator || number1.numerator * number2.denominator == number1.denominator * number2.numerator);
}
bool operator >=(const Rational& number1, const Rational& number2){
	return (number1.numerator * number2.denominator > number1.denominator * number2.numerator || number1.numerator * number2.denominator == number1.denominator * number2.numerator);
}
Rational operator +(const Rational& number1, const Rational& number2){
	int tempnum = (number1.numerator*number2.denominator) + (number2.numerator*number1.denominator);
	int tempdem = (number1.denominator*number2.denominator);
	Rational numbertoreturn = Rational(tempnum, tempdem);
	return numbertoreturn;
}
Rational operator -(const Rational& number1, const Rational& number2){
	int tempnum = (number1.numerator*number2.denominator) - (number2.numerator*number1.denominator);
	int tempdem = (number1.denominator*number2.denominator);
	Rational numbertoreturn = Rational(tempnum, tempdem);
	return numbertoreturn;
}
Rational operator *(const Rational& number1, const Rational& number2){
	int tempnum = (number1.numerator * number2.numerator);
	int tempdem = (number1.denominator * number2.denominator);
	Rational numbertoreturn = Rational(tempnum, tempdem);
	return numbertoreturn;
}
Rational operator /(const Rational& number1, const Rational& number2){
	int tempnum = (number1.numerator * number2.denominator);
	int tempdem = (number1.denominator * number2.numerator);
	Rational numbertoreturn = Rational(tempnum, tempdem);
	return numbertoreturn;
}
void yesorno(bool value){
	if (value == true){
		cout << "true";
	}
	else if (value == false){
		cout << "false";
	}
}
int main(){
	cout << "Welcome to my Rational number calculator. \n";
	Rational rational1;
	Rational rational2;
	cout << "Please input the value for the first rational number in the form of numerator then denominator: ";
	cin >> rational1;
	cout << "Please input the value for the second rational number in the form of numerator then denominator: ";
	cin >> rational2;
	cout << "The value for rational 1 is: " << rational1 << "\n";
	cout << "The value for rational 2 is: " << rational2 << "\n";
	Rational rational3 = rational1 + rational2;
	Rational rational4 = rational1 - rational2;
	Rational rational5 = rational1 * rational2;
	Rational rational6 = rational1 / rational2;
	cout << "Adding these numbers gives you: " << rational3;
	cout << "Subtracting these numbers gives you: " << rational4;
	cout << "Multiplying these numbers gives you: " << rational5;
	cout << "Dividing these numbers gives you: " << rational6;
	cout << "Is Rational 1 less then Rational 2? : ";
	yesorno(rational1 < rational2);
	cout << "\n";
	cout << "Is Rational 1 greater then Rational 2? : ";
	yesorno(rational1 > rational2);
	cout << "\n";
	cout << "Is Rational 1 less then or equal to Rational 2? : ";
	yesorno(rational1 <= rational2);
	cout << "\n";
	cout << "Is Rational 1 greater then or equal to Rational 2? : ";
	yesorno(rational1 >= rational2);
	cout << "\n";
	system("Pause");
	return 0;
}