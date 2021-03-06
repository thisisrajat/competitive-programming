#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#define LIMIT 10000000
#define MAX 350
using namespace std;



bool prime[LIMIT];
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cost[LIMIT];

int movex[4] = {1, -1, 0, 0};
int movey[4] = {0, 0, 1, -1};

int dfs(int x, int y, int n) {

    visited[x][y] = true;
    for(int i=0; i<4; i++) {

        int x2 = x + movex[i];
        int y2 = y + movey[i];

        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n) continue;

        if(visited[x2][y2])
            continue;

        if(prime[arr[x2][y2]])
            continue;

        if(arr[x2][y2]%2 != arr[x][y]%2)
            continue;

        dfs(x2,y2,n);

    }
}


int main() {
    prime[0] = prime[1] = false;

    for(int i=2; i<LIMIT; ++i) {
        prime[i] = true;
    }

    for(int i=2; i*i<LIMIT; ++i) {
        if(prime[i]) {
                for(int j= i*i; j<LIMIT; j+=i) {
                prime[j] = false;
            }
        }
    }

    for(int i=0, c=0; i<LIMIT; i++) {
        if(prime[i]) {
            cost[i] = c; c++;
        }
        else {
            cost[i] = i/2 + (i%2)*2;
        }
    }

    int T;
    cin >> T;

    while(T--) {
        int N;
        scanf("%d",&N);

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%d",&arr[i][j]);
                visited[i][j] = false;
            }
        }

        long long total=0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(visited[i][j])
                    continue;
                total += cost[arr[i][j]];
                if(!prime[arr[i][j]]) {
                    dfs(i,j, N);
                }

            }
        }

        cout << total << endl;
    }

    return 0;
}