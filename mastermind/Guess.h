#ifndef GUESS_H
#define GUESS_H

#include <utility>
#include <ctime>
#include <iostream>

using namespace std;

class Guess
{
private:
	int aGuess[4];
	bool isValid(int);
public:
	Guess();
	void setGuess(int, int, int, int);
	void secretCode();
	int operator[](int) const;
};

//implementations
Guess::Guess()
{
	aGuess[0] = aGuess[1] = aGuess[2] = aGuess[3] = -1;
	srand(time(NULL));
}
int Guess::operator[](int index) const
{
	return aGuess[index];
}
//checks to see if the guess is a valid number
bool Guess::isValid(int num)
{
	return (num >= 0 && num <= 5);
}
//sets the guess to 4 valid ints
void Guess::setGuess(int g1, int g2, int g3, int g4)
{
	if (isValid(g1)) aGuess[0] = g1;
	else cout << "The first element of your guess is not a valid guess" << endl;
	if (isValid(g2)) aGuess[1] = g2;
	else cout << "The second element of your guess is not a valid guess" << endl;
	if (isValid(g3)) aGuess[2] = g3;
	else cout << "The third element of your guess is not a valid guess" << endl;
	if (isValid(g4)) aGuess[3] = g4;
	else cout << "The fourth element of your guess is not a valid guess" << endl;
}
//sets the secret code to a random number 0-5
void Guess::secretCode()
{
	aGuess[0] = rand()%6;
	aGuess[1] = rand()%6;
	aGuess[2] = rand()%6;
	aGuess[3] = rand()%6;
}
#endif
