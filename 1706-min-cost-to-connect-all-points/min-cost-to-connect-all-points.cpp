class Solution {
public:
    struct Edge{
        int src;
        int des;
        int wt;
    };
    static bool cmp(const Edge &e1, const Edge &e2){
        return e1.wt < e2.wt;
    }
    int find(vector<int> &parent , int x){
        return parent[x] = (parent[x]==x) ? x : find(parent,parent[x]);
    }
    void Union(vector<int>& parent , vector<int>& rank , int a ,int b){
        a = find(parent ,a);
        b = find(parent,b);
        if(a==b) return;
        if(rank[a]<=rank[b]){
            parent[a] = b;
            rank[b]++;
        }
        else{
            parent[b] = a;
            rank[a]++;
        }
    }
    int Kruskal(vector<Edge> &input, int v){
        vector<int> parent(v+1);
        vector<int> rank(v+1,0);
        for(int i=0;i<=v;i++){
            parent[i] = i;
        }
        sort(input.begin(),input.end(),cmp);
        int ans = 0;
        int edgecount =0;
        int i =0;
        while(edgecount<v-1 && i<input.size()){
            Edge curr = input[i];
            int srcpar = find(parent,curr.src);
            int despar = find(parent,curr.des);
            if(srcpar != despar){
                Union(parent,rank,srcpar,despar);
                ans += curr.wt;
                edgecount++;
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<Edge> input;
        for(int i=0;i<v-1;i++){
            for(int j=i+1;j<v;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                input.push_back({i,j,dist});
            }
        }
        return Kruskal(input,v);
    }
};