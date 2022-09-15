class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int,int> m;
        vector<int> v;
        sort(changed.begin(),changed.end());
        if(changed.size()%2!=0){
            return {};
        }
        for(int i=0;i<changed.size();i++){
            m[changed[i]]++;
        }
        for(int i=0;i<changed.size();i++){
           if( m[changed[i]*2] > 0 && m[changed[i]]>0){
               m[changed[i]]--;
               m[changed[i]*2]--;
               if(m[changed[i]*2]<0) break;
               v.push_back(changed[i]);
           }
        }
        if(v.size()== (changed.size()/2)){
            return v;
        }
        else{
            return {};
        }
        
    }
};