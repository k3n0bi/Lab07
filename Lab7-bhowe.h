// Lab7-bhowe.h
// Ben Howe
// COSC 2013
// November 15, 2018

// Testing out different sorting algorithms.

#ifndef LAB7_BHOWE_H
#define LAB7_BHOWE_H

#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
void bubble_sort(vector<double> & myVector)
{
  int size = myVector.size() - 1;
  int end = size;
  double current = 0;
  double next = 0;

  while (end > 0)
  {
    for (int i = 0; i < end; i++)
    {
      current = myVector.at(i);
      next = myVector.at(i + 1);
      if (current > next)
      {
        //swap
        myVector.at(i) = next;
        myVector.at(i + 1) = current;
      }
    }
    end--;
  }

  //return myVector;

  /*
  C++ code from rosettacode.org
  Link: http://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort

  void bubble_sort(RandomAccessIterator begin, RandomAccessIterator end) {
  bool swapped = true;
  while (begin != end-- && swapped) {
  swapped = false;
  for (auto i = begin; i != end; ++i) {
  if (*(i + 1) < *i) {
  std::iter_swap(i, i + 1);
  swapped = true;
  }
  }
  }
  }
  */

}

void insertion_sort(vector<double> & myVector)
{
  double val;
  for (int i = 1; i < myVector.size(); i++)
  {
    val = myVector.at(i);
    int j = i - 1;
    while (j >= 0 && myVector.at(j) > val)
    {
      myVector.at(j + 1) = myVector.at(j);
      j--;
    }
    myVector.at(j + 1) = val;
  }



  /*
  Pseudocode for insertion_sort from http://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort
  function insertionSort(array A)
    for i from 1 to length[A]-1 do
        value := A[i]
        j := i-1
        while j >= 0 and A[j] > value do
            A[j+1] := A[j]
            j := j-1
        done
        A[j+1] = value
    done
  */
}

void selection_sort(vector<double> & myVector)
{
  //start with first element, find the smallest element and swap it with the first
  //move to the second, rinse-repeat

  int start = 0;
  int finish = myVector.size() - 1;
  int small_pos = 0;
  double small_val = DBL_MAX; // Make sure your small number is smaller than the initialization value.
  double current = 0;
  double swap = 0;

  while (start <= finish)
  {
    current = myVector.at(start);
    //cout << "start: "<<start << endl;
    for (int i = start; i <= finish; i++)
    {

      if (myVector.at(i) < small_val)
      {
        small_pos = i;
        small_val = myVector.at(i);
      }

    }
    if (current > small_val)
    {
      //swap
      myVector.at(start) = small_val;
      myVector.at(small_pos) = current;
    }
    start++;
    small_val = DBL_MAX;
    small_pos = 0;

  }

  /*
  I read the description at http://rosettacode.org/wiki/Sorting_algorithms/Selection_sort
  I vieweed the visualization at: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html
  Finally, I started with the code from my bubble sort algorithm and reworked it.
  */
}

/* merge_sort sort-------------------------------------------------
code taken from: https://www.includehelp.com/cpp-tutorial/merge-sort-with-example.aspx
slightly modified from int array to double vector.
name changed to merge_sort for consistency sake.
*/

void Merge(vector<double> & A, int p, int q, int r)     /*It merges two arrays */
{

  int n1 = q - p + 1, i, j, k;       /*n1 is the size of L[]*/

  int n2 = r - q;               /*n2 is the sixe of R[]*/

  //int L[n1], R[n2];
  vector<double> L;
  vector<double> R;
  
  for (i = 0; i < n1; i++)

  {
    //L[i] = A[p + i];
    L.push_back(A[p + i]); //modified to accomodate vector
  }

  for (j = 0; j < n2; j++)
  {
    //R[j] = A[q + j + 1];
    R.push_back(A[q + j + 1]); //modified to accomodate vector
  }

  i = 0, j = 0;

  for (k = p; i < n1&&j < n2; k++)
  {
    if (L[i] < R[j])
    {
      A[k] = L[i++];
    }
    else
    {
      A[k] = R[j++];
    }
  }

  while (i < n1)             /*If L[] has more elements than R[] then it will put all the reamining elements of L[] into A[]*/
  {
    A[k++] = L[i++];
  }

  while (j < n2)             /*If R[] has more elements than L[] then it will put all the reamining elements of R[] into A[]*/
  {
    A[k++] = R[j++];
  }
}

void merge_sort(vector<double> & A, int p, int r)    /*It will will divide the array and sort them while merging them*/
{
  int q;

  if (p < r)
  {
    q = (p + r) / 2;                      /*q is the middle element to divide the array*/
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    Merge(A, p, q, r);
  }

}


/* quick sort-------------------------------------------------
code taken from: https://www.includehelp.com/cpp-tutorial/quick-sort-with-algorithm-example.aspx
slightly modified from int array to double vector
name changed to quick_sort for consistency sake.
I tried several other sources, but for some reason none would work, so I settled on this one.
*/

//int partition(int, int, int);
int partition(vector<double> & a, int s, int e)
{
  double pivot = a[e];
  int pind = s;
  int i;
  double t;
  for (i = s; i < e; i++)
  {
    if (a[i] <= pivot)
    {
      t = a[i];
      a[i] = a[pind];
      a[pind] = t;
      pind++;
    }
  }

  t = a[e];
  a[e] = a[pind];
  a[pind] = t;
  return pind;
}
void quick_sort(vector<double> & a, int s, int e)
{
  if (s < e)
  {
    int pind = partition(a, s, e);
    quick_sort(a, s, pind - 1);
    quick_sort(a, pind + 1, e);
  }
}

#endif
