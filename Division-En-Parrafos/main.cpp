// O(n)
#include <bits/stdc++.h>
using namespace std;
void getLengthOfWordArr(string *wordArr, int *lengthOfWordArr, int n) {
  for(int i = 0; i < n; ++i) {
    lengthOfWordArr[i] = wordArr[i].length();
  }
}
template <class T>
void print_array(T *arr, int n) {
  for(int i = 0; i < n; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main(int argc, char const *argv[]) {
  string wordArr[] = { "hola", "como", "te", "encuentras", "el", "dia", "de", "hoy" };
  int n = sizeof(wordArr) / sizeof(wordArr[0]);
  int *lengthOfWordArr = new int[n];
  getLengthOfWordArr(wordArr, lengthOfWordArr, n);

  cout << "\nWords: " << endl;
  print_array(wordArr, n);
  cout << "\nLength of Words: " << endl;
  print_array(lengthOfWordArr, n);

  int lengthOfLine = 20;
  // the ideal whitespace can't equal zero because it will join the words together
  int whitespaceIdealAmplitude = 5; // in millimeters


  // std::vector<string> words (wordArr, wordArr + sizeof(wordArr) / sizeof(string) );
  delete[] lengthOfWordArr;
  return 0;
}

/*
LA DIVISIÓN EN PÁRRAFOS
Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se
desea agruparlas en líneas de longitud L. Las palabras están separadas por espacios
cuya amplitud ideal (en milímetros) es b, pero los espacios pueden reducirse o
ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que
una línea pi, pi+1, ..., pj tenga exactamente longitud L. Sin embargo, existe una
penalización por reducción o ampliación en el número total de espacios que aparecen
o desaparecen. El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|,
siendo b’ el ancho real de los espacios, es decir
(L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n (la última palabra)
el costo será cero a menos que b’ < b (ya que no es necesario ampliar la última
línea).

Diseñe un algoritmo para resolver el problema.

THE DIVISION IN PARAGRAPHS
Given a sequence of words p1, p2, ..., pn of lengths l1, l2, ..., ln
you want to group them into lines of length L. The words are separated by spaces
whose ideal amplitude (in millimeters) is b, but the spaces can be reduced or
be enlarged if necessary (but not overlapping words), so that
a line pi, pi + 1, ..., pj has exactly the length L. However, there is a
penalty for reduction or expansion in the total number of spaces that appear
or disappear. The cost of fixing the line
pi, pi + 1, ..., pj is (j - i) | b '- b |,
being b 'the real width of the spaces, that is to say
(L-li-li + 1 - ... - lj) / (j - i). However, if j = n (the last word)
the cost will be zero unless b '<b (since it is not necessary to extend the last
line).

Design an algorithm to solve the problem.
*/
