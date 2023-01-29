### Heap Notes

### Helpful Links:
    1. https://www.hackerearth.com/practice/notes/heaps-and-priority-queues/#:~:text=It%20will%20take%20O(log,queue%20and%20min%20-%20priority%20queue.
    2. https://www.geeksforgeeks.org/heap-data-structure/
    

#### 1. What is Heap? - Book Page 550
        - A Heap is a tree with some special properties.
        - A Heap is a special Tree-based data structure in which the tree is a complete binary tree i.e. all leaf nodes must be at h or h-1 level.
        - Heap Propery: root->val>childern or root->val<childern throughout the heap. 
        
#### 2. Types of Heap:
        Based on the heap property,heaps are classified into two categories:
          - Min Heap
          - Max Heap
          
#### 3. Representing Heaps:
        - Heaps are represented using arrays. Since, heaps are complete binary trees. So, there will not be any wastage of locations.
        
#### 4. 0-Based Indexing:
        Parent: (i-1)/2
        Left Child: 2*i+1
        Right Child: 2*i+2
        
#### 5. Operations of Heap Data Structure:
        - Heapify: 
              A process of creating a heap from an array.
        - Insertion: 
              A process to insert an element in existing heap time complexity O(log N).
        - Deletion: 
              Deleting the top element of the heap or the highest priority element, and then organizing the heap and returning the element with time complexity O(log N).
        - Peek: 
              To check or find the most prior element in the heap, (max or min element for max and min heap)      
              
              
