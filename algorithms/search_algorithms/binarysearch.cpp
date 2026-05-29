#include "binarysearch.h"
#include "algorithms/search_algorithms/ui_binarysearch.h"

BinarySearch::BinarySearch(QWidget *parent) : QWidget(parent), ui(new Ui::BinarySearch) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    goBackButton= new QRadioButton();

    inputN = new QSpinBox(this);
    acceptN = new QPushButton("Enter", this);

    layout->addWidget(goBackButton);
    layout->addWidget(inputN);
    layout->addWidget(acceptN);

    this->setLayout(layout);

    connect(goBackButton, &QRadioButton::clicked, this, &BinarySearch::goBack);
    connect(acceptN, &QPushButton::clicked, this, &BinarySearch::on_acceptN_clicked);
}

BinarySearch::~BinarySearch()
{
    delete ui;
}

void BinarySearch::on_acceptN_clicked() {
    if(N == 0) {
        N = inputN->value();

        if(N <= 0) {
            return;
        }

        acceptN->setText("Enter Element");
        inputN->setValue(0);
        return;
    }

    if(data.size() < N) {
        int element = inputN->value();
        data << element;
        inputN->setValue(0);
    }

    if(data.size() == N) {
        inputN->setDisabled(true);
        acceptN->setDisabled(true);

        display();
    }
}

void BinarySearch::display() {

}