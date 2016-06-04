#include "solvesudoku.h"

bool SolveSudoku::solveSudokuHelper(char (&board)[9][9]) {
    QVector<int> rc = nextUnassigned(board);
    int row, column = 0;
    if (rc[0] == -1) {
        return true;
    }
    else {
        row = rc[0];
        column = rc[1];
    }

    for (char num = '1'; num <= '9'; num++)
    {
        if (isValid(board, row, column, num))
        {
            board[row][column] = num;
            if (solveSudokuHelper(board))
                return true;
            board[row][column] = NULL;
        }
    }
    return false;

}


bool SolveSudoku::isValid(char (&board)[9][9], int row, int column, char num) {
    for (int i = 0; i < 9; ++i) {
        if (num == board[row][i]) return false;
        if (num == board[i][column]) return false;
    }

    for (int i = row - row % 3; i < row - row % 3 + 3; ++i) {
        for (int j = column - column % 3; j < column - column % 3 + 3; ++j) {
            if (num == board[i][j]) return false;
        }
    }
    return true;
}

QVector<int> SolveSudoku::nextUnassigned(char (&board)[9][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == NULL)
                return QVector<int>{i, j};
        }
    }
    return QVector<int>{-1,-1};
}

bool SolveSudoku::isValidSudoku(char (&board)[9][9]) {
    for (int i = 0; i < 9; ++i) {
        QVector<int> c(9,0);
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] >= '1' && board[i][j] <= '9') {
                ++c[board[i][j] - 49];
                if (c[board[i][j] - 49] > 1) {
                    return false;
                }
            }else if(board[i][j] != NULL){          //isValid non-number
                return false;
            }
        }
    }
    for (int i = 0; i < 9; ++i) {
        QVector<int> c(9, 0);
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] >= '1' && board[j][i] <= '9') {
                ++c[board[j][i] - 49];
                if (c[board[j][i] - 49] > 1) {
                    return false;
                }
            }
        }
    }

    for (int k = 0; k < 9; k = k + 3) {
        for (int p = 0; p < 9; p = p + 3) {
            QVector<int> c(9, 0);
            for (int i = k; i < k + 3; ++i) {
                for (int j = p; j < p + 3; ++j) {
                    if (board[i][j] >= '1' && board[i][j] <= '9') {
                        ++c[board[i][j] - 49];
                        if (c[board[i][j] - 49] > 1) {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}
