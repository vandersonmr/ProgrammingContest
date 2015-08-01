#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

#define X 0
#define Y 1

typedef int tPointi[2];

int Area2(tPointi a, tPointi b, tPointi c) {
  return a[X] * b[Y] - a[Y] * b[X] + a[Y] * c[X] - a[X] * c[Y] + b[X] * c[Y] - c[X] * b[Y];
}

bool Collinear(tPointi a, tPointi b, tPointi c) {
  return Area2(a, b, c) == 0;
}

bool Between(tPointi a, tPointi b, tPointi c) { // True only if c is between AB
  tPointi ba, ca;
  if (!Collinear(a, b, c)) return false;
  if (a[X] != b[X])
    return ((a[X] <= c[X]) && (c[X] <= b[X])) || ((a[X] >= c[X]) && (c[X] >= b[X]));
  else
    return ((a[Y] <= c[Y]) && (c[Y] <= b[Y])) || ((a[Y] >= c[Y]) && (c[Y] >= b[Y]));
}

int main() {
	int n; 
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		int vertices[n][2];
		for (int i = 0; i < n; i++) 
			scanf("%d %d\n", &vertices[i][0], &vertices[i][1]);
		vector<int> pX;	
		vector<int> pY;	
		for (int i = 0; i < n; i++) {
			int xt, yt;
			if (i == n-1) {
				xt = vertices[i][0] - vertices[0][0];
				yt = vertices[i][1] - vertices[0][1];
				if (xt == 0) pY.push_back(vertices[i][0]);
				else pX.push_back(vertices[i][1]);
			} else {
				xt = vertices[i][0] - vertices[i+1][0];
				yt = vertices[i][1] - vertices[i+1][1];
				if (xt == 0) pY.push_back(vertices[i][0]);
				else pX.push_back(vertices[i][1]);
			}
		}
		sort(pX.begin(), pX.end());
		sort(pY.begin(), pY.end());
		auto it1 = unique(pX.begin(), pX.end());
		auto it2 = unique(pY.begin(), pY.end());
		pX.resize(distance(pX.begin(),it1));
		pY.resize(distance(pY.begin(),it2));
		
			
		vector<vector<int>> J;
		int id = 0;
		for (auto i : pX) {
			vector<int> p = {id++};
			J.push_back(p);
		}
		for (auto j : pY) {
			vector<int> p = {id++};
			J.push_back(p);
		}
		
		id = 0;
		for (auto i : pX) {
			int idY = pX.size();
			for (auto j : pY) {
				int *t = new int[2];
				t[0] = j;
				t[1] = i;
				bool deuBom = true;
				for (int a = 0; a < n; a++) {
					if (a == n-1) {	
						if(!Collinear(vertices[a], vertices[0], t)) continue;
						if(Between(vertices[a], vertices[0], t)) {
							deuBom = false;
						}	
					} else {
						if(!Collinear(vertices[a], vertices[a+1], t)) continue;
						if(Between(vertices[a], vertices[a+1], t)) {
							deuBom = false;
						}
					}
				}
				if (deuBom) {
					vector<int> p = {id, idY};
					J.push_back(p);
				} else {
					delete t;
				}
				idY++;
			}
			id++;
		}
		for (auto i : J) {
			for (auto e : i)
				printf("%d ", e);
			printf("\n");	
		}

		printf("\n");
		printf("%ld\n\n", pX.size() + pY.size());	
	}
	return 0;
}
