#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct point {
	double x, y;
};

double function1(double x) {
	return 3 * x * x + 6 * x - 5;
}
double function2(double x) {
	return (7 - 3 * x) / x;
}
double function3(double x) {
	return atan(x * x - 16);
}
double function4(double x) {
	return 3 * pow(x, 7) - 7 * pow(x, 6);
}
double function5(double x) {
	return -15 / x + x * x;
}
double function6(double x) {
	return sqrt(cos(x)) * x * x;
}
double function7(double x) {
	return (x * x + 6 * x - 5) / (2 * x - 7);
}
double function8(double x) {
	return 3 * x * x * x - x / 7;
}
double function9(double x) {
	return 16 * x - sin(7 / x);
}
double function10(double x) {
	return 1 / x + 1 / tan(8 * x);
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "введите номер функции (1-10): " << endl;
	int n;
	cin >> n;

	cout << "введите x0: " << endl;
	int x0;
	cin >> x0;

	int size = 5;
	// создаем и заполняем массив точек
	point* arr = new point[size];
	double a, b, h, x;
	a = x0 - 10;
	b = x0 + 10;
	h = (b - a) / size;
	x = a;
	for (int i = 0; i < size; ++i) {
		arr[i].x = x;
		//arr[i].y = function1(x);
		x += h;
	}

	switch (n)
	{
	case 1:
		for (int i = 0; i < size; ++i) {
			arr[i].y = function1(arr[i].x);
		}
	case 2:
		for (int i = 0; i < size; i++)
			arr[i].y = function2(arr[i].x);
	case 3:
		for (int i = 0; i < size; i++)
			arr[i].y = function3(arr[i].x);
	case 4:
		for (int i = 0; i < size; i++)
			arr[i].y = function4(arr[i].x);
	case 5:
		for (int i = 0; i < size; i++)
			arr[i].y = function5(arr[i].x);
	case 6:
		for (int i = 0; i < size; i++)
			arr[i].y = function6(arr[i].x);
	case 7:
		for (int i = 0; i < size; i++)
			arr[i].y = function7(arr[i].x);
	case 8:
		for (int i = 0; i < size; i++)
			arr[i].y = function8(arr[i].x);
	case 9:
		for (int i = 0; i < size; i++)
			arr[i].y = function9(arr[i].x);
	case 10:
		for (int i = 0; i < size; i++)
			arr[i].y = function10(arr[i].x);
	default:
		cout << "неверный номер функции" << endl;
	}
	// открываем файл для записи
	ofstream wr;
	wr.open("data.txt");
	if (!wr.is_open()) {
		cout << "File opening error\size";
		return 0;
	}
	// записываем массив точек в файл
	for (int i = 0; i < size; ++i) {
		wr << arr[i].x << ' ' << arr[i].y << endl;
		cout << '(' << arr[i].x << ' ' << arr[i].y << ')' << endl;
	}
	wr.close();
	// вызов батника, который вызывает gnuplot и передает ему файл с инструкциями instruction.txt
	system("start_gnuplot.bat");
	system("pause");
	return 0;
}