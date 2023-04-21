#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"

#include <QMainWindow>
#include <QVector>
#include <string>

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
    void rescale_graph(QCustomPlot *graph);

    void on_upload_dots_clicked();
    void on_download_primitive_dots_clicked();
    void on_gen_dots_but_clicked();
    void on_download_source_dots_clicked();

    void draw_primitive_graph();


private:
    void left_rec_method();
    void right_rec_method();
    void trap_rec_method();
    void simpson_rec_method();

    void draw_graph(QCustomPlot *graph, QVector<double> x_data, QVector<double> y_data);

    void process_dots();
    void init_graph(QCustomPlot *graph);


    Ui::MainWindow *ui;

    double d, x_begin = 0.0;
    int N, rng = 11;
    std::string rpn_func;

    QVector<double> inp_x, inp_y;
    QVector<double> left_rec_x, right_rec_x, avg_rec_x, trap_x, simp_x;
    QVector<double> left_rec_y, right_rec_y, avg_rec_y, trap_y, simp_y;
};
#endif // MAINWINDOW_H
