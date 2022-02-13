#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <QWidget>
#include "ui_mainwindow.h"

class TimeManager : public QObject {
Q_OBJECT
public:
    explicit TimeManager(QObject *parent = nullptr);
    void setUi(Ui::MainWindow *);
public slots:

    void makeSelectStop();
    void makeSelectValid();


private:
    Ui::MainWindow *ui;
    ~TimeManager();

};

#endif // TIMEMANAGER_H
