/*
 * C++ Program to Find All Pairs Shortest Path
 */
#include <iostream>
#include <cstdlib>
#define max 10
#define infi 999
using namespace std;
int p[max][max];
/*
 * All Pairs Shortest Path using Floyd's Algorithm
 */
void allpairshort(int a[max][max], int n) {
  int k, i, j;
  for (k = 0; k < n; k++) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][k] + a[k][j] < a[i][j]) {
          a[i][j] = a[i][k] + a[k][j];
          p[i][j] = k;
        }
      }
    }
  }
}

/*
 * Storing the shortest path
 */
void shortest(int i, int j) {
  int k = p[i][j];
  if (k > 0) {
    shortest(i, k);
    cout<<"  "<<k<<"  ";
    shortest(k, j);
  }
}
/*
 * Display the Shortest Path
 */
void findpath(int a[max][max], int i, int j, int n) {
  cout<<"Path from " << i <<" to "<< j << ":";
  if (a[i][j]  < infi) {
    cout<<"  "<<i<<"  ";
    shortest(i, j);
    cout<<"  "<<j<<" ";
  }
}
/*
 * Main Contains Menu
 */
int main() {
  int i, j;
  int a[][10] =  {{0, 10, infi, 30, 100},
    {infi, 0 , 50, infi, infi},
    {infi, infi , 0, infi, 10},
    {infi, infi , 20, 0, 60},
    {infi, infi , infi, infi, 0},
  };

  allpairshort(a, 5);
  findpath(a, 0, 4, 5);
  return 0;
}
