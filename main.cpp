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


using namespace std;


hello

string getWord(){
    cout << "Player One Enter Word\n";
    string userWord;
    
    cin >> userWord;
    
    return userWord;
}

char getGuess(){
    cout << "Take a Guess!\n";
    
    char guess;
    
    cin >> guess;
    
    return guess;
}

int checkIfInWord(string userWordList, char guess){
    int position;
    
    for(int count = 0; count < userWordList.size(); count++){
        if(userWordList[count] == guess){
            position = count;

        }
    }
    
    return position;
}

                          
string hideWord(string userWord){
    string hiddenWord = "";
    for(int count = 0; count < userWord.size(); count++){
        hiddenWord+= "*";
    }
    
    return hiddenWord;
}

bool checkIfGameWon(string word){
    bool won = false;
    return 0;
}

int main() {
    
    bool gameWon = false;
    
    //Get the word
    
    string userWordOriginal = getWord();
    
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
    
  
        for(int count = 0; count < occurences; count++){
            int position = checkIfInWord(userWordList, guess);
           

            if(position){
                hiddenWord[position] = userWordOriginal[position];
                userWordList[position] = '*';
            } else{
                lives--;            }
        }
    
        cout << hiddenWord;
    
    }
    
    
    return 0;
}



