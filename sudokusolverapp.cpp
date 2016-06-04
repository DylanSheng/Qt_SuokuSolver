#include "sudokusolverapp.h"
#include "ui_sudokusolverapp.h"
#include "solvesudoku.h"

SudokuSolverApp::SudokuSolverApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuSolverApp)
{
    ui->setupUi(this);
    GenerateBoard();
}

SudokuSolverApp::~SudokuSolverApp()
{
    delete ui;
}


void SudokuSolverApp::GenerateBoard() //generate a empty board. set default.
{
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            board[i][j] = NULL;
        }
    }
    showSolution(board);
}

void SudokuSolverApp::readBoard(char (&board)[9][9]) //readboard. store value in global variable board.
{
    QTableWidget* table = ui->Board;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            QTableWidgetItem *item = new QTableWidgetItem(NULL);
            item = table->takeItem(r, c);//set item value            
            board[r][c] = QString(item->text()).toStdString()[0];
        }
    }


}

void SudokuSolverApp::showSolution(char (&board)[9][9]){     //show board[][]
    QTableWidget* table = ui->Board;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            QTableWidgetItem *item = new QTableWidgetItem(QString(board[r][c]));
            item->setTextAlignment(Qt::AlignCenter); // set text center          
            table->setItem(r, c, item);//set item value
        }
    }
}



/*-----------------------------------------action---------------------------------------------------*/
void SudokuSolverApp::on_Default_Sudoku_clicked()   //show default sudoku
{
    char v[9][9]  = {
        { NULL,NULL,'9','7','4','8',NULL,NULL,NULL },
        { '7',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
        { NULL,'2',NULL,'1',NULL,'9',NULL,NULL,NULL },
        { NULL,NULL,'7',NULL,NULL,NULL,'2','4',NULL },
        { NULL,'6','4',NULL,'1',NULL,'5','9',NULL },
        { NULL,'9','8',NULL,NULL,NULL,'3',NULL,NULL },
        { NULL,NULL,NULL,'8',NULL,'3',NULL,'2',NULL },
        { NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'6' },
        { NULL,NULL,NULL,'2','7','5','9',NULL,NULL }
    };
    std::memcpy(board, v, sizeof(board));
    showSolution(board);
}

void SudokuSolverApp::on_SolveSudoku_clicked()  //solve current sudoku on the board
{
    SudokuSolverApp::readBoard(board);
    SolveSudoku s;
    if(s.isValidSudoku(board)){
        if(!s.solveSudokuHelper(board)){
            QMessageBox msg;
            msg.setText("No Solution!");
            msg.exec();
        }
    }else{
        QMessageBox msg;
        msg.setText("Not Valid!");
        msg.exec();
    }
    showSolution(board);
}

void SudokuSolverApp::on_ClearBoard_clicked()   //clear board
{
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = NULL;

    showSolution(board);
}
