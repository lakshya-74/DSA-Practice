class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(int i=0;i<bills.size();i++){
            int ret = bills[i] - 5;
            if(ret==0){
                mp[bills[i]]++;
            }
            else if(ret==5){
                if(mp[ret]>0){
                    mp[ret]--;
                    mp[10]++;
                }
                else return false;
            }
            else if(ret==15){
                if(mp[10]>0 && mp[5]>0){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>2){
                    mp[5] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};