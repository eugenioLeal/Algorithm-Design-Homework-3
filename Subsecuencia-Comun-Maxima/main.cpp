// O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> commonSubsequence(int *sequence1, int n1,int * sequence2, int n2, std::vector<int> commonSubsequences, int endOfSequence);
template <class T> void print_vector(vector<T> vec);
void printCommonSubsequences(std::vector<int> commonSubsequences, int endOfSequence);

vector<int> commonSubsequence(int *sequence1, int n1,int * sequence2, int n2, std::vector<int> commonSubsequences, int endOfSequence) {
  // track and update the size of the sequences while going through the elements
  int elementsLeft1 = n1, elementsLeft2 = n2;
  // independent indexes for sequence1 and sequence2
  int i1 = 0, i2 = 0;
  // counter to track the maximum length of subsequence
  int subsequenceStreak = 0;
  // increment the index of the sequence that has the most elements
  while( i1 < n1 && i2 < n2 ) {
    // compare for a common element
    if ( sequence1[i1] == sequence2[i2])
    { // Found a match
      //cout << "found common element at: " << i1 << " and " << i2 << endl;
      // here push an element to the subsequence
      commonSubsequences.push_back(sequence1[i1]);

      // increment both indexes to try to find a larger subsequence
      i1++; i2++;
      // update the elements Left in both sequences
      elementsLeft1--; elementsLeft2--;
    }
    else if( elementsLeft1 == elementsLeft2 )
    { // both sequences hove the same elements to check but there is no match
      commonSubsequences.push_back(endOfSequence);
      // compare the values of the elements and increment the one with the lower value
      if( sequence1[i1] < sequence2[i2] ) {
        i1++;
        elementsLeft1--;
      } else {
        i2++;
        elementsLeft2--;
      }
    }
    else if( elementsLeft1 > elementsLeft2 )
    { // sequence 1 has more elements to check
      commonSubsequences.push_back(endOfSequence);
      i1++;
      elementsLeft1--;
    }
    else if( elementsLeft1 < elementsLeft2 )
    { // sequence2 has more elements to check
      commonSubsequences.push_back(endOfSequence);
      i2++;
      elementsLeft2--;
    }
  }
  return commonSubsequences;
}

template <class T>
void print_vector(vector<T> vec) {
  for (int i=0;i<vec.size();i++)
    std::cout << ' ' << vec[i];
  std::cout << '\n';
}

void printCommonSubsequences(std::vector<int> commonSubsequences, int endOfSequence) {
  for(int i = 0; i < commonSubsequences.size(); ++i) {
    if( commonSubsequences[i] == endOfSequence ) {
      cout << endl;
    } else {
      cout << commonSubsequences[i] << "  ";
    }
  }
  cout << endl;
}

int main(int argc, char const *argv[]) {
  int sequence1[] = { 1, 2, 3, 4, 8, 9, 10 , 12, 14 };
  int n1 = sizeof(sequence1) / sizeof(sequence1[0]);
  int sequence2[] = { 3, 4, 8, 11, 12, 14 };
  int n2 = sizeof(sequence2) / sizeof(sequence2[0]);
  vector <int> commonSubsequences;
  // A unique integer that cannot be an element in sequences that determines where the sequences end
  int endOfSequence = -99999999;

  // Expected subsequences (not necesarry, just a visual candy)
  // { 3 } { 4 } { 8 } { 3 4 } { 3 4 8 } { 12 } { 14 } { 12 14 }
  // Expected max subsequence
  // { 3 4 8 }
  // determine the subsequence with maximum length

  // We will try to find a common element between the 2 sequences with the minimum index number of each respective array
  commonSubsequences = commonSubsequence(sequence1, n1, sequence2, n2, commonSubsequences, endOfSequence);

  // Print the sequences to determine the determine the maximum length common subsequence
  printCommonSubsequences(commonSubsequences, endOfSequence);


  return 0;
}

/*
LA SUBSECUENCIA COMÚN MÁXIMA

Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una
subsecuencia de X (siendo k ≤ m) si existe una secuencia creciente {i1 i2 ... ik}
de índices de X tales que para todo j = 1, 2, ..., k tenemos xij = zj.

Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es
subsecuencia de X y subsecuencia de Y.

Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima común
a dos secuencias.

THE MAXIMUM COMMON SUBSEQUENCE

Given a sequence X = {x1 x2 ... xm}, it is said that Z = {z1 z2 ... zk} is a
subsequence of X (where k ≤ m) if there is a growing sequence {i1 i2 ... ik}
of indices of X such that for all j = 1, 2, ..., k we have xij = zj.

Given two sequences X and Y, it is said that Z is a common subsequence of X and Y if it is
subsequence of X and subsequence of Y.

Design an algorithm to determine the maximum length common subsequence
to two sequences.
*/
