class Solution {
public:
    vector<vector<int>> graph;
    void toposort(vector<int>& ans,int n){
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                indegree[x]++;
            }
        }
        vector<bool> visited(n,false);
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                visited[i] = true;
            }
        }
        while(q.size()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            for(auto x:graph[curr]){
                if(!visited[x]){
                    indegree[x]--;
                    if(indegree[x]==0){
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        toposort(ans,numCourses);
        if(ans.size()==numCourses) return ans;
        return {};

    }
};