class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = 0;
        for(auto x:apple){
            total += x;
        }
        priority_queue<int> pq;
        for(auto x:capacity){
            pq.push(x);
        }
        int count =0;
        while(total>0){
            count++;
            total -= pq.top();
            pq.pop();
        }
        return count;
    }
};