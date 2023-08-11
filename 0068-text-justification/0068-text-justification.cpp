class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0;
        vector<string> ans;
        while(i<words.size()){
            int j = i+1;
            int linelength = words[i].size();
            string curr;
            while(j<words.size() && linelength+words[j].size()+(j-i)<=maxWidth){
                linelength += words[j].size();
                j++;
            }
            
            int numWords = j-i;
            int numSpaces = maxWidth - linelength;
            
            
            if(numWords==1 || j==words.size()){
                curr += words[i];
                
                for(int k = i+1;k<j;k++){
                    curr+=' '+words[k];
                }
                curr += string(maxWidth-curr.size(),' ');
            }
            else{
                int spaceBetweenWords = numSpaces/(numWords-1);
                int extraSpaces = numSpaces%(numWords-1);
                curr += words[i];
          
                for( int k = i+1;k<j;k++){
                    curr+=string(spaceBetweenWords,' ');
                    if(extraSpaces>0){
                        curr+= ' ';
                        extraSpaces--;
                    }
                    curr+=words[k];
                    
                }
            }
            ans.push_back(curr);
            i=j;
            
            
        }
        return ans;
    }
};