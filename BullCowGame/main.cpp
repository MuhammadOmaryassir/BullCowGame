/*
this is console excutble, that makes use of bullCowGame class
this acts as the view in a  MVC pattern, and is responsible for all 
user interaction. For the game logic check the FBullCowGame class.
*/
#include<iostream>
#include<string>
#include"FBullCowGame.h"

using FText = std::string;
using int32 = int;


//methods prototypes

void PrintIntro();	
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instantiate For a new game

int main()
{
	bool bPlayAgain = false;
	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain=AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0;  //exit the application
}


//		End Of Main.Cpp

//intro to the game
void PrintIntro() {

	std::cout << "\n\nWelcome To Bulls and Cows \n";
	std::cout << "Can You guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram am thinking of ..? \n";

	std::cout << std::endl;
	return;
}

//Play The Game
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//std::cout << MaxTries << std::endl;

	//loop asking for guesses while the game is not won
	//and still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)	{
		FText guess = GetValidGuess(); 

		// submit the valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess);

		//print numbers of bulls and cows
		std::cout << "Bulls= " << BullCowCount.Bulls;
		std::cout << ". Cows= " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}


//loop continualy until the user gives a valid guess
FText GetValidGuess()  

{
	FText guess = "";
	EGuessStatus status = EGuessStatus::invalid_status;

	do {
	//get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry ();
	std::cout << "Try"<< CurrentTry<<". Enter a guess  ";
	std::getline(std::cin, guess); 

	status = BCGame.CheckGuessValidity(guess);
	
	switch (status)
	{
	case EGuessStatus::Wrong_lenth:
		std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n\n";
		break;

	case EGuessStatus::Not_Isogram:
		std::cout << "please enter a word without repeating letters.\n\n";
		break;
	
	default:
	// assumeing the guess is valid	
		break;
		}

	} while (status != EGuessStatus::ok); //keep looping until we get no errors
	return guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same hidden word.?  (Y,N)\n";
	FText response = "";
	std::getline(std::cin, response);
	return (response[0] == 'Y' )|| (response[0] == 'y');
}
 
void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well Done - You Win!\n";
	}
	else
	{
		std::cout << "Better Luck Next Time!\n";
	}
}
