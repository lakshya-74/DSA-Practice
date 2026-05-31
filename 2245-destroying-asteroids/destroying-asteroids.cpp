class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        int n = a.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i] = a[i] - mass;
        }
        sort(diff.begin(),diff.end());
        long long sum = mass;
        for(int i=0;i<n;i++){
            if(diff[i]<=0){
                sum += (mass+diff[i]);
            }
            else if(mass+diff[i]<=sum){
                sum += (mass + diff[i]);
            }
            else return false;
        }
        return true;
    }
};