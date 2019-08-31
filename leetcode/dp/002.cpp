#include <iostream>
#include <queue>

using namespace std;

char map[1005][1005];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	int n, m;
	cin>>n>>m;

	int s_x = 1000;
	int s_y = 1000;

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin>>map[i][j];
			if (map[i][j] == 'S') {
				s_x = i;
				s_y = j;
			}
		}
	}

	int steps = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(s_x, s_y));

	int t_x = 1000;
	int t_y = 1000;

	while (!q.empty()) {
		pair<int, int> cur_pos = q.front();
		q.pop();

		for (int i=0; i<4; i++) {
			int n_x = cur_pos.first + dx[i];
			int n_y = cur_pos.second + dy[i];
			if (n_x < 0 || n_x > n-1 || n_y < 0 || n_y > m-1)
				continue; 
			if (map[n_x][n_y] == 'E') {
				cout<<steps<<endl;
				return 0;
			} else if (map[n_x][n_y] == '.') {
				q.push(make_pair(n_x, n_y));
				map[cur_pos.first][cur_pos.second] = '#';
			}
		}
		steps++;
	}
	return 0;
}
