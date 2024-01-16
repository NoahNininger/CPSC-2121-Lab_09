/*
 * Name:            Noah Nininger
 * Date Submitted:  04/18/2023
 * Lab Section:     001
 * Assignment Name: nQueens
 */

#include <iostream>
#include <vector>

using namespace std;

// checks if the queen can be placed at position [r,c]
bool isAvaliable(int**queens,int n,int col,int row)
{
    for(int r = 0; r < n; r++)      // loop through rows
    {
        if(queens[row][r] == 1)
            { return false; }
    }

 // checking right diagonal
    for(int r = row, c = col; r < n && c >= 0; r++, c--)
    {
        if(queens[r][c] == 1)
            { return false; }
    }

 // checking left diagonal
    for(int r = row, c = col; r >= 0 && c >= 0; r--, c--)
    {
        if(queens[r][c] == 1)
            { return false; }
    }

    return true;
}

// uses recursion to count how many solutions there are
int recursiveHelper(int **queens, int n, int col)
{
    int row;
    int count {0};

    if(col == n)
        { return 1; }

    for(int r = 0; r < n; r++)      // loop through rows
        {
            row = r;

         // if coordinate is avaliable
            if(isAvaliable(queens, n, col, row))
            {
                queens[row][col] = 1;
                count += recursiveHelper(queens, n, col + 1);   // recursion
                queens[row][col] = 0;
            }
        }

        return count;
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    int **queens = new int *[n];

    for(int i = 0; i < n; i++)
    {
        queens[i] = new int[n];

        for(int j = 0; j < n; j++)
            { queens[i][j] = 0; }
    }

    return recursiveHelper(queens, n, 0);
}

/*
int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}*/
