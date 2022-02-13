#include "timemanager.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QObject>
#include <QDebug>

TimeManager::TimeManager(QObject *parent)
        : QObject(parent) {


}

void TimeManager::makeSelectStop() {

    this->ui->timerSelect->setDisabled(true);

}


void TimeManager::makeSelectValid() {

    this->ui->timerSelect->setDisabled(false);
}

TimeManager::~TimeManager() {

}

void TimeManager::setUi(Ui::MainWindow *ui) {
    this->ui = ui;
}
