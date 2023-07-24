#include "../include/helper.h"

#include <iostream>
using std::cout;
using std::cin;
using std::istringstream;



int Helper::ReadInt(int small, int big) {

  string input;
  cin >> input;
  istringstream stringstreamObj(input);

  int value;
  stringstreamObj >> value;
  if (stringstreamObj.fail()) {
    cout << "ERROR: Expected integer input,Try again - Enter number: ";
    return ReadInt(small, big);
  }

  if (small <= value && value <= big)
    return value;

  cout << "Error: Expected range is small = " << small << ", big = " << big << ",Try again - Enter number : ";
  return ReadInt(small, big);
}

int Helper::RunMenu(vector<string> &menu)
{
  cout << "\n\nPlease make a choice:\n";
  for (int i = 0; i < (int) menu.size(); ++i)
    cout << "\t" << i + 1 << " - " << menu[i] << "\n";
  cout << "\tEnter Choice: ";
  return Helper::ReadInt(1, menu.size());
}
;
