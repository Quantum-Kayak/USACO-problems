#include <iostream>
#include <cmath>

int main() {
    const int   width  = 80;   // columns
    const int   height = 40;   // rows   (tweak for your terminal)
    const double cx = width  / 2.0;
    const double cy = height / 2.0;
    const double rx = width  * 0.4;   // radii: 40 % of width, 40 % of height
    const double ry = height * 0.4;

    const char  ink = '#';     // glyph for filled pixels
    const char  blank = ' ';   // background

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double dx = (x - cx) / rx;
            double dy = (y - cy) / ry * 2.0;   // *2: compensate char-cell aspect
            std::cout << ((dx*dx + dy*dy <= 1.0) ? ink : blank);
        }
        std::cout << '\n';
    }
}
