class Solution {
public:
    #define pp pair<int,int>
    struct node{
        int r;
        int c;
        int e;
        int mask;
    };
    vector<pp> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    int minMoves(vector<string>& nums, int energy) {
        int n = nums.size();
        int m = nums[0].size();
        int sr=-1 ,sc = -1;
        vector<vector<int>> v(n,vector<int>(m,-1));
        int position = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]=='S'){
                    sr = i;
                    sc = j;
                }
                else if(nums[i][j]=='L'){
                    v[i][j] = position++;
                }
            }
        }
        if(position==0) return 0;
        int mx = pow(2,position) - 1;
        queue<node> q;
        q.push({sr,sc,energy,0});
        vector<vector<vector<vector<int>>>> visited(n,vector<vector<vector<int>>>(m,vector<vector<int>>(energy+1,vector<int>(mx+1,0))));
        visited[sr][sc][energy][0] = 1;
        int moves = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int i = curr.r;
                int j = curr.c;
                int en = curr.e;
                int ma = curr.mask;
                if(ma==mx) return moves;
                if(en==0) continue;
                for(auto x:dir){
                    int nr = i + x.first;
                    int nc = j + x.second;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && nums[nr][nc]!='X'){
                        int ne = en - 1;
                        int nmask = ma;
                        if(nums[nr][nc]=='R'){
                            ne = energy;
                        }
                        else if(nums[nr][nc]=='L'){
                            int p = v[nr][nc];
                            nmask |= (1<<p); 
                        }
                        if(!visited[nr][nc][ne][nmask]){
                            visited[nr][nc][ne][nmask] = 1;
                            q.push({nr,nc,ne,nmask});
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};