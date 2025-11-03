class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       vector<int> visited;
       visited.resize(rooms.size(),0);
       queue<int> q;
       q.push(0);
       while(q.size()){
            int curr = q.front();
            q.pop();
            visited[curr] = 1;
            for(int i=0;i<rooms[curr].size();i++){
                if(visited[rooms[curr][i]]==0){
                    q.push(rooms[curr][i]);
                    visited[rooms[curr][i]] = 1;
                }    
            }
       }
       for(int i=0;i<rooms.size();i++){
        if(visited[i]==0) return false;
       }
       return true;
    }
};