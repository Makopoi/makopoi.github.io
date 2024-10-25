#include<iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void generateRandomNumbers(vector<int>& numbers) {
    while (numbers.size() < 5) {
        int num = rand() % 50 + 1; // Generate random number between 1 and 50
        if (find(numbers.begin(), numbers.end(), num) == numbers.end()) {
            numbers.push_back(num);
        }
    }
}

void displayGuessedNumbers(const vector<int>& guessedNumbers) {
    cout << "You have guessed these numbers: ";
    for (int guess : guessedNumbers) {
        cout << guess << " ";
    }
    cout << endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // seed random number generator
    char playAgain;

    do {
        vector<int> numbersToGuess;
        generateRandomNumbers(numbersToGuess);

        vector<int> guessedNumbers;
        int attempts = 0;

        cout << "\nWelcome to the Five Guessing Number game!" << endl;
        cout << "I have selected 5 random numbers between 1 and 50." << endl;
        cout << "You can enter your guesses one by one." << endl;
        cout << "Type 'exit' to quit the game at any time." << endl;

        while (guessedNumbers.size() < 0) {
            string input;
            cout << "Enter your guess (1-50) or type 'exit' to quit: ";
            cin >> input;

            if (input == "exit") {
                cout << "Thank you for playing! Goodbye!" << endl;
                return 0;
            }

            // Convert input to integer
            int guess;
            try {
                guess = stoi(input);
            } catch (invalid_argument&) {
                cout << "Invalid input. Please enter a number between 1 and 50." << endl;
                continue;
            }

            // Check if guess is valid
            if (guess < 1 || guess > 50) {
                cout << "Number out of range! Please guess a number between 1 and 50." << endl;
                continue;
            }

            // Provide feedback
            if (find(guessedNumbers.begin(), guessedNumbers.end(), guess) != guessedNumbers.end()) {
                cout << "You've already guessed that number!" << endl;
            } else {
                guessedNumbers.push_back(guess);
                attempts++;
                
                if (find(numbersToGuess.begin(), numbersToGuess.end(), guess) != numbersToGuess.end()) {
                    cout << "Correct guess!" << endl;
                } else {
                    cout << "Wrong guess! Try again." << endl;
                }

                // Display guessed numbers
                displayGuessedNumbers(guessedNumbers);

                // Check if all numbers are guessed
                if (guessedNumbers.size() >= 5) {
                    cout << "Congratulations! You've guessed all the numbers." << endl;
                    cout << "It took you " << attempts << (attempts == 1 ? " attempt." : " attempts.") << endl;
                }
            }
        }

        cout << "The numbers to guess were: ";
        for (int num : numbersToGuess) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Would you like to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing! Goodbye!" << endl;
    return 0;
}
