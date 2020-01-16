// Elhadj Diallo
//CSS342 UWB
//Assignment5
/*This program  is design to sort efficiently a huge data readed from a file and output it in different format based on the
 * user input on the commande line. It also print out the statistic of ho much each sorted function has to access the function
 * from a data structure ArrayList that is implemented and ouput. It output the sorted value with the statistic along if -d is selected.
 * only the statistic if two argument or it says the length must be in the rage 2-3.*/

///////////////////////////////////////////////////////
//  Main test driver.
//////////////////////////////////////////////////////
#include <cstdio>
#include <stdexcept>
#include <string>
#include "ArrayList.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>


template<class Type>
void insertionSort(ArrayList<Type> &theArray, int arrayLength);

//Quick sort function
template<class Type>
void quickSort(ArrayList<Type> &arr, int startIndex, int HighestIndex);

template<class Type>
int partition(ArrayList<Type> &arr, int lowIndex, int HighestIndex);

//merge methods
template<class Type>
void merge(ArrayList<Type> &theArray, int, int, int);

//merge the sorted arrays
template<class Type>
void merge_sort(ArrayList<Type> &arr, int lowIndex, int highIndex);

//print array function
template<class Type>
void printArray(ArrayList<Type> &arr);
int main(int argc, char *argv[]) {

    //command line -d
    if (argc == 3 && string(argv[1]) == "-d") {
        ArrayList<int> OriginalArray;
        int num;
        ifstream fin;
        fin.open("dataSmall.txt");
        while (fin >> num) {
            OriginalArray.append(num);
        }
        fin.close();

        //duplicate the original arrayList to three different arrayList
        ArrayList<int> InsertionTest(OriginalArray);
        ArrayList<int> Merge_sort(OriginalArray);
        ArrayList<int> Quick_Sort(OriginalArray);

        OriginalArray.clearStatistics();
        //storing the data to a vector to print outside later.
        vector<int> storeStatistics;
        insertionSort(InsertionTest, InsertionTest.getSize());
        //save the first value
        storeStatistics.push_back(InsertionTest.getNumAccess());
        storeStatistics.push_back(InsertionTest.getNumSwap());
        storeStatistics.push_back(InsertionTest.getNumRemove());
        storeStatistics.push_back(InsertionTest.getNumInsertAt());
        storeStatistics.push_back(InsertionTest.getNumAppends());
        // clear statistics values;
        InsertionTest.clearStatistics();
        //sort the merge function
        merge_sort(Merge_sort, 0, Merge_sort.getSize() - 1);
        //store the values of storeStatistics
        storeStatistics.push_back(Merge_sort.getNumAccess());
        storeStatistics.push_back(Merge_sort.getNumSwap());
        storeStatistics.push_back(Merge_sort.getNumRemove());
        storeStatistics.push_back(Merge_sort.getNumInsertAt());
        storeStatistics.push_back(Merge_sort.getNumAppends());
        InsertionTest.clearStatistics();
        //sort the quickSort
        quickSort(Quick_Sort, 0, Quick_Sort.getSize() - 1);
        //store the values of storeStatistics
        storeStatistics.push_back(Quick_Sort.getNumAccess());
        storeStatistics.push_back(Quick_Sort.getNumSwap());
        storeStatistics.push_back(Quick_Sort.getNumRemove());
        storeStatistics.push_back(Quick_Sort.getNumInsertAt());
        storeStatistics.push_back(Quick_Sort.getNumAppends());
        //clear statistic values
        InsertionTest.clearStatistics();

//atatistic output
        printf("\n%s %s", "Filename: ", string(argv[2]).c_str());
        printf("\n%s %d", "Number of Items: ", OriginalArray.getSize());
        //print array before sorted
        printf("\n%s", "Original ArrayList: \n");
        printArray(OriginalArray);
        //print array after sorted for each function
        printf("\n%s", "After Sorting Methods called:");
        printf("\n%s", "MergeSortResults: \n");
        printArray(Merge_sort);
        printf("\n%s", "InsertionSortResults: \n");
        printArray(InsertionTest);
        printf("\n%s", "QuickSortResult: \n");
        printArray(Quick_Sort);
        printf("\n%s %10s  %10s %10s %10s %10s ", "Number Of: ", "Access", "Swap", "Remove", "InsertAt", "Append");
        //print the InsertSort statistic
        printf("\n%s %8d %10d %10d %10d %10d", "InsertionSort", storeStatistics[0], storeStatistics[1],
               storeStatistics[2], storeStatistics[3], storeStatistics[4]);
        //print the merge sort
        printf("\n%s %11d %10d %10d %10d %10d", "MergerSort", storeStatistics[5], storeStatistics[6],
               storeStatistics[7], storeStatistics[8], storeStatistics[9]);
        //print the Quick sort statistic
        printf("\n%s %12d %10d %10d %10d %10d", "QuickSort", storeStatistics[10], storeStatistics[11],
               storeStatistics[12], storeStatistics[13], storeStatistics[14]);
    }
    else if (argc == 2 ) {
        ArrayList<int> OriginalArray;
        int num;
        ifstream fin;
        fin.open(argv[1]);
        while (fin >> num) {
            OriginalArray.append(num);
        }
        fin.close();

        //duplicate the original arrayList to three different arrayList
        ArrayList<int> InsertionTest(OriginalArray);
        ArrayList<int> Merge_sort(OriginalArray);
        ArrayList<int> Quick_Sort(OriginalArray);

        OriginalArray.clearStatistics();
        //storing the data to a vector to print outside later.
        vector<int> storeStatistics;
        insertionSort(InsertionTest, InsertionTest.getSize());
        //save the first value
        storeStatistics.push_back(InsertionTest.getNumAccess());
        storeStatistics.push_back(InsertionTest.getNumSwap());
        storeStatistics.push_back(InsertionTest.getNumRemove());
        storeStatistics.push_back(InsertionTest.getNumInsertAt());
        storeStatistics.push_back(InsertionTest.getNumAppends());
        // clear statistics values;
        InsertionTest.clearStatistics();
        //sort the merge function
        merge_sort(Merge_sort, 0, Merge_sort.getSize() - 1);
        //store the values of storeStatistics
        storeStatistics.push_back(Merge_sort.getNumAccess());
        storeStatistics.push_back(Merge_sort.getNumSwap());
        storeStatistics.push_back(Merge_sort.getNumRemove());
        storeStatistics.push_back(Merge_sort.getNumInsertAt());
        storeStatistics.push_back(Merge_sort.getNumAppends());
        InsertionTest.clearStatistics();
        //sort the quickSort
        quickSort(Quick_Sort, 0, Quick_Sort.getSize() - 1);
        //store the values of storeStatistics
        storeStatistics.push_back(Quick_Sort.getNumAccess());
        storeStatistics.push_back(Quick_Sort.getNumSwap());
        storeStatistics.push_back(Quick_Sort.getNumRemove());
        storeStatistics.push_back(Quick_Sort.getNumInsertAt());
        storeStatistics.push_back(Quick_Sort.getNumAppends());
        //clear statistic values
        InsertionTest.clearStatistics();

        //  if -d not selected
        printf("\n%s %s", "Filename: ", string(argv[1]).c_str());
        printf("\n%s %d", "Number of Items: ", OriginalArray.getSize());
        printf("\n%s %10s  %10s %10s %10s %10s ", "Number Of: ", "Access", "Swap", "Remove", "InsertAt", "Append");
        //print the InsertSort statistic
        printf("\n%s %8d %10d %10d %10d %10d", "InsertionSort", storeStatistics[0], storeStatistics[1],
               storeStatistics[2], storeStatistics[3], storeStatistics[4]);
        //Print the merge sroting
        printf("\n%s %11d %10d %10d %10d %10d", "MergerSort", storeStatistics[5], storeStatistics[6],
               storeStatistics[7], storeStatistics[8], storeStatistics[9]);
        //print the Quick sort statistic
        printf("\n%s %12d %10d %10d %10d %10d", "QuickSort", storeStatistics[10], storeStatistics[11],
               storeStatistics[12], storeStatistics[13], storeStatistics[14]);
        cout << endl;
    }
    else {
        cout << "argc Must be length 2 or 3 in order to display array and their statistics " << endl;
    }
    cout << endl;


    return 0;
}

