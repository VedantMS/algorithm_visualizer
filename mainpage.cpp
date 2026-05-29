#include "mainpage.h"
#include "ui_mainpage.h"
#include <QRadioButton>

MainPage::MainPage(QWidget *parent) : QWidget(parent), ui(new Ui::MainPage) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);

    title = new QLabel("Select Algorithm Type", this);

    searchBox = new QComboBox(this);
    searchBox->addItem("Search Algorithms");
    searchBox->addItem("Linear Search");
    searchBox->addItem("Binary Search");

    sortBox = new QComboBox(this);
    sortBox->addItem("Sort Algorithms");
    sortBox->addItem("Bubble Sort");
    sortBox->addItem("Selection Sort");
    sortBox->addItem("Merge Sort");
    sortBox->addItem("Quick Sort");


    layout->addWidget(title);
    layout->addWidget(searchBox);
    layout->addWidget(sortBox);

    this->setLayout(layout);

    connect(searchBox, &QComboBox::textActivated, this, &MainPage::search);
    //connect(sortBox, &QComboBox::textActivated, this, &MainPage::sort);
}

MainPage::~MainPage() {
    delete ui;
}
