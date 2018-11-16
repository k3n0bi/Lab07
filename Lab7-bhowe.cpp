// Lab7-bhowe.cpp
// Ben Howe
// COSC 2013
// November 15, 2018

// Testing out different sorting algorithms.

// Modification of SortedDriver.cpp from Lab 6.

// tom bailey   1445  25 mar 2014
// Construct sorted sequences and call functions that
//   process the sorted sequences.

#include "RandomUtilities.h"
#include "ContainerPrinting.h"
#include "winTimer.h"//CHANGE: this to unixTimer.h if on mac/linux
#include "Lab7-bhowe.h"
#include <list>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// post: a sorted vector of listSize random doubles from
//         the range minNum to maxNum has been returned.
vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
  vector<double> theList;
  for (size_t i = 0; i < listSize; ++i)
  {
    theList.push_back(randReal(minNum, maxNum));
  }

  //Disabled sorting so my functions have something to do!
  //sort(begin(theList), end(theList));

  return theList;
}



int
main()
{
  int choice = 0; // index through sorting algorithms

  cout << "Sorting!" << endl
    << "-----------------------------" << endl << endl;
  while (choice < 6)
  {
    while (true)
    {
      // User Interface stuff so user knows which algorithm they're using.
      switch (choice)
      {
      case 0:
        cout << "stl::sort - ";
        break;
      case 1:
        cout << "bubble sort - ";
        break;
      case 2:
        cout << "insertion sort - ";
        break;
      case 3:
        cout << "selection sort - ";
        break;
      case 4:
        cout << "merge sort - ";
        break;
      case 5:
        cout << "quick sort - ";
        break;
      default:
        break;
      }

      cout << "Enter size for numbers vector (0 for next sorting algorithm): ";
      int n = 0;
      cin >> n;
      if (n <= 0)
        break;
      cout << "Enter seed for rand: ";
      unsigned int seed;
      cin >> seed;
      srand(seed);

      // Construct a sorted list of numbers
      Timer get;
      get.start();
      vector<double> numbers = getNums(n, -n, n);
      get.stop();
      cout << "Constructed in " << get() << " seconds"
        << endl;

      //if (n < 10)
        //cout << numbers << endl << endl;

      
      Timer time;
      time.start();

      // use the right algorithm.
      switch (choice)
      {
      case 0:
        sort(begin(numbers), end(numbers)); //stl::sort
        break;
      case 1:
        bubble_sort(numbers);
        break;
      case 2:
        insertion_sort(numbers);
        break;
      case 3:
        selection_sort(numbers);
        break;
      case 4:
        merge_sort(numbers, 0, numbers.size() - 1);
        break;
      case 5:
        quick_sort(numbers, 0, numbers.size() - 1);
        break;
      default:
        break;
      }

      
      time.stop();
      //cout << "result-------------" << endl;
      //cout << numbers << endl;
      cout << "sort completed in " << time() << " seconds." << endl;

    }
    choice++; // on to the next sorting function!
  }


  return 0;
}
