#include "linearsearch.h"
#include "algorithms/search_algorithms/ui_linearsearch.h"

LinearSearch::LinearSearch(QWidget *parent) : QWidget(parent), ui(new Ui::LinearSearch) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    goBackButton= new QRadioButton();










    layout->addWidget(goBackButton);
    this->setLayout(layout);

    connect(goBackButton, &QRadioButton::clicked, this, &LinearSearch::goBack);
}

LinearSearch::~LinearSearch() {
    delete ui;
}
