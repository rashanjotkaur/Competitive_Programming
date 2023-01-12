## Priority Queue Notes

### Links
    https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

#### 1. What is Priority Queue in C++ Standard Template Library (STL)?
        a) A C++ priority queue is a type of container, specifically designed such that the first element of the queue is either the greatest or the smallest of 
           all elements in the queue, and elements are in non-increasing or non-decreasing order (hence we can see that each element of the queue has a priority 
           {fixed order}).
        b) In C++ STL, the top element is always the greatest by default. We can also change it to the smallest element at the top. 
        c) **Priority queues are built on the top of the max heap and use an array or vector as an internal structure. 
        d) In simple terms, STL Priority Queue is the implementation of Heap Data Structure.
        
#### 2. Max Heap for Priority Queue
        priority_queue <int> pq;
        Input: 10 2 4 8 6 9  
        Output: 10 9 8 6 4 2 
        
### Important: 
    A priority queue is implemented as MAX heap by default in C++ but, it also provides us an option to change it to MIN heap by passing another parameter 
    while creating a priority queue.
    
#### 3. Max Heap for Priority Queue
        priority_queue <int, vector <int>, greater<int>> pq;
        Input: 10 2 4 8 6 9  
        Output: 2 4 6 8 9 10
