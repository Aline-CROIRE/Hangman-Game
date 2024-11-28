include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    // Set up the game
    const int max_wrong = 8; // Maximum number of wrong guesses allowed

    vector<string> words; // Collection of possible words
    words.push_back("hang");
    words.push_back("better");
    words.push_back("true");
    words.push_back("trans");
    words.push_back("good");
    words.push_back("boy");
    words.push_back("girl");

    // Randomize the words
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(), words.end());
    const string TheWord = words[0]; // Word to guess

    int wrong = 0;
    string soFar(TheWord.size(), '_'); // Word guessed so far
    string used = "";                  // Letters already used

    // Welcome message
    cout << "Welcome to the Hangman Game. Good Luck!" << endl;

    // Main loop
    while ((wrong < max_wrong) && (soFar != TheWord)) {
        cout << "\nYou have " << (max_wrong - wrong) << " incorrect guesses left." << endl;
        cout << "You have used the following letters: " << used << endl;
        cout << "So far, the word is: " << soFar << endl;

        // Get player's guess
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        guess = tolower(guess); // Make guess lowercase

        while (used.find(guess) != string::npos) {
            cout << "You have already guessed '" << guess << "'." << endl;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = tolower(guess); // Make guess lowercase
        }

        used += guess;

        // Check if the player's guess is correct
        if (TheWord.find(guess) != string::npos) {
            cout << "That's right! '" << guess << "' is in the word." << endl;

            // Update `soFar` to include the new guess
            for (size_t i = 0; i < TheWord.size(); i++) {
                if (TheWord[i] == guess) {
                    soFar[i] = guess;
                }
            }
        } else {
            cout << "Sorry, '" << guess << "' is not in the word!" << endl;
            ++wrong;
        }
    }

    // End the game
    if (wrong == max_wrong) {
        cout << "\nYou have been Hanged!" << endl;
    } else {
        cout << "\nYou guessed it!" << endl;
    }
    cout << "The word was: " << TheWord << endl;

    return 0;
}
