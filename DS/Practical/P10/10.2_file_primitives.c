/*
 * Practical 10.2: File Primitives
 * Demonstrates fopen, fprintf and fclose by writing records to a file and reading them back.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file_pointer;
	char name[50];
	int marks;
	int n;

	printf("Enter the number of records: ");
	scanf("%d", &n);

	file_pointer = fopen("students.txt", "w");

	if (file_pointer == NULL)
	{
		printf("Error: Unable to open file.\n");
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		printf("Enter name and marks: ");
		scanf("%49s %d", name, &marks);
		fprintf(file_pointer, "%s %d\n", name, marks);
	}

	fclose(file_pointer);
	printf("Data written to students.txt successfully.\n");

	file_pointer = fopen("students.txt", "r");

	if (file_pointer == NULL)
	{
		printf("Error: Unable to open file.\n");
		return 1;
	}

	char line[100];
	printf("\nContents of students.txt:\n");
	while (fgets(line, sizeof(line), file_pointer) != NULL)
		printf("%s", line);

	fclose(file_pointer);

	return 0;
}

/*
 * Output:
 * Enter the number of records: 2
 * Enter name and marks: Ravi 85
 * Enter name and marks: Sita 92
 * Data written to students.txt successfully.
 *
 * Contents of students.txt:
 * Ravi 85
 * Sita 92
 */
