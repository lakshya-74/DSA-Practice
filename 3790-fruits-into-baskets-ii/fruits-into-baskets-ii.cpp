class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int count =0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    flag = true;
                    baskets[j]= 0;
                    break;
                }
            }
            if(!flag) count++;
        }
        return count;
    }
};