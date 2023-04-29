#include <QVector>
#include "derive_integrate.h"


//    integral counting
namespace integrate_methods {
    void avg_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d) {
        out_x.clear();
        out_y.clear();

        out_x.push_back(x_begin + 0);
        out_y.push_back(0);

        double result = 0.0;
        int N = inp_y.length();
        for (int i = 0; i < N; i++) {
            if ((i == 0) || (i == N - 1))
                result += (double) inp_y[i] * d/2.0;
            else
                result += (double) inp_y[i] * d;

            out_x.push_back(x_begin + (i + 1) * d);
            out_y.push_back(result);
        }
    }


    void right_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d) {
        out_x.clear();
        out_y.clear();

        out_x.push_back(x_begin + 0);
        out_y.push_back(0);

        double result = 0.0;
        for (int i = 1; i < inp_y.length(); i++) {
            result += (double) d * inp_y[i];

            out_x.push_back(x_begin + i * d);
            out_y.push_back(result);
        }
    }


    void left_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d) {
        out_x.clear();
        out_y.clear();

        out_x.push_back(x_begin + 0);
        out_y.push_back(0);

        double result = 0.0;
        for (int i = 1; i < inp_y.length(); i++) {
            result += (double) d * inp_y[i - 1];

            out_x.push_back(x_begin + i * d);
            out_y.push_back(result);
        }
    }


    void trap_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d) {
        out_x.clear();
        out_y.clear();

        out_x.push_back(x_begin + 0);
        out_y.push_back(0);

        double result = 0.0;
        for (int i = 1; i < inp_y.length(); i++) {
            result += (inp_y[i - 1] + inp_y[i]) / 2 * d;

            out_x.push_back(x_begin + i * d);
            out_y.push_back(result);
        }
    }


    void simpson_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d) {
        out_x.clear();
        out_y.clear();

        out_x.push_back(x_begin + 0);
        out_y.push_back(0);

        double result = 0.0;
        int N = inp_y.length();
        for (int i = 2; i < N; i += 2) {
            result += ((float) d / 3) * (inp_y[i - 2] + 4.0 * inp_y[i - 1] + inp_y[i]);

            out_x.push_back(x_begin + i * d);
            out_y.push_back(result);
        }

        if (N % 2 == 0) {
            result += (inp_y[N - 1] + inp_y[N - 2]) / 2 * d;

            out_x.push_back(x_begin + N*d);
            out_y.push_back(result);
        }
    }
}


//    derivative counting
namespace derivate_methods {
    void derivate(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d) {
        out_x.clear();
        out_y.clear();

//        out_x.push_back(x_begin + 0);
//        out_y.push_back(0);

        double result = 0.0;
        int N = inp_y.length();
        for (int i = 0; i < (N - 1); i++) {
            result = (inp_y[i + 1] - inp_y[i]) / d;

            out_x.push_back(x_begin + d*i);
            out_y.push_back(result);
        }
    }
}
