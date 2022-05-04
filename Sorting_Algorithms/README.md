# Sorting Algorithms

#### 1. What are Sorting Algorithms?
        Sorting Algorithms are methods of reorganizing a large number of items into some specific order such as highest to lowest, or vice-versa, 
        or even in some alphabetical order.

#### 2. What are the types of Sorting Algorithms?
        Types of Sorting Algorithms:
            Selection Sort
            Bubble Sort
            Insertion Sort
            Quick Sort  
            Merge Sort 
            Heap Sort
            Radix Sort
            Bucket Sort
            
#### 3. How does Selection Sort works?
        1. Selection sort works by taking the smallest element in an unsorted array and bringing it to the front. 
        2. You’ll go through each item (from left to right) until you find the smallest one. The first item in the array is now sorted, 
           while the rest of the array is unsorted.
        3. The selection sort algorithm is a simple, yet effective sorting algorithm. 
        4. A selection-based sorting algorithm is described as an in-place comparison-based algorithm that divides the list into two parts, 
           the sorted part on the left and the unsorted part on the right. Initially, the sorted section is empty, and the unsorted section 
           contains the entire list. 
        5. When sorting a small list, selection sort can be used. 
        6. In the selection sort, the cost of swapping is irrelevant, and all elements must be checked. 
        7. The cost of writing to memory matters in selection sort, just as it does in flash memory (the number of writes/swaps is O(n) 
           as opposed to O(n2) in bubble sort).
        8. Selection Sort is unstable, in-place sorting algorithm.
           
#### 4. Applications of Selection Sort?
        The following are some applications of how to use selection sort: 
        1. When memory writing is a costly operation, this can be useful.
        2. In terms of the number of writes ((n) swaps versus O(n2) swaps), selection sort is preferable to insertion sort.
        3. Since, Selections Sort never makes more than O(n) swaps and can be useful when memory write is costly operation.
           For e.g. If writes are significantly more expensive than reads, as with EEPROM or Flash memory, where each write reduces the memory's lifespan.
           
#### 5. How does Bubble Sort works?
        1. Bubble Sort is based on the idea of repeatedly comparing pairs of adjacent elements and then swapping their positions 
           if they are in the wrong order. 
        2. Bubble sort is a stable, in-place sort algorithm.
        3. Steps:
              In an unsorted array of n elements, start with the first two elements and sort them in ascending order. 
              (Compare the element to check which one is greater).
              Compare the second and third element to check which one is greater, and sort them in ascending order.
              Compare the third and fourth element to check which one is greater, and sort them in ascending order.
              ...
              Repeat steps 1–n until no more swaps are required.
         4. Bubble Sort takes minimum time when elements are already sorted.
  
#### 6. What are advantages and disadvantages of Bubble Sort?
        Advantages:
            1. Simple to understand.
            2. Ability to detect that the list is sorted efficiently is built into the algorithm. When the list is already sorted (best-case), 
               the complexity of bubble sort is only O(n).
        Disadvantages:
            1. It is very slow and runs in O(n2) time in worst as well as average case. Because of that Bubble sort does not deal well 
               with a large set of data. For example, Bubble sort is three times slower than Quicksort even for n = 100.

#### 7. How does Insertion Sort works?
        1. Insertion Sort is an in-place, stable, comparison-based sorting algorithm. 
        2. The idea is to maintain a sub-list which is always sorted. 
        3. An element which is to be 'insert'ed in this sorted sub-list, has to find its appropriate place and then it has to be inserted there. 
           Hence the name, insertion sort.
        4. Steps:
              If it is the first element, it is already sorted.
              Pick the next element.
              Compare with all the elements in sorted sub-list.
              Shift all the the elements in sorted sub-list that is greater than the value to be sorted.
              Insert the value.
              Repeat until list is sorted.
        5. Here, shifting of greater elements is done.
        6. Insertion sort runs in O(n2) in its worst and average cases. It runs in O(n) time in its best case.
        7. Space complexity is O(1) because an extra variable key is used (as a temp variable for insertion).
        
#### 8. How does Quick Sort works?
        1. Quick Sort is capable of sorting a list of data elements significantly faster (twice or thrice faster) than any of the common sorting algorithms. 
        2. It is one of the most efficient sorting algorithms.
        3. It is based on the splitting of an array (partition) into smaller ones and swapping (exchange) based on the comparison with 'pivot' 
           element selected. 
        4. Due to this, quick sort is also called as "Partition Exchange" sort. 
        5. Like Merge sort, Quick sort also falls into the category of divide and conquer approach of problem-solving methodology.
        6. Steps:
               1. It picks an element as pivot and partitions the given array around the picked pivot. 
               2. There are many different versions of quickSort that pick pivot in different ways. 
                      Always pick first element as pivot.
                      Always pick last element as pivot (implemented below)
                      Pick a random element as pivot.
                      Pick median as pivot.
               


      
