#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct question 
{
  string actualQuestion = "";
  string answer = "";
  string choice1, choice2, choice3 = "";
};

void questionClearer(question &lmao) 
{
  lmao.actualQuestion = "";
  lmao.answer = "";
  lmao.choice1 = "";
  lmao.choice2 = "";
  lmao.choice3 = "";
}

int main() 
{
  string userChoice = "";
  int score = 0;
  vector<question> questionList;
  ifstream test("test.txt", ios::in);

  bool q1, q2, q3, q4 = false;

  question questionHolder;

  string str;
  bool islastQuestion = false;
  bool isQuestion = false;
  int counter = 0;

  if (test.is_open()) 
  {

    while (getline(test, str, '\n')) 
    {
      if (str[str.length() - 1] == '?') 
      {
        questionClearer(questionHolder);
        isQuestion = true;
        islastQuestion = true;
        questionList.push_back(questionHolder);
        counter++;
      }
      if (isQuestion == true) 
      {
        questionHolder.actualQuestion = str;
        isQuestion = false;
      } 
      else if (islastQuestion == true) 
      {
        islastQuestion = false;
        questionHolder.answer = str;
      } 
      else if (questionHolder.choice1 == "") 
      {
        questionHolder.choice1 = str;
      } 
      else if (questionHolder.choice2 == "") 
      {
        questionHolder.choice2 = str;
      } 
      else if (questionHolder.choice3 == "") 
      {
        questionHolder.choice3 = str;
        questionList[counter - 1] = questionHolder;
      }
    }

    random_shuffle(questionList.begin(), questionList.end());
    for (int i = 0; i <= 9; i++) 
    {
      q1 = false;
      q2 = false;
      q3 = false;
      q4 = false;

      srand((unsigned)time(0));

      cout << endl << questionList[i].actualQuestion << endl << endl;

      while (q1 == false || q2 == false || q3 == false || q4 == false) 
      {
        int randomizer2;
        randomizer2 = (rand() % 4);
        
        if (randomizer2 == 0 && q1 == false) 
        {
          cout << questionList[i].answer << endl;
          q1 = true;
        }
        if (randomizer2 == 1 && q2 == false) 
        {
          cout << questionList[i].choice1 << endl;
          q2 = true;
        }
        if (randomizer2 == 2 && q3 == false) 
        {
          cout << questionList[i].choice2 << endl;
          q3 = true;
        }
        if (randomizer2 == 3 && q4 == false) 
        {
          cout << questionList[i].choice3 << endl;
          q4 = true;
        }
      }

      cout << endl << "write the answer in full:" << endl;

      getline(cin, userChoice);
      if (userChoice == questionList[i].answer) 
      {
        score++;
      }

      cout << endl << "The correct answer was: " << questionList[i].answer << endl;
    }
  }

  cout << "Your score: " << score << endl;
  if (score == 0) 
  {
    cout << "you need some help";
  }
  if (score > 7) 
  {
    cout << "didnt know you were chill like that";
  }
}
