#include "difference_of_squares.h"
#include "math.h"

unsigned int sum_of_nats ( unsigned int number) {
  return number * (number - 1) / 2;
}

unsigned int sum_of_squares(unsigned int number) {
  // unsigned ok, all squares of reals are positive
  unsigned int running_sum=0;
  for(unsigned int i = 1; i < number+1; i++){
    running_sum += pow(i,2); 
  };
  return running_sum;
}

unsigned int square_of_sum(unsigned int number) {
  return pow(sum_of_nats(number),2);
}

unsigned int difference_of_squares(unsigned int number){
  return square_of_sum(number) - sum_of_squares(number);
}
