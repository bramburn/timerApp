#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void onactionCloseTriggered();
    void startTimerBtnClicked();
    void updateTimer();


    void on_stopTimerBtn_clicked();

    void on_timerSelect_currentIndexChanged(int index);
signals:
    void stopWatchStart();
    void stopWatchPause();
    void stopWatchStop();
    void timerFinished();

private:
    Ui::MainWindow *ui;
    QTime *stopWatch;
    QTimer *timer;
    bool started{false};
    bool paused{false};
    int minutes{5};

};
#endif // MAINWINDOW_H
