#include <cstdio>
#include <cmath>
#include <queue>

struct point {
    double x;
    double y;
};

point p[100];

double dist[100][100];
bool visited[100];

double square_dist(const point& a, const point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}



int main() {
    int C, N, x, y;
    scanf("%d", &C);
    for(int c = 0; c < C; ++c) {
        scanf("%d", &N);
        for(int n = 0; n < N; ++n) {
            scanf("%lf %lf", &(p[n].x), &(p[n].y));
            visited[n] = false;
        }
        for(int n1 = 0; n1 < N; ++n1) {
            for(int n2 = n1+1; n2 < N; ++n2) {
                double d = square_dist(p[n1], p[n2]);
                dist[n1][n2] = d;
                dist[n2][n1] = d;
            }
        }

        std::queue<int> queue;
        queue.push(0);
        double length = 0.0;
        while(!queue.empty()) {
            int point = queue.front();
            visited[point] = true;
            queue.pop();

            int min_point = -1;
            double min_dist = 99999.0;
            for(int i = 0; i < N; ++i) {
                if(visited[i]) continue;
                if(dist[point][i] < min_dist) {
                    min_dist = dist[point][i];
                    min_point = i;
                }
            }
            if(min_point > 0) {
                printf("%d %d %f\n", point, min_point, dist[point][min_point]);
                length += min_dist;
                queue.push(min_point);
            }
        }
        printf("%.2f\n", length);
    }
    return 0;
}