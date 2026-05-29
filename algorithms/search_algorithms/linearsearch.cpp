#include "linearsearch.h"
#include "algorithms/search_algorithms/ui_linearsearch.h"

LinearSearch::LinearSearch(QWidget *parent) : QWidget(parent), ui(new Ui::LinearSearch) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    goBackButton= new QRadioButton();

    inputN = new QSpinBox(this);
    inputN->clear();

    acceptN = new QPushButton("Enter Total Elements", this);

    layout->addWidget(goBackButton);
    layout->addWidget(inputN);
    layout->addWidget(acceptN);

    this->setLayout(layout);

    connect(goBackButton, &QRadioButton::clicked, this, &LinearSearch::goBack);
    connect(acceptN, &QPushButton::clicked, this, &LinearSearch::on_acceptN_clicked);
}

LinearSearch::~LinearSearch() {
    delete ui;
}

void LinearSearch::on_acceptN_clicked() {
    if(N == 0) {
        N = inputN->value();

        if(N <= 0) {
            return;
        }

        acceptN->setText("Enter Element");
        inputN->clear();
        return;
    }

    if(data.size() < N) {
        int element = inputN->value();
        data << element;
        inputN->clear();

        if (data.size() == N) {
            acceptN->setText("Enter Value to Find");
        }

        return;
    }

    int element = inputN->value();
    val = element;

    inputN->setDisabled(true);
    acceptN->setDisabled(true);

    display();
}

void LinearSearch::display() {

}