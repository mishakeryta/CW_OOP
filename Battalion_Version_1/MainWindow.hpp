#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include "Battalion.hpp"
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

private:
    Battalion battalion;
    void MilitariesToQWidgetTable(QTableWidget& tabel,const vector<Military>& vector);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
