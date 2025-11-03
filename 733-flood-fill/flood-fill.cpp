class Solution {
public:
    void dfs(vector<vector<int>>& image , int r , int c , int icolor , int fcolor){
        if(r<0 || c<0 || r>=image.size() || c>=image[0].size()) return;
        if(image[r][c]!=icolor) return;
        image[r][c] = fcolor;
        dfs(image,r-1,c,icolor,fcolor);
        dfs(image,r+1,c,icolor,fcolor);
        dfs(image,r,c-1,icolor,fcolor);
        dfs(image,r,c+1,icolor,fcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }

};