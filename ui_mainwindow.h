/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QSplitter *splitter_3;
    QLabel *label_5;
    QLineEdit *dist;
    QPushButton *gen_dots_but;
    QSplitter *splitter_1;
    QLabel *label_2;
    QLineEdit *function;
    QSplitter *splitter_2;
    QLabel *label_3;
    QLineEdit *begin;
    QLabel *label_4;
    QLineEdit *end;
    QPushButton *upload_dots;
    QLabel *label_9;
    QLabel *path_to_file;
    QLabel *left_rec_val;
    QLabel *right_rec_val;
    QLabel *avg_rec_val;
    QLabel *trap_val;
    QLabel *simpson_val;
    QPushButton *download_primitive_dots;
    QRadioButton *avg_rec_but;
    QRadioButton *right_rec_but;
    QRadioButton *left_rec_but;
    QRadioButton *trap_but;
    QRadioButton *simpson_but;
    QCustomPlot *source_graph;
    QCustomPlot *primitive_graph;
    QPushButton *download_source_dots;
    QLabel *label_6;
    QLabel *label_7;
    QCustomPlot *deriv_source_graph;
    QLabel *label_8;
    QCustomPlot *deriv_primitive_graph;
    QLabel *label_10;
    QPushButton *scale_source_but;
    QPushButton *scale_primitive_but;
    QPushButton *scale_deriv_primit_but;
    QPushButton *scale_deriv_source_but;
    QLabel *label_11;
    QPushButton *download_deriv_dots;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_12;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(950, 685);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 181, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(10);
        font1.setBold(true);
        label->setFont(font1);
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setGeometry(QRect(10, 100, 291, 22));
        splitter_3->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_3);
        label_5->setObjectName("label_5");
        splitter_3->addWidget(label_5);
        dist = new QLineEdit(splitter_3);
        dist->setObjectName("dist");
        dist->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-bottom: 1px solid #ef3124;"));
        dist->setFrame(false);
        splitter_3->addWidget(dist);
        gen_dots_but = new QPushButton(centralwidget);
        gen_dots_but->setObjectName("gen_dots_but");
        gen_dots_but->setGeometry(QRect(10, 130, 291, 29));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("13")});
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        gen_dots_but->setFont(font2);
        gen_dots_but->setCursor(QCursor(Qt::PointingHandCursor));
        gen_dots_but->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #ef3124;\n"
"color: #ffffff;\n"
"border: none;\n"
"font: Roboto bold;\n"
"}\n"
"QPushButton:pressed {\n"
"	border: 1px solid #ef3124;\n"
"	color: #ef3124;\n"
"   	background-color: #ffffff;\n"
"}"));
        splitter_1 = new QSplitter(centralwidget);
        splitter_1->setObjectName("splitter_1");
        splitter_1->setGeometry(QRect(10, 40, 291, 23));
        splitter_1->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_1);
        label_2->setObjectName("label_2");
        splitter_1->addWidget(label_2);
        function = new QLineEdit(splitter_1);
        function->setObjectName("function");
        function->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-bottom: 1px solid #ef3124;"));
        function->setFrame(false);
        splitter_1->addWidget(function);
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setGeometry(QRect(10, 70, 291, 23));
        splitter_2->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName("label_3");
        splitter_2->addWidget(label_3);
        begin = new QLineEdit(splitter_2);
        begin->setObjectName("begin");
        begin->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-bottom: 1px solid #ef3124;"));
        begin->setFrame(false);
        splitter_2->addWidget(begin);
        label_4 = new QLabel(splitter_2);
        label_4->setObjectName("label_4");
        splitter_2->addWidget(label_4);
        end = new QLineEdit(splitter_2);
        end->setObjectName("end");
        end->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-bottom: 1px solid #ef3124;"));
        end->setFrame(false);
        splitter_2->addWidget(end);
        upload_dots = new QPushButton(centralwidget);
        upload_dots->setObjectName("upload_dots");
        upload_dots->setGeometry(QRect(10, 230, 131, 29));
        upload_dots->setFont(font2);
        upload_dots->setCursor(QCursor(Qt::PointingHandCursor));
        upload_dots->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #ef3124;\n"
"color: #ffffff;\n"
"border: none;\n"
"font: Roboto bold;\n"
"}\n"
"QPushButton:pressed {\n"
"	border: 1px solid #ef3124;\n"
"	color: #ef3124;\n"
"   	background-color: #ffffff;\n"
"}"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 200, 181, 20));
        label_9->setFont(font1);
        path_to_file = new QLabel(centralwidget);
        path_to_file->setObjectName("path_to_file");
        path_to_file->setGeometry(QRect(150, 237, 151, 22));
        path_to_file->setLayoutDirection(Qt::RightToLeft);
        path_to_file->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"border: none;\n"
