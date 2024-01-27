#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "func_calculus.h"
#include "derive_integrate.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

#include <fstream>
#include <filesystem>
#include <string>
#include <cmath>
#include <iostream>


void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Enter) {
        qDebug() << "Enter have been pressed";
    }
}


void MainWindow::rescale_graph(QCustomPlot *graph) {
    graph->xAxis->setRange(-rng, rng);
    graph->yAxis->setRange(-rng, rng);
    graph->replot();
}


void MainWindow::init_graph(QCustomPlot *graph) {
    graph->xAxis->setRange(-rng, rng);
    graph->yAxis->setRange(-rng, rng);

    graph->setInteraction(QCP::iRangeZoom, true);
    graph->setInteraction(QCP::iRangeDrag, true);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->avg_rec_but, SIGNAL(clicked()), this, SLOT(draw_primitive_graph()));
    connect(ui->right_rec_but, SIGNAL(clicked()), this, SLOT(draw_primitive_graph()));
    connect(ui->left_rec_but, SIGNAL(clicked()), this, SLOT(draw_primitive_graph()));
    connect(ui->trap_but, SIGNAL(clicked()), this, SLOT(draw_primitive_graph()));
    connect(ui->simpson_but, SIGNAL(clicked()), this, SLOT(draw_primitive_graph()));

    connect(ui->scale_source_but, &QPushButton::clicked, this, [=](){ rescale_graph(ui->source_graph); });
    connect(ui->scale_primitive_but, &QPushButton::clicked, this, [=](){ rescale_graph(ui->primitive_graph); });
    connect(ui->scale_deriv_source_but, &QPushButton::clicked, this, [=](){ rescale_graph(ui->deriv_source_graph); });
    connect(ui->scale_deriv_primit_but, &QPushButton::clicked, this, [=](){ rescale_graph(ui->deriv_primitive_graph); });

    QShortcut *returnShortcut = new QShortcut(QKeySequence("Return"), ui->gen_dots_but);
    connect(returnShortcut, SIGNAL(activated()), ui->gen_dots_but, SLOT(click()));

    init_graph(ui->source_graph);
    init_graph(ui->primitive_graph);
    init_graph(ui->deriv_source_graph);
    init_graph(ui->deriv_primitive_graph);

    ui->begin->setText("-10");
    ui->end->setText("10");
    ui->dist->setText("0.1");
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::draw_graph(QCustomPlot *graph, QVector<double> x_data, QVector<double> y_data) {
    graph->clearGraphs();

    graph->addGraph();
    graph->graph(0)->setPen(QPen(Qt::red));
    graph->graph(0)->setData(x_data, y_data);

    graph->replot();
}


void MainWindow::draw_primitive_graph() {
    if (ui->avg_rec_but->isChecked()) {
//        draw_graph(ui->primitive_graph, avg_rec_x, avg_rec_y);
        integral_x = &avg_rec_x;
        integral_y = &avg_rec_y;

    } else if (ui->right_rec_but->isChecked()) {
//        draw_graph(ui->primitive_graph, right_rec_x, right_rec_y);
        integral_x = &right_rec_x;
        integral_y = &right_rec_y;

    } else if (ui->left_rec_but->isChecked()) {
//        draw_graph(ui->primitive_graph, left_rec_x, left_rec_y);
        integral_x = &left_rec_x;
        integral_y = &left_rec_y;

    } else if (ui->trap_but->isChecked()) {
//        draw_graph(ui->primitive_graph, trap_x, trap_y);
        integral_x = &trap_x;
        integral_y = &trap_y;

    } else if (ui->simpson_but->isChecked()) {
//        draw_graph(ui->primitive_graph, simp_x, simp_y);
        integral_x = &simp_x;
        integral_y = &simp_y;

    } else {
        QMessageBox::warning(this,
                             tr("Не выбран метод интегрирования"),
                             tr("Выберите метод интегрирования, только затем можно будет выгрузить точки первообразной."));
        return;
    }
    draw_graph(ui->primitive_graph, *integral_x, *integral_y);
}


void MainWindow::process_dots() {
//    source graph
    draw_graph(ui->source_graph, inp_x, inp_y);

    integrate_methods::avg_rec_method(inp_y, avg_rec_x, avg_rec_y, x_begin, d);
    ui->avg_rec_val->setText(QString::number(avg_rec_y.last(), 'g', 8));

    integrate_methods::right_rec_method(inp_y, right_rec_x, right_rec_y, x_begin, d);
    ui->right_rec_val->setText(QString::number(right_rec_y.last(), 'g', 8));

    integrate_methods::left_rec_method(inp_y, left_rec_x, left_rec_y, x_begin, d);
    ui->left_rec_val->setText(QString::number(left_rec_y.last(), 'g', 8));

    integrate_methods::trap_rec_method(inp_y, trap_x, trap_y, x_begin, d);
    ui->trap_val->setText(QString::number(trap_y.last(), 'g', 8));

    integrate_methods::simpson_rec_method(inp_y, simp_x, simp_y, x_begin, d);
    ui->simpson_val->setText(QString::number(simp_y.last(), 'g', 8));

//    primitive graph
    draw_primitive_graph();

//    derivative graph
    derivate_methods::derivate(inp_y, deriv_sour_x, deriv_sour_y, x_begin, d);
    derivate_methods::derivate(*integral_y, deriv_prim_x, deriv_prim_y, x_begin, d);
//    for (int i = 0; i < 10; i++)
//        std::cout << deriv_prim_x[i] << " " << deriv_prim_y[i] << " " << integral_y->at(i) << " " << integral_y->at(i + 1) << "\n";

    draw_graph(ui->deriv_source_graph, deriv_sour_x, deriv_sour_y);
    draw_graph(ui->deriv_primitive_graph, deriv_prim_x, deriv_prim_y);
}


