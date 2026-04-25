class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        vector<bool> ans(queries.size(),false);
        sort(edgeList.begin(), edgeList.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        int j = 0;
        for(int i=0;i<queries.size();i++){
            while(j<edgeList.size() && queries[i][2]>edgeList[j][2]){
                int a = edgeList[j][0];
                int b = edgeList[j][1];
                Union(a,b);
                j++;
            }
            int a = queries[i][0];
            int b = queries[i][1];
            if(find(a)==find(b)){
                ans[queries[i][3]] = true;
            }
        }
        return ans;
    }
};