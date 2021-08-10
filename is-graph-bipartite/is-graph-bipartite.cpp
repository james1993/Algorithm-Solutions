class Solution {
 	public:
 		bool isBipartite(vector<vector<int>>& graph) {
 			vector<int>color(graph.size(), -1);

 			for (int i = 0; i < graph.size(); i++) 
            {
 				if (color[i] != -1) continue; //node is already colored

 				color[i] = 1;
 				queue<int>q;
 				q.push(i);

 				while (!q.empty()) 
                {
 					int t = q.front();
 					q.pop();

 					for (int j = 0; j < graph[t].size(); j++) 
                    {
 						if (color[graph[t][j]] == -1) 
                        {
 							color[graph[t][j]] = 1-color[t];
 							q.push(graph[t][j]);
 						} 
                        else if (color[graph[t][j]] == color[t]) return false;
 					}
 				}
 			}

 			return true;
 		}
 	};