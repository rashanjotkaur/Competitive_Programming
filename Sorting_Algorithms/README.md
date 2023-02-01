# Sorting Algorithms

https://www.fullstack.cafe/blog/sorting-algorithms-interview-questions

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

#### 7a. How does Insertion Sort works?
         - Insertion Sort is an in-place, stable, comparison-based sorting algorithm. 
         - Insert an element from unsorted array to its correct position in sorted array.
         - The idea is to maintain a sub-list which is always sorted. 
         - An element which is to be 'inserted' in this sorted sub-list, has to find its appropriate place and then it has to be inserted there. 
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
        
#### 7b. Why is insertion sort called online sort or online algorithm?
        - Insertion sort, by contrast, is online because it does not need to know anything about what values it will sort and the information is requested 
          WHILE the algorithm is running. Simply put, it can grab new values at every iteration.

### Important
####    What does it mean for a sorting algorithm to be online?
        - An online sorting algorithm is one that will work if the elements to be sorted are provided one at a time with the understanding 
          that the algorithm must keep the sequence sorted as more and more elements are added in.

####    What is online vs offline algorithm?
        - An offline algorithm knows all about its input data the moment it is invoked. 
        - An online algorithm, on the other hand, can get parts or all of its input data while it is running.

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
               
#### 9. How does merge sort works? 
        1. Merge sort is one of the most efficient sorting algorithms. 
        2. It works on the principle of Divide and Conquer. 
        3. Merge sort repeatedly breaks down a list into several sublists until each sublist consists of a single element and 
           merging those sublists in a manner that results into a sorted list.
           
#### 10. Which sort algorithm works best on mostly sorted data?
        1. Only a few items: Insertion Sort
        2. Items are mostly sorted already: Insertion Sort
        3. Concerned about worst-case scenarios: Heap Sort
        4. Interested in a good average-case result: Quick Sort
        5. Items are drawn from a dense universe: Bucket Sort
        6. Desire to write as little code as possible: Insertion Sort
        
#### 11. When is Quicksort better than Mergesort?
        1. They're both O(n log n) and yet most people use Quicksort instead of Mergesort. Why is that?
        2. Quicksort has O(n2) worst-case runtime and O(n log n) average case runtime. 
        3. However, it’s superior to merge sort in many scenarios because many factors influence an algorithm’s runtime, and, when 
           taking them all together, quicksort wins out.
        4. Quicksort in particular requires little additional space (it's in-place and MergeSort requires extra memory linear to number of elements to be sorted)           5. It exhibits good cache locality (does half as many reads as the other algorithms), and this makes it faster than merge sort in many cases. 
        6. In addition, it’s very easy to avoid quicksort’s worst-case run time of O(n2) almost entirely by using an appropriate choice 
           of the pivot – such as picking it at random (this is an excellent strategy).
        7. The average case performance for quicksort is faster than mergesort. 
        8. But this is only true if you are assuming constant time to access any piece of memory on demand. In RAM this assumption is generally 
           not too bad (it is not always true because of caches, but it is not too bad). However if your data structure is big enough to live on 
           disk, then quicksort gets killed by the fact that your average disk does something like 200 random seeks per second.
        9. If data has to be sorted on disk, you really, really want to use some variation of mergesort.


#### 12. Why isn't heapsort stable?
         - Heapsort is not stable because operations on the heap can change the relative order of equal items. 
         - Consider array 21 20a 20b 12 11 8
               - Here 20a = 20b just to differentiate the order we represent them as 20a and 20b.
               - While heapsort first 21 is removed and placed in the last index then 20a is removed and placed in last but one index and 
                 20b in the last but two  index so after heap sort the array looks like.
               - After Sorting: 7 8 11 12 20b 20a 21.
               - It does not preserve the order of elements and hence can't be stable.
      

#### 13. 
