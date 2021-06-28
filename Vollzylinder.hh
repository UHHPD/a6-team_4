#ifndef VOLLZYLINDER_HH
#define VOLLZYLINDER_HH

#include "Vektor.hh"
#include "Koerper.hh"
#include <iostream>

class Vollzylinder : public Koerper{
public: 
  Vollzylinder() : Koerper(){}
  Vollzylinder(double nr, double nl);

  Vektor punkt();
  std::string name(){
    return "Vollzylinder";
  }
private:
  double r_, l_;
};

#endif
