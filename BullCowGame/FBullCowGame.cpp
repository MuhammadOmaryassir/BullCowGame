#include "FBullCowGame.h"
#include <map>
#define TMap std::map


using int32 = int;
using FString = std::string;



FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 3 ;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	bGameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))	//if the guess isnt an isogram
	{
		return EGuessStatus::Not_Isogram; //ToDo write function

	}else if (false)  //if the guess isnt all lowercase

	{
		return EGuessStatus::Not_Lowercase; //ToDo write function
	}
	else if (Guess.length() != GetHiddenWordLength())	 //if the guess lenth is wrong 

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

	if(BullCowCount.Bulls==WordLength)
	{
		bGameIsWon = true;

	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen; //setup our map 

	for(auto Letter : Word) //For all letters in the word 
	{ 
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we do NOT have an isogram
			
		}
		else {
			LetterSeen[Letter] = true;// add the letter to the map
			
		}
	}
	return true; // for example in cases where /0 is entered
}


