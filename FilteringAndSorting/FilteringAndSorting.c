#include <stdio.h>
#include <stdlib.h>

// 1.) Read up to 10,000 chars from std input
// 2.) Extract words containing CS240
// 3.) Sort these words in ASCII order
// 4.) Outputs sorted words and their indicies

// Test Case: If there are no wrods that contain "CS240" print nothing.
// Use only stdio.h and stdlib.h
// Utilize putchar(), getchar(), printf(), and scanf()
// Cannot use string.h

/* IGNORE ABOVE - COMMENTS ARE FOR PLANNING AND MAKING SURE I EXECUTE WHAT IS NEEDED*/

#define MAX_INPUT_LENGTH 10000   // Max length of the input text
#define MAX_WORD_LENGTH 1000     // Max length of a single word
#define MAX_WORDS 1000           // Max number of words 

char words[MAX_WORDS][MAX_WORD_LENGTH];   // Arr for substring "CS240"
int word_lengths[MAX_WORDS];              // Arr for lengths of words
int word_indices[MAX_WORDS];              // Arr for original indices of words

// Function to swap two words 
void swap_words(int i, int j)
{
    int temp_length = word_lengths[i];       
    word_lengths[i] = word_lengths[j];       // Swap word
    word_lengths[j] = temp_length;          

    int temp_index = word_indices[i];        
    word_indices[i] = word_indices[j];       // Swap indices
    word_indices[j] = temp_index;           

    // Swap words char by char
    for (int k = 0; k < MAX_WORD_LENGTH; k++)
    {
        char temp_char = words[i][k];        
        words[i][k] = words[j][k];           
        words[j][k] = temp_char;             
    }
}

// Function to compare two word lexi
int compare_words(int i, int j)
{
    int len_i = word_lengths[i];             
    int len_j = word_lengths[j];            
    int min_len = (len_i < len_j) ? len_i : len_j;   

    // Compare the words char by char
    for (int k = 0; k < min_len; k++)
    {
        if (words[i][k] < words[j][k])       
            return -1;                       
        else if (words[i][k] > words[j][k])  
            return 1;                        
    }

    // If all char min_len -> compare lengths
    if (len_i < len_j)
        return -1;                          
    else if (len_i > len_j)
        return 1;                            
    else
        return 0;                            
}

// Function to sort using bubble sort algorithm
void bubbleSort(int n)
{
    int swapped;                             

    for (int i = 0; i < n - 1; i++)          // Loop through each element
    {
        swapped = 0;                         
        for (int j = 0; j < n - i - 1; j++)  
        {
            int cmp = compare_words(j, j + 1);   
            if (cmp > 0)                        
            {
                swap_words(j, j + 1);            
                swapped = 1;                     
            }
            else if (cmp == 0)                  
            {
                // Compare indices 
                if (word_indices[j] > word_indices[j + 1])
                {
                    swap_words(j, j + 1);        
                    swapped = 1;                 
                }
            }
        }
        if (!swapped)                            
            break;                               // Array is sorted; exit early
    }
}

int main()
{
    int total_input_chars = 0;                   
    int total_words = 0;                         // Total number of words containing "CS240"
    int word_index = 0;                          // Index of the current word 
    char word_buffer[MAX_WORD_LENGTH];           // Buffer 
    int word_length = 0;                         // Length of the current word
    char c;                                      // Store the current cha

    // Read input char until EOF or max input length is reached
    while ((c = getchar()) != EOF && total_input_chars < MAX_INPUT_LENGTH)
    {
        total_input_chars++;                     // Increment total input char 
        // Check for whitespace  
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (word_length > 0)                
            {
                int contains_CS240 = 0;          // Indicate if word contains "CS240"
                // Check if the word contains "CS240" 
                for (int i = 0; i <= word_length - 5; i++)
                {
                    if (word_buffer[i] == 'C' &&
                        word_buffer[i + 1] == 'S' &&
                        word_buffer[i + 2] == '2' &&
                        word_buffer[i + 3] == '4' &&
                        word_buffer[i + 4] == '0')
                    {
                        contains_CS240 = 1;      // Set the flag if "CS240" is found
                        break;                   // Exit the loop early
                    }
                }
                if (contains_CS240)              // If the word contains "CS240"
                {
                    // Copy the word into the words array
                    for (int i = 0; i < word_length; i++)
                    {
                        words[total_words][i] = word_buffer[i];
                    }
                    word_lengths[total_words] = word_length;    // Store word length
                    word_indices[total_words] = word_index;     // Store word original index
                    total_words++;                              // Increment the total word count

                    if (total_words >= MAX_WORDS)               // Check if max word reached
                        break;                                  // Exit the loop 
                }
                word_length = 0;                                // Reset word length for next word
                word_index++;                                   // Increment the word index
            }
        }
        else
        {
            if (word_length < MAX_WORD_LENGTH)                  // Ensure word length is within limit
            {
                word_buffer[word_length++] = c;                 // Add character to buffer
            }
        }
    }

    // Handle the last word; input --> doesn't end with whitespace
    if (word_length > 0)
    {
        int contains_CS240 = 0;                  // indicate if word contains "CS240"
        // Check if the word contains "CS240" 
        for (int i = 0; i <= word_length - 5; i++)
        {
            if (word_buffer[i] == 'C' &&
                word_buffer[i + 1] == 'S' &&
                word_buffer[i + 2] == '2' &&
                word_buffer[i + 3] == '4' &&
                word_buffer[i + 4] == '0')
            {
                contains_CS240 = 1;              // Set the flag if "CS240" is found
                break;                           // Exit the loop early
            }
        }
        if (contains_CS240)                      // If the word contains "CS240"
        {
            // Put word into the words array
            for (int i = 0; i < word_length; i++)
            {
                words[total_words][i] = word_buffer[i];
            }
            word_lengths[total_words] = word_length;    // Store the word length
            word_indices[total_words] = word_index;     // Store the word original index
            total_words++;                              // Increment the total word count
        }
        word_length = 0;                                // Reset word length
        word_index++;                                   // Increment the word index
    }

    if (total_words > 0)                                // If there are word containing "CS240"
    {
        bubbleSort(total_words);                        // Sort the words lexi~

        // Output the sorted words - commas
        for (int i = 0; i < total_words; i++)
        {
            for (int j = 0; j < word_lengths[i]; j++)
            {
                putchar(words[i][j]);                   // Print each char of the word
            }
            if (i < total_words - 1)
                putchar(',');                           // Print comma if not the last word
        }
        putchar('\n');                                  // Move to the next line

        // Output original indices of the sorted words separated by comma
        for (int i = 0; i < total_words; i++)
        {
            printf("%d", word_indices[i]);              // Print word original index
            if (i < total_words - 1)
                putchar(',');                           // Print comma if not the last index
        }
    }

    return 0;                                          
}
