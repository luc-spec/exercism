#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>

bool validate(char *sus);
bool contains_only_allowed_chars(char *sus);
void drop_spaces(char *may_have_spaces);
unsigned int sum_of_doubles(char *valid_num);
bool luhn(char *num);

#endif
