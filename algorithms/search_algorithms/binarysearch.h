#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QSpinBox>

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

private:
    Ui::BinarySearch *ui;
    QVBoxLayout *layout;
    QRadioButton *goBackButton;
    QSpinBox *inputN;
    QPushButton *acceptN;
    QVector<int> data;
    int N;

    void display();
};

#endif // BINARYSEARCH_H
