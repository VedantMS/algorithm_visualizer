#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QLabel>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QComboBox>

namespace Ui {
class MainPage;
}

class MainPage : public QWidget {
    Q_OBJECT

    public:
        explicit MainPage(QWidget *parent = nullptr);
        ~MainPage();

    signals:
        void search(const QString &algorithm);
        void sort(const QString &algorithm);

    private:
        Ui::MainPage *ui;
        QVBoxLayout *layout;
        QLabel *title;
        QComboBox *searchBox, *sortBox;
};

#endif // MAINPAGE_H
