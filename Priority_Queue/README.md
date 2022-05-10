# Priority Queues

#### 1. MinHeap Priority Queue - Smallest Element is at TOP
        priority_queue <int, vector <int>, greater <int> > pq;
        
        
#### 2. MaxHeap Priority Queue - Largest Element is at TOP
        priority_queue <int> pq;
        
#### 3. Max Happiness Question
        Thomas has R units of Money and goes to a bakery to have some pastries. Every pastry costs him 1 unit of money and there 
        is an infinte supply of all kinds of patries. The bakery has N different kinds of pastries. The i-th pastry has some ai and bi 
        value associated with it. When Thomas eats the i-th pastry for the first time, he gets ai amount of happiness. When he eats the 
        i-th pastry for the second time, he gets (ai - bi)amount of happiness and so on. When he eats the i-th pastry for the k-th time, 
        the amount of happiness he gets is equal to max (0, ai - (k-1)*bi). Calculate the maximum amount of happiness Thomas can get 
        with the amount of money he has.

        Input: The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first 
        line of each test case contains two space separated integer values of N and R. The second line contains N space separated pairs 
        of integer (ie, 2*N integers) denoting the values of ai and bi.

        Output: Print a single integer denoting the maximum amount of happiness that Thomas can gain with the given amount of money he has.

        Your Task: You don't need to read input or print anything. Your task is to complete the function maxHappiness() which takes the
        array a[], the array b[], their size N and amount of money R as inputs and returns the maximum amount of Happiness that Thomas 
        can gain with R amounts of Money. Since the result can be very large, return the result mod 998244353.

        Constrains: 1 <= T <= 100 1 <= |N|, |R| <= 2106 1 <= ai, bi <= 2106

        Example: Sample Input: 2 2 3 8 2 7 2 2 10 5 1 10 5

        Sample Output: 21 30

        Explanation: Test Case 1: Thomas eats the 0-th pastry and gains happiness 8. Then he eats the 1-st pastry and gains 
        happiness 7. Then he eats the 0-th pastry and gains happiness 8-2 = 6. After this, he exhausts all his money. 
        Hence, the total amount of Happiness = 8 + 7 + 6 = 21.
        
        
        
