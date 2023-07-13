class Solution {
public:
    
    bool dfs(vector<vector<char>> &board , string &word,int ind,int i,int j){
        // cout<<board[i][j]<<" :"<<word[ind]<<endl;
        
        if(ind==word.size()-1){
            if(word[ind] == board[i][j])
            return true;
        }
        char c = board[i][j];
        if(c == word[ind]){
            board[i][j] = '*';
            bool t=false,b=false,r=false,l=false;
            
            if(i-1>=0)
             t = dfs(board,word,ind+1,i-1,j);
            if(i+1<board.size())
             b = dfs(board,word,ind+1,i+1,j);
            if(j+1<board[0].size())
             r = dfs(board,word,ind+1,i,j+1);
            if(j-1>=0)
             l = dfs(board,word,ind+1,i,j-1);
            board[i][j] = c;
            return (t|b|l|r);
        }
        
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(board[i][j] == word[0]){
                    if(dfs(board , word, 0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};