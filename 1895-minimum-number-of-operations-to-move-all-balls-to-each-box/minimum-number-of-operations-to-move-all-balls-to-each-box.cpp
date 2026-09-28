class Solution {
public:
    vector<int> minOperations(string box) {
        int n = box.size();
        vector<int> ans(n,0);
        int count =0;
        if(box[n-1]=='1') count++;
        long long sum = count==1?n-1:0;
        for(int i=n-2;i>=0;i--){
            ans[i] = sum - (count*i);
            if(box[i]=='1'){ 
                count++;
                sum += i;
            }    
        }
        sum = 0;
        count =0;
        if(box[0]=='1') count++;
        for(int i=1;i<n;i++){
            ans[i] += (count*i) - sum;
            if(box[i]=='1'){
                count++;
                sum += i;
            }
        }
        return ans;
    }
};