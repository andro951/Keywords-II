//Keywords II
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	// Display Title of program to user
	cout << "====================================================" << endl;

	// Ask the recruit to login using thier name
	cout << "Please enter your name: ";

	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string userName;
	cin >> userName;
	cout << "====================================================" << endl;
	// Display an overview of what Keywords II is to the recruit 
	cout << "Congradulations on making it through the orrigional Keywords training program, " << userName << ".\n"
		<< "Due to your exceptional performance, you have been selected to continue training.\n"
		// Display an directions to the recruit on how to use Keywords
		<< "In Keywords II, the user guesses letters one at a time.\n"
		<< "If the guessed letter is contained in one of the 3 keywords, all of those letters will be revealed.\n"
		<< "The user continues to guess until the keywords are complete or the user has guessed wrong 8 times.\n";





	// Create a collection of 10 words you had wrote down manually
	string keywords[] =
	{
		{ "abyss" },
		{ "banshee" },
		{ "grail" },
		{ "dervish" },
		{ "essence" },
		{ "codex" },
		{ "forbidden" },
		{ "glacial" },
		{ "crucible" },
		{ "remnant" }
	};

	// Create an int var to count the number of simulations being run starting at 1
	int simulationNumber = 1;
	bool repeatProgram = false;  //Used to determine if the program loop should repeat.
	//Program loop
	do
	{
		// Display the simulation # is staring to the recruit. 
		cout << "====================================================\n"
			<< "Simulation #" << simulationNumber << endl
			<< "====================================================\n";
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		vector<string> randomThree; //Used to track which words have been added to correctWords.
		string correctWords = ""; //Combination of the random 3 keywords.
		string displayedWords = ""; //Current progrogress the user has made to guessing all of the letters in the correctWords.
		randomThree.empty(); //Deletes data from ramdomThree from the previous run of the program.
		int randomNumber;
		vector<string>::const_iterator iter; //Create a const iterator for use later.
		while (randomThree.size() < 3) //Choose random words from keywords[] until 3 have been chosen.
		{
			randomNumber = rand() % 10; //Create random number from 0-9.
			iter = find(randomThree.begin(), randomThree.end(), keywords[randomNumber]); //Choose a random keyword[] and check if it is already in randomThree.
			//If the word is already included, nothing else will happen, and the while loop will repeat.
			if (iter == randomThree.end()) //If the word is not included, add it to ramdomThree and correctWords.
			{
				randomThree.push_back(keywords[randomNumber]); //Add word to randomThree.
				correctWords += keywords[randomNumber]; //Add word to 
				displayedWords += string(keywords[randomNumber].length(), '_'); //Fill in blanks in displayedWords equal to the length of the chosen word.
				if (randomThree.size() < 3) //If there are less than 3 words chosen, add a space to correctWords and displayedWords.
				{
					correctWords += " ";
					displayedWords += " ";
				}
			}
		}

		string validGuesses = "abcdefghijklmnopqrstuvwxyz"; //Only accepts lower case letters as valid inputs.  Used to check all characters in the string input by the user as their guess.
		string lettersGuessed = string(validGuesses.length(), '_'); //Tracks all letters that have been guessed by the user.  Initially filled with blanks.
		int incorrectGuesses = 0; //Track the number of incorrect guesses.
		string guess; //Input from the user.
		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while (incorrectGuesses < 8 & displayedWords != correctWords)
		{
			cout << "Please enter your guess: ";
			//     Get recruit's next guess
			cin >> guess;
			bool validGuess = false; //Track if guess is contained in validGuesses.
			bool guessedPreviously = false; //Track if guess is contained in lettersGuessed.
			bool incorrectGuess = true; //Track if guess is contained in correctWords.
			if (guess.length() == 1) //The guess is not valid unless it is one character.
			{
				for (int i = 0; i < validGuesses.length(); i++) //Check if guess is contained in validGuesses.
				{
					if (guess[0] == validGuesses[i])
					{
						validGuess = true; //If it is contained in validGuesses, the guess is valid and the rest of the loop will exicute.
						//     While recruit has entered a letter that he or she has already guessed
						if (guess[0] == lettersGuessed[i]) //Check if guess is contained in lettersGuessed.
						{
							//          Get recruit ’s guess
							guessedPreviously = true; //Ask for a new guess.
							incorrectGuess = false; //Do not count the same guess against them that they have already made.
							cout << "You have already guessed this leter.\n";
						}
						//     Add the new guess to the group of used letters
						lettersGuessed[i] = guess[0]; //Add the guess to lettersGuessed.
					}
				}
			}
			if (validGuess)
			{
				if (guessedPreviously == false)
				{
					//          Update the word guessed so far with the new letter
					for (int i = 0; i < correctWords.length(); i++)
					{
						if (guess[0] == correctWords[i]) //If guess is contained in correctWords, add it to displayedWords and do not increase incorectGuesses.
						{
							displayedWords[i] = guess[0];
							incorrectGuess = false;
						}
					}
				}
			}
			else //If guess is longer than 1 character or not contained in validGuesses, get a new guess from the user.
			{
				cout << "Invalid guess.\n";
				incorrectGuess = false;
			}
			cout << "----------------------------------------------------\n";

			if (incorrectGuess) //If guess was valid but incorrect, add 1 to incorrectGuesses.
			{
				incorrectGuesses++;
			}
			//     Show player how much of the secret word he or she has guessed
			cout << displayedWords << endl
				//     Show recruit the letters he or she has guessed
				<< "letters guessed: " << lettersGuessed << endl
				//     Tell recruit how many incorrect guesses he or she has left
				<< "Incorrect guesses remaining: " << 8 - incorrectGuesses << endl;
		}

		cout << "----------------------------------------------------\n\n";

		if (incorrectGuesses < 8) //If the Guessing loop ended with less than 8 incorect words, the user guessed the words correctly.
		{
			//     Congratulate the recruit on guessing the secret words
			cout << "Congradulations.  You have guessed all 3 words correctly.\n";
		}
		// If the recruit has made too many incorrect guesses
		else
		{
			//     Tell the recruit that he or she has failed the Keywords II course.
			cout << "You have failed the Keywords II course.  You require more practice.\n";
		}

		bool waitingForValidInput = true;
		while (waitingForValidInput) //Repeats until a valid input is entered.
		{
			// Ask the recruit if they would like to run the simulation again
			cout << "Would you like to try again? (type yes or no)\n";
			string userAnswer; //Stores the user's answer to the above question.
			cin >> userAnswer;
			// If the recruit wants to run the simulation again
			if (userAnswer == "yes" || userAnswer == "Yes" || userAnswer == "YES") //If yes is entered, repeat the Program loop.
			{
				//     Move program execution back up to // Display the simulation # is staring to the recruit. 
				repeatProgram = true;
				waitingForValidInput = false;
			}
			// Otherwise 
			else if (userAnswer == "no" || userAnswer == "No" || userAnswer == "NO") //If no is entered, end the Program loop and exit the program.
			{
				repeatProgram = false;
				waitingForValidInput = false;
			}
			else //If anything other than yes or no is entered, repeat the waitingForValidInput loop.
			{
				cout << "\nInvalid input.\n\n";
			}
		}
		//     Increment the number of simiulations ran counter
		simulationNumber += 1;
	} while (repeatProgram);
	//     Display End of Simulations to the recruit
	cout << "End of simulation\n";
	//     Pause the Simulation with press any key to continue
	system("pause");	
}