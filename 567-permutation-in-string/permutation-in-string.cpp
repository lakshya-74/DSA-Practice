class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s1[i]]++;
        }
        int count =0;
        int r = 0 , l = 0;
        while(r<m){
            if(mpp[s2[r]]>0) count++;
            mpp[s2[r]]--;
            if(count==n) return true;
            if(r-l+1==n){
                mpp[s2[l]]++;
                if(mpp[s2[l]]>0) count--;
                l++;
            }
            r++;
        }
        return false;
    }
};