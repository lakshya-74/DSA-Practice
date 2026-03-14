class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> a,b;
        for(int i=0;i<nums1.size();i++){
            a[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            b[nums2[i]]++;
        }
        for(auto &x:a){
            if(b.find(x.first)!=b.end()){
                if(x.second<b[x.first]){
                    b[x.first] -= x.second;
                    x.second = 0;
                }
                else{
                    x.second -= b[x.first];
                    b[x.first] = 0;
                }
            }
        }
        int count =0;
        for(auto x:a){
            if(x.second&1) return -1;
            count += x.second/2;
        }
        for(auto x:b){
            if(x.second&1) return -1;
            count += x.second/2;
        }
        return count/2;
    }
};