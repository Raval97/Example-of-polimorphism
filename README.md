# Example-of-polimorphism
Project showing graphic use of polymorphism in C ++.

The program creates Shape class objects, respectively a triangle, a circle, a parallelogram, and ComplexShape.

The Shape class uses the Display class, from which the inheritance of classes suitable 
for display in descriptive and graphic form is inherited.

GraphicalDisplay draws shapes using the parameters which are two vectors for the triangle and the parallelogram 
and the radius for the circle

The project was created as credits for classes in Programming Methods.

main code: 

int main(){
	Display *w1 = new GraphicalDisplay();
	Display *w2 = new TextDisplay();
	Shape * o1 = new Triangle(w1, 3, 2, 2,-2);
	Shape * o2 = new Parallelogram(w1, 3, 2, 2,-2);
	Shape * o3 = new Circle(w1, 5);
	ComplexShape * o4 = new ComplexShape(w1);
	o4->add(o1);
	o4->add(o2);
	o4->add(o3);
	o4->draw();
	o1->draw();
	o2->draw();
	o3->draw();
	o1->changeDisplay(w2);
	o2->changeDisplay(w2);
	o3->changeDisplay(w2);
	o4->changeDisplay(w2);
	o4->draw();
	o1->draw();
	o2->draw();
	o3->draw();
	delete o1;
	delete o2;
	delete o3;
	delete o4;
	delete w2;
	delete w1;
	return 0;
}
![Image description](example_of_resoult.png)

result:

   t
  t
ttt
 tt
  t
  p
 ppp
pppppp
 ppp
  p
     c
  ccccccc
 ccccccccc
 ccccccccc
 ccccccccc
ccccccccccc
 ccccccccc
 ccccccccc
 ccccccccc
  ccccccc
     c

Drawing a triangle from vectors (3, 2), (2, -2).
Drawing a parallelogram from vectors (3, 2), (2, -2).
Drawing a circle with radius 5.
Drawing a triangle from vectors (3, 2), (2, -2).
Drawing a parallelogram from vectors (3, 2), (2, -2).
Drawing a circle with radius 5.