"border-bottom: 1px solid #ef3124;"));
        path_to_file->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        left_rec_val = new QLabel(centralwidget);
        left_rec_val->setObjectName("left_rec_val");
        left_rec_val->setGeometry(QRect(210, 333, 91, 23));
        right_rec_val = new QLabel(centralwidget);
        right_rec_val->setObjectName("right_rec_val");
        right_rec_val->setGeometry(QRect(210, 303, 91, 23));
        avg_rec_val = new QLabel(centralwidget);
        avg_rec_val->setObjectName("avg_rec_val");
        avg_rec_val->setGeometry(QRect(210, 273, 91, 23));
        trap_val = new QLabel(centralwidget);
        trap_val->setObjectName("trap_val");
        trap_val->setGeometry(QRect(210, 363, 91, 23));
        simpson_val = new QLabel(centralwidget);
        simpson_val->setObjectName("simpson_val");
        simpson_val->setGeometry(QRect(210, 393, 91, 23));
        download_primitive_dots = new QPushButton(centralwidget);
        download_primitive_dots->setObjectName("download_primitive_dots");
        download_primitive_dots->setGeometry(QRect(10, 526, 141, 29));
        download_primitive_dots->setFont(font2);
        download_primitive_dots->setCursor(QCursor(Qt::PointingHandCursor));
        download_primitive_dots->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #ef3124;\n"
"color: #ffffff;\n"
"border: none;\n"
"font: Roboto bold;\n"
"}\n"
"QPushButton:pressed {\n"
"	border: 1px solid #ef3124;\n"
"	color: #ef3124;\n"
"   	background-color: #ffffff;\n"
"}"));
        avg_rec_but = new QRadioButton(centralwidget);
        avg_rec_but->setObjectName("avg_rec_but");
        avg_rec_but->setGeometry(QRect(10, 273, 231, 26));
        avg_rec_but->setChecked(true);
        right_rec_but = new QRadioButton(centralwidget);
        right_rec_but->setObjectName("right_rec_but");
        right_rec_but->setGeometry(QRect(10, 303, 221, 26));
        left_rec_but = new QRadioButton(centralwidget);
        left_rec_but->setObjectName("left_rec_but");
        left_rec_but->setGeometry(QRect(10, 333, 211, 26));
        trap_but = new QRadioButton(centralwidget);
        trap_but->setObjectName("trap_but");
        trap_but->setGeometry(QRect(10, 363, 161, 26));
        trap_but->setChecked(false);
        simpson_but = new QRadioButton(centralwidget);
        simpson_but->setObjectName("simpson_but");
        simpson_but->setGeometry(QRect(10, 393, 161, 26));
        source_graph = new QCustomPlot(centralwidget);
        source_graph->setObjectName("source_graph");
        source_graph->setGeometry(QRect(320, 30, 300, 300));
        primitive_graph = new QCustomPlot(centralwidget);
        primitive_graph->setObjectName("primitive_graph");
        primitive_graph->setGeometry(QRect(640, 30, 300, 300));
        download_source_dots = new QPushButton(centralwidget);
        download_source_dots->setObjectName("download_source_dots");
        download_source_dots->setGeometry(QRect(10, 490, 291, 29));
        download_source_dots->setFont(font2);
        download_source_dots->setCursor(QCursor(Qt::PointingHandCursor));
        download_source_dots->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #ef3124;\n"
"color: #ffffff;\n"
"border: none;\n"
"font: Roboto bold;\n"
"}\n"
"QPushButton:pressed {\n"
"	border: 1px solid #ef3124;\n"
"	color: #ef3124;\n"
"   	background-color: #ffffff;\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(320, 10, 301, 20));
        label_6->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(640, 10, 301, 20));
        label_7->setFont(font1);
        deriv_source_graph = new QCustomPlot(centralwidget);
        deriv_source_graph->setObjectName("deriv_source_graph");
        deriv_source_graph->setGeometry(QRect(320, 370, 300, 300));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(320, 350, 301, 21));
        label_8->setFont(font1);
        deriv_primitive_graph = new QCustomPlot(centralwidget);
        deriv_primitive_graph->setObjectName("deriv_primitive_graph");
        deriv_primitive_graph->setGeometry(QRect(640, 370, 300, 300));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(640, 350, 301, 21));
        label_10->setFont(font1);
        scale_source_but = new QPushButton(centralwidget);
        scale_source_but->setObjectName("scale_source_but");
        scale_source_but->setGeometry(QRect(510, 10, 111, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("13")});
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setItalic(true);
        scale_source_but->setFont(font3);
        scale_source_but->setCursor(QCursor(Qt::PointingHandCursor));
        scale_source_but->setStyleSheet(QString::fromUtf8("color: #ef3124;\n"
"border: none;"));
        scale_primitive_but = new QPushButton(centralwidget);
        scale_primitive_but->setObjectName("scale_primitive_but");
        scale_primitive_but->setGeometry(QRect(880, 10, 61, 21));
        scale_primitive_but->setFont(font3);
        scale_primitive_but->setCursor(QCursor(Qt::PointingHandCursor));
        scale_primitive_but->setStyleSheet(QString::fromUtf8("color: #ef3124;\n"
"border: none;"));
        scale_deriv_primit_but = new QPushButton(centralwidget);
        scale_deriv_primit_but->setObjectName("scale_deriv_primit_but");
        scale_deriv_primit_but->setGeometry(QRect(880, 350, 61, 21));
        scale_deriv_primit_but->setFont(font3);
        scale_deriv_primit_but->setCursor(QCursor(Qt::PointingHandCursor));
        scale_deriv_primit_but->setStyleSheet(QString::fromUtf8("color: #ef3124;\n"
"border: none;"));
        scale_deriv_source_but = new QPushButton(centralwidget);
        scale_deriv_source_but->setObjectName("scale_deriv_source_but");
        scale_deriv_source_but->setGeometry(QRect(560, 350, 61, 21));
        scale_deriv_source_but->setFont(font3);
        scale_deriv_source_but->setCursor(QCursor(Qt::PointingHandCursor));
        scale_deriv_source_but->setStyleSheet(QString::fromUtf8("color: #ef3124;\n"
"border: none;"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 460, 241, 20));
        label_11->setFont(font1);
        download_deriv_dots = new QPushButton(centralwidget);
        download_deriv_dots->setObjectName("download_deriv_dots");
        download_deriv_dots->setGeometry(QRect(160, 526, 141, 29));
        download_deriv_dots->setFont(font2);
        download_deriv_dots->setCursor(QCursor(Qt::PointingHandCursor));
        download_deriv_dots->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: #ef3124;\n"
