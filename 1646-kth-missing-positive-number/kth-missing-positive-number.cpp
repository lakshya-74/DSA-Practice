class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<bool> v(2002,false);
        for(int i=0;i<arr.size();i++){
            v[arr[i]] = true;
        }
        int count =0;
        for(int i=1;i<v.size();i++){
            if(v[i]==false){
                count++;
            }
            if(count==k) return i;
        }
        return -1;
    }
};