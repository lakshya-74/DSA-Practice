class Solution {
public:
    int count(vector<vector<int>>& img1 , vector<vector<int>>& img2 , int r, int c){
        int n = img1.size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1 && i+r>=0 && i+r<n && j+c>=0 && j+c<n){
                    if(img2[i+r][j+c]==1) ans++;
                }
            }
        }
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        for(int row_offset=-n+1;row_offset<n;row_offset++){
            for(int col_offset=-n+1;col_offset<n;col_offset++){
                ans = max(ans,count(img1,img2,row_offset,col_offset));
            }
        }
        return ans;
    }
};