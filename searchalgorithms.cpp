#include "searchalgorithms.h"
#include "ui_searchalgorithms.h"

SearchAlgorithms::SearchAlgorithms(QWidget *parent) : QWidget(parent), ui(new Ui::SearchAlgorithms) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);

    title = new QLabel("Select Algorithm", this);

    searchBox = new QComboBox(this);
    searchBox->addItem("Search Algorithms");
    searchBox->addItem("Linear Search");
    searchBox->addItem("Binary Search");

    layout->addWidget(title);
    layout->addWidget(searchBox);
    layout->addWidget(sortBox);

    this->setLayout(layout);

    //connect(searchBox, &QComboBox::textActivated, this, &MainPage::search);
}

SearchAlgorithms::~SearchAlgorithms() {
    delete ui;
}
