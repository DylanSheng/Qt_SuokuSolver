#ifndef SUDOKUSOLVERAPP_H
#define SUDOKUSOLVERAPP_H

#include <QMainWindow>
#include <QTableView>
#include <QVector>
#include <QMessageBox>
#include <QGridLayout>
#include <QBrush>
namespace Ui {
class SudokuSolverApp;
}

class SudokuSolverApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit SudokuSolverApp(QWidget *parent = 0);
    ~SudokuSolverApp();

public :

private slots:
    void on_Default_Sudoku_clicked();

    void on_SolveSudoku_clicked();

    void on_ClearBoard_clicked();

private:
    Ui::SudokuSolverApp *ui;
    void GenerateBoard();
    char board[9][9] = {' '};
    void showSolution(char (&board)[9][9]);
    void readBoard(char (&board)[9][9]);
};

#endif // SUDOKUSOLVERAPP_H
