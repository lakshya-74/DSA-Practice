/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums , int lo ,int hi){
        if(lo>hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* a = new TreeNode(nums[mid]);
        a->left = helper(nums,lo,mid-1);
        a->right = helper(nums,mid+1,hi);
        return a;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,n-1);
    }
};