class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i =0;
        int j = people.size()-1;
        int count =0;
        while(i<j){
            int sum = people[i] + people[j];
            if(sum>limit){
                j--;
            }
            else{
                i++;
                j--;
            }
            count++;
        }
        if(i==j) count++;
        return count;
    }
};