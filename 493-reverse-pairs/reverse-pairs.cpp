class Solution {
public:
    void merge(int lo , int mid , int hi , vector<int>& nums){
        vector<int> temp;
        int left = lo;
        int right = mid+1;
        while(left<=mid && right<=hi){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=hi){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=lo;i<=hi;i++){
            nums[i] = temp[i-lo];
        }
    }
    int countpairs(int lo , int mid , int hi , vector<int>& nums){
        int count =0;
        int right = mid+1;
        for(int i=lo;i<=mid;i++){
            while(right<=hi && nums[i]>2*(long long)nums[right]) right++;
            count += (right-(mid+1));
        }
        return count;
    }
    int mergesort(int lo , int hi , vector<int>& nums){
        int count =0;
        if(lo>=hi) return 0;
        int mid = (lo + hi)/2;
        count += mergesort(lo,mid,nums);
        count += mergesort(mid+1,hi,nums);
        count += countpairs(lo,mid,hi,nums);
        merge(lo,mid,hi,nums);
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(0,n-1,nums);
    }
};