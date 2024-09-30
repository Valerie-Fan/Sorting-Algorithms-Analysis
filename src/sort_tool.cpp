// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Modify     [2023/9/12 Ming-Bang Fan]
//  Modify     [2024/9/2 Meng-Chen Wu]
// **************************************************************************

#include "sort_tool.h"
#include <iostream>
#include <random>
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    for (int i = 1; i < data.size(); i++) {
	    int key =  data[i];
	    int j = i - 1;
	    while (j >= 0 && data[j] > key) {
		    data[j + 1] = data[j];
		    j--;
	    }
	    data[j + 1] = key;
    }
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data,int f){
    QuickSortSubVector(data, 0, data.size() - 1, f);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high, const int flag) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    // flag == 0 -> normal QS
    // flag == 1 -> randomized QS
    if (low < high) {
	    if (flag == 0) {
		   int middle = this->Partition(data, low, high);
		   this->QuickSortSubVector(data, low, middle - 1, flag);
		   this->QuickSortSubVector(data, middle + 1, high, flag);
	    } else {
		   int middle = this->RandomizedPartition(data, low, high);
		   this->QuickSortSubVector(data, low, middle - 1, flag);
		   this->QuickSortSubVector(data, middle + 1, high, flag);
	    }
    }
}
int SortTool::RandomizedPartition(vector<int>& data, int low, int high){
    // Function : RQS's Partition the vector 
    // TODO : Please complete the function
    // Generate a random integer (ref: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)
//    random_device rd;  // a seed source for the random number engine
//    mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
//    uniform_int_distribution<> distrib(low, high);
//    int random = distrib(gen);

//	 Method 2: Use simpler std::rand (less randomness but more efficient)
	 srand(time(NULL));  // Seed the random number generator (use once)
	 int random = low + rand() % (high - low + 1);

    #ifdef _DEBUG_ON_
    cout << "Random number: " << random << "\n";
    #endif

    // Exchange data[random] and data[high]
    int temp = data[random];
    data[random] = data[high];
    data[high] = temp;

    // Run normal partition
    return this->Partition(data, low, high);
}
int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    int key = data[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
	    if (data[j] <= key) {
		    i++;
		    // Exchange data[i] and data[j]
		    int temp = data[i];
		    data[i] = data[j];
		    data[j] = temp;
	    }
    }

    // Exchange data[i + 1] and data[high]
    data[high] = data[i + 1];
    data[i + 1] = key;
    #ifdef _DEBUG_ON_
    cout << "q: " << i + 1 << "\n";
    cout << "Data: ";
    for (int i = low; i < high; i++) {
	    cout << data[i] << " ";
    }
    cout << "\n";
    #endif
    return i + 1;
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed

    //  Base case
    if (low >= high) { return; }
    
    // Recursive case
    int middle = (low + high) / 2;
    this->MergeSortSubVector(data, low, middle);
    this->MergeSortSubVector(data, middle + 1, high);

    this->Merge(data, low, middle, middle + 1, high);
}

// Merge
// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
	// Function : Merge two sorted subvector with pre-allocated arrays
	int nL = middle1 - low + 1;
	int nR = high - middle2 + 1;

	// Pre-allocate arrays for L and R
	int* L = new int[nL];
	int* R = new int[nR];

	// Copy data[low:middle1] into L[0:nL]
	for (int i = 0; i < nL; i++) {
		L[i] = data[low + i];
	}

	// Copy data[middle2:high] into R[0:nR]
	for (int i = 0; i < nR; i++) {
		R[i] = data[middle2 + i];
	}

	// Merge L and R into data[low:high]
	int k = 0;
	int i = 0;
	int j = 0;
	while (i < nL && j < nR) {
		if (L[i] <= R[j]) {
			data[low + k] = L[i];
			i++;
		} else {
			data[low + k] = R[j];
			j++;
		}
		k++;
	}

	// Copy any remaining elements from L
	while (i < nL) {
		data[low + k] = L[i];
		i++;
		k++;
	}

	// Copy any remaining elements from R
	while (j < nR) {
		data[low + k] = R[j];
		j++;
		k++;
	}

	// Clean up the dynamically allocated arrays
	delete[] L;
	delete[] R;

#ifdef _DEBUG_ON_
	for (int i = 0; i < high - low + 1; i++) {
		cout << data[low + i] << " ";
	}
	cout << "\n";
#endif
}

// bottom-up style implementation of merge sort
void SortTool::BottomUpMergeSort(vector<int>& data)
{
	int n = data.size();
	int* merged = new int[n];  // Pre-allocate array for merging results

	int groupMem = 1;  // Start by merging groups of size 1

	while (groupMem < n) {
		int i = 0;

		while (i < n) {
			int middle = min(i + groupMem, n);
			int end = min(i + 2 * groupMem, n);

			// Merge the two groups: data[i:middle-1] and data[middle:end-1]
			int left = i, right = middle;
			int k = 0;  // Index for the merged array

			while (left < middle && right < end) {
				if (data[left] <= data[right]) {
					merged[k] = data[left];
					left++;
				} else {
					merged[k] = data[right];
					right++;
				}
				k++;
			}

			// Copy remaining elements from the left group
			while (left < middle) {
				merged[k] = data[left];
				left++;
				k++;
			}

			// Copy remaining elements from the right group
			while (right < end) {
				merged[k] = data[right];
				right++;
				k++;
			}

			// Copy merged result back to data
			for (int j = 0; j < k; j++) {
				data[i + j] = merged[j];
			}

			i += 2 * groupMem;  // Move to the next pair of groups
		}

#ifdef _DEBUG_ON_
		cout << "Data: ";
		for (int j = 0; j < n; j++) {
			cout << data[j] << " ";
		}
		cout << "\n";
#endif

		groupMem *= 2;  // Increase group size for the next iteration
	}

	delete[] merged;  // Free the pre-allocated array
}

// Heap sort method, be aware that you are NOT required to implement heap sort in PA1
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

//Max heapify
void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
}

//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
}
