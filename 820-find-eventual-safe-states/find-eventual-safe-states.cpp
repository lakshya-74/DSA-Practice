class Solution {
public:
    bool check_cycle(int src , vector<vector<int>>& graph , vector<int>& visited ,
    vector<int>& path_visited , vector<int>& check){
        visited[src] = 1;
        path_visited[src] = 1;
        check[src] = 0;
        for(auto adj:graph[src]){
            if(!visited[adj]){
                if(check_cycle(adj,graph,visited,path_visited,check)){
                    return true;
                }
            }
            else{
                if(path_visited[adj]) return true;
            }
        } 
        check[src] = 1;
        path_visited[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0) , path_visited(n,0) , check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                check_cycle(i,graph,visited,path_visited,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};