
/* This programs expects numeric input at the beginning
 * in order to tell it which characters to print.
 * If for example, one wants only characters 0 to 10 from
 * the array printed, then one must enter 0 10 -1
 * (-1 to exit) and so if the string is 
 * "Hello my name is " only the first ten characters
 * of that string would be displayed
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_COLS 20 //Max columns to process
#define MAX_INPUT 1000 //Max length of input and output lines

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

int main(void) {
  int n_columns;   /* number of columns to process*/
  int columns[MAX_COLS];  /* the columns to process */
  char input[MAX_INPUT];  /* array for input line */
  char output[MAX_INPUT]; /* array for output line */

  /*
   * Read the list of column numbers
   */

  n_columns = read_column_numbers(columns, MAX_COLS); /* columns is an array of size 20, MAX_COLS is size 20 just passing the array and its size*/

  /*
   * Read, process and print the remaing lines of input
   */
  //gets*char var) read one line of text and pass to char array, not 0--> not end, NULL--> end
  //int c, string is a char arry terminated by a NUL
  //for example, "hello"-->h e l l o NUL
  //
  while( gets(input) != NULL ) {
    printf( "Original input : %s\n", input);
    rearrange(output, input, n_columns, columns);
    printf( "Rearranged line: %s\n", output );
  }//end while

  return EXIT_SUCCESS;
}//end main

int read_column_numbers(int columns[], int max) {
  int num = 0;
  int ch;
  /*
   * Get the numbers, stopping at eof or when a number is < 0
   */
  while( num < max && scanf( "%d", &columns[num] ) == 1 && columns[num] >= 0 ) {
    num += 1;
  }//end while

  /*
   * Make sure we have an even number of inputs, as they are supposed to be paired
   */ 
  if( num % 2 != 0 ) {
    puts( "Last column number not paired.");
    exit( EXIT_FAILURE );
  }//end if

  /*
   * Discard the rest of the line that contained the final number
   */ 
  while( (ch = getchar()) != EOF && ch != '\n' ) {
    ;
  }//end while
  return num;

}//end function

/*
 * Process a line of input by concatenating the characters from the indicating columns.
 * The output line is then NUL terminated
 */

void rearrange( char *output, char const *input, int n_columns, int const columns[] ) {

  int col;              /*subscript for column array */
  int output_col;       /* Output column counter */
  int len;              /* Length of input line */

  len = strlen( input );
  output_col = 0;
  /* 
   * Process each pair of column numbers 
  */

  for(col = 0; col < n_columns ; col +=2) { 
    int nchars = columns[col + 1] - columns[col] + 1;

    /* 
     * If the input line isn't this long or the output 
     * array is full, we're done.
     */
    if( columns[col] >= len || output_col == MAX_INPUT - 1 ) {
      break;
    }//end if

    /*
     * If there isn't enough room in the output array, only copy what
     * will fit
     */
    if( output_col + nchars > MAX_INPUT - 1 ) {
      nchars = MAX_INPUT - output_col - 1;
    }//end if

    /*
     * Copy the relevant data
     */  
    strncpy( output + output_col, input + columns[col], nchars );
    output_col += nchars;
  }//end for
  output[output_col] = '\0';
}//end function