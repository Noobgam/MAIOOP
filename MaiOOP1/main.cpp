#include "Triangle.h"
#include "Hexagon.h"
#include "Octagon.h"
#include <string>

const int N = 10;
char cmd[100];
using namespace std;

int main() {
	string cmd;
	while (cin >> cmd) {
		Figure* fig = nullptr;
		if (cmd == "t") {
			fig = new Triangle();
		}
		else if (cmd == "h") {
			fig = new Hexagon();
		}
		else if (cmd == "o") {
			fig = new Octagon();
		}
		else
			return 0;
		fig->Print();
		cout << endl << fig->Area() << endl;
		delete fig;
	}
	return 0;
}