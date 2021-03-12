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



  priority_queue<node, vector<node>, greater<node> > pq; 
  pq.push(make_pair(0,0));

  
  while(!pq.empty()) {
    node actual_city = pq.top();
    cout << "llegando a nodo " << actual_city.second + 1 << " con " << actual_city.first << endl;
    pq.pop();
    visited[actual_city.second] = true;
    vector<node> children = graph[actual_city.second];
    int actual_distance = actual_city.first;
    for(auto child: children){
      int tent_distance = child.second + actual_distance;
      if(!visited[child.first] && tent_distance < distances[0][child.first]) {
        pq.push(make_pair(tent_distance, child.first));
        distances[0][child.first] = tent_distance;
      }
    }
  }


  for(int i = 0; i<p; ++i)
    cout << distances[0][i] << " "; 




  return 0; 
}