#include <iostream>
#include <string>
using namespace std;

int main(){
  string word[100000];
  int totalWordCount, startPosition = 0, endPosition, currentPosition;
  int charCount, wordCount, spaceCount, spacePerWord, extraSpacePerWordCount;

  for (totalWordCount = 0; cin >> word[totalWordCount]; totalWordCount++);

  while (true){
    charCount = 0;
    currentPosition = startPosition;
    for (int i = 0; i < totalWordCount; i++){
      charCount += (word[currentPosition].length() +1);
      if (charCount > 61){
        charCount -= (word[currentPosition].length() +2);
        break;
      }
      currentPosition++;
    }
    endPosition = currentPosition;

    if (endPosition >= totalWordCount){
      for (int i = startPosition; i < totalWordCount -1; i++)
        cout << word[i] << ' ';
      cout << word[totalWordCount -1] << endl;
      break;
    }

    wordCount = endPosition - startPosition;
    spaceCount = 60 + (wordCount -1) - charCount;
    spacePerWord = spaceCount / (wordCount -1);
    extraSpacePerWordCount = spaceCount - spacePerWord * (wordCount -1);

    for (int i = startPosition; i < endPosition - extraSpacePerWordCount -1; i++){
      cout << word[i];
      for (int j = 0; j < spacePerWord; j++)
        cout << ' ';
    }
    for (int i = endPosition - extraSpacePerWordCount -1; i < endPosition - 1; i++){
      cout << word[i];
      for (int j = 0; j < spacePerWord +1; j++)
        cout << ' ';
    }
    cout << word[endPosition -1] << endl;
    startPosition = endPosition;
  }
}
