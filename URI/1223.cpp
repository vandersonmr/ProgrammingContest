#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include <cmath>                                                                                                       

struct Point {                                                                                                         
  int x, y;                                                                                                            
};                                                                                                                     

struct Line {                                                                                                          
  Point Pa, Pb;                                                                                                        
  int a, b, c;                                                                                                         
  Line() {}
  Line(Point A, Point B) {                                                                                             
    Pa = A;                                                                                                            
    Pb = B;                                                                                                            
    a = A.y - B.y;                                                                                                     
    b = B.x - A.x;                                                                                                     
    c = A.x*B.y - B.x*A.y;                                                                                             
  }                                                                                                                    
};                                                                                                                     

int dot(Point& A, Point& B, Point& C){                                                                                 
  Point AB;                                                                                                            
  Point BC;                                                                                                            
  AB.x = B.x-A.x;                                                                                                      
  AB.y = B.y-A.y;                                                                                                      
  BC.x = C.x-B.x;                                                                                                      
  BC.y = C.y-B.y;                                                                                                      
  int dot = AB.x * BC.x + AB.y * BC.y;                                                                                 
  return dot;                                                                                                          
}

int cross(Point& A, Point& B, Point& C) {                                                                              
  Point AB;                                                                                                            
  Point AC;                                                                                                            
  AB.x = B.x-A.x;                                                                                                      
  AB.y = B.y-A.y;                                                                                                      
  AC.x = C.x-A.x;                                                                                                      
  AC.y = C.y-A.y;                                                                                                      
  int cross = AB.x * AC.y - AB.y * AC.x;                                                                               
  return cross;                                                                                                        
}                                                                                                                      

double distance(Point& A, Point& B){                                                                                   
  int d1 = A.x - B.x;                                                                                                  
  int d2 = A.y - B.y;                                                                                                  
  return std::sqrt(d1*d1+d2*d2);                                                                                       
}                                                                                                                      

double linePointDist(Line& L, Point& C, bool isSegment) {                                                
  double dist = cross(L.Pa,L.Pb,C) / distance(L.Pa,L.Pb);                                                                          
  if(isSegment) {                                                                                                      
    int dot1 = dot(L.Pa,L.Pb,C);                                                                                             
    if(dot1 > 0) return distance(L.Pb,C);                                                                                 
    int dot2 = dot(L.Pb,L.Pa,C);                                                                                             
    if(dot2 > 0) return distance(L.Pa,C);                                                                                 
  }                                                                                                                    
  return std::abs(dist);                                                                                               
} 

int main() {
  int n;
  while(scanf("%d", &n) != EOF) {
    int l, h;
    double min = FLT_MAX;
    scanf("%d %d", &l, &h);
    Line Old;
    for (int i = 1; i <= n; i++) {
      int yi, xf, yf;
      scanf("%d %d %d", &yi, &xf, &yf);
      Point P1, P2;
      if (i % 2 != 0) {
        P1.x = 0;
        P1.y = yi;
        P2.x = xf;
        P2.y = yf;
        if (l - xf < min) 
          min = l - xf;
      } else {
        P1.x = l;
        P1.y = yi;
        P2.x = xf;
        P2.y = yf;
        if (xf < min)
          min = xf;
      }
      Line N(P1, P2);
      if (i != 1) {
        double d = linePointDist(N, Old.Pb, true);
        if (d < min) 
          min = d;
      }
      Old = N;
    }
    printf("%.2lf\n", min);
  }
  return 0;
}
