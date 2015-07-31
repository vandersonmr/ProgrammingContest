#define MAX 999999999
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
 
class compare
{
public:
    bool operator() (std::pair<int, int> a, std::pair<int, int> b)
	    {
		return a.second > b.second;
	    }
};
    
 
void dijkstra(int s,int d,std::map< int,std::vector< std::vector<int> > > myGraph,int nodes,std::vector<std::vector<int> > &seq){
    int i,u,v,alt,*dist,*previous,*cost;
    std::vector<int> myVec;
    std::vector<int>::iterator vec_elem;
    std::vector< std::vector<int> > prev;
    std::vector< std::vector<int> >::iterator elem;
    std::priority_queue< std::pair< int,int >, std::vector<std::pair<int,int> >, compare > priorQ;
 
    dist=new int[nodes];
    cost=new int[nodes];
    previous=new int[nodes];
 
    for (i=0;i<nodes;i++){
	dist[i]=MAX;
	previous[i]=-1;
	cost[i]=0;
    }
 
    //set source distance to 0
    dist[s-1]=0;
 
    //add all vertices to priority queue
    for (i=0;i<nodes;i++){
	priorQ.push(make_pair(i+1,dist[i]));
    }
 
    while(!priorQ.empty()){
	
	//pick the top element
	u = priorQ.top().first;
	priorQ.pop();
 
	if (dist[u-1]==MAX){
	    break;
	}
 
	//if target found stop searching
	if (u==d){
	    break;
	}
 
	//main Dijkstra loop
	for (elem=myGraph[u].begin();elem!=myGraph[u].end();elem++){
	    myVec=*elem;
	    v=myVec[0];
	    alt=dist[u-1]+myVec[1];
	    
	    if (alt<dist[v-1]){
		dist[v-1]=alt;
		previous[v-1]=u-1;
		cost[v-1]=myVec[1];
		priorQ.push(make_pair(v,dist[v-1]));
	    }
	}
    }
    
    myVec.clear();
    u=d-1;
    
    //generate path sequence
    while (previous[u] != -1){
	myVec.push_back(u+1);
	myVec.push_back(cost[u]);
	seq.push_back(myVec);
	u=previous[u];
	myVec.clear();
    }
}
 
int main(void){
    int N,M;
    int i;
    int **graph;
    std::vector< std::vector<int> > seq;
    std::vector< std::vector<int> >::iterator vec_elem,pos;
    std::vector<int> myVec,odd;
    std::map< int,std::vector< std::vector<int> > > myAdj,myMap;
    std::map< int,std::vector< std::vector<int> > >::iterator map_elem;
 
    //Input reading
    scanf("%d %d",&N,&M);
    graph=new int*[M];
    for (i=0;i<M;i++){
	graph[i]=new int[3];
	scanf("%d %d %d",&graph[i][0],&graph[i][1],&graph[i][2]);
	myVec.push_back(graph[i][1]);
	myVec.push_back(graph[i][2]);
	myAdj[graph[i][0]].push_back(myVec);
	myVec.clear();
	myVec.push_back(graph[i][0]);
	myVec.push_back(graph[i][2]);
	myAdj[graph[i][1]].push_back(myVec);
	myVec.clear();
}
 
    //Find shortest path between vertices e.g (1,4)
    //seq (vector of vectors) describing sequence path in the form <"node","cost to node">
    dijkstra(1,4,myAdj,M,seq); 
 
    return 0;
}

