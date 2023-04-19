#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void select_method();

    void on_upload_dots_clicked();
    void on_download_dots_clicked();

    void on_gen_dots_but_clicked();

    void on_gen_dots_but_2_clicked();

    void on_scale_source_clicked();

    void on_scale_primitive_clicked();

private:
    void draw_source_graph();
    void draw_primitive_graph();

    void avg_rec_method();
    void left_rec_method();
    void right_rec_method();
    void trap_rec_method();
    void simpson_rec_method();

    void process_dots();


    Ui::MainWindow *ui;

    double d, x_begin = 0.0;
    int N;
    std::string rpn_func;

    QVector<double> inp_x, inp_y;
    QVector<double> left_rec_x, right_rec_x, avg_rec_x, trap_x, simp_x;
    QVector<double> left_rec_y, right_rec_y, avg_rec_y, trap_y, simp_y;
};
#endif // MAINWINDOW_H
