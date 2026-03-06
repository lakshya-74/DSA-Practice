class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();

        // did using set 
        // T.C -> O(n+n) 

        // if(n==1) return 1;
        // unordered_set<char> st;
        // int l = 0 , r = 0;
        // while(r<n){
        //     while(st.count(s[r])){
        //         st.erase(s[l]);
        //         l++;
        //     }
        //     st.insert(s[r]);
        //     ans = max(ans,r-l+1);
        //     r++;
        // }
        // return ans;

        // do it with hashmap that store <char , idx>
        map<char,int> mpp;
        int l = 0;
        int r = 0;
        while(r<n){
            if(mpp.find(s[r])!=mpp.end()){ // updating when we find duplicate
                if(mpp[s[r]]>=l){
                    l = mpp[s[r]]  + 1;
                }
            }
            mpp[s[r]] = r;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};