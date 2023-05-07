#ifndef SORTS_H
#define SORTS_H

#include <vector>
using namespace std;

void bubble_sort(vector<int> &v);

void selection_sort(vector<int> &v);

void insertion_sort(vector<int> &v);

void heapsort(vector<int> &v);

void quick_sort(vector<int> &v);

void count_sort(vector<int> &v, int max);

void radix_sort(vector<int> &v, int max);

void merge_sort(vector<int> &v);  // <- first priority

void bucket_sort(vector<int> &v);

void tree_sort(vector<int> &v);


int binary_search(vector<int> &v, int target);

int lower_bound(vector<int> &v, int target);

int upper_bound(vector<int> &v, int target);

#endif //SORTS_H
