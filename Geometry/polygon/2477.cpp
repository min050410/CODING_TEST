// 참외밭

#include <stdio.h>

int N;
int arr[6 + 2][2 + 2];  // 주어지는 방향, 길이쌍
int cnt[4]; // 방향 별 등장 횟수 저장

int main(void) {
    
    int s = 1; // 작은 사각형의 넓이
    int b = 1; // 큰 사각형의 넓이

    // 입력 받기
    scanf("%d", &N);
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        cnt[arr[i][0]]++;
    }

    for (int i = 0; i < 6; i++) {

        if (cnt[arr[i][0]] == 1) {
            // 한 번씩 등장하는 방향이다
            b *= arr[i][1]; // 큰 사각형의 너비/높이이다
            continue;
        }

        int n = (i + 1) % 6;
        int nn = (i + 2) % 6;
        // 나(I)랑 다다음거(nn)랑 같으면 그 사이에 있는 것(n)이 작은 사각형의 너비/높이이다.
        if (arr[i][0] == arr[nn][0]) s *= arr[n][1];
    }

    printf("%d", (b - s) * N);

    return 0;
}