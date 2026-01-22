#include<vector>
using namespace std;
//一种用分而治之方法的实现
//具体方法：中间点mid，最大子数组要么都在mid左边，要么都在mid右边，要么跨mid
//都左、都右是子问题，而跨中间可以以mid为界分成两部分分别求，可以在线性时间内求出
//注意：函数中high指的是要求范围的最后一个，也就是说要操作的数组大小为high-low+1!!!
vector<int> FindMaxCrossingSubArray(vector<int>& nums,int low,int mid,int high) {
    vector<int> ans(3);
    int sum=0;
    int left_sum,right_sum;
    int maxleft,maxright;
    for (int i=mid;i>=low;i--) {
        if (i==mid) {
            left_sum=sum;
        }
        sum+=nums[i];
        if (sum>left_sum) {
            left_sum=sum;
            maxleft=i;
        }
    }
    sum=0;
    for (int j=mid+1;j<=high;j++) {
        if (j==mid+1) {
            right_sum=sum;
        }
        sum+=nums[j];
        if (sum>right_sum) {
            right_sum=sum;
            maxright=j;
        }
    }
    ans[0]=maxleft;
    ans[1]=maxright
    ans[2]=left_sum+right_sum;
    return ans;
}
vector<int> FindMaximumSubArray(vector<int>& nums,int low,int high) {
    vector<int> ans(3);
    if (high==low) {
        ans[0]=low;
        ans[1]=high;
        ans[2]=nums[low];
        return ans;
    }
    mid=low+(high-low)/2;
    vector<int> ansleft=FindMaximumSubArray(nums,low,mid);
    vector<int> ansright=FindMaximumSubArray(nums,mid+1,high);
    vector<int> anscross=FindMaxCrossingSubArray(nums,low,mid,high);
    if (ansleft>=ansright&&anscross>=ansleft) {
        return ansleft;
    }else if (ansright>=ansleft&&ansright>=anscross) {
        return ansright;
    }else {
        return anscross;
    }
}