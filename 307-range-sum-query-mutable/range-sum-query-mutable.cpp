class NumArray {
public:
    vector<int> v;
    vector<int> segTree;
    void buildtree(int i , int l , int r){
        if(l==r){
            segTree[i] = v[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildtree(2*i+1,l,mid);
        buildtree(2*i+2,mid+1,r);
        segTree[i] = segTree[2*i+1]+segTree[2*i+2]; 
    }
    void updateTree(int i,int l , int r , int idx , int val){
        if(l==r){
            segTree[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid) updateTree(2*i+1,l,mid,idx,val);
        else updateTree(2*i+2,mid+1,r,idx,val);
        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }
    int query(int i, int l ,int r ,int left , int right){
        if(left>r || right<l) return 0;
        if(left<=l && r<=right) return segTree[i];
        int mid = l + (r-l)/2;
        return query(2*i+1,l,mid,left,right) + query(2*i+2,mid+1,r,left,right);
    }
    NumArray(vector<int>& nums) {
        v = nums;
        segTree.resize(4*nums.size());
        buildtree(0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        v[index] = val;
        updateTree(0,0,v.size()-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,v.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */