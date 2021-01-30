#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include<bits/stdc++.h>

using namespace std;

vector<pair<char, int>> sortChars(vector<pair<char, int>> v) {
  vector<pair<char, int>> sortedVec;
  sort(v.begin(), v.end());
  int maxIndex = 0;
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v.size(); j++) {
      if(v[j].second > v[maxIndex].second) {
        maxIndex = j;
      }
    }
    sortedVec.push_back(v[maxIndex]);
    v[maxIndex].second = 0;
  }
  return sortedVec;
}

vector<pair<string, int>> sortWordsNums(vector<pair<string, int>> v) {
  vector<pair<string, int>> sortedVec;
  int maxIndex = 0;
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v.size(); j++) {
      if(v[j].second > v[maxIndex].second) {
        maxIndex = j;
      }
    }
    sortedVec.push_back(v[maxIndex]);
    v[maxIndex].second = 0;
  }
  return sortedVec;
}

int main() {
  char ch;
  string temp = "";
  string tempNum = "";
  int k = 0;
  int l = 0;
  vector<pair<char, int>> chars;
  vector<pair<string, int>> words;
  vector<pair<string, int>> numbers;
  while(cin.get(ch)) {
    //GET CHARS
    bool flag = false;
    int flagIndex = 0;
    bool wordFlag = false;
    int wordFlagIndex = 0;
    bool numberFlag = false;
    int numberFlagIndex = 0;
    for(int i = 0; i < chars.size(); i++) {
      if(ch == chars[i].first) {
        flag = true;
        flagIndex = i;
      }
    }
    if(flag) {
      chars[flagIndex].second++;
    } else {
      chars.push_back(make_pair(ch, 1));
    }
    //GET WORDS
    if(isalpha(ch)) {
      temp += tolower(ch);
      k++;
    } else if((!isalpha(ch)) && (k != 0)) {
      k = 0;
      for(int i = 0; i < words.size(); i++) {
        if(temp == words[i].first) {
          wordFlag = true;
          wordFlagIndex = i;
        }
      }
      if(wordFlag) {
        words[wordFlagIndex].second++;
      } else {
        words.push_back(make_pair(temp, 1));
      }
      temp = "";
    }
    //GET NUMBERS
    if(isdigit(ch)) {
      tempNum += ch;
      l++;
    } else if((!isdigit(ch)) && (l !=0)) {
      l = 0;
      for(int i = 0; i < numbers.size(); i++) {
        if(tempNum == numbers[i].first) {
          numberFlag = true;
          numberFlagIndex = i;
        }
      }
      if(numberFlag) {
        numbers[numberFlagIndex].second++;
      } else {
        numbers.push_back(make_pair(tempNum, 1));
      }
      tempNum = "";
    }
  }
  chars = sortChars(chars);
  int num_spaces = 0;
  if(words.size() >= 10) {
    for(int i = 0; i < 10; i++) {
      if(words[i].first.size() > num_spaces) {
        num_spaces = words[i].first.size();
      }
    }
  } else {
    for(int i = 0; i < words.size(); i++) {
      if(words[i].first.size() > num_spaces) {
        num_spaces = words[i].first.size();
      }
    }
  }
  if(numbers.size() >= 10) {
    for(int i = 0; i < 10; i++) {
      if(numbers[i].first.size() > num_spaces) {
        num_spaces = numbers[i].first.size();
      }
    }
  } else {
    for(int i = 0; i < numbers.size(); i++) {
      if(numbers[i].first.size() > num_spaces) {
        num_spaces = numbers[i].first.size();
      }
    }
  }
  if(chars.size() < 10) {
    cout << "Total " << chars.size() << " different characters, " << chars.size() << " most used characters:" << endl;
    for(int i = 0; i < chars.size(); i++) {
      string character = "";
      character += chars[i].first;
      if(chars[i].first == '\n') {
        character = "\\n";
      }
      if(chars[i].first == '\t') {
        character = "\\t";
      }
      printf("No. %i: %-*s %i\n", i, num_spaces + 5, character.c_str(), chars[i].second);
    }
  } else {
    cout << "Total " << chars.size() << " different characters, 10 most used characters:" << endl;
    for(int i = 0; i < 10; i++) {
      string character = "";
      character += chars[i].first;
      if(chars[i].first == '\n') {
        character = "\\n";
      }
      if(chars[i].first == '\t') {
        character = "\\t";
      }
      printf("No. %i: %-*s %i\n", i, num_spaces + 5, character.c_str(), chars[i].second);
    }
  }
  words = sortWordsNums(words);
  if(words.size() < 10) {
    cout << "Total " << words.size() << " different words, " << words.size() << " most used words:" << endl;
    for(int i = 0; i < words.size(); i++) {
      printf("No. %i: %-*s %i\n", i, num_spaces + 5, words[i].first.c_str(), words[i].second);
    }
  } else {
    cout << "Total " << words.size() << " different words, 10 most used words:" << endl;
    for(int i = 0; i < 10; i++) {
      printf("No. %i: %-*s %i\n", i, num_spaces + 5, words[i].first.c_str(), words[i].second);
    }
  }
  numbers = sortWordsNums(numbers);
  if(numbers.size() < 10) {
    cout << "Total " << numbers.size() << " different numbers, " << numbers.size() << " most used numbers:" << endl;
    for(int i = 0; i < numbers.size(); i++) {
      printf("No. %i: %-*s %i\n", i, num_spaces + 5, numbers[i].first.c_str(), numbers[i].second);
    }
  } else {
    cout << "Total " << numbers.size() << " different numbers, 10 most used numbers:" << endl;
    for(int i = 0; i < 10; i++) {
      printf("No. %i: %-*s %i\n", i, num_spaces + 5, numbers[i].first.c_str(), numbers[i].second);
    }
  }
  /*cout << "------------------" << endl;
  words = sortWordsNums(words);
  for(int i = 0; i < words.size(); i++) {
    cout << words[i].first << " : " << words[i].second << endl;
  }
  cout << "------------------" << endl;
  numbers = sortWordsNums(numbers);
  for(int i = 0; i < numbers.size(); i++) {
    cout << numbers[i].first << " : " << numbers[i].second << endl;
  }*/
  return 0;
}
