#include "linearsearch.h"
#include "algorithms/search_algorithms/ui_linearsearch.h"
#include <QDebug>

LinearSearch::LinearSearch(QWidget *parent) : QWidget(parent), ui(new Ui::LinearSearch) {
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    goBackButton= new QRadioButton();

    inputN = new QSpinBox(this);
    inputN->clear();

    acceptN = new QPushButton("Enter Total Elements", this);

    timer = new QTimer(this);

    layout->addWidget(goBackButton);
    layout->addWidget(inputN);
    layout->addWidget(acceptN);

    this->setLayout(layout);

    connect(goBackButton, &QRadioButton::clicked, this, &LinearSearch::goBack);
    connect(acceptN, &QPushButton::clicked, this, &LinearSearch::on_acceptN_clicked);
    connect(timer, &QTimer::timeout, this, &LinearSearch::linearsearch);
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
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    layout->addWidget(view);

    drawArray();
}

void LinearSearch::drawArray() {
    QFont font("Times New Roman", 14);

    for(int i = 0; i < N; i++) {
        QGraphicsRectItem *rect = new QGraphicsRectItem(0, 0, 100, 50);

        rect->setBrush(Qt::cyan);
        rect->setPos(i * 100, 0);

        QString num = QString::number(data[i]);
        QString indexText = QString::number(i);
        QGraphicsSimpleTextItem *value = new QGraphicsSimpleTextItem(num, rect);
        QGraphicsSimpleTextItem *index = new QGraphicsSimpleTextItem(indexText, rect);

        value->setFont(font);
        value->setBrush(Qt::black);

        index->setFont(font);
        index->setBrush(Qt::magenta);

        qreal xoffset = (rect->rect().width() - value->boundingRect().width()) / 2;
        qreal yoffset = (rect->rect().height() - value->boundingRect().height()) / 2;

        value->setPos(xoffset, yoffset);
        index->setPos(xoffset, rect->rect().height() + 20);

        scene->addItem(rect);
        scene->addItem(index);

        array << rect;
    }

    QPolygonF points = QPolygonF({QPointF(0, 0), QPointF(20, 0), QPointF(10, 15)});
    arrayArrow = new QGraphicsPolygonItem(points);

    arrayArrow->setBrush(Qt::magenta);
    arrayArrow->setPos(40, -20);

    scene->addItem(arrayArrow);

    timer->start(2000);
}

void LinearSearch::linearsearch() {
    if(index == N) {
        array[index - 1]->setBrush(Qt::yellow);

        arrayArrow->hide();
        timer->stop();

        return;
    }

    arrayArrow->setPos(40 + index * 100, -20);

    array[index]->setBrush(Qt::blue);

    if(index > 0) {
        array[index - 1]->setBrush(Qt::yellow);
    }

    if(val == data[index]) {
        QTimer::singleShot(1000, this, [this](){
            array[index]->setBrush(Qt::green);
        });

        timer->stop();

        return;
    }

    index++;
}