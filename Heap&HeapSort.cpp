#include<vector>
using namespace std;
//提示：这里的堆在数组中的下标默认以1开始！！！
int parent(int i) {
    return i/2;
}
int left(int i) {
    return 2*i;
}
int right(int i) {
    return 2*i+1;
}
//维护最大堆的性质：parent节点都要大于子节点
//下面函数让根为下标i的节点的子树满足最大堆性质
//注意：这时已经假定根节点为左右孩子的子树都已满足最大堆性质！！！
void MaxHeapify(vector<int>& arr, int i) {
    l=left(i);
    r=right(i);
    int largest;
    if(l<=arr.size() && arr[l]>arr[i]) {//这里arr.size实际上不对，应该为堆的实际有效元素大小
        largest=l;
    }else {
        largest=i;
    }
    if(r<=arr.size() && arr[r]>arr[largest]) {
        largest=r;
    }
    if(largest!=i) {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest);
    }
}
void MaxHeapify(vector<int>& arr, int i) {
    int heap_size = arr.size();
    int largest;
    while (true) {
        int l = left(i);
        int r = right(i);
        largest = i;
        if (l <= heap_size && arr[l-1] > arr[i-1]) {
            largest = l;
        }
        if (r <= heap_size && arr[r-1] > arr[largest-1]) {
            largest = r;
        }
        if (largest != i) {
            swap(arr[i-1], arr[largest-1]);//-1是为了0-based和1-based转换
            i = largest;
        } else {
            break;
        }
    }
}

void BuildMaxHeap(vector<int>& arr) {
    for (int i=arr.size()/2; i>=1; i--) {
        MaxHeapify(arr, i);
    }
}
