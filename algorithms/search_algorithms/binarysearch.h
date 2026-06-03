#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

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
class BinarySearch;
}

class BinarySearch : public QWidget
{
    Q_OBJECT

    public:
        explicit BinarySearch(QWidget *parent = nullptr);
        ~BinarySearch();

    signals:
        void goBack();

    private slots:
        void on_acceptN_clicked();
        void binarysearch();

    private:
        Ui::BinarySearch *ui;
        QVBoxLayout *layout;
        QRadioButton *goBackButton;
        QSpinBox *inputN;
        QPushButton *acceptN;
        QVector<int> data;

        QGraphicsScene *scene;
        QGraphicsView *view;

        QVector<QGraphicsRectItem *> array;

        QGraphicsPolygonItem *arrayArrowLow;
        QGraphicsPolygonItem *arrayArrowHigh;
        QGraphicsPolygonItem *arrayArrowMid;

        QGraphicsSimpleTextItem *llabel, *hlabel, *mlabel;

        bool state = false;

        QTimer *timer;

        int N = 0;
        int val = 0;
        int low, high, mid;

        void display();
        void drawArray();
        void updateLabels();
};

#endif // BINARYSEARCH_H
