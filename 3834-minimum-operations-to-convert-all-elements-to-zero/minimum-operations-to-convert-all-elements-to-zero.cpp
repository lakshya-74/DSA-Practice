class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // // brute force
        // set<int> st;
        // for(int i=0;i<n;i++) st.insert(nums[i]);
        // int ans = 0;
        // for(auto it:st){
        //     if(it==0) continue;
        //     bool flag = true;
        //     for(int i=0;i<n;i++){
        //         if(nums[i]==it){ // we are checking if nums[i] matchs with our it then how long it will be good subaaray (means how longyou didn't encounter with value<nums[i]) 
        //             if(flag){
        //                 ans++;
        //                 flag = false;
        //             }
        //         }
        //         else if(nums[i]<it) flag = true; // means i have a value <nums[i] so from now i need one more operation 
        //     }
        // }
        // return ans;

        // optimal

        stack<int> st;
        int ans =0;
        int mx =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>nums[i]){
                st.pop();
            }
            if(nums[i]==0) continue;
            else if(st.empty()){
                st.push(nums[i]);
                ans++;
            }
            else if(st.top()<nums[i]){
                ans++;
                st.push(nums[i]);
            }
        }
        return ans;
    }
};