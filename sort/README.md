# 常用排序算法

## 排序算法分类

插入排序：直接插入排序、折半插入排序、希尔排序

交换排序：冒泡排序、快速排序

选择排序：简单选择排序、堆排序

归并排序

## [选择排序](./select_sort.cpp)

算法思想：  

每一趟从待排序的数据元素中选择一个最小（或者最大）的元素，放在前边排好序的元素后边。直到所有元素全部排好序。  

算法执行过程举例：

| 趟数 | 序列情况       |
| ---- | -------------- |
| 0    | 7，3，6，9，10 |
| 1    | 3，7，6，9，10 |
| 2    | 3，6，7，9，10 |
| 3    | 3，6，7，9，10 |
| 4    | 3，6，7，9，10 |
| 5    | 3，6，7，9，10 |
第0趟表示初始序列，第一趟排好第一个位置，第二趟排好第二个位置。。。

时间复杂度：  
第一趟时对比![](http://latex.codecogs.com/gif.latex?(n-1))次，其中![](http://latex.codecogs.com/gif.latex?n)为序列的长度；  
第二趟时对比![](http://latex.codecogs.com/gif.latex?(n-2))次， 
.....
一共对比了![](http://latex.codecogs.com/gif.latex?(n*n)/2)次，即时间复杂度为![](http://latex.codecogs.com/gif.latex?O(n^2))  

最坏情况： 最坏情况为整个序列是逆序的，对比一次，交换一次，此时的时间复杂度仍然为 ![](http://latex.codecogs.com/gif.latex?O(n^2))  

稳定性： 数值相等的两个元素在排序前后的相对位置不变，因此此算法是稳定的。  



```C
void SelectSort(ElemType A[]. int n)
{
  for (i=0; i<n-1; i++) {
    min = i;
    for (j=i+1; j<n; j++)
      if (A[j] < A[min]) min = j;
    if (min != i ) swap(A[i], A[min]);
  }
}
```

## 堆排序

算法思想：   

"小顶堆数据结构"：把未排序的数组看成是二叉树的数组存储结构，父节点小于左右孩子。  
因此堆排序算法可分为：建堆、调整以及输出三个阶段。

- 建堆： 调整元素位置使其满足"小顶堆"结构；
- 调整： 将堆顶元素(最小元素)移动到最末端，然后调整前边的元素位置，使其重新满足“小顶堆”结构；
- 输出： 将上一步放在最末端的元素输出，并重复“建堆、调整、输出“步骤。  

时间复杂度：  

最坏情况：  

稳定性：  

``` c
// 建立大根堆
void BuildMaxHeap(ElemType A[], int len)
{
  for (int i=len/2; i>0; i--)
    AdjustDown(A, i, len);
}

void AdjustDown(ElemType A[], int k, int len)
{
  A[0] = A[k];
  for (i=2*k); i<=len; i*=2) {
    if (i<len && A[i]<A[i+1]) 
      i++;
    if (A[0] >= A[i])
      break;
    else{
      A[k] = A[i];
      k = i;
    }
  }// end of for
  A[k] = A[0];
}

// 堆排序
void HeapSort(ElemType A[], int len)
{
  BuildMaxHeap(A, len);
  for (i=len; i>1; i--) {
    Swap(A[i], A[1]);
    AdjustDown(A, 1, i-1);
  }
}
```



## [插入排序](./insert_sort.cpp)

算法思想：  

从未排序的序列中拿出一个，遍历已经排好序的序列找到合适的位置，将未排序的元素插入到已排好序的序列的合适位置。  

算法执行过程举例：

| 趟数 | 序列情况       |
| ---- | ------------ |
| 0    | 7，3，6，9，10 |
| 1    | 7，3，6，9，10 |
| 2    | 3，7，6，9，10 |
| 3    | 3，6，7，9，10 |
| 4    | 3，6，7，9，10 |
| 5    | 3，6，7，9，10 |
第0趟为初始序列，第1趟时序列没有变化，第2趟时拿第二个数字3从头往后找合适的位置将数字3插入进去。。。。

时间复杂度：![](http://latex.codecogs.com/gif.latex?O(n^2))  

最坏情况：![](http://latex.codecogs.com/gif.latex?O(n^2))  

稳定性：  稳定  

```c
void InsertSort(ElemType A[], int n)
{
	int i, j;
	for (i = 2; i<=n; i++) {
		if (A[i].key < A[i-1].key) {
			A[0] = A[i].key;
			for (j=i-1; A[0].key<A[j].key); --j) 
				A[j+1] = A[j];
			A[j+1] = A[0];
		}
	}
}
```



## [冒泡排序](./bubble_sort.cpp)

算法思想： 

每一趟只对比相邻的两个元素，如果不符合排序条件，就交换这两个元素的位置。直到排好序列。  

时间复杂度： ![](http://latex.codecogs.com/gif.latex?O(n^2))   

最坏情况： ![](http://latex.codecogs.com/gif.latex?O(n^2))   

稳定性： 稳定 

```c
void BubbleSort(ElemType A[], int n)
{
  for (i=0; i<n-1; i++) {
    flag = false;
    for (j=n-1; j>i; j--) {
      if(A[j-1].key > A[j].key) {
      	swap(A[j-1], A[j]);
        flag = true;
      }
    }
    if (flag == false) 
      return;
  }
}
```

## [快速排序](./quick_sort.cpp)

算法思想:  

先确定一个枢值，然后将比枢值大的元素都放在枢值的右边，把比枢值小的元素都放在枢值得左边。这样就能确定枢值在序列中的最终位置，然后分别对枢值左右两边的序列递归调用排序算法，就能排好序列。

时间复杂度：![](http://latex.codecogs.com/gif.latex?O(nlogn))    

最坏情况：  

稳定性：  不稳定  

```c
void QuickSort(ElemType A[], int low, int high)
{
  if (low < high) {
    int pivotpos = Partition(A, low, high);
    QuickSort(A, low, pivotpos-1);
    QuickSort(A, pivotpos+1, high);
  }
}

int Partition(ElemType A[], int low, int high)
{
	ElemType pivot = A[low];
  while (low<high) {
    while (low<high && A[high] >= pivot) --high;
    A[low] = A[high];
    while (low<high && A[low] >= pivot) ++low;
    A[high] = A[low];
  }
  A[low] = pivot;
  return low;
}
```



## 桶排序

算法思想：   

时间复杂度：  

最坏情况：  

稳定性：  





## 归并排序

算法思想：   

时间复杂度：  

最坏情况：  

稳定性：  

```C
ElemType * B = (ElemType *)malloc((n+1)*sizeof(ElemType));
void Merge(ElemType A[], int low, int high) 
{
  for (int k=low; k<high; k++)
    B[k] = A[k];
  for (i=low; j=mid+1, k=i; i<mid && j<= high; k++) {
    if (B[i]<B[j])
      A[k] = B[i++];
    else
      A[k] = B[j++];
  } // end for
  while (i<=mid) A[k++] = B[i++];
  while (j<=high) A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high)
{
  if (low<high) {
    int mid = (low+high)/2;
    MergeSort(A, low, mid);
    MergeSort(A, mid+1, high);
    Merge(A, low, mid, high);
  }
}
```



## 总结



| 算法     | 最好情况时间复杂度|平均时间复杂度 | 最坏情况下时间复杂度 | 空间复杂度 | 稳定性 |
| -------- | :----------: | :---------- :| :------- : | -------- - | -------- - |
| 直接插入排序 |![](http://latex.codecogs.com/gif.latex?O(n)) |![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(1)) | 是 |
| 冒泡排序 |![](http://latex.codecogs.com/gif.latex?O(n)) |![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(1)) | 是 |
|简单选择排序 | ![](http://latex.codecogs.com/gif.latex?O(n^2))  | ![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(1)) | 否|
| 快速排序 | ![](http://latex.codecogs.com/gif.latex?O(nlogn)) |![](http://latex.codecogs.com/gif.latex?O(nlogn)) | ![](http://latex.codecogs.com/gif.latex?O(n^2)) | ![](http://latex.codecogs.com/gif.latex?O(log(n+1))) | 否 |
| 归并排序 |  ||                      |            |        |
| 堆排序 |    |            |                      |            |        |
| 桶排序 |    |            |                      |            |        |


