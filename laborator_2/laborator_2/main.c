/*
* Calculeaza o valoare aproximativa a radacinii patrate a unui numar
* real pozitiv, cu o precizie data.
*/

#include <stdio.h>

#define eps 1e-6

void print_menu() {
	printf("1. Input the number\n2. Exit\n");
}

int get_command() {
	printf("Give command: ");
	int cmd;
	scanf("%d", &cmd);
	return cmd;
}

double module(double x) {
	if (x < 0) {
		return -x;
	}
	return x;
}

double get_square_root(double n) {
	double sol = n / 2;
	double left = 1, right = n;

	while (module(sol * sol - n) > eps) {
		if (sol * sol > n) {
			right = sol;
		}
		else {
			left = sol;
		}

		sol = (right + left) / 2;
	}

	return sol;
}

double get_n() {
	int n;

	printf("n = ");
	scanf("%d", &n);

	return n;
}

int main() {
	double n;

	while (1) {
		print_menu();
		int cmd = get_command();

		if (cmd == 1) {
			n = get_n();
			double sqrt_n = get_square_root(n);

			printf("The square root of %F is %F\n", n, sqrt_n);
		}
		else
			break;
	}

	return 0;
}
