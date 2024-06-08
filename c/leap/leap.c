#include "leap.h"
bool leap_year(int year) {
  // !(x%y) results in 1 iff there **is not** a remainder
  return year%100 ? !(year%4) : !(year%400); 
}
