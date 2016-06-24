#pragma once
#include<string>

using FString = std::string;
using int32 = int;

// all values intialised to zero 
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus 
{
	invalid_status,
	ok,
	Not_Isogram,
	Wrong_lenth,
	Not_Lowercase

};

class FBullCowGame
{
public:

	FBullCowGame();	//Contructor
	int32 GetMaxTries() const ;
	int32 GetCurrentTry() const ;
	int32 GetHiddenWordLength() const ;
	bool IsGameWon() const ;


	EGuessStatus CheckGuessValidity(FString) const ; // ToDo make a more rich return value


	void Reset(); // ToDo make a more rich return value


	// counts Bulls&Cows and increases try # asuming a valid guess
	FBullCowCount SubmitValidGuess(FString);




private:

	// Look To The Contructor For Initialisation

	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const ;
};
			