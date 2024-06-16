#include "luhn.h"
#include <stdbool.h>
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"

/* <Validation> per "Validating a Number" */
bool passes_validation(char* sus){
  return input_length_allowed(sus) && contains_only_allowed_chars(sus);
}

bool input_length_allowed( char* sus){
  return (strlen(sus) > 1) || printf("ERROR: length of input must be greater than 1"); 
}

bool contains_only_allowed_chars(char* sus){
  bool no_disallowed_chars_present = true; // innocent until proven guilty
  for ( unsigned int i=strlen(sus); i >= 0; i-- ) {
    if ((sus[i] < 48 || sus[i] > 57) && !(sus[i] == 32)){ // ASCII: numbers 0-9 = codes 48-57, SPACE = 32
      no_disallowed_chars_present = false;
      printf("ERROR: must contain only spaces or digits 0-9");
    };
  };
  return  no_disallowed_chars_present;
}
/* </Validation> per "Validating a Number" */
/* <Luhn> */
// Description: cleans up the array, output is ready for Luhn check
// Input:
// 1. *may_have_spaces
//   - is len > 1
//   - contains only spaces or 0-9 digits
// Output
// 1. may_have_spaces -- modified in place
//   - all spaces removed
//   - ready for Luhn check
void drop_spaces(char *may_have_spaces){
  unsigned int clean_index = 0;
  char *nospaces = malloc(sizeof(nospaces) * (strlen(may_have_spaces)+1));
  for ( unsigned int dirty_index=strlen(may_have_spaces); dirty_index >= 0; dirty_index-- ) {
    if (!(may_have_spaces[dirty_index] == 32)) {// the entry is a number in 0-9
      nospaces[clean_index] = may_have_spaces[dirty_index];
      clean_index++;
    };
  };
  strncpy(nospaces,may_have_spaces,sizeof(char)); // overwrite sus with the clean array
  free(nospaces);
  // End state -- array modified in place to move all spaces to the end
}

// Description: double every other digit starting from the right
// return sum of 16 digits (max possible 16*9=144
unsigned int sum_of_doubles(char *valid_num){
  // To avoid unnecessary math, store a lookup table of the logic for
  // "double it, if >9 then subtract 9" where the index is the answer
  // ex. EVERY_OTHER_DOUBLE[9] = (9*2)-9 = 9 // over 9 so subtract 9
  // ex. EVERY_OTHER_DOUBLE[9] = (4*2)   = 8 // not over 9, don't subtract 9
  const int lut[10] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };
  unsigned int running_sum_of_doubles = 0;
  for ( unsigned int i=strlen(valid_num)-1; i > 1; i-=2 ) {
    if (valid_num[i] != 32) { // we have a number
      running_sum_of_doubles += lut[(int)valid_num[i]]; // LUT to avoid unneeded math
    };
  };
  return running_sum_of_doubles;
}

bool luhn( char *input_num ) {
  // ! (sum_of_doubles % 10) yields true if evenly divisible by 10
  return passes_validation(input_num); //&& !(sum_of_doubles(input_num) % 10);
}

/* </Luhn> */
