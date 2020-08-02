#include <cstdio>

struct pos {
    float x;
    float y;
};

pos p[100];

float dist[100][100];

float dist_square(const pos& a, const pos& b) {
    return (a.x - b.x) * (a.x-b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    int C, N, x, y;
    scanf("%d", &C);
    for(int c = 0; c < C; ++c) {
        scanf("%d", &N);
        for(int n = 0; n < N; ++n) {
            scanf("%f %f", &p[n].x, &p[n].y);
        }
        for(int n1 = 0; n1 < N; ++n1) {
            for(int n2 = n1+1; n2 < N; ++n2) {
                float d = dist_square(p[n1], p[n2]);
                dist[n1][n2] = d;
                dist[n2][n1] = d;
            }
        }
    }
    return 0;
}