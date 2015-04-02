#include <stdio.h>
#include <stack>

using namespace std;

int main() {
  int n;
  scanf("%d\n",&n);
  for(int i=0; i < n; i++) {
    bool t = true;
    char a;
    scanf("%c", &a);
    stack<char> s;
    while(a != '\n') {
      if(a == '{' || a == '(' || a == '[') {
        s.push(a);
      } else {
        if(s.size() > 0) {
          char b = s.top();
          if(!(b == '{' && a == '}') && !(b == '[' && a == ']') && !(b == '(' && a == ')')) {
            t = false;
            break;
          }
          s.pop();
        } else {
          t = false;
          break;
        }
      }
      scanf("%c", &a);
    }
    if(t) {
      printf("S\n");
    } else {
      printf("N\n");
    }
  }
  return 0;
}
