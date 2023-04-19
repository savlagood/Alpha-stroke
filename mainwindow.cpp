#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reverse_polish_notation.h"

#include <QFileDialog>
#include <QMessageBox>

#include <cmath>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <filesystem>
#include <string>

//namespace fp = std::filesystem;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->avg_rec_but, SIGNAL(clicked()), this, SLOT(select_method()));
    connect(ui->right_rec_but, SIGNAL(clicked()), this, SLOT(select_method()));
    connect(ui->left_rec_but, SIGNAL(clicked()), this, SLOT(select_method()));
    connect(ui->trap_but, SIGNAL(clicked()), this, SLOT(select_method()));
    connect(ui->simpson_but, SIGNAL(clicked()), this, SLOT(select_method()));

    ui->source_graph->xAxis->setRange(-8, 8);
    ui->source_graph->yAxis->setRange(-8, 8);
    ui->primitive_graph->xAxis->setRange(-8, 8);
    ui->primitive_graph->yAxis->setRange(-8, 8);

    ui->source_graph->setInteraction(QCP::iRangeZoom, true);
    ui->source_graph->setInteraction(QCP::iRangeDrag, true);

    ui->primitive_graph->setInteraction(QCP::iRangeZoom, true);
    ui->primitive_graph->setInteraction(QCP::iRangeDrag, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::avg_rec_method() {
    avg_rec_x.clear();
    avg_rec_y.clear();
    avg_rec_x.push_back(x_begin + 0);
    avg_rec_y.push_back(0);

    double result = 0;
    for (int i = 0; i < N; i++) {
        if ((i == 0) || (i == N - 1))
            result += (double) inp_y[i] * d/2.0;
        else
            result += (double) inp_y[i] * d;

        avg_rec_x.push_back(x_begin + (i + 1) * d);
        avg_rec_y.push_back(result);
    }

    ui->avg_rec_val->setText(QString::number(result, 'g', 8));
}


void MainWindow::right_rec_method() {
    right_rec_x.clear();
    right_rec_y.clear();
    right_rec_x.push_back(x_begin + 0);
    right_rec_y.push_back(0);

    double result = 0.0;
    for (int i = 1; i < N; i++) {
        result += (double) d * inp_y[i];

        right_rec_x.push_back(x_begin + i * d);
        right_rec_y.push_back(result);
    }

    ui->right_rec_val->setText(QString::number(result, 'g', 8));
}


void MainWindow::left_rec_method() {
    left_rec_x.clear();
    left_rec_y.clear();
    left_rec_x.push_back(x_begin + 0);
    left_rec_y.push_back(0);

    double result = 0.0;
    for (int i = 1; i < N; i++) {
        result += (double) d * inp_y[i - 1];

        left_rec_x.push_back(x_begin + i * d);
        left_rec_y.push_back(result);
    }

    ui->left_rec_val->setText(QString::number(result, 'g', 8));
}


void MainWindow::trap_rec_method() {
    trap_x.clear();
    trap_y.clear();
    trap_x.push_back(x_begin + 0);
    trap_y.push_back(0);

    double result = 0.0;
    for (int i = 1; i < N; i++) {
        result += (inp_y[i - 1] + inp_y[i]) / 2 * d;

        trap_x.push_back(x_begin + i * d);
        trap_y.push_back(result);
    }

    ui->trap_val->setText(QString::number(result, 'g', 8));
}


void MainWindow::simpson_rec_method() {
    simp_x.clear();
    simp_y.clear();
    simp_x.push_back(x_begin + 0);
    simp_y.push_back(0);

    double result = 0.0;
    for (int i = 2; i < N; i += 2) {
        result += ((float) d / 3) * (inp_y[i - 2] + 4.0 * inp_y[i - 1] + inp_y[i]);

        simp_x.push_back(x_begin + i * d);
        simp_y.push_back(result);
    }

    if (N % 2 == 0) {
        result += (inp_y[N - 1] + inp_y[N - 2]) / 2 * d;

        simp_x.push_back(x_begin + (int) N*d);
        simp_y.push_back(result);
    }

    ui->simpson_val->setText(QString::number(result, 'g', 8));
}


void MainWindow::draw_source_graph() {
    ui->source_graph->addGraph();
    ui->source_graph->graph(0)->setPen(QPen(Qt::red));
    ui->source_graph->graph(0)->setData(inp_x, inp_y);

    ui->source_graph->replot();
}


void MainWindow::draw_primitive_graph() {
    QVector<double> out_x, out_y;

    if (ui->avg_rec_but->isChecked()) {
        for (int i = 0; i < avg_rec_x.size(); i++)
            out_x.push_back(avg_rec_x[i]);
        for (int i = 0; i < avg_rec_y.size(); i++)
            out_y.push_back(avg_rec_y[i]);

    } else if (ui->right_rec_but->isChecked()) {
        for (int i = 0; i < right_rec_x.size(); i++)
            out_x.push_back(right_rec_x[i]);
        for (int i = 0; i < right_rec_y.size(); i++)
            out_y.push_back(right_rec_y[i]);

    } else if (ui->left_rec_but->isChecked()) {
        for (int i = 0; i < left_rec_x.size(); i++)
            out_x.push_back(left_rec_x[i]);
        for (int i = 0; i < left_rec_y.size(); i++)
            out_y.push_back(left_rec_y[i]);

    } else if (ui->trap_but->isChecked()) {
        for (int i = 0; i < trap_x.size(); i++)
            out_x.push_back(trap_x[i]);
        for (int i = 0; i < trap_y.size(); i++)
            out_y.push_back(trap_y[i]);

    } else if (ui->simpson_but->isChecked()) {
        for (int i = 0; i < simp_x.size(); i++)
            out_x.push_back(simp_x[i]);
        for (int i = 0; i < simp_y.size(); i++)
            out_y.push_back(simp_y[i]);

    } else {
        QMessageBox::warning(this,
                             tr("Не выбран метод интегрирования"),
                             tr("Выберите метод интегрирования, только затем можно будет выгрузить точки первообразной."));
        return;
    }

    ui->primitive_graph->addGraph();
    ui->primitive_graph->graph(0)->setPen(QPen(Qt::red));
    ui->primitive_graph->graph(0)->setData(out_x, out_y);

    ui->primitive_graph->replot();
}


void MainWindow::process_dots() {
    ui->source_graph->clearGraphs();
    draw_source_graph();

//    cout << "avg\n";
    avg_rec_method();
//    cout << "right\n";
    right_rec_method();
//    cout << "left\n";
    left_rec_method();
//    cout << "trap\n";
    trap_rec_method();
//    cout << "simpson\n";
    simpson_rec_method();

//    cout << "graph\n";
    ui->primitive_graph->clearGraphs();
    draw_primitive_graph();
}


void MainWindow::on_upload_dots_clicked()
{
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


void MainWindow::on_download_dots_clicked()
{
    string op_file = filesystem::current_path().string() + "\\primitive_dots.txt";
    QString out_file_path = QFileDialog::getSaveFileName(this,
                                                         QString::fromStdString("Сохранить точки первообразной"),
                                                         QString::fromStdString(op_file).toLocal8Bit());

    if (out_file_path.isEmpty())
        return;

    ofstream fout(out_file_path.toLocal8Bit());
    if (!fout) {
        QMessageBox::warning(this, tr("Ошибка при создании файла"), tr("Невозможно создать файл"));
        return;
    }

    if (ui->avg_rec_but->isChecked()) {
        fout << avg_rec_y.size() << "\n";
        fout << d << "\n" << x_begin << "\n";
        for (int i = 0; i < avg_rec_y.size(); i++)
            fout << avg_rec_y[i] << " ";

    } else if (ui->right_rec_but->isChecked()) {
        fout << right_rec_y.size() << "\n";
        fout << d << "\n" << x_begin << "\n";
        for (int i = 0; i < right_rec_y.size(); i++)
            fout << right_rec_y[i] << " ";

    } else if (ui->left_rec_but->isChecked()) {
        fout << left_rec_y.size() << "\n";
        fout << d << "\n" << x_begin << "\n";
        for (int i = 0; i < left_rec_y.size(); i++)
            fout << left_rec_y[i] << " ";

    } else if (ui->trap_but->isChecked()) {
        fout << trap_y.size() << "\n";
        fout << d << "\n" << x_begin << "\n";
        for (int i = 0; i < trap_y.size(); i++)
            fout << trap_y[i] << " ";

    } else if (ui->simpson_but->isChecked()) {
        fout << simp_y.size() << "\n";
        fout << d << "\n" << x_begin << "\n";
        for (int i = 0; i < simp_y.size(); i++)
            fout << simp_y[i] << " ";

    } else {
        QMessageBox::warning(this,
                             tr("Не выбран метод интегрирования"),
                             tr("Выберите метод интегрирования, только затем можно будет выгрузить точки первообразной."));
    }

    fout.close();
}


void MainWindow::select_method() {
    ui->primitive_graph->clearGraphs();
    draw_primitive_graph();
}


void MainWindow::on_gen_dots_but_clicked()
{
    if (!ui->function->text().size() || !ui->begin->text().size() || !ui->end->text().size() || !ui->dist->text().size()) {
        QMessageBox::warning(this, tr("Внимание"), tr("Для построения графика функции должны быть заполнены все поля!"));
        return;
    }

    std::string func = ui->function->text().toStdString();
    rpn_func = rpn::convert_to_rpn(func);

    std::string str_x_begin = ui->begin->text().toStdString();
    x_begin = rpn::evaluate_rpn(rpn::convert_to_rpn(str_x_begin), 0.0);

    std::string str_x_end = ui->end->text().toStdString();
    double x_end= rpn::evaluate_rpn(rpn::convert_to_rpn(str_x_end), 0.0);

    if (x_end <= x_begin) {
        QMessageBox::warning(this, tr("Внимание"), tr("Значение в начальной точке построения должно быть меньше, чем в конечной!"));
        return;
    }

    d = stod(ui->dist->text().toStdString());

    inp_x.clear();
    inp_y.clear();
    N = 0;
    for (int i = 0; x_begin + i*d <= x_end; i++) {
        double cur_val = rpn::evaluate_rpn(rpn_func, (double) x_begin + i*d);
        if (inp_y.size() > 0 && abs(inp_y.last() - cur_val) > pow(10, 12))
            continue;
        else
            inp_y.push_back(cur_val);

        inp_x.push_back(x_begin + i*d);
        N++;
    }

    process_dots();
}


void MainWindow::on_gen_dots_but_2_clicked()
{
    string op_file = filesystem::current_path().string() + "\\func_dots.txt";
    QString out_file_path = QFileDialog::getSaveFileName(this,
                                                         QString::fromStdString("Сохранить точки исходной функции"),
                                                         QString::fromStdString(op_file).toLocal8Bit());
    if (out_file_path.isEmpty())
        return;

    ofstream fout(out_file_path.toLocal8Bit());
    if (!fout) {
        QMessageBox::warning(this, tr("Ошибка при создании файла"), tr("Невозможно создать файл"));
        return;
    }

    fout << N << "\n" << d << "\n" << x_begin << "\n";
    for (int i = 0; i < inp_y.size(); i++) {
        fout << inp_y[i] << " ";
    }

    fout.close();
}


void MainWindow::on_scale_source_clicked()
{
    ui->source_graph->xAxis->setRange(-8, 8);
    ui->source_graph->yAxis->setRange(-8, 8);
    ui->source_graph->replot();
}


void MainWindow::on_scale_primitive_clicked()
{
    ui->primitive_graph->xAxis->setRange(-8, 8);
    ui->primitive_graph->yAxis->setRange(-8, 8);
    ui->primitive_graph->replot();
}

