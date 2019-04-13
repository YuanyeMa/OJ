牛客网，《剑指offer》刷题记录。  

本程序全部使用`clang++ 3.9` 编译通过。   

# 01 - [二维数组中的查找](./01-serchInMartix.cpp)

题目描述：  
	在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
	
解题思路：  
	矩阵是有序的，对于行，从左往右下标变大，元素值递增；对于列从上往下，列下标变大，元素值递增；
	因此可以从矩阵的右上角开始搜索，当target元素比当前元素大时，行索引+1往下方搜索；否则列索引-1往左边搜索。
	

# 02 - [替换空格](./02-replaceSpace.cpp) 

题目描述：  
	请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
	
解题思路：  
	从后往前移动，两个指针，一个指向替换空格后的字符串的尾部（pw），另一个指向替换前字符串的尾部(pr)。如果遇到空格就在pw处写入替换的字符，否则就将pr处的字符赋值给pw。


# 03 - [从尾到头打印链表](./03-printListFromTailToHead.cpp) 

题目描述：  
	输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

解题思路：  
	此题和使用递归逆转单链表类似，但是更简单一些，可以设置一个全局或者似有的vector<int>容器，递归返回的时候，将节点的value域push_back给vector，最后返回构造的vector即可。

# 04 -  重建二叉树

题目描述：  
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
	
解题思路：  
	先根序的第一个元素一定为根元素，中根序中根左边的元素一定在左子树，右边的元素一定在右子树。可以通过递归进行树的重建。
	目前还没写出来。

# 05 - [用两个栈来实现一个队列](./05-stack-make-queue.cpp)

题目描述：  
	完成队列的Push和Pop操作。 队列中的元素为int类型。    

解题思路：  
	两个栈，一个作为调整元素顺序的buffer使用。

 - 入队时：先将stack1的元素都pop到stack2中去；然后将新元素push到stack1；再将stack2中的pop回stack1;
- 出队时：直接从stack1 pop一个元素。

# 06 -  [求旋转数组的最小数字](./06-minNumberInRotateArray.cpp)

题目描述：  

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。  

解题思路：  

1.  最简单的思路就是顺序查找，时间复杂度为O(n)， 我就是采用这个思路的；
2. 由于是有序数组，自然想到用二分查找，可以将时间复杂度降低到O(logN)，但是旋转的有序数组还有些不同：
   - 旋转后的数组，前边的元素都大于后边的元素，最小值即为两个递增子数组的分界点；
   - 用`left`和`right`指针分别指向第一个和最后一个元素，`mid`指向中间元素，则如果中间元素**大于**`left`元素，则最小值一定在中间元素的后边，令`left` = `mid`； 反之，如果中间元素**小于**`left`元素，则最小值一定在之间元素的前边，令`right` = `mid;`
   - 循环结束的条件：`left`指向前边递增数组的最大值，`right`指向后边递增数组的最小值，即`right-left == 1`;
   - 此题目中要求是**非减排序数组**，也就是说会出现元素值相等的情况，如果`left mid right`指向的三个元素均相等，则没有办法使用上边的思路求解，只能在区间内顺序查找。



# 07 - [斐波那契数列](./06-Fibonacci.cpp)  

题目描述：  

​	斐波那契数列的表达式如下所示，第0 项为0 ，求第n  项的值，n<=39

- ![](http://latex.codecogs.com/gif.latex?F_0=0)
- ![](http://latex.codecogs.com/gif.latex?F_1=1)
- ![](http://latex.codecogs.com/gif.latex?F_n=F_{n-1}+F_{n-2}(n>=2))

解题思路：

1. 递归解法，时间复杂度为![](http://latex.codecogs.com/gif.latex?O(2^n))；
2. 循环解法， 时间复杂度为![](http://latex.codecogs.com/gif.latex?O(n))；
3. 矩阵求解， 时间复杂度为![](http://latex.codecogs.com/gif.latex?O(logn))；
4. 公式求解， 时间复杂度为![](http://latex.codecogs.com/gif.latex?O(1))，但是涉及到无理数计算，会损失精度；



关于矩阵求解方式  

![](http://latex.codecogs.com/gif.latex?\begin{bmatrix}F_3\\\\F_2\end{bmatrix}=\begin{bmatrix}1&1\\\\1&0\end{bmatrix}*\begin{bmatrix}F_2\\\\F_1\end{bmatrix}=\begin{bmatrix}1&1\\\\1&0\end{bmatrix}*\begin{bmatrix}1&1\\\\1&0\end{bmatrix}*\begin{bmatrix}F_1\\\\F_0\end{bmatrix})

**矩阵快速幂**

例如求

![](http://latex.codecogs.com/gif.latex?A^9=A*A*A*A*A*A*A*A*A)  9次乘法    
![](http://latex.codecogs.com/gif.latex?=A*(A*A)*(A*A)*(A*A)*(A*A)=A*(A^2)^4 ) 6次乘法    
![](http://latex.codecogs.com/gif.latex?=A*((A^2)^2)^2)  4次乘法   



# 08 - [跳台阶](./08-jumpFloor.cpp)



题目描述：  

一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。  



解题思路：    

假设共有n个台阶，共f(n)种跳法。  

- 假定第一次跳一个台阶，那么剩下n-1个台阶，共f(n-1)种跳法；
- 假定第一次跳两个台阶，那么剩下n-2个台阶，共f(n-2)种跳法；
- 则n个台阶时共f(n-1)+f(n-2)种跳法，递归即可求出总跳法；
- 当n=1时 f(n) = 1, 当n=2时f(n) = 2， 即构造了一个斐波那契数列。  



# 09 - [变态跳台阶](./09-jumpFloorII.cpp)

题目描述：  

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。  

解题思路：  

也可以循环调用第八题中写好的递归函数，但是此种解法开销太大，看到有网友推导出的公式，感慨数学分析才是王道啊。推导过程如下：  

- f(1) = 1
- f(2) = f(2-1) + f(2-2)
-  .....
- f(n-1) = f((n-1)-1) + f((n-1)-2 + ... + f(0) = f(0) + f(1) +f(2) + ... + f(n-2)  
- f(n) = f(n-1) + f(n-2) + ... + f(0) = f(0) + f(1) + f(2) + ... + f(n-1) = \** f(n-1) + f(n-1) \**  此处的第二个f(n-1)即为上式
- 故：f(n) = 2*f(n-1)

 



# 14 - [查找单向链表的倒数第k个节点](./14-FindKthTotail.cpp)

题目描述：  

输入一个链表，输出该链表中倒数第k个结点。  

解题思路：  

- 第一反应是用栈来实现，先遍历链表，将元素依次入栈，然后出栈的时候开始计数，当计到k时，返回栈顶元素。但是此方法需要占用额外的存储空间。  
- 第二种方法是，用两个指针，一个快指针fast_p，一个慢指针slow_p。快指针先向前移动k个元素，然后快指针和慢指针一起向后移动，当快指针到达链表尾部的时候，慢指针刚好指向目标节点。  



# 15 - [反转链表](./15-ReverseList.cpp)

题目描述：  

输入一个链表，反转链表后，输出新链表的表头。  



解题思路：  

- 递归： 刚开始比较纠结，新链表的表头指针怎么传递，分析后发现重构链表的指针域时不需要用到递归的返回值，递归的返回值可以用来传递新链表的表头指针，通过层层递归返回最终返回给调用递归处。
- 用栈



# 16 - [合并两个排序链表](./16-MergeSortedList.cpp)

题目描述：   

输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

  

解题思路：    

这道题的思路都是一样的，不过看到网友的代码，真的好简洁。学习一下。  






