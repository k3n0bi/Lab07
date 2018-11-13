#ifndef LAB7_BHOWE_H
#define LAB7_BHOWE_H

#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
vector<double> bubble_sort(vector<double> & myVector)
{
	int size = myVector.size()-1;
	int end = size;
	double current = 0;
	double next = 0;
	
	while(end>0)
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

	return myVector;

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

vector<double> insertion_sort(vector<double> & myVector)
{
	return myVector;
}

vector<double> selection_sort(vector<double> & myVector)
{
	//start with first element, find the smallest element and swap it with the first
	//move to the second, rinse-repeat

	int start = 0;
	int finish = myVector.size() - 1;
	int small_pos = 0;
	double small_val = DBL_MAX; // Make sure your small number is smaller than the initialization value.
	double current = 0;
	double swap = 0;

	while (start<=finish)
	{
		current = myVector.at(start);
		//cout << "start: "<<start << endl;
		for (int i = start; i <= finish; i++)
		{
			
			if(myVector.at(i)< small_val)
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

	return myVector;

	/*
	Read description at http://rosettacode.org/wiki/Sorting_algorithms/Selection_sort
	Vieweed the visualization at: https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html
	I started with the code from my bubble sort algorithm and reworked it.
	*/
}

vector<double> merge_sort(vector<double> & myVector)
{
	return myVector;
}

vector<double> quick_sort(vector<double> & myVector)
{
	return myVector;
}
#endif
