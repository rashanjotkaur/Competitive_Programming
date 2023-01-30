// https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Func 1: 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector <int> res;
    vector <int> minHeap;
    for(int i=0;i<n;i++){
        vector <int> temp=q[i];
        if(temp.size()==1 && !minHeap.empty()){
            res.push_back(minHeap[0]);
            minHeap[0]=minHeap[minHeap.size()-1];
            minHeap.pop_back();
            minHeapify(minHeap,0,minHeap.size());
        }
        else{
            minHeap.push_back(temp[1]);
            minHeapifyInsertion(minHeap,minHeap.size()-1,minHeap.size());
        }
    }
    return res;
}

// Func 2:
void minHeapify(vector <int> &minHeap, int i, int n){
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left<n && minHeap[left]<minHeap[smallest])
        smallest=left;
    if(right<n && minHeap[right]<minHeap[smallest])
        smallest=right;
    if(smallest!=i){
        swap(minHeap[smallest],minHeap[i]);
        minHeapify(minHeap,smallest,n);
    }
}

// Func 3:
void minHeapifyInsertion(vector <int> &minHeap, int i, int n){
    if(i<=0)   
        return ;
    int parent=(i-1)/2;
    if(minHeap[parent]>minHeap[i]){
        swap(minHeap[parent],minHeap[i]);
        minHeapifyInsertion(minHeap,parent,n);
    }
}


