// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cmath>

double pown(double value, uint16_t n) {
    double res = 1.0;
    for (uint64_t i = 0; i < n; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double res = 1;
    for (uint16_t i = 1; i <= count; ++i) {
        res += calcItem(x, i);
    }
    return res;
}

double sinn(double x, uint16_t count) {
    double res = 0.0;
    for (uint16_t i = 0; i < count; i++) {
        res += (i % 2 == 0 ? 1 : -1) * calcItem(x, 2 * i + 1);
    }
    return res;
}

double cosn(double x, uint16_t count) {
    double res = 1;
    for (uint64_t i = 2; i <= count; i++) {
        res += calcItem(x, (2 * i) - 2) * pown((-1.0), i - 1);
    }
    return res;
}
