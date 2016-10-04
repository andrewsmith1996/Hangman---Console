//
//  main.cpp
//  hangman
//
//  Created by Andrew Smith on 03/10/2016.
//  Copyright © 2016 Andrew Smith. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cctype>



using namespace std;


string getWord(){
    
    //Get Word from User
    cout << "Player One Enter Word\n";
   
    string userWord;
    cin >> userWord;
    
    //Convert the word to uppercase
    transform(userWord.begin(), userWord.end(),userWord.begin(), ::toupper);
    
    return userWord;
}

char getGuess(){
    
    //Get the guess from the user
    cout << "Take a Guess!\n";
    
    char guess;
    
    cin >> guess;
    
    //Return the uppercase version of the guess
    return toupper(guess);
}

bool checkIfInWord(string userWordList, char guess){
    bool inWord = false;
    
    //Check each character in the string to see if the guess is present
    for(int count = 0; count < userWordList.size(); count++){
        if(userWordList[count] == guess){
            inWord = true;

        }
    }
    
    return inWord;
}


int checkWhereInWord(string userWordList, char guess){
    int position;
    
    //Check each character in string for the guess
    for(int count = 0; count < userWordList.size(); count++){
        if(userWordList[count] == guess){
            position = count;
            
        }
    }
    
    return position;
}

                          
string hideWord(string userWord){
    string hiddenWord = "";
    
    //Create a new string of stars
    for(int count = 0; count < userWord.size(); count++){
        hiddenWord+= "*";
    }
    
    return hiddenWord;
}


int checkIfUnmasked(string hiddenWord){
    
    //Count number of stars to see if string has been unmasked
    int numberOfStars = count(hiddenWord.begin(), hiddenWord.end(), '*');
    
    return numberOfStars;
}

int main() {
    
    bool gameWon = false;
    int lives = 5;
    
    //Get the word
    string userWordOriginal = getWord();
    
    //Mask the word
    string hiddenWord = hideWord(userWordOriginal);

    
    //Declare the array
    char userWordList[userWordOriginal.size()];
    
    //Populate list with the string
    for(int count = 0; count < userWordOriginal.size(); count++){
        userWordList[count] = userWordOriginal[count];
    }
    
    while(gameWon == false){
        //Get the user's guess
        char guess = getGuess();
    
        //Find number of occurences
        int occurences = count(userWordOriginal.begin(), userWordOriginal.end(), guess);
        
    
        //Actual Game Loop
        if(occurences != 0){
            for(int count = 0; count < occurences; count++){
        
                //Check where the guess is in the word
                int position = checkWhereInWord(userWordList, guess);
                
                //Edit the masked string
                hiddenWord[position] = userWordOriginal[position];
                userWordList[position] = '*';
                
                //Check if word completely unmasked
                int numberStars = checkIfUnmasked(hiddenWord);
               
                if(numberStars == 0){
                    gameWon = true;
                }

            }
            
        } else{
            //If wrong then decrease the lives of the player
            lives--;
            
            //If no lives remaining then the game is over
            if(lives == 0){
                gameWon = true;
            }

        }
    
        //Print the word to the screen
        cout << hiddenWord << endl;
    
    }
    
    //Check how many lives remaining
    if(lives == 0){
        cout << "You ran out of lives!\nPlayer 2 Wins!\n";
    } else{
        cout << "You guessed the word!\nPlayer 1 Wins!\n";
    }
    
    return 0;
}



