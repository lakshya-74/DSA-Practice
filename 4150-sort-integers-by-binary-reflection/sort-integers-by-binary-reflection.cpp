class Solution {
public:
    string getreverse(int n){
        string s;
        while(n>0){
            if(n%2==1) s += '1';
            else s += '0';
            n /= 2;
        }
        return s;
    }
    int getnum(string s){
        int n = 0;
        int x = 0;
        for(int i=s.size()-1;i>=0;i--){
            n += (s[i]-'0')*pow(2,x);
            x++;
        }
        return n;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            string s = getreverse(nums[i]);
            int n = getnum(s);
            v.push_back({n,nums[i]});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};