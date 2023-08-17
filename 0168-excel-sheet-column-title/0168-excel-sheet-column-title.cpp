class Solution {
public:
    string convertToTitle(int columnNumber) {
    
        string s = "";
        while(columnNumber > 26){
            int temp = columnNumber % 26;
            if(temp == 0){
                s = 'Z' + s;
                columnNumber /= 26;
                columnNumber--;
            }
            else{
                
                s = char(temp + 'A' - 1) + s;
                columnNumber /= 26;
            }
        }
        if(columnNumber){
            s = char(columnNumber + 'A' - 1) + s;
        }
        return s;
    }
};