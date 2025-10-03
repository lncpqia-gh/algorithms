// made as a result of UCR CS150, DFA
#include <iostream>
#include <vector>
#include <fstream>
#include <string>



int main() {
  // prompt: user for file name
  // TODO: file check, prompt again if fail
  std::ifstream inFS;
  std::string textString;
  std::string filename;
  std::cout << "Give a filename: ";
  std::cin >> filename;
  inFS.open(filename);
  // TODO: validation
  std::getline(inFS, textString);
  // TODO: getline until EOF
  std::cout << textString << std::endl;
  // prompt: user for string to find (case sensitive)
  //         user for new file to go thru
  std::string findString;
  std::cout << "find: ";
  std::cin >> findString;

  // algorithm
  // start w first char
  // scan string for those char, marking down each position
  // scan those positions for second char, eliminate the ones not good
  // repeat until end of string
  std::vector<int> positionVec;
  char currChar = findString.at(0);
  // first scan treated as an initializer: will be written separately
  for (unsigned i = 0; i < textString.size(); i++) {
    if (textString.at(i) == currChar) {
      positionVec.push_back(i);
    }
  }

  currChar = findString.at(1);
  for (unsigned i = 1; i < findString.size(); i++) {
    std::cout << "i is " << i << std::endl;
    for (unsigned j = 0; j < positionVec.size(); j++) {
      std::cout << "j is " << j << std::endl;
      // check if string position + how many characters is good
      if (textString.at(positionVec.at(j) + i) != findString.at(i)) {
        // remove the position from the list
        positionVec.erase(positionVec.begin() + j);
      }
    }
  }
  
  std::cout << positionVec.size() << " instance";
  if (positionVec.size() != 1) std::cout << "s";
  std::cout << " of " << findString << " found."  << std::endl;
  // show first find (string is in caps) with trailing characters on left and right
  // prompt: user to choose new string
  //         user to choose to go left
  //         user to choose to go right
  int positionIndex = 0;
  std::cout << "...";
  // important cases: when trailing characters are at begin or end of string
  int trailCount = 0;
  int backTrailIndex;
  std::string backTrailString;
  while (trailCount < 15) {
    if (textString.at(positionVec.at(positionIndex)) == textString.at(0)) break;
    trailCount++;
  }
  backTrailIndex = positionVec.at(positionIndex) - trailCount;
  for (int i = 0; i < trailCount; i++) {
    std::cout << textString.at(backTrailIndex + i);
  }
  std::cout << findString;
}