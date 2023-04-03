class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
       sort(people.rbegin(),people.rend());
        int count=0;
        // int pos=0;
        // for(int i=0;i<people.size();i++){
        //     if(people[i]==limit){
        //         count++;
        //     }
        //     else{
        //         pos=i;
        //         break;
        //     }
        // }
        int i=0;
        int j = people.size()-1;
        while(i<=j){
            if(people[i]+people[j]<=limit && i!=j){
                count++;
                i++;
                j--;
            }
            else if(people[i]+people[j]>limit && i!=j){
                count++;
                i++;
            }
            else if(i==j){
                count++;
                i++;
            }
        }
        return count;
    }
};