#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include "Battalion.hpp"
#include <functional>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbReadFromFile_clicked();


    void on_pbSave_clicked();

    void on_pbAdd_clicked();

    void on_actionSave_triggered();

    void on_actionPrevSave_triggered();

    void on_actionAddNewMilitary_triggered();

    void on_action_task3_triggered();

    void on_action_task3_1_triggered();

    void on_action_task3_2_triggered();

    void on_action_task3_3_triggered();

    void on_action_task4_triggered();

    void on_action_task5_triggered();

    void on_actionTask1_triggered();

    void on_actionTask2_triggered();

private:
    Battalion battalion;
    void militariesToQWidgetTable(QTableWidget& tabel,const vector<Military>& vector);
    void showThatSuit(QString& textOfCondiotion,std::function<bool(const Military&)> condion);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
