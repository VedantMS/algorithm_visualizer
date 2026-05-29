#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "mainpage.h"

#include "algorithms/search_algorithms/linearsearch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override;

    private slots:
        void searchAlgorithm(const QString &algorithm);
        void goToMainPage();

    private:
        Ui::MainWindow *ui;

        QStackedWidget *centralWidget;
        MainPage *firstPage;
        LinearSearch *linearSearchPage;

};

#endif // MAINWINDOW_H