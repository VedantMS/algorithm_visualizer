#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <QVBoxLayout>
#include <QComboBox>
#include <QLabel>

namespace Ui {
class SearchAlgorithms;
}

class SearchAlgorithms : public QWidget
{
    Q_OBJECT

public:
    explicit SearchAlgorithms(QWidget *parent = nullptr);
    ~SearchAlgorithms();

private:
    Ui::SearchAlgorithms *ui;
    QVBoxLayout *layout;
    QLabel *title;
    QComboBox *searchBox, *sortBox;
};

#endif // SEARCHALGORITHMS_H
