// #include <bits/stdc++.h>
// using namespace std ;

// void solve(){
//     int n = 0 ;
//     cin>>n ;
//     int m = 0 ;
//     cin>>m ;
//     int start_x=0, start_y =0;
//     int end_x=0, end_y=0 ;
//     vector<vector<char>> grid(n, vector<char>(m, 'a')) ;
//     for(int i = 0 ; i < n ; i++){
//         for(int j = 0 ; j < m ; j++){
//             cin>>grid[i][j] ;
//             if(grid[i][j] == 'A'){
//                 start_x = i ; start_y = j ;
//             }
//             if(grid[i][j] == 'B'){
//                 end_x = i ; end_y = j ;
//             }
//         }
//     }

//     vector<vector<bool>> visited(n, vector<bool>(m, false)) ;
//     queue<pair<pair<int, int>, string>> pq ;
//     visited[start_x][start_y] = true ;
//     pq.push({{start_x, start_y}, ""}) ;
//     int x = 0 ;
//     int y = 0 ;
//     string temp = "" ;
//     string ans = "" ;
//     while(!pq.empty()){
//         x = pq.front().first.first ;
//         y = pq.front().first.second ;
//         temp = pq.front().second ;
//         pq.pop() ;
//         if(x != 0){
//             if(!visited[x-1][y] && (grid[x-1][y] == '.')){
//                 visited[x-1][y] = true ;
//                 pq.push({{x-1, y}, temp+'U'}) ;
//             }
//             else if(grid[x-1][y] == 'B'){
//                 ans = temp + 'U' ;
//                 break ;
//             }
//         }
//         if(y != m-1){
//             if(!visited[x][y+1] && (grid[x][y+1] == '.')){
//                 visited[x][y+1] = true ;
//                 pq.push({{x, y+1}, temp+'R'}) ;
//             }
//             else if(grid[x][y+1] == 'B'){
//                 ans = temp + 'R' ;
//                 break ;
//             }
//         }
//         if(x != n-1){
//             if(!visited[x+1][y] && (grid[x+1][y] == '.')){
//                 visited[x+1][y] = true ;
//                 pq.push({{x+1, y}, temp + 'D'}) ;
//             }
//             else if(grid[x+1][y] == 'B'){
//                 ans = temp + 'D' ;
//                 break ;
//             }
//         }
//         if(y != 0){
//             if(!visited[x][y-1] && (grid[x][y-1] == '.')){
//                 visited[x][y-1] = true ;
//                 pq.push({{x, y-1}, temp+'L'}) ;
//             }
//             else if(grid[x][y-1] == 'B'){
//                 ans = temp + 'L' ;
//                 break ;
//             }
//         }
//     }

//     int length = ans.length() ;
//     if(length != 0){
//         cout<<"YES"<<endl ;
//         cout<<length<<endl ;
//         cout<<ans<<endl ;
//     }
//     else{
//         cout<<"NO"<<endl ;
//     }
// }
// int main(){

//     ios_base::sync_with_stdio(false) ;
//     cin.tie(NULL) ;
//     cout.tie(NULL) ;

//     solve() ;
//     return 0 ;
// }

// my code resulted in tle for one case dont know why. I guess that string is creating that over head 
// may be try using from which node it came like parent rather than storing the string then it will be better 

#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

int n, m;
char A[1000][1000];
bool vis[1000][1000];

// previousStep stores the previous direction that we moved in to arrive that
// this cell
int previousStep[1000][1000];

// 0 = up, 1 = right, 2 = down, 3 = left
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

int main() {
	cin >> n >> m;

	queue<ii> q;
	ii begin, end;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			if (A[i][j] == 'A') {
				begin = mp(i, j);
			} else if (A[i][j] == 'B') {
				end = mp(i, j);
			}
		}
	}

	q.push(begin);
	vis[begin.f][begin.s] = true;

	while (!q.empty()) {
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			ii v = mp(u.f + dx[i], u.s + dy[i]);
			if (v.f < 0 || v.f >= n || v.s < 0 || v.s >= m) continue;
			if (A[v.f][v.s] == '#') continue;
			if (vis[v.f][v.s]) continue;
			vis[v.f][v.s] = true;
			previousStep[v.f][v.s] = i;
			q.push(v);
		}
	}

	if (vis[end.f][end.s]) {
		cout << "YES" << endl;
		vector<int> steps;
		while (end != begin) {
			int p = previousStep[end.f][end.s];
			steps.push_back(p);
			// undo the previous step to get back to the previous square
			// Notice how we subtract dx/dy, whereas we added dx/dy before
			end = mp(end.f - dx[p], end.s - dy[p]);
		}
		reverse(steps.begin(), steps.end());

		cout << steps.size() << endl;
		for (char c : steps) { cout << stepDir[c]; }
		cout << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}