class Solution {
public:
    /*
    void dfs(vector<int> adjList[], vector<int> &visited, int src) {
        visited[src] = 1;
        
        for (int i = 0; i < adjList[src].size(); i++) {
            if (visited[adjList[src][i]] == 0) {
                dfs(adjList, visited, adjList[src][i]);
            }
        }
    }
    */
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
      
        int components = 0;
        vector<int> visited(n, 0);
        vector<vector<int>> adjList(n);
    
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) 
        {
            if (visited[i] == 0) 
            {
                components++;
                visited[i] = 1;
                
                queue<int> queue;
                queue.push(i);
                while(!queue.empty())
                {
                    int level_size = queue.size();
                    for(int i = 0; i < level_size; i++)
                    {
                        int current = queue.front();
                        queue.pop();
                        
                        for(int j = 0; j < adjList[current].size(); j++)
                        {
                            if(visited[adjList[current][j]] == 0)
                            {
                                visited[adjList[current][j]] = 1;
                                queue.push(adjList[current][j]);
                            }
                        }
                    }
                }
            }
        }
        return components;
    }
};