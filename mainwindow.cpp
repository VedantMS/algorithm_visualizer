#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    centralWidget = new QStackedWidget();
    setCentralWidget(centralWidget);

    firstPage = new MainPage(this);
    linearSearchPage = new LinearSearch(this);

    centralWidget->addWidget(firstPage);
    centralWidget->addWidget(linearSearchPage);

    connect(firstPage, &MainPage::search, this, &MainWindow::searchAlgorithm);
    connect(linearSearchPage, &LinearSearch::goBack, this, &MainWindow::goToMainPage);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::searchAlgorithm(const QString &algorithm) {
    if(algorithm == "Linear Search") {
        centralWidget->setCurrentWidget(linearSearchPage);
    }

    //else if(algorithm == "Binary Search");
}

void MainWindow::goToMainPage() {
    centralWidget->setCurrentWidget(firstPage);
}