class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int mx = fruits[n-1][0];
        vector<int> pre(mx+2,0) , suff(mx+2,0);
        int j = 0;
        pre[0] = fruits[j][0]==0?fruits[j++][1]:0;
        for(int i=1;i<mx+1;i++){
            if(j<n && fruits[j][0]==i){
                pre[i] = pre[i-1] + fruits[j][1];
                j++;
            }
            else pre[i] = pre[i-1];
        }
        j = n-1;
        suff[mx] = fruits[n-1][0]==mx?fruits[j--][1]:0;
        for(int i=mx-1;i>=0;i--){
            if(j>=0 && fruits[j][0]==i){
                suff[i] = suff[i+1] + fruits[j][1];
                j--;
            }
            else suff[i] = suff[i+1];
        }
        
        int ans = 0;
        int r = min(mx,startPos+k);
        int val = 0;
        if(startPos<=mx) val = pre[r] - (startPos==0?0:pre[startPos-1]);
        ans = max(ans,val);
        int l = max(0,startPos-k);
        if(l<=min(startPos,mx)) val = suff[l] - (startPos+1<=mx?suff[startPos+1]:0);
        ans = max(ans,val);
        // moves left then turn to right
        for(int x=1;2*x<=k;x++){
            int nk = k-x;
            int npos = startPos - x;
            if(npos<0) break;
            int r = min(mx,npos+nk);
            if(r<npos) continue;
            int v = pre[r] - (npos==0?0:pre[npos-1]);
            ans = max(ans,v);
        }

        // moves right then left
        for(int x=1;2*x<=k;x++){
            int nk = k-x;
            int npos = startPos + x;
            if(npos>mx) break;
            int v = suff[max(0,npos-nk)] - suff[npos+1];
            ans = max(ans,v);
        }
        return ans;
    }
};