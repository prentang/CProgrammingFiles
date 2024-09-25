#include <stdio.h>

// Input text can be empty, single line, or multiple lines
// Word - sequence of non-whitespace char - seperated by space, tabs, newline: count
// Char - occurrences of each alphab char in text - include uppercase: print char and count e.g. format: char: count
// Corner cases: only allowed 10000 max. char and if empty string must return empty string

int main() {
    int word_count = 0;     //Init the word count to zero
    int is_in_word = 0;       //Flag to indicate if currently inside a word
    int letterCount[26] = {0};  //Array to hold counts of letters a -> z
    int currentChar;         //Variable to store the current char
    int maxChars = 10000;    //Maximum number of char to read
    int charsRead = 0;     //Counter for the number of char read

    //Read characters until EOF or maxChars is reached
    while ((currentChar = getchar()) != EOF && charsRead < maxChars) {
        charsRead++;     //Increment the char read count

        //Check if the current char is a 'whitespace' char
        if (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
            is_in_word = 0;   //Not inside a word anymore
        } else {
            //If not already in a word, found a new word
            if (!is_in_word) {
                word_count++;  //Increment the word count
                is_in_word = 1;  //Indicate we're inside a word
            }
        }

        //Check if the char is an alphabetic letter
        if ((currentChar >= 'a' && currentChar <= 'z') ||
            (currentChar >= 'A' && currentChar <= 'Z')) {
            char c = currentChar | 32;  //Convert to lowercase (if uppercase)
            letterCount[c - 'a']++;   //Increment the count for this letter
        }
    }

    //If no words were found in the input
    if (word_count == 0) {
    //Do not print anything (empty string)
        return 0; //Exit the program- bye
    }

    //Print the total number of words
    printf("%d\n", word_count);

    //Loop through each letter in the alphabet
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0) {
            putchar('a' + i);    //Print the letter
            putchar(':');    //Print a colon
            putchar(' ');     //Print a space
            printf("%d\n", letterCount[i]);  //Print the count of the letter
            //* IGNORE: printf("%c: %d\n", 'a' + i) <-- Multi-char constant warning/error
        }
    }

    return 0;  
}
