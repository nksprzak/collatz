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

#include "Collatz.h"

using namespace std;

int lazy[10000] = {0};
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
            if(buf <= 10000 && x < 10000) lazy[buf] = count;
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