//printArray function
template<class Type>
void printArray(ArrayList<Type> &arr) {
    cout << "[";
    for (int i = 0; i < arr.getSize(); i++) {
        cout << arr[i] << ",";
    }
    cout << "]"<<endl;
}


//---------------------------------------------------MERGESORT-------------------------------------------------------------------
template <class Type>
void merge(ArrayList<Type> &array, int lowestIndex, int midPoint, int highestIndex) {
    int nl = midPoint - lowestIndex + 1;
    int nr = highestIndex - midPoint;
    //tenmporairy created array that serves as sub_arrays
    ArrayList<int> first_Array(nl);
    ArrayList<int> second_Array(nr);
    int i, j, k;
    //fill left and right sub-arrays
    for(i = 0; i<nl; i++)
        first_Array.append(array[lowestIndex + i]);
    for(j = 0; j<nr; j++)
        second_Array.append(array[midPoint + 1 + j]);
    i = 0; j = 0; k = lowestIndex;
    //marge temp arrays to real array
    while(i < nl && j<nr) {
        if(first_Array[i] <= second_Array[j]) {
            array[k] = first_Array[i];
            i++;
        }else{
            array[k] = second_Array[j];
            j++;
        }
        k++;
    }
    while(i<nl) {       //extra element in left array
        array[k] = first_Array[i];
        i++; k++;
    }
    while(j<nr) {     //extra element in right array
        array[k] = second_Array[j];
        j++; k++;
    }
}

template <class Type>
void merge_sort(ArrayList<Type> &array, int l, int r) {
    int m;
    if(l < r) {
        int m = l+(r-l)/2;
        // Sort first and second arrays
        merge_sort(array, l, m);
        merge_sort(array, m+1, r);
        merge(array, l, m, r);
    }
}

//---------------------------------------------------INSERTION-SORT-------------------------------------------------------------------
//insertion sort methods

template<class Type>
void insertionSort(ArrayList<Type> &arr, int length) {
    int i, j, tmp;
    for (i = 1; i < arr.getSize(); i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            arr.swap(j, j-1);
            j--;
        }
    }
}

//---------------------------------------------------QUICK-SORT-------------------------------------------------------------------
//quick sort methods
// The main function that implements QuickSort
template<class Type>
void quickSort(ArrayList<Type> &arr, int startIndex, int HighestIndex) {
    int mid;
    if (startIndex < HighestIndex) {
        mid = partition(arr, startIndex, HighestIndex);
        quickSort(arr, startIndex, mid);
        quickSort(arr, mid + 1, HighestIndex);
    }
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot */
template<class Type>
int partition(ArrayList<Type> &arr, int startIndex, int highestIndex) {
    int pivot = arr[startIndex];
    int lowStartIndex = startIndex - 1;
    int arrayLength = highestIndex + 1;
    do {
        do {
            arrayLength--;
        } while (pivot < arr[arrayLength]);
        do {
            lowStartIndex++;
        } while (pivot > arr[lowStartIndex]);
        if (lowStartIndex < arrayLength) {
            arr.swap(lowStartIndex, arrayLength);
        }
    } while (lowStartIndex < arrayLength);
    return arrayLength;
}