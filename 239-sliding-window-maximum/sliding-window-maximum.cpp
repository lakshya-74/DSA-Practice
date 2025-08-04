class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        // int n = arr.size();
        // vector<int> ngi(n);
        // vector<int> ans;
        // stack<int> st;
        // st.push(n-1);
        // ngi[n-1] = n;
        // // making ngi for every element such that we will find at which any biiger number is in window or not 
        // for(int i=n-2;i>=0;i--){
        //     while(st.size()>0 && arr[i]>=arr[st.top()]) st.pop();
        //     if(st.size()==0) ngi[i] = n;
        //     else ngi[i] = st.top();
        //     st.push(i);
        // }
        // for(int i=0;i<n-k+1;i++){
        //     int check = arr[i];
        //     int j =i;
        //     while(j<(i+k)){
        //         check = arr[j];
        //         j = ngi[j];
        //     }
        //     ans.push_back(check);
        // }
        // return ans;

        // using DEQUE
        int n = arr.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(dq.size()>0 && arr[i]>arr[dq.back()]) dq.pop_back();
            dq.push_back(i);
            while(dq.size()>0 && (i-k+1)>dq.front()) dq.pop_front();
            if(i>=(k-1)) ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};