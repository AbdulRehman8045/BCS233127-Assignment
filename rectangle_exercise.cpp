
//Design a class named Rectangle that includes
//● data members for the length and width of a rectangle,
//● respective mutator and accessor functions to set and get values of length and width, and
//● a member function named recArea() to compute the area of rectangle(length x width)
//From the Rectangle class, derive a class named Cuboid that contains
//● a data field named height in addition to length and width,
//● two functions named setHeight and getHeight() to set and get value of height data field,
//and
//Department of Computer Science / Software Engineering
//Faculty of Computing, Capital University of Science and Technology
//78
//● a member function named cuboidArea() to calculate the area of a cuboid(length x width
//	x height)
// 
//	Draw UML diagram for each class and show inheritance relationship between these classes


#include<iostream>
using namespace std;
#include<string>


class Rectangle {

	double length;
	double width;
public:
	//Rectangle() {
		/*cout << "length";
		cin >> length;
		cout << "width";
		cin >> width;*/

		//}

	void setLength(double len) {
		length = len;
	}

	void setWidth(double wid) {
		width = wid;
	}

	double getLength() {
		return length;
	}

	double getWidth() {
		return width;
	}

	double recArea() {

		double area = (length * width);
		return area;
	}
};

int main() {

	Rectangle rectangle = Rectangle();
	rectangle.setLength(3);
	rectangle.setWidth(4.1);
	cout<<rectangle.getLength();
	cout << rectangle.getWidth();
	cout << rectangle.recArea();
    return 0;
}




