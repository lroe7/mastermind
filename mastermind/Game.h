#ifndef GAME_H
#define GAME_H

#include "Guess.h"
#include <iostream>

using namespace std;

class Game
{
private:
	Guess userGuess;
	Guess secretCode;
	int whitePegs, blackPegs, numGuesses;
	void giveFeedback();
	bool isWinner();
	bool gameOver();
public:
	Game();
	void playGame();
	void getGuess();
};

//implementations
Game::Game()
{
	whitePegs = blackPegs = numGuesses = 0;
}
void Game::playGame()
{
	//set the secret code
	secretCode.secretCode();
	//plays the game, gets guess from user and gives feedback until the game ends
	do
	{
		getGuess();
		giveFeedback();
		numGuesses++;
		if (isWinner())
		{
			cout << "YOU WIN" << endl;
			//end the game
		}
		else if (gameOver())
		{
			cout << "YOU LOSE" << endl;
			cout << "The secret code was " << secretCode[0] << secretCode[1] << secretCode[2] << secretCode[3] << endl;
			//end the game
		}
	} while (!isWinner() && !gameOver());
}
//takes the user's guess and sets the user guess to what the user inputted
void Game::getGuess()
{
	int a, b, c, d;
	cout << "Please enter 4 integers from 0-5 for a guess" << endl;
	cin >> a >> b >> c >> d;
	userGuess.setGuess(a, b, c, d);
}
void Game::giveFeedback()
{
	//initialize the counter arrays
	whitePegs = blackPegs = 0;
	int codeCount[6];
	int guessCount[6];
	for (int i = 0; i < 6; i++)
	{
		codeCount[i] = 0;
		guessCount[i] = 0;
	}
	//count black pegs
	for (int i = 0; i < 4; i++)
	{
		if (userGuess[i] == secretCode[i])
			blackPegs++;
	}
	//count white pegs
	for (int i = 0; i < 4; i++)
	{
		int a = userGuess[i];
		guessCount[a] ++;
		int b = secretCode[i];
		codeCount[b] ++;
	}
	for (int i = 0; i < 6; i++)
	{
		if (codeCount[i] <= guessCount[i])
			whitePegs += codeCount[i];
		else
			whitePegs += guessCount[i];
	}
	whitePegs = whitePegs - blackPegs;
	cout << "You have " << whitePegs << " white pegs and " << blackPegs << " black pegs " << endl;
	cout << "You have " << 9 - numGuesses << " guesses left " << endl;
}
//checks if the user input the right guess and won the game
bool Game::isWinner()
{
	if (blackPegs == 4)
		return true;
	else
		return false;
}
//checks to see if the game is over because the user ran out of guesses
bool Game::gameOver()
{
	if (numGuesses == 10)
		return true;
	else
		return false;
}
#endif 
