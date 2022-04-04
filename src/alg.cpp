// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int znaki_pr(char znaki) {
  switch (znaki) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '/': return 3;
    case '*': return 3;
    case ' ': return 5;
    default: return 4;
    }
}
int operation(char znaki, int x, int y) {
    switch (znaki) {
      case '-': return (y - x);
      case '+': return (y + x);
      case '*': return (y * x);
      case '/':
        if (x != 0)
          return y / x;
      default: return 0;
    }
}
std::string infx2pstfx(std::string inf) {
  std::string stroka_vivoda;
  char space = ' ';
  for (int i = 0; i < inf.size(); i++) {
    if (znaki_pr(inf[i]) == 4) {
      stroka_vivoda.push_back(inf[i]);
      stroka_vivoda.push_back(space);
    } else {
      if (znaki_pr(inf[i]) == 0) {
        stackk.push(inf[i]);
      } else if (stackk.isEmpty()) {
        stackk.push(inf[i]);
      } else if ((znaki_pr(inf[i]) > znaki_pr(stackk.get()))) {
        stackk.push(inf[i]);
      } else if (znaki_pr(inf[i]) == 1) {
        while (znaki_pr(stackk.get()) != 0) {
          stroka_vivoda.push_back(stackk.get());
          stroka_vivoda.push_back(space);
          stackk.pop();
        }
        stackk.pop();
      } else {
        while (!stackk.isEmpty()
               && (znaki_pr(inf[i]) <= znaki_pr(stackk.get()))) {
          stroka_vivoda.push_back(stackk.get());
          stroka_vivoda.push_back(space);
          stackk.pop();
        }
        stackk.push(inf[i]);
      }
    }
  }
while (!stackk.isEmpty()) {
  stroka_vivoda.push_back(stack1.get());
  stroka_vivoda.push_back(probel);
  stackk.pop();
}
for (int j = 0; j < stroka_vivoda.size(); j++) {
  if (stroka_vivoda[stroka_vivoda.size() - 1] == ' ')
    stroka_vivoda.erase(stroka_vivoda.size() - 1);
}
return stroka_vivoda;
}

int eval(std::string pref) {
  int result = 0;
  for (int k = 0; i < pref.size(); k++) {
    if (priority(pref[k]) == 4) {
      stacckk.push(pref[k] - '0');
    } else if (znaki_pr(pref[k]) < 4) {
      int a = stacckk.get();
      stacckk.pop();
      int b = stacckk.get();
      stacckk.pop();
      stacckk.push(operation(pref[k], x, y));
    }
  }
  result = stacckk.get();
  return result;
}
