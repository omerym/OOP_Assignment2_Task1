#include <iostream>
#include <string>

using namespace std;

bool isRealNumber(string& str) {
  // Check if the string is empty.
  if (str.empty()) {
    return false;
  }

  string tempStr = str;

  // Check if the first character is a plus or minus sign.
  bool isNegative = (tempStr[0] == '-');
  if (isNegative) {
    tempStr = tempStr.substr(1);
  }

  // Check if the string contains only digits and a decimal point.
  for (int i = 0; i < tempStr.length(); i++) {
    if (!isdigit(tempStr[i]) && tempStr[i] != '.') {
      return false;
    }
  }

  // Check if the string contains more than one decimal point.
  int dotCount = 0;
  for (int i = 0; i < tempStr.length(); i++) {
    if (tempStr[i] == '.') {
      dotCount++;
    }
  }
  if (dotCount > 1) {
    return false;
  }

  return true;
}

int main() {
  string str = "123.456";
  bool isReal = isRealNumber(str);

  if (isReal) {
    cout << "The string is a real number." << endl;
  } else {
    cout << "The string is not a real number." << endl;
  }

  return 0;
}