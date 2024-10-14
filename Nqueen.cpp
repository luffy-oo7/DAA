/*
Name:Ashutosh Gadhave
Roll.No:TIA14
Batch:A                 */
//n Queens Problems

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int N = board.size();
    for (int i = 0; i < col; ++i)
        if (board[row][i] == 1)
            return false;

    for (int i = 0; i < row; ++i)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i < N && j >= 0; ++i, --j)
        if (board[i][j] == 1)
            return false;

    return true;
}

void printBoard(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int &solutionCount) {
    int N = board.size();
    if (col >= N) {
        solutionCount++;
        cout << "Solution " << solutionCount << ":\n";
        printBoard(board);
        return false; 
    }

    for (int i = 0; i < N; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQueensUtil(board, col + 1, solutionCount);
            board[i][col] = 0; 
        }
    }
    return false;
}

int main() {
    cout << "Enter the number of queens: ";
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    
    int solutionCount = 0;

    solveNQueensUtil(board, 0, solutionCount);

    if (solutionCount == 0) {
        cout << "No solution exists.\n";
    } else {
        cout << "Total solutions: " << solutionCount << endl;
    }

    return 0;
}
/*
Enter the number of queens: 4
Solution 1:
. . Q .
Q . . .
. . . Q
. Q . .

Solution 2:
. Q . .
. . . Q
Q . . .
. . Q .

Total solutions: 2*/