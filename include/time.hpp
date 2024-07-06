#pragma once

namespace time {
    // long getElapsedTime(bool, bool);
    long *generic(void (*function)(float*, int), int, int);
    long *testSortSpecific(void (function)(float*, int), int, int);
}