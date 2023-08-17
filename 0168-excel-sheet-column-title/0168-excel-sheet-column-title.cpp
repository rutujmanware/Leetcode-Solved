// class Solution {
// public:
//     string convertToTitle(int columnNumber) {
    
//         string s = "";
//         while(columnNumber > 26){
//             int temp = columnNumber % 26;
//             if(temp == 0){
//                 s = 'Z' + s;
//                 columnNumber /= 26;
//                 columnNumber--;
//             }
//             else{
                
//                 s = char(temp + 'A' - 1) + s;
//                 columnNumber /= 26;
//             }
//         }
//         if(columnNumber){
//             s = char(columnNumber + 'A' - 1) + s;
//         }
//         return s;
//     }
// };

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans ="";
        while(columnNumber>0)
        {
            char ch = char(ceil((columnNumber-1)%26 +65));
            ans = ch+ans;
            columnNumber = (columnNumber-1)/26;
        }
        return ans;
    }
};