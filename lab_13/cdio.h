#ifndef cdio_h
#define CDIO_H

double u1(double *a, double *end);
int input(double *a, double *end);
void output(double *a, double *end);
void find_max_diff(double *a, double *end, double u, int *imax1, int except1);
void delete(double *a, double *end, int imax);
void insert(double *a, double *end, size_t p, double u2);
double max_arr(double *a, double *end);
void move_1(double *a, double *end);

#endif

