#include <stdio.h>

// Input: Line consisting of a list with ONLY positive integers 
// Sort the numbers from least to greatest
// Obtain the greatest common divisor between smallest and largest
// Output line 1: the greatest common divisor
// Output line 2: sorted list (by commas)
// CornerCase(s): can contain 0 integers, each int is < 1,000,000, each list has  less than 10,000 ints
// Could we use a sorting algorithm? Bubble sort? Selection Sort? 
// Technically we could double check after to make sure there is a list of elements? But do we do it before? 


// 10/04/2024
// 1.) Init an Empty List 'A' to store integers
// 2.) Read the input string using getchar
//      a.) For each Char
//          b.) If char is a digit, concatenate digits
// 3.) Sort list 'A' 
// 4.) Compute GCD of smallest and largest nums
// 5.) Print GCD
// 6.) Print list:
//      a.) Loop through the list
//          b.) For each element:
//              c.) If not last element, printf() followed by comma
//              d.) If last element, print without a comma

//10/08/2024
// 1.) Init Empty List to store inte
// 2.) Read input 
//      a.) Loop to read input using getchar
//      b.) If char is a digit --> concat 
//      c.) if char = comma or new line
//          store num into num list
//          update min and max
//          reset for next num
//          if new line; break
// 3.) Compute GCD of smallest and largest nums
// 4.) Print GCD
// 5.) Sort list
// 6.) Print the sorted list


/* IGNORE ABOVE: NOTES/THOUGHTS */

#define MAX_NUM 10000
#define MAX_VALUE 999999

int nums[MAX_NUM];
int counts[MAX_VALUE + 1];  // counts[0 ---> 999999]
int n = 0;

// Compute the Greatest Common Divisor (Euclidean?)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int ch;
    int num = 0;
    int min = MAX_VALUE;
    int max = 0;
    int i;

    // Read input line until End of File
    while ((ch = getchar()) != EOF) {
        
        // If the char is 0 or 9
        if (ch >= '0' && ch <= '9') {
            // Convert to num
            num = num * 10 + (ch - '0');
        
        // If comma or new line
        } else if (ch == ',' || ch == '\n') {

            // add number to array (increment count)
            nums[n++] = num;

            // update min if current num < 
            if (num < min) min = num;
            // update max if current num >
            if (num > max) max = num;
            // Reset num for next num
            num = 0;
            
            // If newline -> end of input; break
            if (ch == '\n') break;

        }
    }
    // Store the last number if not followed by a comma or newline
    if (num > 0) {
        // Add last number to array
        nums[n++] = num; 
        if (num < min) min = num; // Update min if neccess
        if (num > max) max = num; // Update max if neccess
    }

    // Compute GCD of the smallest and largest num
    int g = gcd(min, max);
    printf("%d\n", g);

    // Counting Sort
    for (i = 0; i < n; i++) {
        counts[nums[i]]++;
    }

    // Output sorted list
    for (i = 0; i <= max; i++) {
        while (counts[i] > 0) {
            printf("%d", i);
            counts[i]--;
            if (counts[i] > 0 || i < max) {
                putchar(',');
            }
        }
    }
    putchar('\n');
    return 0;
}