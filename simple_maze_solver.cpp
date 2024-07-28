// Maze solving program.
// more info after the program.scroll down ^_^.

#include <iostream>

using namespace std;

int main() {
	// size of the 2D-arrary.
	constexpr int n = 20;

	// maze container 2D-Array.
	int x[n][n];

	// here a is y coordinate, b is x coordinate of the matix.
	int a = 0, b = 0;

	// taking input for 2-D array.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x[i][j];
		}
	}

	// checking for a entrance.
	for (int i = 0; i < n; i++) {
		if (x[i][0] == 1) {
			a = i;
			break;
		}

		if (x[i][n - 1] == 1) {
			a = i;
			b = n - 1;
			break;
		}

		if (x[0][i] == 1) {
			b = i;
			break;
		}

		if (x[n - 1][i] == 1) {
			b = i;
			a = n - 1;
			break;
		}
	}

	// taking entrance as starting point and finding a path to exit.
	cout << "Entrance: (" << a << "," << b << ")" << '\n';

	bool finished = false;

	while (!finished) {
		// checking if there are any 1's(open spaces) nearby to go and changing the path we
		// travelled to 2.
		/*
		we come to this else if there is no '1' nearby which means that it is a dead end.
		so we trace our path back which are 2's and change them to 3 which means it is the path it
		visited once but is a dead end.
		*/
		for (int lookfor = 1; lookfor <= 2; ++lookfor) {
			int curr_x = b;
			int curr_y = a;

			if (a < n - 1 && x[a + 1][b] == lookfor) {
				a += 1;
			} else if (a >= 1 && x[a - 1][b] == lookfor) {
				a -= 1;
			} else if (b < n - 1 && x[a][b + 1] == lookfor) {
				b += 1;
			} else if (b >= 1 && x[a][b - 1] == lookfor) {
				b -= 1;
			} else {
				continue;
			}

			x[curr_y][curr_x] = lookfor + 1;
			break;
		}

		// if it finds an exit it changes finished to 1 to break the loop.
		if (a == n - 1 || b == n - 1 || a == 0 || b == 0)
			finished = true;

		cout << "(" << a << "," << b << ")" << '\n';
	}

	x[a][b] = 2;

	// printing final maze.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}

/*
It takes input of a maze in which '0' is blocked site and '1' is open site,It finds a path if there
is any(Only 1 in and 1 out mazes).

Output : path with 2 is final path 3 is the path it visited once but is a dead end.

It solves simple mazes but can give error for some mazes like if there is a connected path like
below in the maze it can get messy.

1 1 1 1 1 1 1
1 0 0 0 0 0 1
1 0 0 0 0 0 1
1 0 0 0 0 0 1
1 1 1 1 1 1 1

I typed these inputs so you can try changing size of the array like 5X5(should change values in for
loop too) and make a small maze and tell me if any errors,TY ^_^.

Input 1.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1 1 1 1 1 0 0 1 0 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0 1 0 0 1 0 0 0
0 1 0 0 0 0 0 1 0 0 0 0 0 1 1 1 1 0 0 0
0 1 1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1 1 1 1 1 0 0 0 1 1 1 1
0 0 1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0
0 0 1 0 1 0 1 0 0 0 1 1 1 0 1 1 1 0 0 0
0 0 1 1 1 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0
0 1 0 0 1 0 1 1 1 0 1 0 0 0 1 0 0 0 0 0
0 1 1 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0
0 0 1 0 1 1 1 0 1 0 0 0 0 1 0 0 0 0 0 0
0 0 1 0 1 0 1 0 1 0 0 0 1 1 1 1 1 1 0 0
0 0 1 1 1 0 1 0 1 1 1 1 1 0 0 0 0 1 0 0
0 0 0 1 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0
0 1 1 1 0 0 1 0 0 0 0 0 1 0 1 1 1 1 0 0
0 0 0 1 0 0 1 1 1 1 1 1 1 0 1 0 0 0 0 0
1 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 1 1 0
0 1 1 1 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Output 1.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 3 3 3 3 3 0 0 3 0 0 0
0 3 3 3 3 3 3 3 3 3 0 0 0 3 0 0 3 0 0 0
0 3 0 0 0 0 0 3 0 0 0 0 0 3 3 3 3 0 0 0
0 3 3 0 0 0 0 3 3 0 0 0 0 0 0 0 0 0 0 0
0 0 3 0 0 0 0 0 3 3 3 3 3 0 0 0 2 2 2 2
0 0 3 0 3 0 0 0 0 0 0 0 3 0 0 0 2 0 0 0
0 0 3 0 3 0 1 0 0 0 3 3 3 0 2 2 2 0 0 0
0 0 3 3 3 0 1 0 0 0 3 0 0 0 2 0 0 0 0 0
0 1 0 0 3 0 1 1 1 0 3 0 0 0 2 0 0 0 0 0
0 1 1 0 3 0 0 0 1 0 0 0 0 2 2 0 0 0 0 0
0 0 1 0 2 2 2 0 1 0 0 0 0 2 0 0 0 0 0 0
0 0 1 0 2 0 2 0 1 0 0 0 2 2 1 1 1 1 0 0
0 0 1 2 2 0 2 0 1 1 1 1 2 0 0 0 0 1 0 0
0 0 0 2 0 0 2 0 0 0 0 0 2 0 0 0 0 1 0 0
0 1 1 2 0 0 2 0 0 0 0 0 2 0 1 1 1 1 0 0
0 0 0 2 0 0 2 2 2 2 2 2 2 0 1 0 0 0 0 0
2 2 0 2 0 0 0 0 0 0 0 0 0 0 1 0 1 1 1 0
0 2 2 2 0 0 0 0 0 1 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Input 2.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 0 0 1 0 1 1 1 1 1 1 0 0 0 0 0
0 0 1 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0
0 0 1 1 0 0 0 1 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 1 1 1 0 0 0 0 1 0 0 0 0 0
0 0 0 1 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0
0 0 0 1 1 1 1 1 1 1 0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
1 1 1 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Input 3.

0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 1 1 1 1 1 1 0 0 0 0 0
0 0 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0
0 0 1 1 1 1 1 1 0 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 1 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0
1 1 1 0 1 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
