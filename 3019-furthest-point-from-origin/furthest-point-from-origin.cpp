class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int ans = 0;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L') curr--;
            else curr++;
        }
        ans = max(ans,abs(curr));
        curr = 0;
        for(int i=0;i<n;i++){
            if(moves[i]=='R') curr++;
            else curr--;
        }
        ans = max(ans,abs(curr));
        return ans;
    }
};