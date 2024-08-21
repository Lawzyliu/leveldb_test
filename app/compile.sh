#!/bin/bash
g++ -o main main.cc ../build/libleveldb.a -I../include -lpthread /lib/libisal.a
g++ -o demo demo.cc ../build/libleveldb.a -I../include -lpthread /lib/libisal.a
g++ -o demo_new demo_new.cc ../build/libleveldb.a -I../include -lpthread /lib/libisal.a
