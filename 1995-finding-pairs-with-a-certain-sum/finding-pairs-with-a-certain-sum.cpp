class FindSumPairs {
public:
    vector<int> nums1 , nums2;
    map<int,int> mp;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]++;
        }
    }
    void add(int index, int val) {
        mp[nums2[index]]--;
        if(mp[nums2[index]]==0){
            mp.erase(nums2[index]);
        }
        nums2[index] += val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int c =0;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(tot-nums1[i])!=mp.end()){
                c += mp[tot-nums1[i]];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */