#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QSpinBox>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTextBlockFormat>
#include <QTimer>

namespace Ui {
class LinearSearch;
}

class LinearSearch : public QWidget {
    Q_OBJECT

    public:
        explicit LinearSearch(QWidget *parent = nullptr);
        ~LinearSearch();

    signals:
        void goBack();

    private slots:
        void on_acceptN_clicked();
        void linearsearch();

    private:
        Ui::LinearSearch *ui;
        QVBoxLayout *layout;
        QRadioButton *goBackButton;
        QSpinBox *inputN;
        QPushButton *acceptN;
        QVector<int> data;

        QGraphicsScene *scene;
        QGraphicsView *view;

        QVector<QGraphicsRectItem *> array;

        QGraphicsPolygonItem *arrayArrow;

        QTimer *timer;

        int N = 0;
        int val = 0;
        int index = 0;

        void display();
        void drawArray();
};

#endif // LINEARSEARCH_H
