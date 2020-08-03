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

bool decision(const int& N, double d) {
    std::queue<int> queue;
    bool visited[100] = {false,};
    
    queue.push(0);
    visited[0] = true;
    int seen = 0;
    while(!queue.empty()) {
        int point = queue.front();
        queue.pop();
        ++seen;
        for(int i = 0; i < N; ++i) {
            if(visited[i]) continue;
            if(dist[point][i] < d) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }
    return N == seen;
}

double optimize(const int& N) {
    double low = 0, high = 1416.00;
    for(int i = 0; i < 100; ++i) {
        double mid = (low + high) / 2;
        if(decision(N, mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    int C, N, x, y;
    scanf("%d", &C);
    for(int c = 0; c < C; ++c) {
        scanf("%d", &N);
        for(int n = 0; n < N; ++n) {
            scanf("%lf %lf", &(p[n].x), &(p[n].y));
        }
        for(int n1 = 0; n1 < N; ++n1) {
            for(int n2 = n1+1; n2 < N; ++n2) {
                double d = square_dist(p[n1], p[n2]);
                dist[n1][n2] = d;
                dist[n2][n1] = d;
            }
        }
        
        printf("%.2f\n", optimize(N));
    }
    return 0;
}