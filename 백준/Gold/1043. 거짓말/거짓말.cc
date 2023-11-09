#include <stdio.h>
#include <queue>

using namespace std;

#define MAX 52
#define endl printf("\n");
#define PF printf("Hello\n");

queue<int> q;
bool visited[MAX];      // 진실을 아는 사람
int party[MAX][MAX];    // n번 파티에 누가 있는지 / 0번에는 파티의 사람 수가 있음
int where[MAX][MAX];      // 이 사람은 몇번 파티에 있는지 / 0번에는 몇개의 파티에 참여중인지

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int know_truth;
    scanf("%d", &know_truth);
    for (int i = 0; i < know_truth; i++) {
        int tmp;
        scanf("%d", &tmp);
        q.push(tmp);
        visited[tmp] = true;
    }

    for (int i = 1; i <= m; i++) {
        int num;
        scanf("%d", &num);
        party[i][0] = num;
        for (int j = 1; j <= num; j++) {
            int tmp;
            scanf("%d", &tmp);
            party[i][j] = tmp;
            where[tmp][0]++;
            where[tmp][where[tmp][0]] = i;
        }
    }

    while(!q.empty()) {
        for (int i = 1; i <= where[q.front()][0]; i++) {
            for (int j = 1; j <= party[where[q.front()][i]][0]; j++) {
                if (visited[party[where[q.front()][i]][j]]) continue;
                visited[party[where[q.front()][i]][j]] = true;
                q.push(party[where[q.front()][i]][j]);
            }
        }
        q.pop();
    }

    int cnt = m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= party[i][0]; j++) {
            if (visited[party[i][j]]) {
                cnt--;
                break;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}