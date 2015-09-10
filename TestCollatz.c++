// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(CollatzFixture, read) {
    string s("1 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(10, 1);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(492, 1589);
    ASSERT_EQ(182, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

/*
% ls -al /usr/include/gtest/
...
gtest.h
...



% locate libgtest.a
/usr/lib/libgtest.a
...



% locate libpthread.a
...
/usr/lib32/libpthread.a



% locate libgtest_main.a
/usr/lib/libgtest_main.a
...



% g++-4.8 -pedantic -std=c++11 -Wall -fprofile-arcs -ftest-coverage Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -pthread

% valgrind ./TestCollatz
==20589== Memcheck, a memory error detector
==20589== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==20589== Using Valgrind-3.10.0.SVN and LibVEX; rerun with -h for copyright info
==20589== Command: ./TestCollatz
==20589==
Running main() from gtest_main.cc
[==========] Running 10 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 10 tests from CollatzFixture
[ RUN      ] CollatzFixture.read
[       OK ] CollatzFixture.read (16 ms)
[ RUN      ] CollatzFixture.eval_1
[       OK ] CollatzFixture.eval_1 (3 ms)
[ RUN      ] CollatzFixture.eval_2
[       OK ] CollatzFixture.eval_2 (2 ms)
[ RUN      ] CollatzFixture.eval_3
[       OK ] CollatzFixture.eval_3 (2 ms)
[ RUN      ] CollatzFixture.eval_4
[       OK ] CollatzFixture.eval_4 (2 ms)
[ RUN      ] CollatzFixture.eval_5
[       OK ] CollatzFixture.eval_5 (2 ms)
[ RUN      ] CollatzFixture.eval_6
[       OK ] CollatzFixture.eval_6 (2 ms)
[ RUN      ] CollatzFixture.eval_7
[       OK ] CollatzFixture.eval_7 (3 ms)
[ RUN      ] CollatzFixture.print
[       OK ] CollatzFixture.print (6 ms)
[ RUN      ] CollatzFixture.solve
[       OK ] CollatzFixture.solve (8 ms)
[----------] 10 tests from CollatzFixture (55 ms total)

[----------] Global test environment tear-down
[==========] 10 tests from 1 test case ran. (82 ms total)
[  PASSED  ] 10 tests.
==20589==
==20589== HEAP SUMMARY:
==20589==     in use at exit: 0 bytes in 0 blocks
==20589==   total heap usage: 373 allocs, 373 frees, 60,949 bytes allocated
==20589==
==20589== All heap blocks were freed -- no leaks are possible
==20589==
==20589== For counts of detected and suppressed errors, rerun with: -v
==20589== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


% gcov -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"     >> TestCollatz.out



% gcov -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'" >> TestCollatz.out



% cat TestCollatz.out
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
*/
