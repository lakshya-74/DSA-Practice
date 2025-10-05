class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mpp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        for(auto x:mpp){
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
             ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};