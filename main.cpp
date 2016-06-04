#include "sudokusolverapp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SudokuSolverApp w;
    w.show();

    return a.exec();
}
