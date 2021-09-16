/**** 167 LA CASA DE SOLID NIEVES ****/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> node;
vector<vector<node>> graph; 
vector<bool> visited;
vector<vector<int>> distances;


int main(int argc, char const *argv[])
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int p, f, c;
  cin >> p >> f >> c;

  graph.resize(p);
  visited.resize(p);
  distances.resize(p,vector<int>(p, INT_MAX));

  int demandant_cities[f];

  for (int i = 0; i < f; ++i)
  {
    cin >> demandant_cities[i];
  }

  for (int i = 0; i < c; ++i)
  {
    int c1, c2, d;
    cin >> c1 >> c2 >> d;
    // first = city to, second = distance to that city
    graph[c1 - 1].push_back(make_pair(c2 -1 , d));
    graph[c2 - 1].push_back(make_pair(c1 -1, d));
  }


  // first: distance, second city arrived
  priority_queue<node, vector<node>, greater<node> > pq; 
  

  int start = 0;
  pq.push(make_pair(0,start));
  distances[start][start] = 0;

  for (int i = 0; i < p; ++i){
  	int start = i;
  	pq.push(make_pair(0,start));
  	distances[start][start] = 0;

  	while(!pq.empty()) {
	    node actual_city = pq.top();
	    pq.pop();
	    if (visited[actual_city.second]) {
	    	continue;
	    }
	    visited[actual_city.second] = true;
	    vector<node> children = graph[actual_city.second];
	    int actual_distance = actual_city.first;
	    for(auto child: children){
	    	int tent_distance = child.second + actual_distance;
	    	if(!visited[child.first] && tent_distance <= distances[start][child.first]) {
	        	pq.push(make_pair(tent_distance, child.first));
		        distances[start][child.first] = tent_distance;
		        distances[child.first][start] = tent_distance;
      		}
		}
 	}
 	fill(visited.begin(), visited.end(), false);

  }

  


  float min = INT_MAX * 1.0;
  int index_min;
  for (int j = 0; j < p; ++j){
  	float sum = 0.0;

  	for(int i = 0; i < f ; ++i) {
  		int d_city = demandant_cities[i] - 1;
    	sum += distances[j][d_city];
  	}
  	sum /= f;
  	if(sum < min) {
  		index_min = j+1;
  		min = sum;
  	}
  }


  cout << index_min << endl;
   
  return 0; 
}