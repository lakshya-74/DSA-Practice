class Solution {
public:
    void func(vector<int>& v){
        int k = 0;
        for(int i=1;i<10;i++){
            v[k] = i;
            k++;
        }
        for(int i=0;i<k;i++){
            int rem = v[i]%10;
            if(rem<9){
                v[k] = v[i]*10 + rem+1;
                k++;
            }
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v(50,-1);
        func(v);
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            if(v[i]>=low && v[i]<=high) ans.push_back(v[i]);
        }
        return ans;
    }
};