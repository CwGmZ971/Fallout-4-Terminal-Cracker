# Fallout 4 Terminal Cracker

This is a simple C++ program (developed in Visual Studio 2022) that helps you crack the password in terminal hacking minigames found in Fallout 4. In the minigame, the player must guess a password by selecting words in the terminal window and the likeness to the correct password is then given, you can then provide that score to this tool and it will filter the remaining potential passwords until the correct password is found.

## Features

- Allows the user to enter a list of words separated by commas.
- Accepts guesses from the user and provides feedback based on likeness scores.
- Filters out remaining words based on guessed words and likeness scores.
- Displays the final password when only one possible word remains.
- Handles input validation for integer input and string input.

## How to Use

1. **Compilation**:
   - For Unix-like Systems: Compile the program using a C++ compiler (e.g., g++) with the following command:
     ```
     g++ main.cpp -o fallout_terminal_cracker
     ```
   - For Windows Users: Compile the program using Visual Studio or another IDE that supports C++ development.

2. **Running the Program**:
   - After compilation, run the compiled executable:
     ```
     ./fallout_terminal_cracker
     ```

3. **Follow the On-Screen Prompts**:
   - Enter a list of words separated by commas.
   - Guess the password by entering words and providing likeness scores.

4. **Password Retrieval**:
   - If the program narrows down the possible words to one, it will display the password.

5. **Exiting the Program**:
   - Press enter to exit the program.

## Example

--- FALLOUT 4 TERMINAL CRACKER INITIALIZING ---  
Enter all words separated by commas: hello,world,test,apple,banana  
Enter guessed word: hello  
Enter likeness score (0 - 5): 0  
Password: banana  
Press enter to exit

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
