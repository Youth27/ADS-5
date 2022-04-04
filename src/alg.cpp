// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int znaki_op(char znaki) {
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
int calcul(char znaki, int x, int y) {
    switch (znaki) {
    case '+': return (y + x);
    case '-': return (y - x);
    case '*': return (y * x);
    case '/':
        if (x != 0)
            return y / x;
    default: return 0;
    }
}
std::string infx2pstfx(std::string inf) {
  std::string output;
    char space = ' ';
    for (int i = 0; i < inf.size(); i++) {
        if (znaki_op(inf[i]) == 4) {
            output.push_back(inf[i]);
            output.push_back(space);
        } else {
            if (znaki_op(inf[i]) == 0) {
                stackk.push(inf[i]);
            } else if (stackk.isEmpty()) {
                stackk.push(inf[i]);
            } else if ((znaki_op(inf[i]) > znaki_op(stackk.get()))) {
                stackk.push(inf[i]);
            } else if (znaki_op(inf[i]) == 1) {
                while (znaki_op(stackk.get()) != 0) {
                    output.push_back(stackk.get());
                    output.push_back(space);
                    stackk.pop();
                }
                stackk.pop();
            } else {
                while (!stackk.isEmpty()
                    && (znaki_op(inf[i]) <= znaki_op(stackk.get()))) {
                    output.push_back(stackk.get());
                    output.push_back(probel);
                    stackk.pop();
                }
                stackk.push(inf[i]);
            }
        }
    }
    while (!stackk.isEmpty()) {
        output.push_back(stackk.get());
        output.push_back(space);
        stackk.pop();
    }
    for (int i = 0; i < output.size(); i++) {
        if (output[output.size() - 1] == ' ')
            output.erase(output.size() - 1);
    }
    return output;
}
int eval(std::string pref) {
  int result = 0;
    for (int i = 0; i < pref.size(); i++) {
        if (znaki_op(pref[i]) == 4) {
            stacckk.push(pref[i] - '0');
        } else if (znaki_op(pref[i]) < 4) {
            int x = stacckk.get();
            stacckk.pop();
            int y = stacckk.get();
            stacckk.pop();
            stacckk.push(calcul(pref[i], x, y));
        }
    }
    result = stacckk.get();
    return result;
}
