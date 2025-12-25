class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(happiness[i]);
        }
        long long total = 0;
        int x = k;
        while(k){
            if((pq.top()-(x-k))>0){
                total += pq.top() - (x-k);
            }
            else break;
            pq.pop();
            k--;
        }
        return total;
    }
};