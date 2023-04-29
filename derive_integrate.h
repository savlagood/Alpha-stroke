#ifndef DERIVE_INTEGRATE_H
#define DERIVE_INTEGRATE_H


namespace integrate_methods {
    void avg_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d);
    void right_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d);
    void left_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d);
    void trap_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d);
    void simpson_rec_method(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d);
}


namespace derivate_methods {
    void derivate(QVector<double> inp_y, QVector<double> &out_x, QVector<double> &out_y, double x_begin, double d);
}

#endif // DERIVE_INTEGRATE_H
