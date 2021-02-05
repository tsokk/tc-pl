#include <iostream>

using namespace std;

int main() {

  char input_line[] = "?+++??++????++??";
  int max_length = 17;
  int quest_count = 0;

  int i; // original form of the exercise
  for (i = 0; i != max_length; i++)
    if (input_line[i] == '?')
      quest_count++;

  cout << quest_count << '\n';

  quest_count = 0;

  i = max_length; // using while loop
  while (i--)
    if (input_line[i] == '?')
      quest_count++;

  cout << quest_count << '\n';

  quest_count = 0;

  // using pointer as the controlled variable
  for (char *p = input_line; *p != '\0'; p++)
    if (*p == '?')
      quest_count++;

  cout << quest_count << '\n';

  quest_count = 0;

  // using range-for
  for (const auto& c : input_line)
    if (c == '?')
      quest_count++;

  cout << quest_count << '\n';
}
