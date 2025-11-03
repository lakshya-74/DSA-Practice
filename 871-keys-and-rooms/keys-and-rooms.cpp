class Solution {
public:
    vector<list<int>> graph;
    vector<int> visited; 
    void addGraph(int src,int dest){
        graph[src].push_back(dest);
    }
    void dfs(int src ,int dest){
        visited[src] = 1;
        for(auto x:graph[src]){
            if(visited[x]==0){
                dfs(x,dest);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        graph.resize(rooms.size());
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                addGraph(i,rooms[i][j]);
            }
        }
        visited.resize(rooms.size(),0);
        dfs(0,rooms.size()-1);
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==0) return false;
        }
        return true;
    }
};