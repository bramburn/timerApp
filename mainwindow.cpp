#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QTime>
#include "timemanager.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {

    TimeManager *timeManagerClass = new TimeManager(this);
    timeManagerClass->setUi(ui); //pass the pointer

//    todo: add settings to fill in the information
//    QSettings sts;
//    ui->focusText->setPlainText(sts.value("FocusText").toString());
    this->timer = new QTimer();

    connect(this, &MainWindow::stopWatchStart, timeManagerClass, &TimeManager::makeSelectStop);

    connect(this, &MainWindow::stopWatchStop, timeManagerClass, &TimeManager::makeSelectValid);


    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::startTimerBtnClicked() {
    //set the
    if (!started) {
        if (stopWatch->second() == 0) {
            // carry on from pause
            stopWatch = new QTime(0, minutes, 0);
        }

        connect(this->timer, &QTimer::timeout,
                this, &MainWindow::updateTimer);
        timer->start(1000);
        updateTimer();
        ui->startBtnTimer->setText(QString("Pause Timer"));
        started = true;
        emit stopWatchStart();
    } else {
        timer->stop();
        ui->startBtnTimer->setText(QString("Continue"));
        started = false;
        emit stopWatchPause();
    }
}


void MainWindow::onactionCloseTriggered() {
//    QSettings sts;
//    sts.setValue("FocusText", ui->focusText->toPlainText());
    this->close();
}


void MainWindow::updateTimer() {

    *stopWatch = stopWatch->addSecs(-1);

    if (stopWatch->toString("m:ss") == QString("0:00")) {
        qDebug() << QString("Stopped");
        //destroy timer and release
        emit timerFinished();
    }

    QString currentTimeText = stopWatch->toString("m:ss");
    ui->timeDisplay->setText(currentTimeText);


}


void MainWindow::on_stopTimerBtn_clicked() {
    timer->stop();
    //refactor
    stopWatch = new QTime(0, minutes, 0);
    disconnect(this->timer, &QTimer::timeout,
               this, &MainWindow::updateTimer);
    ui->startBtnTimer->setText(QString("Start Focus"));
    ui->timeDisplay->setText("00:00");

    started = false;
    emit stopWatchStop();
}


void MainWindow::on_timerSelect_currentIndexChanged(int index) {
    switch (index) {
        case 0:
            minutes = 5;
            break;
        case 1:
            minutes = 10;
            break;
        case 2:
            minutes = 15;
            break;
        case 3:
            minutes = 20;
            break;
    }

}

