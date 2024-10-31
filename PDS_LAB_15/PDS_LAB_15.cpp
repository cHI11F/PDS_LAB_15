#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class NQueens {
public:
    NQueens(int n) : n(n), board(n, vector<char>(n, '.')) {}

    void solve() {
        backtrack(0);
    }

private:
    int n;
    vector<vector<char>> board;

    void backtrack(int row) {
        if (row == n) {
            printBoard();
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (isSafe(row, col)) {
                board[row][col] = 'Q';
                backtrack(row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col) {

        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = 0; i < row; ++i) {
            if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
            if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return false;
        }
        return true;
    }

    void printBoard() {
        for (const auto& row : board) {
            for (char cell : row) {
                cout << cell << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    
    int n;
    cout << "Введіть натуральне число n: ";
    cin >> n;

    NQueens nQueens(n);
    nQueens.solve();

    return 0;
}
