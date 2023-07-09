void addSolution(vector< vector <int> > &board, vector< vector<int> > &ans, int n )
{
    vector<int> temp;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    
    ans.push_back(temp);
}

bool isSafe(int row, int col,vector< vector <int> > &board, int n )
{
    int x=row;
    int y=col;
    //check for same row
    while(y>=0)
    {
        if(board[x][y] ==1)
        {
            return false;
        }
        else
        {
            y--;
        }
    }
    
    x= row;
    y=col;
    //Check upper diagonal
    while(x>=0 && y>=0)
    {
        if(board[x][y] ==1)
        {
            return false;
        }
        else
        {
            x--;
            y--;
        }
    }
    
    x=row;
    y=col;
    //check for lower digonal
    while(x<n && y>=0)
    {
        if(board[x][y] ==1)
        {
            return false;
        }
        else
        {
            x++;
            y--;
        }
    }
    
    return true;
    
}

void solve(int col, vector< vector <int> > &board, vector< vector<int> > &ans, int n )
{
    if(col == n)
    {
        
        addSolution(board ,ans, n);
        return;
    }
    //Treverse each row
    for(int row=0;row<n;row++)
    {
        if(isSafe(row, col, board, n))
        {
            board[row][col] =1;
            
            //Recursion
            solve(col+1 , board, ans, n);
            
            //Backtracking
            board[row][col] =0;
        }
    }

}

vector<vector<int>> solveNQueens(int n) {
    vector< vector <int> > board(n, vector<int> (n,0));
    vector< vector<int> > ans;
    
    solve(0, board, ans, n);
    
    return ans;
}