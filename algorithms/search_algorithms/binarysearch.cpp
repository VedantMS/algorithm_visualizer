#include "binarysearch.h"
#include "algorithms/search_algorithms/ui_binarysearch.h"

BinarySearch::BinarySearch(QWidget *parent) : QWidget(parent), ui(new Ui::BinarySearch) {
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

    connect(goBackButton, &QRadioButton::clicked, this, &BinarySearch::goBack);
    connect(acceptN, &QPushButton::clicked, this, &BinarySearch::on_acceptN_clicked);
    connect(timer, &QTimer::timeout, this, &BinarySearch::binarysearch);
}

BinarySearch::~BinarySearch()
{
    delete ui;
}

void BinarySearch::on_acceptN_clicked() {
    if(N == 0) {
        N = inputN->value();

        if(N <= 0 || N > 10) {
            QMessageBox::about(this, "Invalid Argument", "Total number of arguments cannot be <= 0 or > 10");
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

        if(data.size() == N) {
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

void BinarySearch::display() {
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);

    layout->addWidget(view);

    drawArray();
}

void BinarySearch::drawArray() {
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

        array << rect;
    }

    low = 0;
    high = N - 1;
    mid = low + (high - low) / 2;

    QPolygonF points = QPolygonF({QPointF(0, 0), QPointF(20, 0), QPointF(10, 15)});
    arrayArrowLow = new QGraphicsPolygonItem(points);
    arrayArrowHigh = new QGraphicsPolygonItem(points);
    arrayArrowMid = new QGraphicsPolygonItem(points);

    llabel = new QGraphicsSimpleTextItem("Low", arrayArrowLow);
    hlabel = new QGraphicsSimpleTextItem("High", arrayArrowHigh);
    mlabel = new QGraphicsSimpleTextItem("Mid", arrayArrowMid);

    arrayArrowLow->setBrush(Qt::magenta);
    arrayArrowLow->setPos(40, -20);

    arrayArrowHigh->setBrush(Qt::darkMagenta);
    arrayArrowHigh->setPos(40 + high * 100, -20);

    arrayArrowMid->setBrush(Qt::green);
    arrayArrowMid->setPos(40 + mid * 100, -20);

    mlabel->hide();

    scene->addItem(arrayArrowLow);
    scene->addItem(arrayArrowHigh);

    QTimer::singleShot(2000, this, [this]{
        array[mid]->setBrush(Qt::blue);

        scene->addItem(arrayArrowMid);
        mlabel->show();

        timer->start(2000);
    });
}

void BinarySearch::binarysearch() {
    if(low > high) {
        arrayArrowLow->hide();
        arrayArrowHigh->hide();
        arrayArrowMid->hide();

        timer->stop();
        return;
    }

    if(state) {
        int num = mid;
        mid = low + (high - low) / 2;

        arrayArrowMid->setPos(40 + mid * 100, -20);
        array[mid]->setBrush(Qt::blue);
        array[num]->setBrush(Qt::yellow);



        state = false;
    }

    else {
        if(data[mid] == val) {
            array[mid]->setBrush(Qt::green);
            timer->stop();
            return;
        }

        if(data[mid] < val) {
            int num = low;
            low = mid + 1;

            if(low <= high) {
                arrayArrowLow->setPos(40 + low * 100, -20);

                if(low == high) {
                    llabel->setPos(0, -40);
                }

                else {
                    llabel->setPos(0, -20);
                }
            }
        }

        else {
            int num = high;
            high = mid - 1;

            if(low <= high) {
                arrayArrowHigh->setPos(40 + high * 100, -20);

                if(low == high) {
                    hlabel->setPos(0, -40);
                }

                else {
                    hlabel->setPos(0, -20);
                }
            }
        }

        state = true;
    }
}

void BinarySearch::updateLabels() {
    llabel->setPos(0, -20);
    hlabel->setPos(0, -20);
    mlabel->setPos(0, -20);

    if(low == low && mid == high) {
        mlabel->setPos(0, -60);
    }

    else if(mid == low || mid == high) {
        mlabel->setPos(0, -40);
    }

    else {
        mlabel->setPos(0, -20);
    }
}