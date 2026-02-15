class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int,int> mpp;
        int n = bulbs.size();
        for(int i=0;i<n;i++){
            mpp[bulbs[i]]++;
        }
        vector<int> ans;
        for(auto x:mpp){
            if(x.second&1) ans.push_back(x.first);
        }
        return ans;
    }
};