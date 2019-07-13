#include <iostream>

using namespace std;

void qsort(float * data, int l, int r)
{
	int i = l;
	int j = r;
	float mid  = data[(l+r)/2];
	while(i<=j){
		while (data[j]>mid ) j--;
		while (data[i]<mid ) i++;
		if (i<=j) {
			swap(data[i], data[j]);
			i++;
			j--;
		}
	} 
	if (l<j) qsort(data, l, j);
	if (i<r) qsort(data, i, r);

}

//另外一种写法
int Partition(float a[],int low,int high)
{
    float pivot = a[low];                            //当前表中第一个元素设为枢轴质，对表进行划分 
    while(low<high)                                     //循环跳出条件 
    {               
        while(low<high && a[high]>=pivot)	--high;
        a[low] = a[high];                               //将比枢轴值小的元素移动到左端 
        while(low<high && a[low]<=pivot) 	++low;
        a[high] = a[low];                               //将比枢轴值大的元素移动到右端 
    }
    a[low] = pivot;                                     //枢轴元素存放到最终位置 
    return low;                                         //返回存放枢轴的最终位置 
}

void QuickSort(float a[],int low,int high)
{
    if(low<high)                                        //递归出口 
    //Partition()是划分操作，将表a[low...high]划分为满足上述条件的两个子表 
    {
        int pivotpos = Partition(a,low,high);           //划分 
        QuickSort(a,low,pivotpos-1);                    //依次对两个字表进行递归排序 
        QuickSort(a,pivotpos+1,high);                   
    }
} 


int main(void)
{
	// input
	const int MAXN = 1001;
	float numbers[MAXN];

	int n = 0;
	cout<<"len : ";
	cin>>n;

	for (int i = 0; i < n; i++) {
		cout<<i<<" of numbers : ";
		cin>>numbers[i];
	}

	// sort
	//qsort(numbers, 0, n-1);
	QuickSort(numbers, 0, n-1);

	// output
	cout<<endl;
	cout<<"after sort : ";
	for (int i = 0; i<n; i++)
		cout<<numbers[i]<<" ";
	cout<<endl;


	return 0;
	return 0;
}

