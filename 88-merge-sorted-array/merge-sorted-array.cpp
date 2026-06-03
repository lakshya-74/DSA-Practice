class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0 , j =0;
        while(i<m && j<n){
            nums2.push_back(min(nums1[i],nums2[j]));
            if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        while(i<m){
            nums2.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            nums2.push_back(nums2[j]);
            j++;
        }
        j = n;
        for(int k=0;k<n+m;k++){
            nums1[k] = nums2[j++];
        }
    }
};