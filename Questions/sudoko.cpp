class Solution
{

    bool canWePlace(vector<vector<char>> &Board, int row, int col, char num)
    {
        for (int j = 0; j < 9; j++)
        {
            if (Board[row][j] == num)
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (Board[i][col] == num)
                return false;
        }

        int r = (row / 3) * 3;
        int c = (col / 3) * 3;

        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {
                if (Board[i][j] == num)
                    return false;
            }
        }

        return true;
    }

    bool sudoko(vector<vector<char>> &board, int row, int col)
    {
        if (row == 9)
            return true;

        if (col == 9)
            return sudoko(board, row + 1, 0);

        if (board[row][col] != '.')
            return sudoko(board, row, col + 1);

        for (int num = 1; num <= 9; num++)
        {
            char ch = '0' + num;

            if (canWePlace(board, row, col, ch))
            {
                board[row][col] = ch;

                if (sudoko(board, row, col + 1))
                    return true;

                board[row][col] = '.'; // backtrack
            }
        }

        return false; // AFTER loop
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        sudoko(board, 0, 0);
    }
};