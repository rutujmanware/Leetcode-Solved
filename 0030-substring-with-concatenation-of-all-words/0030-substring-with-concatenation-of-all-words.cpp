class Solution {
public:
    bool checkSubstr(unordered_map<string,int> m,string str,int wordsize){
        for(int j=0;j<str.size();j+=wordsize){
            if(m.count(str.substr(j,wordsize))){
                if(--m[str.substr(j,wordsize)] == -1){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m;
        for(auto word:words){
            m[word]++;
        }
        vector<int> v;
        int totsize = words.size();
        int wordsize = words[0].size();
        int windowsize = totsize*wordsize;
        int n = s.size();
        for(int i=0;i+windowsize<=n;i++){
            string str = s.substr(i,windowsize);
            // cout<<str<<endl;
            if(checkSubstr(m,str,wordsize)){
                v.push_back(i);
            }
           
        }
        return v;
    }
};