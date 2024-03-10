# Fallout 4 Terminal Cracker

This is a simple C++ program that helps crack the password in terminal hacking minigames found in Fallout 4. In the game, the player must guess a password by inputting words and their likeness to the correct password is then given, in this tool you provide that score, and it filters the remaining potential passwords.

## Features

- Allows the user to enter a list of words separated by commas.
- Accepts guesses from the user and provides feedback based on likeness scores.
- Filters out remaining words based on guessed words and likeness scores.
- Displays the final password when only one possible word remains.
- Handles input validation for integer input and string input.

## How to Use

1. Compile the program using a C++ compiler (e.g., g++):
g++ main.cpp -o fallout_terminal_cracker

2. Run the compiled executable:

./fallout_terminal_cracker

3. Follow the on-screen prompts:
- Enter a list of words separated by commas.
- Guess the password by entering words and providing likeness scores.

4. If the program narrows down the possible words to one, it will display the password.

5. Press enter to exit the program.

## Example

--- FALLOUT 4 TERMINAL CRACKER INITIALIZING ---
Enter all words separated by commas: hello,world,test,apple,banana  
Enter guessed word: hello  
Enter likeness score (0 - 5): 0  
Password: banana  
Press enter to exit  


## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.


