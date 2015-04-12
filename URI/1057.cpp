#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <unordered_map>

using namespace std;

struct Pos {
  int x, y;

  Pos() {};

  Pos(int a, int b) : x(a), y(b) {};
};

struct Map {
  int s;
  char *map;
  Map(int size) : s(size) { map = new char[size*size]; };

  void setPos(int x, int y, char c) {
    map[x + s*y] = c;
  }

  char getPos(int x, int y) {
    if (x >= s || y >= s || y < 0 || x < 0) return '#';
    return map[x + s*y];
  }
};

struct Players {
  Pos positions[3];

  Pos getPos(char c) {
    if (c == 'A') {
      return positions[0];
    } else if (c == 'B') {
      return positions[1];
    } else if (c == 'C') {
      return positions[2];
    }
  }

  void setPos(char c, Pos P) {
    if (c == 'A') {
      if ((P.x == positions[1].x && P.y == positions[1].y) ||
          (P.x == positions[2].x && P.y == positions[2].y)) return;
      positions[0] = P;
    } else if (c == 'B') {
      if ((P.x == positions[0].x && P.y == positions[0].y) ||
          (P.x == positions[2].x && P.y == positions[2].y)) return;
      positions[1] = P;
    } else if (c == 'C') {
      if ((P.x == positions[0].x && P.y == positions[0].y) ||
          (P.x == positions[1].x && P.y == positions[1].y)) return;
      positions[2] = P;
    }
  }

  int getHash() {
    int Hash = 0;
    Hash += (positions[0].x+1) + (positions[0].y+1)*10;
    Hash += (positions[1].x+1)*100 + (positions[1].y+1)*1000;
    Hash += (positions[2].x+1)*10000 + (positions[2].y+1)*100000;
    return Hash;
  }
};

int lixo = 0;
int main() {
  int n;
  lixo=scanf("%d", &n); 
  for (int l = 0; l < n; l++) {
    int s;
    lixo=scanf("%d\n", &s);
    Players P;
    Map map(s);

    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        char c;
        lixo=scanf("%c", &c);
        if (c == 'A' || c == 'B' || c == 'C') {
          P.setPos(c, Pos(i, j));
          map.setPos(i, j, '.');
        } else {
          map.setPos(i, j, c);
        }
      }
      lixo=scanf("\n");
    }

    list<Players> queue;
    list<int> depth;
    queue.push_back(P);
    depth.push_back(0);
    unordered_map<int, bool> Visited;

    bool achou = false;
    while(!queue.empty()) {
      Players P1 = queue.front();
      queue.pop_front();

      int dp = depth.front();
      depth.pop_front();

      Pos A = P1.getPos('A');
      Pos B = P1.getPos('B');
      Pos C = P1.getPos('C');

/*      for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
          if (A.x == i && A.y == j) printf("A");
          if (B.x == i && B.y == j) printf("B");
          if (C.x == i && C.y == j) printf("C");
          else 
            printf(":%d", map.getPos(i, j));
        }
        printf("\n");
      }

      std::system("sleep 1");
      std::system("clear");*/
      Visited[P.getHash()] = true;

      if (map.getPos(A.x, A.y) == 'X' && map.getPos(B.x, B.y) == 'X' &&
          map.getPos(C.x, C.y) == 'X') {
        printf("Case %d: %d\n", l+1, dp);
        achou = true;
        break;
      }

      for (int m = 0; m < 4; m++) { 
        A = P1.getPos('A');
        B = P1.getPos('B');
        C = P1.getPos('C');

        Players P2;
        P2.setPos('A', A);
        P2.setPos('B', B);
        P2.setPos('C', C);
        bool traped = true;
        if (m == 0) {
          if (map.getPos(A.x, A.y + 1) == '.' || map.getPos(A.x, A.y + 1) == 'X') {
            A.y = A.y + 1;
            P2.setPos('A', A);
            traped = false;
          }
          if (map.getPos(B.x, B.y + 1) == '.' || map.getPos(B.x, B.y + 1) == 'X') {
            B.y = B.y + 1;
            P2.setPos('B', B);
            traped = false;
          }
          if (map.getPos(C.x, C.y + 1) == '.'|| map.getPos(C.x, C.y + 1) == 'X') {
            C.y = C.y + 1;
            P2.setPos('C', C);
            traped = false;
          }
          if (!traped && Visited.count(P2.getHash()) == 0) { 
            queue.push_back(P2);
            depth.push_back(dp+1);
          }
        }
        if (m == 1) {
          if (map.getPos(A.x, A.y - 1) == '.'|| map.getPos(A.x, A.y - 1) == 'X') {
            A.y = A.y - 1;
            P2.setPos('A', A);
            traped = false;
          }
          if (map.getPos(B.x, B.y - 1) == '.'|| map.getPos(B.x, B.y - 1) == 'X') {
            B.y = B.y - 1;
            P2.setPos('B', B);
            traped = false;
          }
          if (map.getPos(C.x, C.y - 1) == '.'|| map.getPos(C.x, C.y - 1) == 'X') {
            C.y = C.y - 1;
            P2.setPos('C', C);
            traped = false;
          }
          if (!traped && Visited.count(P2.getHash()) == 0) { 
            queue.push_back(P2);
            depth.push_back(dp+1);
          }
        }
        if (m == 2) {
          if (map.getPos(A.x + 1, A.y) == '.'|| map.getPos(A.x+1, A.y) == 'X') {
            A.x = A.x + 1;
            P2.setPos('A', A);
            traped = false;
          }
          if (map.getPos(B.x + 1, B.y) == '.'|| map.getPos(B.x+1, B.y) == 'X') {
            B.x = B.x + 1;
            P2.setPos('B', B);
            traped = false;
          }
          if (map.getPos(C.x + 1, C.y) == '.'|| map.getPos(C.x+1, C.y) == 'X') {
            C.x = C.x + 1;
            P2.setPos('C', C);
            traped = false;
          }
          if (!traped && Visited.count(P2.getHash()) == 0) { 
            queue.push_back(P2);
            depth.push_back(dp+1);
          }
        }
        if (m == 3) {
          if (map.getPos(A.x - 1, A.y) == '.'|| map.getPos(A.x-1, A.y) == 'X') {
            A.x = A.x - 1;
            P2.setPos('A', A);
            traped = false;
          }
          if (map.getPos(B.x - 1, B.y) == '.'|| map.getPos(B.x-1, B.y) == 'X') {
            B.x = B.x - 1;
            P2.setPos('B', B);
            traped = false;
          }
          if (map.getPos(C.x - 1, C.y) == '.'|| map.getPos(C.x-1, C.y) == 'X') {
            C.x = C.x - 1;
            P2.setPos('C', C);
            traped = false;
          }
          if (!traped && Visited.count(P2.getHash()) == 0) {
            queue.push_back(P2);
            depth.push_back(dp+1);
          }
        }
      }
    }
    if(!achou)
      printf("Case %d: trapped\n", l+1);
  }
}
