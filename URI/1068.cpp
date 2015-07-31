#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main() {
  char exp[1010];
  while(scanf("%s\n", exp) != EOF) {
    stack<char> parser;
    int i = 0;
    bool right = true;
    while (exp[i] != '\0') {
      if (exp[i] == '(') {
        parser.push('(');
      } else if (exp[i] == ')') {
        if (parser.size() == 0) {
          right = false;
          break;
        }

        if (parser.top() == '(') {
          parser.pop();
        } else {
          right = false;
          break;
        }
      }
      i++;
    }
    if (right && parser.empty())
      printf("correct\n");
    else 
      printf("incorrect\n");
  }
  return 0;
}
