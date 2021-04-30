#include <stdio.h>

struct dial_code {
  char *country;//country as characters
  int code;//code as integers
};
int main (int argc, char* argv[]) {
  int inter_code, i;//setting the internation code
  const struct dial_code country_codes[] = {
    {"Mexico", 32}, {"Egypt", 52},
    {"Japan", 55}, {"Lithoia", 44},
    {"China", 73}, {"Colombia", 13},
    {"Brazil", 24}, {"Nigeria", 36},
    {"Ethiopia", 51}, {"Germany", 47},
    {"Sweden",42}, {"India", 34},
    {"Korea", 79}, {"Spain", 88},
    {"USA", 19}, {"Cuba", 99},
    {"France", 50}, {"Canada", 92},
    {"New England", 74}, {"Russia", 63},
    };//setting up the countries to corrispond to a code
  int ent_code = sizeof(country_codes) / sizeof(*country_codes);
  do{
    int found = 0;
    printf("Input international code: ");
    scanf("%d", &inter_code);//ask the user to input the number
    for (i = 0; i < ent_code; i++) {
      if (country_codes[i].code == inter_code) {
          printf("The country is: %s\n", country_codes[i].country);
          found = 1;//steps the code takes in order to look for the code
        }
      }
      if (!found)
      printf("Code not found.\n");//if the code cant be found then it displays that the code cannot be found
      break;
  } 
  while(1);
  return 0;
}