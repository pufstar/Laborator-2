/*
* 1. Calculeaza o valoare aproximativa a radacinii patrate a unui numar
* real pozitiv, cu o precizie data.
*
* 2. Tiparste triunghiul lui Pascal, cu toate combinarile C(m,k) de m obiecte
* luate cate k, k = 0, 1, ..., m, in linia m, pentru m = 1, 2, ..., n.
*/

#include <stdio.h>

#define eps 1e-6

/*
	Prints on the screen the menu.
*/
void print_menu() {
	printf("1. Compute the square root\n2. Print the pascal triangle\nx. Exit\n");
}

/*
	Returns the command inputed by the user
*/
int get_command() {
	int cmd;

	printf("Give command: ");
	scanf("%d", &cmd);

	return cmd;
}

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
double module(double x) {
	if (x < 0)
		return -x;
	return x;
}

/*
	Returns the square root of the parameter n.
	Input:
	n - double floating point variable
	Output:
	sol - double floating point variable,
	representing the square root of n
*/
double get_square_root(double n) {
	double sol, left, right;
	if (n > 1) {
		sol = n / 2;
		left = 1., right = n;
	}
	else {
		sol = n * 2;
		left = n, right = 1.;
	}

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

/*
	Returns n from the user input.
	Output:
	n - positive double floating point variable
*/
double get_n() {
	double n;

	printf("n = ");
	scanf("%lf", &n);

	return n;
}

/*
	Computes the Pascal triangle
	Input:
		n - the rank of the matrix, integer
		matrix - 2D integer matrix, where the triangle will be saved
*/
void get_pascal_triangle(int n, int matrix[100][100]) {
	matrix[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
		}
	}
}

int main() {
	while (1) {
		print_menu();
		int cmd = get_command();

		if (cmd == 1) {
			double n;
			n = get_n();

			double sqrt_n = get_square_root(n);

			printf("The square root of %lf is %lf\n", n, sqrt_n);
		}
		else if (cmd == 2) {
			int n;
			printf("n = ");
			scanf("%d", &n);

			int pascal[100][100];
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					pascal[i][j] = 0;

			get_pascal_triangle(n, pascal);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= i; j++) {
					printf("%d ", pascal[i][j]);
				}
				printf("\n");
			}
		}
		else break;
	}

	return 0;
}
