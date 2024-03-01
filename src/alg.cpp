// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>

double pown(double value, uint16_t n) {
    return pow(value, n);
}

uint64_t fact(uint16_t n) {
    if (n == 1)
        return 1;
    if (n > 1)
        return fact(n - 1) * n;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double res = 1;
    for (int i = 1; i <= count; ++i) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0;
    for (uint64_t i = 1; i <= count; ++i) {
        res += pown(-1, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 0;
    for (uint64_t i = 0; i <= count; ++i) {
        res += (pown(-1, i) * pown(x, 2 * i - 1)) / fact(2 * i - 2);
    }
    return res;
}
