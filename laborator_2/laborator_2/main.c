/*
* Calculeaza o valoare aproximativa a radacinii patrate a unui numar
* real pozitiv, cu o precizie data.
*/

#include <stdio.h>

#define eps 1e-6

void print_menu() {
	/*
		Prints on the screen the menu.
	*/
	printf("1. Input the number\n2. Exit\n");
}

int get_command() {
	/*
		Returns the command inputed by the user
	*/
	int cmd;

	printf("Give command: ");
	scanf("%d", &cmd);

	return cmd;
}

double module(double x) {
	/*
		Returns the module of the parameter x.
			  | -x, x < 0
		|x| = |
		      | x, x > 0

		Input:
			x - double floating point variable
		Output:
			|x|
	*/
	if (x < 0)
		return -x;
	return x;
}

double get_square_root(double n) {
	/*
		Returns the square root of the parameter n.
		Input:
			n - double floating point variable
		Output:
			sol - double floating point variable,
				  representing the square root of n
	*/
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
	/*
		Returns n from the user input.
		Output:
			n - double floating point variable
	*/
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