void MainWindow::on_upload_dots_clicked() {
    QString file_path = QFileDialog::getOpenFileName(this, "Загрузить точки");
    if (file_path.isEmpty())
        return;

//    Reading data from file
    ifstream fin(file_path.toStdString());
    if (!fin) {
        std::string response = "Невозможно открыть выбранный файл: ";
        response = response + file_path.toStdString();
        QMessageBox::warning(this, tr("Ошибка при открытии файла"), tr(response.c_str()));
        return;
    }

    ui->path_to_file->setText(file_path);

    fin >> N >> d >> x_begin;

    inp_x.clear();
    inp_y.clear();

    double el;
    for (int i = 0; i < N; i++) {
        fin >> el;

        if (inp_y.size() > 0 && abs(inp_y.last() - el) > pow(10, 12))
            continue;

        inp_y.push_back(el);
        inp_x.push_back(x_begin + i * d);
    }

    fin.close();

    N = inp_x.size();
    process_dots();
}


void MainWindow::download_dots(QString out_file_path, QVector<double> out_y) {
    if (out_file_path.isEmpty())
        return;

    ofstream fout(out_file_path.toLocal8Bit());
    if (!fout) {
        QMessageBox::warning(this, tr("Ошибка при создании файла"), tr("Невозможно создать файл"));
        return;
    }

    fout << out_y.size() << "\n" << d << "\n" << x_begin << "\n";
    for (int i = 0; i < out_y.size(); i++) {
        fout << out_y[i] << " ";
    }

    fout.close();
}


void MainWindow::on_download_source_dots_clicked() {
    if (integral_y->size() == 0) {
        QMessageBox::warning(this,
                             tr("Нечего скачивать"),
                             tr("Похоже вы еще не ввели исходную функцию."));
        return;
    }

    string op_file = filesystem::current_path().string() + "\\func_dots.txt";
    QString out_file_path = QFileDialog::getSaveFileName(this,
                                                         QString::fromStdString("Сохранить точки исходной функции"),
                                                         QString::fromStdString(op_file).toLocal8Bit());

    download_dots(out_file_path, inp_y);
}


void MainWindow::on_download_primitive_dots_clicked() {
    if (integral_y->size() == 0) {
        QMessageBox::warning(this,
                             tr("Нечего интегрировать"),
                             tr("Похоже вы еще не ввели функцию, которую нужно проинтегрировать, или не загрузили ее точки."));
        return;
    }

    string op_file = filesystem::current_path().string() + "\\primitive_dots.txt";
    QString out_file_path = QFileDialog::getSaveFileName(this,
                                                         QString::fromStdString("Сохранить точки первообразной"),
                                                         QString::fromStdString(op_file).toLocal8Bit());

    download_dots(out_file_path, *integral_y);
}


void MainWindow::on_gen_dots_but_clicked() {
    if (!ui->function->text().size() || !ui->begin->text().size() || !ui->end->text().size() || !ui->dist->text().size()) {
        QMessageBox::warning(this, tr("Внимание"), tr("Для построения графика функции должны быть заполнены все поля!"));
        return;
    }

    std::string func = ui->function->text().toStdString();

    if (!fcalc::is_correct_expression(func)) {
        QMessageBox::warning(this, tr("Внимание"), tr("Неверно введена функция"));
        return;
    }

    func = fcalc::mul_correct(func);
    func = fcalc::brackets_correct(func);

    ui->function->setText(QString::fromStdString(func));
    rpn_func = fcalc::convert_to_rpn(func);

    std::string str_x_begin = fcalc::mul_correct(ui->begin->text().toStdString());
    ui->begin->setText(QString::fromStdString(str_x_begin));
    x_begin = fcalc::evaluate_rpn(fcalc::convert_to_rpn(str_x_begin), 0.0);

    std::string str_x_end = fcalc::mul_correct(ui->end->text().toStdString());
    ui->end->setText(QString::fromStdString(str_x_end));
    double x_end= fcalc::evaluate_rpn(fcalc::convert_to_rpn(str_x_end), 0.0);

    if (x_end <= x_begin) {
        QMessageBox::warning(this, tr("Внимание"), tr("Значение в начальной точке построения должно быть меньше, чем в конечной!"));
        return;
    }

    d = stod(ui->dist->text().toStdString());

    if (abs(log10(d)) + log10(x_end - x_begin) > 7) {
        QMessageBox::warning(this, tr("Внимание"), tr("Следует уменьшить расстояние между точками или отрезок построения!"));
        return;
    }

    inp_x.clear();
    inp_y.clear();
    N = 0;
    for (int i = 0; x_begin + i*d <= x_end; i++) {
        double cur_val = fcalc::evaluate_rpn(rpn_func, (double) x_begin + i*d);
        if (inp_y.size() > 0 && abs(inp_y.last() - cur_val) > pow(10, 12))
            continue;
        else
            inp_y.push_back(cur_val);

        inp_x.push_back(x_begin + i*d);
        N++;
    }

    process_dots();
}


void MainWindow::on_download_deriv_dots_clicked() {
    if (integral_y->size() == 0) {
        QMessageBox::warning(this,
                             tr("Нечего дифференцировать"),
                             tr("Похоже вы еще не ввели функцию, производную которой нужно получить, или не загрузили ее точки."));
        return;
    }

    string op_file = filesystem::current_path().string() + "\\deriv_func_dots.txt";
    QString out_file_path = QFileDialog::getSaveFileName(this,
                                                         QString::fromStdString("Сохранить точки производной от исходной функции"),
                                                         QString::fromStdString(op_file).toLocal8Bit());

    download_dots(out_file_path, deriv_sour_y);
}

