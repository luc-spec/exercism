#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool passes_validation(char*);
bool input_length_allowed(char*);
bool disallowed(char);
bool contains_only_allowed_chars(char*);
void drop_spaces(char*);
int ctoi(char);
int sum_of_doubles(char*);
bool luhn(char*);

#endif
