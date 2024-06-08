#include "difference_of_squares.h"
#include "math.h"

unsigned int sum_of_nats (unsigned int n) {
  return n*(n+1) / 2;
}

// The square of the sum of the first the natural numbers is
// (1 + 2 + ... + 10)² = 55² = 3025.
unsigned int square_of_sum(unsigned int n) {
  return pow(sum_of_nats(n),2);
}

// The sum of the squares of the first the natural numbers is 
// 1² + 2² + ... + 10² = 385
unsigned int sum_of_squares(unsigned int n) {
  // unsigned ok, all squares of reals are positive
  unsigned int running_sum = 0;
  for(unsigned int i = 1; i < n+1; i++) { 
    running_sum += pow(i,2); 
  };
  return running_sum;
}

unsigned int difference_of_squares(unsigned int n){
  return square_of_sum(n) - sum_of_squares(n);
}
