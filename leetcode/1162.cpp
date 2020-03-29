//你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
//
//我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
//
//如果我们的地图上只有陆地或者海洋，请返回 -1。
//
// 
//
//示例 1：
//输入：[[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释： 
//海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
//
//示例 2：
//输入：[[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释： 
//	海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
// 
//
//提示：
//	1 <= grid.length == grid[0].length <= 100
//	grid[i][j] 不是 0 就是 1
//
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <cstdio>

using namespace std;

class Solution {
public:
	int maxDistance(vector<vector<int>>& grid) {
		int h = grid.size();
		int w = grid[0].size();
		int N = h*w+1;
		
		bool all_land = true;
		bool all_ocean = true;
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				if (grid[i][j] != 1)
					all_land = false;
				if (grid[i][j])
					all_ocean = false;
			}
		}

		if (all_land || all_ocean)
			return -1;

		int *dp1 = (int*)malloc(h*w*sizeof(int));
		int *dp2 = (int*)malloc(h*w*sizeof(int));
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) {
				dp1[i*w+j] = N;
				if (grid[i][j]) {
					dp1[i*w+j] = 0;
				} else {
					int r = (i-1)<0?0:(i-1);
					int c = (j-1)<0?0:(j-1);
					if (i==0 && j!=0)
						dp1[i*w+j] = dp1[i*w+c]+1;
					else if (j==0 && i!=0)
						dp1[i*w+j] = dp1[r*w+j]+1;
					else
						dp1[i*w+j] = min(dp1[i*w+c], dp1[r*w+j])+1;
				}
			}
		}

		int result = 0;
		for (int i=(h-1); i>=0; i--) {
			for (int j=(w-1); j>=0; j--) {
				dp2[i*w+j] = N;
				if (grid[i][j]) {
					dp2[i*w+j] = 0;
				} else {
					int c = (j+1)>=w?w:(j+1);
					int r = (i+1)>=h?h:(i+1);
					if (i==(h-1) && j!=(w-1))
						dp2[i*w+j] = min(dp2[i*w+c]+1, dp1[i*w+j]);
					else if (i!=(h-1) && j==(w-1))
						dp2[i*w+j] = min(dp2[r*w+j]+1, dp1[i*w+j]);
					else if (i==(h-1) && j==(w-1)) 
						dp2[i*w+j] = min(N, dp1[i*w+j]);
					else 
						dp2[i*w+j] = min(min(dp2[i*w+c], dp2[r*w+j])+1, dp1[i*w+j]);
					
					result = max(dp2[i*w+j], result);
				}
			}
		}

		free(dp1);
		free(dp2);
		return result;
        }
};

int main()
{
	int map1[][3] = {{1,0,1},{0,0,0},{1,0,1}};
	int map2[][3] = {{1,0,0},{0,0,0},{0,0,0}};

	vector<vector<int> > test;
	for (int i=0; i<3; i++) {
		vector<int> t(map1[i], map1[i]+3);
		test.push_back(t);
	}
	Solution s;
	cout<<s.maxDistance(test)<<endl;
	test.clear();
	for (int i=0; i<3; i++) {
		vector<int> t(map2[i], map2[i]+3);
		test.push_back(t);
	}
	cout<<s.maxDistance(test)<<endl;

	return 0;
}

