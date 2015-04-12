#include <stdio.h>
#include <stack>
#include <cstring>
#include <stdlib.h>

using namespace std;

bool isOp(char c) {
  return c == '+' || c == '-' || c == '/' || c == '*' || c == '^';
}

bool more(char c1, char c2) {
  if(c1 == '^') return true;
  if(c2 == '^') return false;
  if(c1 == '+' || c1 == '-') return false;
  if((c1 == '*' || c1 == '/') && (c2 == '*' || c2 == '/')) return false;
  else return true;
}

char* infix(char*);

char* solveInfix(char* a) {
  char *b = (char*) malloc(301);
  int i=1;
  int j=0;
  if(*a == '(') {
    while(i != 0) {
      a++;
      b[j] = *a; 
      if(*a == '(') i++;
      if(*a == ')') i--;
      j++;
    }
    b[j-1] = '\0';
  }
  return infix(b);
}

char* infix(char *a) {
  stack<char> st;
  char *res = (char*) malloc(301);
  int i=0;
  while(*a != '\0') {
    if(*a == '(') {
      char *s = solveInfix(a);
      while(*s != '\0') {
        res[i] = *s;
        s++;
        i++;
      }
      int u=1;
      while(u != 0) {
        a++;
        if(*a == '(') u++;
        if(*a == ')') u--;
      }
      a++;
      continue;
    } 
    if(isOp(*a)) {
      if(!st.empty()) {
        while(!more(*a,st.top())) {
          res[i] = st.top();
          st.pop();
          i++;
          if(st.empty()) break;
        }
      }
      st.push(*a);
      a++;
      continue;
    } else {
      res[i] = *a;
    }
    i++;
    a++;
  }

  while(!st.empty()) {
    res[i] = st.top();
    st.pop();
    i++;
  }

  res[i] = '\0';
  return res;
}

int main() {
  int d;
  scanf("%d", &d);
  for(int i=0; i < d; i++) {
    char *a = (char*) malloc(301);
    scanf("%s", a); 
    printf("%s\n", infix(a));
  }
  return 0;
}
