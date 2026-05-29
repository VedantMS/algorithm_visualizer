#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    centralWidget = new QStackedWidget();
    setCentralWidget(centralWidget);

    firstPage = new MainPage(this);
    linearSearchPage = new LinearSearch(this);
    binarySearchPage = new BinarySearch(this);

    centralWidget->addWidget(firstPage);
    centralWidget->addWidget(linearSearchPage);
    centralWidget->addWidget(binarySearchPage);

    connect(firstPage, &MainPage::search, this, &MainWindow::searchAlgorithm);
    connect(linearSearchPage, &LinearSearch::goBack, this, &MainWindow::goToMainPage);
    connect(binarySearchPage, &BinarySearch::goBack, this, &MainWindow::goToMainPage);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::searchAlgorithm(const QString &algorithm) {
    if(algorithm == "Linear Search") {
        centralWidget->setCurrentWidget(linearSearchPage);
    }

    else if(algorithm == "Binary Search") {
        centralWidget->setCurrentWidget(binarySearchPage);
    }
}

void MainWindow::goToMainPage() {
    centralWidget->setCurrentWidget(firstPage);
}