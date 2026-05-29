#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QSpinBox>
#include <QtCore>
#include <QtGui>

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

    private:
        Ui::LinearSearch *ui;
        QVBoxLayout *layout;
        QRadioButton *goBackButton;
        QSpinBox *inputN;
        QPushButton *acceptN;
        QVector<int> data;
        int N = 0;
        int val = 0;

        void display();

};

#endif // LINEARSEARCH_H
