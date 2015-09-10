// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#define CACHE

int lazy[10000] = {0};

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------
int collatz_eval (int i, int j) {
    int high = 0;
    int begin = 0;
    if (i > j)
    {
        int change = j;
        j = i;
        i = change;
    }
    if( i < j/2 +1) begin = j/2 + 1;
    else begin = i;
    assert(i > 0 && j > 0);
    for(int x = begin; x <= j; x++)
    {
        int buf = x;
        int count = 1;
        while(buf!=1)
        {
        #ifdef CACHE
            if(buf < 10000 && lazy[buf] != 0)
            {
                count += lazy[buf];
                break;
            }
        #endif
            if(buf%2 == 0)
            {
                buf /= 2;
                count++;   
            } 
            else
            {
                buf = (buf >> 1) + buf + 1;
                count +=2;
            }
        }
    #ifdef CACHE
        if(buf < 10000 && x < 10000) lazy[buf] = count;
    #endif
        if(count > high) high = count;
    }
    assert(high > 0);
    return high;}
// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}


// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------


// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
