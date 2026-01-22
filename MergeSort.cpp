#include<vector>
using namespace std;
//下面是一般实现方法
void merge(vector<int>& arr,int left,int mid,int right) {
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int> leftarr(n1),rightarr(n2);
    for(int i=0;i<n1;i++) {
        leftarr[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++) {
        rightarr[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2) {
        if(leftarr[i]<=rightarr[j]) {
            arr[k]=leftarr[i];
            i++;
        }else {
            arr[k]=rightarr[j];
            j++;
        }
        k++;
    }
    while(i<n1) {
        arr[k]=leftarr[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k]=rightarr[j];
        j++;
        k++;
    }
}
void mergeSortRecursive(vector<int>& arr,int left,int right) {
    if (left<right) {
        int mid=left+(right-left)/2;
        mergeSortRecursive(arr,left,mid);
        mergeSortRecursive(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
//原地合并，需要额外的O（n）空间，但实现更简洁，可以替代merge函数
void mergeInPlace(vector<int>&arr,int left,int mid,int right) {
    vector<int> temp(arr.begin()+left,arr.begin()+right+1);
    int i=0,j=mid-left+1,k=left;
    int n1=mid-left+1;
    int n2=right-left+1;
    while (i<=mid-left&&j<n2) {
        if (temp[i]<=temp[j]) {
            arr[k++]=temp[i++];
        }else {
            arr[k++]=temp[j++];
        }
    }
    while (i<=mid-left) {
        arr[k++]=temp[i++];
    }
    while (j<n2) {
        arr[k++]=temp[j++];
    }
}
void mergeSortOptimized(vector<int>& arr,int left,int right) {
    if (right-left<=16) {
        for (int i=left+1;i<=right;i++) {
            int key=arr[i];
            int j=i-1;
            while (j>=left&&arr[j]>key) {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        return;
    }
    int mid=left+(right-left)/2;
    mergeSortOptimized(arr,left,mid);
    mergeSortOptimized(arr,mid+1,right);
    if (arr[mid]<=arr[mid+1]) {
        return;
    }
    mergeInPlace(arr,left,mid,right);
}