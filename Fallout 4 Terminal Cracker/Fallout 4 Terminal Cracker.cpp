#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to calculate likeness score between two words
int calculateLikeness(const string& word1, const string& word2) {
    int likeness = 0;
    for (int i = 0; i < min(word1.length(), word2.length()); ++i) {
        if (word1[i] == word2[i]) {
            likeness++;
        }
    }
    return likeness;
}

// Function to filter remaining words based on guessed word and likeness
vector<string> filterWords(const vector<string>& remainingWords, const string& guessedWord, int likeness) {
    vector<string> filteredWords;
    for (const auto& word : remainingWords) {
        if (calculateLikeness(word, guessedWord) == likeness) {
            filteredWords.push_back(word);
        }
    }
    return filteredWords;
}

// Function to convert input to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to get input from the user
string getStrInput(const string& prompt) {
    string input;
    bool inputIsValid = false;
    while (!inputIsValid) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            inputIsValid = true;
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
    return input;
}

// Function to validate integer input within a specified range
int getIntInput(const string& prompt, size_t max) {
    int value;
    string input;
    bool inputIsValid = false;
    while (!inputIsValid) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        // Check if:
        // 1. Successfully extracted an integer from the stringstream (ss >> value)
        // 2. End-of-file flag is set on the stringstream (ss.eof())
        // 3. Extracted integer is within the specified range (value >= 0 && value <= max)
        if (ss >> value && ss.eof() && value >= 0 && value <= max) {
            inputIsValid = true;
        }
        else {
            cout << "Invalid input. Please enter an integer between 0 and " << max << "." << endl;
        }
    }
    return value;
}

// Function to display remaining possible words
void displayRemainingWords(const vector<string>& remainingWords) {
    cout << "Possible words narrowed down to: ";
    for (const auto& word : remainingWords) {
        cout << word << " ";
    }
    cout << endl;
}

int main() {
    const string VERSION = "1.1.1";
    
    cout << "--- FALLOUT 4 TERMINAL CRACKER v" << VERSION << " INITIALIZING ---\n";

    string inputWords = getStrInput("Enter all words separated by commas: ");
    stringstream ss(inputWords);
    vector<string> remainingWords;
    string word;

    while (getline(ss, word, ',')) {
        remainingWords.push_back(toLower(word));
    }

    while (remainingWords.size() > 1) {
        string guessedWord = toLower(getStrInput("Enter guessed word: "));

        auto wordIter = find(remainingWords.begin(), remainingWords.end(), guessedWord);

        if (wordIter == remainingWords.end()) {
            cout << "Guessed word is not in the list of remaining words. Please guess again.\n";
            continue;
        }

        size_t maxLikeness = guessedWord.length();
        int likeness = getIntInput("Enter likeness score (0 - " + to_string(maxLikeness) + "): ", maxLikeness);

        remainingWords = filterWords(remainingWords, guessedWord, likeness);

        if (remainingWords.empty()) {
            cout << "No possible words remaining. Check input or previous guesses." << endl;
            break;
        }
        else if (remainingWords.size() != 1) {
            displayRemainingWords(remainingWords);
        }
    }

    if (!remainingWords.empty()) {
        cout << "Password: " << remainingWords[0] << endl;
    }

    cout << "Press enter to exit";
    cin.ignore();
    return 0;
}
