#include "luhn.h"
#include <stdbool.h>
#include "string.h"
#include "stdlib.h"

/* <Validation> per "Validating a Number" */
bool disallowed(char suschar){
  // ASCII: numbers 0-9 = codes 48-57, SPACE = 32
  return (suschar < 48 || suschar > 57) && !(suschar == 32);
}

bool passes_validation(char* sus){
  bool no_disallowed_chars_present = true; // innocent until proven guilty
  int space_count = 0;
  for ( int i=strlen(sus)-1; i >= 0; i-- ) {
    if (disallowed(sus[i])){
      no_disallowed_chars_present = false;
    } else if (sus[i] == 32) {
      space_count += 1;
    } else {
    };
  };
  return  no_disallowed_chars_present && ((strlen(sus)-space_count)>1);
}
/* </Validation> per "Validating a Number" */
/* <Luhn> */

// Why use a builtin when you can make assumptions and write from scratch?
// Simply convert ASCII '0'-'9' to int 0-9
int ctoi(char c){ 
  return (int)c - 48;
}

int sum_of_doubles(char *valid_num){
  const int luhn_doubles[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
  int running_sum = 0;
  int odd = strlen(valid_num) % 2; // even = 0, odd = 1
  
  /* Hold on. Why is this for loop so messy? Well.. (Using ld = luhn_doubles)
   *   1 2 3 ->    1  + ld[2] +    3      // double [1],     not [0] or [2]  *
   * 1 2 3 4 -> ld[1] +    2  + ld[3] + 4 // double [0],[2], not [1] or [3]  *
   * If even length, double odd indexes; if odd length, double even indexes. */

  /* Adding spaces to the mix:
   * 1 ' ' 2 3 ->  1  + ld[2] + 3 // now double [3] and.. [0]?        * 
   * Every time we cross a space we can simply invert the logic.      *
   * Here, even length + odd indexes, hit the space, flip to doubling *
   * even length + even index.                                        */

  /* Why not just remove the spaces and skip all of this?
   * Well, frankly, I wanted to avoid dynamic array sizing and be cheeky *
   * with with a minor efficiency gain. That would totally work though.  */
  
  for ( int i=strlen(valid_num)-1; i >= 0; i-=1 ) {
    if (valid_num[i] != 32){ // never count spaces in the total
      if ((odd && (i%2)) || (!odd && !(i%2))){ // look up luhn double
        running_sum += luhn_doubles[ctoi(valid_num[i])]; 
      } else {
        running_sum+=ctoi(valid_num[i]);
      };
    } else {
      odd = !odd;
    };
  };
  return running_sum;
}

bool luhn( char *input_num ) {
  // ! (sum_of_doubles % 10) yields true if evenly divisible by 10
  return passes_validation(input_num) && !(sum_of_doubles(input_num) % 10);
}
/* </Luhn> */
