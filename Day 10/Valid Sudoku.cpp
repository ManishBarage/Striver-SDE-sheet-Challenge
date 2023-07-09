bool isSafe(int row, int col,int mat[][9],int val)
{
    for(int i=0;i<9;i++)
    {
        //Check row
        if(mat[row][i] == val)
        {
            return false;
        }

        //Check Column
        if (mat[i][col] == val) {
          return false;
        }

        // Check in 3X3 matrix
        if (mat[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }

    return true;
}

bool solve(int mat[][9])
{
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(mat[row][col]==0)
            {
                for(int val=1;val<=9;val++)
                {
                    if(isSafe(row,col,mat,val))
                    {
                        mat[row][col]=val;

                        bool isPossble = solve(mat);
                        
                        if(isPossble)
                        {
                            return true;
                        }
                        else
                        {
                            //BackTrack
                            mat[row][col]=0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}

bool isItSudoku(int matrix[9][9]) {
    
    return solve(matrix);
}
