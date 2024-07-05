#pragma once

namespace test {
    // long getElapsedTime(bool, bool);
    long *testSort(void (*function)(float*, int), int, int);
    long *testSortSpecific(void (function)(float*, int), int, int);
}