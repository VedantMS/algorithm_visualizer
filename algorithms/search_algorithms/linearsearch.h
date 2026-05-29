#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>

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

    private:
        Ui::LinearSearch *ui;
        QVBoxLayout *layout;
        QRadioButton *goBackButton;

};

#endif // LINEARSEARCH_H
