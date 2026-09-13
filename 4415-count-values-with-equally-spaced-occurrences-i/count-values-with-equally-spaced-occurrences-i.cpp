class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        map<int,pair<int,vector<int>>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].first++;
            mpp[nums[i]].second.push_back(i);
        }
        int count = 0;
        for(auto [x,y]:mpp){
            if(y.first==3){
                bool flag = true;
                int curr = y.second[1] - y.second[0];
                for(int i=2;i<y.second.size();i++){
                    int a = y.second[i] - y.second[i-1];
                    if(a!=curr){
                        flag = false;
                        break;
                    }
                }
                if(flag) count++;
            }
        }
        return count;
    }
};