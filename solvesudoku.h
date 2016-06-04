#ifndef SOLVESUDOKU_H
#define SOLVESUDOKU_H

#include <QMainWindow>
#include <QTableView>
#include <QVector>

class SolveSudoku
{
public:
    bool SolveSudoku::isValidSudoku(char (&board)[9][9]);
    bool solveSudokuHelper(char (&board)[9][9]);
private:
    bool isValid(char (&board)[9][9], int row, int column, char num);
    QVector<int> nextUnassigned(char (&board)[9][9]);

};

#endif // SOLVESUDOKU_H
