#include<iostream>
#include<cmath>

using namespace std;

class Function {

protected: 
	double x, y, a, b;

public:
	Function(double t1, double t2): a(t1), b(t2) {}

	virtual void calcFunc(double X) = 0;
	
	void printY() {

		cout << "Значение функции в точке = " << y << '\n';

	}

};

class Hyperbola : public Function {

public: 
	
	Hyperbola(double t1, double t2) : Function(t1, t2) {}

	void calcFunc(double X) {

		y = (b / a) * sqrt(X * X - a * a);
		cout << "\nЗначение гиперболы в точке " << X << " вычислено\n";

	}

};

class Ellipse : public Function {

public:

	Ellipse(double t1, double t2) : Function(t1, t2) {}

	void calcFunc(double X) {

		y = (b / a) * sqrt(a * a - X * X);
		cout << "\nЗначение эллипса в точке " << X << " вычислено\n";

	}

};

int main() {

	setlocale(LC_ALL, "Russian");

	Hyperbola* fig;
	fig = new Hyperbola(3, 9);

	fig->calcFunc(5);
	fig->printY();

	Ellipse* fig1;
	fig1 = new Ellipse(5, 9);

	fig1->calcFunc(3);
	fig1->printY();

	return 0;
}