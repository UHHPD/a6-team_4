#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>

double traegheit(Koerper* k, Vektor a, Vektor u){
  double J = 0;
  double m = k->M / k->N;

  std::cout << "Berechene fuer " << k -> name() << ": ";

  for (int i = 0; i < k->N; ++i) {
    Vektor x = k->punkt();
    Vektor n = ((x-a).kreuz(u));
    double r = (n.betrag()/u.betrag()); 
    J += m * r * r;
  }
  return J;
}

int main() {
  const double ZM_R = 1.0; // Radius der Zylindermantels
  const double ZM_L = 1.0; // Laenge des Zylindermantels

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachse
  std::cout << "Richtung:";
  std::cin >> u;

  std::unique_ptr <Koerper> k1(new Zylindermantel(ZM_R ,ZM_L));
   std::cout << traegheit(k1.get(), a, u) << std::endl;
  
  std::unique_ptr <Koerper> k2(new Vollzylinder(ZM_R ,ZM_L));
  std::cout << traegheit(k2.get(), a, u) << std::endl;
  return 0;
}
