#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;



FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8 ;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (false)	//if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram;
	}else if (false)  //if the guess isnt all lowercase

	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLength())	 //if the guess lenth is wrong 

	{
		return EGuessStatus::Wrong_lenth;
	}

	else
	{
		return EGuessStatus::ok;
	}
	 
		//return an eeror
	//otherwise
		//return ok
}




// recevied a vaild guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{

	//incriments the turn number
	MyCurrentTry++;

	//setup a return varible
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();	//assuming same length as guess
	//loop throgh all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength;MHWChar++){
	//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {

			if (guess[GChar] == MyHiddenWord[MHWChar]) {
				//if the match then..
				if (MHWChar == GChar) {	//if they are in the same place
					BullCowCount.Bulls++;	//incriment bulls
				}
				else							//else
					BullCowCount.Cows++;	//incriment cows, must be cows
			}
		}
	}
	return BullCowCount;
}
