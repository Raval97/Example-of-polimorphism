// PROJECT
#include "graphicalDisplay.h"
#include "textDisplay.h"
#include "circle.h"
#include "triangle.h"
#include "parallelogram.h"
#include "complexShape.h"
#include "shape.h"
#include "display.h"

using namespace std;

Display *d1 = new GraphicalDisplay();
Display *d2 = new TextDisplay();
Shape *s;
ComplexShape * C = new ComplexShape(d1);

void draw();
void enter_circle();
void enter_paralleogram();
void enter_trianglee();
void enter_draw_ComplexShape();

int main()
{
	int choose;
	for (;;)
	{
		cout << "What do you want to draw? (1,2,3,4)\n 1.Circle\n 2.Triangle\n 3.Parraleogram\n 4.Complex shape\n Choose: ";
		cin >> choose;
		switch (choose) {
		case 1:
			enter_circle(); draw(); break;
		case 2:
			enter_trianglee(); draw(); break;
		case 3:
			enter_paralleogram(); draw(); break;
		case 4:
			enter_draw_ComplexShape(); break;
		default: 
			cout << "\nWrong number"; break;
		}
		cout << "\n\nDou you want again [0 / 1]? :  ";
		cin >> choose;
		if (choose == 0)
		{
			delete s;
			delete C;
			delete d2;
			delete d1; 
			exit(0);
		}
		system("cls");
	}

	return 0;
}

void draw() {
	s->draw();
	s->changeDisplay(d2);
	s->draw();
}
void enter_circle() {
	int r;
	cout << "\nEnter the radius of the circle: (must be +):  ";
	cin >> r;
	s = new Circle(d1, r);
}
void enter_paralleogram() {
	int x1, x2, y1, y2;
	cout << "\nEnter the coordinates of the first vector (x,y must be +):";
	cout << "\nx="; cin >> x1; cout << "y="; cin >> y1;
	cout << "\nEnter the coordinates of the second vector (x must be + and y must be -):";
	cout << "\nx="; cin >> x2; cout << "y="; cin >> y2;
	s = new Parallelogram(d1, x1, y1, x2, y2);
}
void enter_trianglee() {
	int x1, x2, y1, y2;
	cout << "\nEnter the coordinates of the first vector (x,y must be +):";
	cout << "\nx="; cin >> x1; cout << "y="; cin >> y1;
	cout << "Enter the coordinates of the second vector (x must be + and y must be -):";
	cout << "\nx="; cin >> x2; cout << "y="; cin >> y2;
	s = new Triangle(d1, x1, y1, x2, y2);
}
void enter_draw_ComplexShape() {
	int count, choose;
	cout << "\nHow many shape do you want (max 5)?: ";
	cin >> count;
	cout << "\t\t1.Circle \t 2.Triangle \t 3.Parraleogram";
	for (int i = 0; i < count; i++) {
		cout << "\n\n" << i + 1 << " shape is: ";
		cin >> choose;
		switch (choose) {
		case 1: enter_circle(); break;
		case 2: enter_trianglee(); break;
		case 3: enter_paralleogram(); break;
		}
		C->add(s);
	}
	C->draw();
	int i = 0;
	while (C->O[i]) {
		C->O[i]->changeDisplay(d2);
		i++;
	}
	C->changeDisplay(d2);
	C->draw();
}