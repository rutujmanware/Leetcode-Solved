class Solution {
public:
    bool isIsland;
    int closedIsland(vector<vector<int>>& grid) {
        isIsland = true;
        int islands = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                //Found a possible land, do traversal and check isIsland
                if(grid[i][j] == 0)
                {
                    findIsland(i,j,grid);
                    if(isIsland)    
                        islands++;  //the current traversal found island, increment count                               
                    else    
                        isIsland = true;
                }
            }
        }
        return islands;
    }

    void findIsland(int i, int j, vector<vector<int>>& grid)
    {      
        //out-of-border coordination: invalid 
        if(!(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()))
        {
            return;
        }
        
        //If we reach water we stop, else continue traversal
        if(grid[i][j] == 1) return; 
        else grid[i][j] = 1;
        //If current land is at border, it's not closed islands, mark isIsland as false
        if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1)
            isIsland = false;
        findIsland(i-1,j,grid);
        findIsland(i,j-1,grid);
        findIsland(i+1,j,grid);
        findIsland(i,j+1,grid);
    }
};