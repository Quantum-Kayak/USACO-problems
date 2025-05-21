#include <iostream>
#include <fstream>
using namespace std;

struct Rect {
    int x1, y1, x2, y2;
    int width, height;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    Rect bi, ba;
    cin >> bi.x1 >> bi.y1 >> bi.x2 >> bi.y2;
    cin >> ba.x1 >> ba.y1 >> ba.x2 >> ba.y2;

    bi.width = bi.x2 - bi.x1;
    bi.height = bi.y2 - bi.y1;
    
    int area = (bi.x2 - bi.x1) * (bi.y2 - bi.y1);
    
    bool fullX = (ba.x1 <= bi.x1 && ba.x2 >= bi.x2);
    bool fullY = (ba.y1 <= bi.y1 && ba.y2 >= bi.y2);
    
    int overlapX = max(0, min(bi.x2, ba.x2) - max(bi.x1, ba.x1));
    int overlapY = max(0, min(bi.y2, ba.y2) - max(bi.y1, ba.y1));
    int overlap = (fullX || fullY) ? (overlapX * overlapY) : 0;
    
    cout << area - overlap << '\n';

    return 0;
}
