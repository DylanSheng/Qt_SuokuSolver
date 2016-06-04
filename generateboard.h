#ifndef GENERATEBOARD_H
#define GENERATEBOARD_H

#include <QTableWidget>
#include <QObject>
class GenerateBoard : public QObject
{
    Q_OBJECT
public:
    GenerateBoard();
    void setupBoard();
private:
    QTableWidget* table = new QTableWidget(9, 9);
};

#endif // GENERATEBOARD_H
