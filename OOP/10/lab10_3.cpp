#include "msoftcon.h"
#include <iostream>
#include <locale.h>

using namespace std;

class circle {
	protected:
		int xCo, yCo;
		int radius;
		color fillcolor;
		fstyle fillstyle;
	public:
		void set(int x, int y, int r, color fc, fstyle fs) {
			xCo = x;
			yCo = y;
			radius = r;
			fillcolor = fc;
			fillstyle = fs;
		}
		void draw() {
			set_color(fillcolor);
			set_fill_style(fillstyle);
			draw_circle(xCo, yCo, radius);
		}
};

int main() {
	init_graphics();

	circle c1;
	circle c2;
	circle c3;

	c1.set(25, 5, 5, cRED, O_FILL);
	c2.set(35, 15, 4, cGREEN, MEDIUM_FILL);
	c3.set(20, 22, 2, cBLUE, X_FILL);

	c1.draw();
	c2.draw();
	c3.draw();

	set_cursor_pos(1, 25);


	return 0;
}