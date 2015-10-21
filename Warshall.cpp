#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int N, M, M1, M2;
    cin >> N;
    char RelationMatrix[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
	    cin >> RelationMatrix[i][j];
    cin >> M;
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
	    for (int j = 0; j < N; j++)
		RelationMatrix[i][j] = RelationMatrix[i][j] | (RelationMatrix[i][k] & RelationMatrix[k][j]);
    for (int i = 0; i < M; i++) {
        cin >> M1 >> M2;
	if (RelationMatrix[M1][M2] == 1)
	    cout << "YES!";
	else
	    cout << "NO!";
    }
    return 0;
}
