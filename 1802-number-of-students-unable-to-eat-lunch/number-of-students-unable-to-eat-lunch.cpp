class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int i=0;
        int count =0;
        while(q.size()>0){
            if(q.front()==sandwiches[i]){
                q.pop();
                i++;
                count = 0; // count is for checking mark that loop dosen't to go infinite
            }
            else{
                q.push(q.front());
                q.pop();
                count++;
            }
            if(count==q.size()) break;
        }
        return count;
    }
};