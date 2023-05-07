#include <iostream>
#include <string>
#include<array>
#include<ctime>


using namespace std;

int main() {
    string words[] = {"computer","egypt","mohamed"}; // Hard-coded word
    srand(time(0));
    int n= rand()%size(words);
    string word = words[n];
    int numGuesses = 10; // Number of guesses allowed
    int numLetters = word.length(); // Number of letters in the word
    string guessedWord(numLetters, '_'); // String to represent the guessed letters
    char letter; // User's guess

    cout << "Welcome to guess the word game!" << endl;
    cout << "The word has " << numLetters << " letters." << endl;
    cout << "You have " << numGuesses << " guesses to try to guess them." << endl;
    cout << "The word so far is: " << guessedWord << endl;

    while (numGuesses > 0 && guessedWord != word) {
        cout << "Enter a letter: ";
        cin >> letter;

        bool correctGuess = false;

        for (int i = 0; i < numLetters; i++) {
            if (word[i] == letter) {
                guessedWord[i] = letter;
                correctGuess = true;
            }
        }

        if (correctGuess) {
            cout << "Correct guess! The word so far is: " << guessedWord << endl;
        } else {
            numGuesses--;
            cout << "Sorry, that letter is not in the word. You have " << numGuesses << " guesses left." << endl;
        }
    }

    if (numGuesses == 0) {
        cout << "Sorry, you ran out of guesses. The word was " << word << "." << endl;
    } else {
        cout << "Congratulations! You guessed the word!" << endl;
    }

    return 0;
}