"color: #ffffff;\n"
"border: none;\n"
"font: Roboto bold;\n"
"}\n"
"QPushButton:pressed {\n"
"	border: 1px solid #ef3124;\n"
"	color: #ef3124;\n"
"   	background-color: #ffffff;\n"
"}"));
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 180, 291, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(10, 440, 291, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 650, 291, 20));
        label_12->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(function, begin);
        QWidget::setTabOrder(begin, end);
        QWidget::setTabOrder(end, dist);
        QWidget::setTabOrder(dist, gen_dots_but);
        QWidget::setTabOrder(gen_dots_but, download_source_dots);
        QWidget::setTabOrder(download_source_dots, upload_dots);
        QWidget::setTabOrder(upload_dots, avg_rec_but);
        QWidget::setTabOrder(avg_rec_but, right_rec_but);
        QWidget::setTabOrder(right_rec_but, left_rec_but);
        QWidget::setTabOrder(left_rec_but, trap_but);
        QWidget::setTabOrder(trap_but, simpson_but);
        QWidget::setTabOrder(simpson_but, download_primitive_dots);
        QWidget::setTabOrder(download_primitive_dots, scale_source_but);
        QWidget::setTabOrder(scale_source_but, scale_primitive_but);
        QWidget::setTabOrder(scale_primitive_but, scale_deriv_source_but);
        QWidget::setTabOrder(scale_deriv_source_but, scale_deriv_primit_but);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\220\320\273\321\214\321\204\320\260 \321\210\321\202\321\200\320\270\321\205", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\260\320\261\320\276\321\200 \321\202\320\276\321\207\320\265\320\272", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265e \320\274\320\265\320\266\320\264\321\203 \321\202\320\276\321\207\320\272\320\260\320\274\320\270", nullptr));
        dist->setInputMask(QString());
        dist->setText(QString());
        gen_dots_but->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\320\270\320\272", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\244\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));
        function->setInputMask(QString());
        function->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217 \320\276\321\202", nullptr));
        begin->setInputMask(QString());
        begin->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276", nullptr));
        end->setInputMask(QString());
        end->setText(QString());
        upload_dots->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\320\270", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \320\270\320\275\321\202\320\265\320\263\321\200\320\260\320\273", nullptr));
        path_to_file->setText(QString());
        left_rec_val->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        right_rec_val->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        avg_rec_val->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        trap_val->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        simpson_val->setText(QCoreApplication::translate("MainWindow", "0.0", nullptr));
        download_primitive_dots->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\320\276\320\276\320\261\321\200\320\260\320\267\320\275\320\260\321\217", nullptr));
        avg_rec_but->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\270\320\265 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\270", nullptr));
        right_rec_but->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\321\213\320\265 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\270", nullptr));
        left_rec_but->setText(QCoreApplication::translate("MainWindow", "\320\233\320\265\320\262\321\213\320\265 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\270", nullptr));
        trap_but->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \321\202\321\200\320\260\320\277\320\265\321\206\320\270\320\271", nullptr));
        simpson_but->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\241\320\270\320\274\320\277\321\201\320\276\320\275\320\260", nullptr));
        download_source_dots->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\320\270 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\321\205\320\276\320\264\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\262\320\276\320\276\320\261\321\200\320\260\320\267\320\275\320\260\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\260\321\217 \320\270\321\201\321\205\320\276\320\264\320\275\320\276\320\271 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\260\321\217 \320\277\320\265\321\200\320\262\320\276\320\276\320\261\321\200\320\260\320\267\320\275\320\276\320\271", nullptr));
        scale_source_but->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\274\320\260\321\201\321\210\321\202\320\260\320\261", nullptr));
        scale_primitive_but->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        scale_deriv_primit_but->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        scale_deriv_source_but->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\264\320\260\320\275\320\275\321\213\321\205 (\321\202\320\276\321\207\320\265\320\272)", nullptr));
        download_deriv_dots->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\320\260\321\217", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Alpha-Beta-Gama tech", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
