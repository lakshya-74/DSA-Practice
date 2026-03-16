class Solution {
public:
    bool rec(int idx , int n , vector<string>& nums,string & s,string &ans){
        if(idx>=n){
            for(int i=0;i<n;i++){
                if(nums[i]==s){
                    return false;
                }
            }
            ans = s;
            return false;
        }
        s += '0';
        if(rec(idx+1,n,nums,s,ans)) return true;
        s.pop_back();
        s += '1';
        if(rec(idx+1,n,nums,s,ans)) return true;
        s.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string s = "";
        string ans = "";
        // rec(0,n,nums,s,ans);
        // return ans;

        for(int i=0;i<n;i++){
            if(nums[i][i]=='0') ans += '1';
            else ans += '0';
        }
        return ans;
    }
};