// O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> gasStationsWeShouldStopAt(int *distanceBetweenGasStation, int n, int rangeOfFuelKilometers) {
  cout << "\nCalculating the Gas Stations we should stop at......" << endl;
  vector<int> result;
  int rangeLeft = rangeOfFuelKilometers;
  for(int i = 0; i < n; ++i) {
    if( distanceBetweenGasStation[i] > rangeLeft ) {
      // std::cout << "have to stop at a gas station # " << i << '\n';
      // stop at a gas station
      // push the position of the gas station you have to stop at
      result.push_back(i);
      // refuel the tanks
      rangeLeft = rangeOfFuelKilometers;
      // continue traveling
      rangeLeft -= distanceBetweenGasStation[i];
    } else {
      // std::cout << "keep traveling" << '\n';
      // keep traveling
      rangeLeft -= distanceBetweenGasStation[i];
    }
    // cout << "rangeLeft: " << rangeLeft << endl;
  }
  return result;
}

template <class T>
void print_vector(vector<T> vec) {
  for (int i=0;i<vec.size();i++)
    std::cout << ' ' << vec[i];
  std::cout << '\n';
}

int main(int argc, char const *argv[]) {
  int distanceBetweenGasStation[] = { 10, 30, 20, 15, 10, 14, 19, 11, 40, 10, 60, 54 };
  int n = sizeof(distanceBetweenGasStation) / sizeof(distanceBetweenGasStation[0]);
  int rangeOfFuelKilometers = 80; // 1000 would be a real world value
  vector<int> result = gasStationsWeShouldStopAt(distanceBetweenGasStation, n, rangeOfFuelKilometers);
  cout << "\n You have to stop at gas stations # : (from 0-n gas stations) " << endl;
  print_vector(result);
  return 0;
}
/*
CAMIONERO CON PRISA
Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite,
con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de
carreteras que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa,
el camionero desea detenerse a abastecer gasolina el menor número de veces posible.

Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el camionero.

TRUCK DRIVER IN A HURRY
A truck driver drives from DF to Acapulco following a given route and carrying a truck that allows him,
with the full gas tank, to travel n kilometers without stopping. The truck driver has a road map that
tells you the distances between the gas stations on your route. As it is in a hurry, the truck driver wants
to stop to supply gasoline as few times as possible.

Design an efficient algorithm that determines which petrol stations the truck driver has to stop.

*/
