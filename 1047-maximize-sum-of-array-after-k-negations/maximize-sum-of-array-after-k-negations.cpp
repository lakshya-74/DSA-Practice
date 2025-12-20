class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k--){
            int x = pq.top();
            if(x==0) break;
            pq.pop();
            x *= -1;
            pq.push(x);
        }
        int sum =0;
        while(pq.size()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};