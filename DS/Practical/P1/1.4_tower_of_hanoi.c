/*
 * Practical 1.4: Tower of Hanoi using Recursion
 */

#include <stdio.h>

int count = 0;

void tower_of_hanoi(int n, char source, char auxiliary, char destination)
{
	if (n == 1)
	{
		count++;
		printf("Step %d: Move disk 1 from %c to %c\n", count, source, destination);
		return;
	}
	tower_of_hanoi(n - 1, source, destination, auxiliary);
	count++;
	printf("Step %d: Move disk %d from %c to %c\n", count, n, source, destination);
	tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main()
{
	int n;

	printf("Enter number of disks: ");
	scanf("%d", &n);

	tower_of_hanoi(n, 'A', 'B', 'C');
	printf("Total moves: %d\n", count);

	return 0;
}

/*
 * Output:
 * Enter number of disks: 3
 * Step 1: Move disk 1 from A to C
 * Step 2: Move disk 2 from A to B
 * Step 3: Move disk 1 from C to B
 * Step 4: Move disk 3 from A to C
 * Step 5: Move disk 1 from B to A
 * Step 6: Move disk 2 from B to C
 * Step 7: Move disk 1 from A to C
 * Total moves: 7
 */
