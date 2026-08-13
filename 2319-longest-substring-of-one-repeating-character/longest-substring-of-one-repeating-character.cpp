class Solution {
public:
    struct Node{
        int maxlen;
        int pre , suff;
        char lchar , rchar;
        Node(){
            maxlen = 0;
            pre = 0;
            suff = 0;
            lchar = '\n';
            rchar = '\n';
        }
    };
    Node Merge(const Node& l, const Node& r, int llen , int rlen){
        Node ans;
        ans.lchar = l.lchar;
        ans.rchar = r.rchar;

        ans.pre = l.pre;
        if(l.pre==llen && l.rchar==r.lchar){
            ans.pre = l.pre + r.pre;
        }

        ans.suff = r.suff;
        if(r.suff==rlen && l.rchar==r.lchar){
            ans.suff = r.suff + l.suff;
        }

        ans.maxlen = max(l.maxlen,r.maxlen);
        if(l.rchar==r.lchar){
            ans.maxlen = max(ans.maxlen,l.suff+r.pre);
        }
        return ans;
    }
    void buildSegmentTree(int i , int l , int r , string& s, vector<Node>& segTree){
        if(l==r){
            segTree[i].maxlen = 1;
            segTree[i].pre = 1;
            segTree[i].suff = 1;
            segTree[i].lchar = s[l];
            segTree[i].rchar = s[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildSegmentTree(2*i+1,l,mid,s,segTree);
        buildSegmentTree(2*i+2,mid+1,r,s,segTree);
        segTree[i] = Merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }
    void update(int i,int l,int r , int ch , int idx,vector<Node>& segTree){
        if(l==r){
            segTree[i].maxlen = 1;
            segTree[i].pre = 1;
            segTree[i].suff = 1;
            segTree[i].lchar = ch;
            segTree[i].rchar = ch;
            return;
        }
        int mid = l + (r-l)/2;
        if(idx<=mid) update(2*i+1,l,mid,ch,idx,segTree);
        else update(2*i+2,mid+1,r,ch,idx,segTree);
        segTree[i] = Merge(segTree[2*i+1],segTree[2*i+2],mid-l+1,r-mid);
    }
    vector<int> longestRepeating(string s, string queryc, vector<int>& queryi) {
        int n = s.size();
        vector<Node> segTree(4*n,Node());
        buildSegmentTree(0,0,n-1,s,segTree);
        int k = queryc.size();
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            int ch = queryc[i];
            int idx = queryi[i];
            update(0,0,n-1,ch,idx,segTree);
            ans[i] = segTree[0].maxlen;
        }
        return ans;
    }
};