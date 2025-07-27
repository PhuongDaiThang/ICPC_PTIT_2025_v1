#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

bool check(Point a, Point b, Point c){
    return (b.x-a.x)*(c.y-a.y) == (b.y-a.y)*(c.x-a.x);
}

int main(){
    int n;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }
    long long total = 0, count = 0;
    total = 1LL * n * (n - 1) * (n - 2) / 6;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(check(points[i], points[j], points[k])){
                    count++;
                }
            }
        }
    }
    cout << total - count << endl;
    return 0;

    
}
4
0 1
1 3
1 1
-1 -1