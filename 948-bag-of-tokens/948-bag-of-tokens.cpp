class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score = 0,res=0;
        int l=0,r=tokens.size()-1;
        while(l<=r){
            if(power>=tokens[l]){
               power -= tokens[l];
               res = max(res,++score);
                l++;
            }
            else if(score>0){
               score--;
               power +=tokens[r];
                r--;
            }
            else{
                break;
            }

        }
        return res;

    }
        
    
};