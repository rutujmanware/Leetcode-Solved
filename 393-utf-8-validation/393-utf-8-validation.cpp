class Solution {
public:
    bool validUtf8(vector<int>& data) {
       
        for(int i=0;i<data.size();i++){
             int nub=0;
            if(data[i]>= 255){
                return false;
            }
            else if((data[i] & 128) == 0){
                nub = 1;
            }
            else if((data[i] & 224) == 192){
                nub = 2;
            }
            else if((data[i] & 240) == 224){
                nub = 3;
            }
            else if((data[i] & 248) == 240){
                nub = 4;
            }
            else{
                return false;
            }
            
            for(int j = 1; j<nub ; j++){
                if(i+j >= data.size()){
                    return false;
                }
                else if((data[i+j] & 192) != 128){
                    return false;
                }
            }
            i = i + nub - 1;
        }
        return true;
    }
};