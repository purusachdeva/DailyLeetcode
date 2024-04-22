class Solution {
    void dfs(int vertex, vector<vector<int>>& graph, vector<int>& vis) {
        vis[vertex] = 1;

        for(auto child : graph[vertex]) {
            if(!vis[child]) {
                dfs(child, graph, vis);
            }
        }
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        dfs(source, graph, vis);

        return vis[destination] == 1;
    }
};