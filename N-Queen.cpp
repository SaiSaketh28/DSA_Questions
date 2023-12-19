// brute force approach
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>answer;
        vector<string>board(n);
        string s(n,'_');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        place(0,answer,board,n);
        return answer;
    }
    void place(int col,vector<vector<string>>answer,vector<string>&board,int n)
    {
        if(col == n)
        {
            answer.push_back(board);
            return;
        }
        for(int row =0;row<n;row++)
        {
            if(check(row,col,board,n))
            {
                board[row][col] = 'Q';
                place(col+1,answer,board,n);
                board[row][col] = '_';
            }
        }
    }
    bool check(int row, int col,vector<string>&board,int n)
    {
        int dupcol = col;
        int duprow = row;
        // checking upper diagonal - worstcase O(n)
        while(duprow>=0 && dupcol>=0)
        {
            if(board[duprow][dupcol] == 'Q')
            {
                return false;
            }
            duprow--;
            dupcol--;
        }
        int drow = row;
        int dcol = col;
        //checking left columns - worstcase O(n)
        while(dcol>=0)
        {
            if(board[drow][dcol] == 'Q')
            {
                return false;
            }
            col--;
        }
        // checking lower left diagonal - worstcase O(n)
        while(row<n && col>=0)
        {
            if(board[row][col] == 'Q')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
};



// Optimization
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>answer;
        vector<string>board(n);
        vector<int> leftrow(n,0),upper_diagonal(2*n-1,0),lower_diagonal(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        place(0,answer,board,n,leftrow,upper_diagonal,lower_diagonal);
        return answer;
    }
    void place(int col,vector<vector<string>>&answer,vector<string>&board,int n,vector<int>&leftrow,vector<int>&upper_diagonal,vector<int>&lower_diagonal)
    {
        if(col == n)
        {
            answer.push_back(board);
            return;
        }
        for(int row =0;row<n;row++)
        {
    if(leftrow[row] == 0 && upper_diagonal[n-1+col-row] == 0 && lower_diagonal[row+col] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                upper_diagonal[n-1+col-row] = 1;
                lower_diagonal[row+col] = 1;
                place(col+1,answer,board,n,leftrow,upper_diagonal,lower_diagonal);
                board[row][col] = '.';
                leftrow[row] = 0;
                upper_diagonal[n-1+col-row] = 0;
                lower_diagonal[row+col] = 0;
            }
        }
    }
};