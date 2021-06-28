#ifndef KOERPER_HH
#define KOERPER_HH

#include "Vektor.hh"
#include <iostream>

class Koerper {
  public:
    Koerper(){}
    const double M = 2.0;
    const int N = 10000;
    virtual Vektor punkt() = 0; 
    virtual std::string name() { return "Koerper";};
};
#endif