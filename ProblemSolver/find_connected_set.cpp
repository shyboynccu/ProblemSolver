/*
Given a 2–d matrix , which has only 1’s and 0’s in it. Find the total number of connected sets in that matrix.
 
 
Explanation:
Connected set can be defined as group of cell(s) which has 1 mentioned on it and have at least one other cell in that set with which they share the neighbor relationship. A cell with 1 in it and no surrounding neighbor having 1 in it can be considered as a set with one cell in it. Neighbors can be defined as all the cells adjacent to the given cell in 8 possible directions ( i.e N , W , E , S , NE , NW , SE , SW direction ). A cell is not a neighbor of itself.
 
 
Input format :
 
First line of the input contains T , number of test-cases.
Then follow T testcases. Each testcase has given format.
N [ representing the dimension of the matrix N X N ].
Followed by N lines , with N numbers on each line.
 
 
 
Ouput format :
 
For each test case print one line ,  number of connected component it has.
 
Sample Input :
 
4
4
0 0 1 0
1 0 1 0
0 1 0 0
1 1 1 1
4
1 0 0 1
0 0 0 0
0 1 1 0
1 0 0 1
5
1 0 0 1 1
0 0 1 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
8
0 0 1 0 0 1 0 0
1 0 0 0 0 0 0 1
0 0 1 0 0 1 0 1
0 1 0 0 0 1 0 0
1 0 0 0 0 0 0 0
0 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
0 0 0 0 0 0 0 0
 
Sample output :
 
1
3
3
9
 
Constraint :
 
0 < T < 6 
0 < N < 1009 
*/
#include <iostream>
#include <string>

using namespace std;
void free_matrix(char** p, int dimension)
{
	if (p)
	{
		for (int i=0; i<dimension; i++)
		{
			if (p[i])
			{
				delete p[i];
			}
		}
		delete p;
	}
}

void free_matrix_cases(char*** p, int case_number, int dimension[])
{
	if (p)
	{
		for (int i=0; i<case_number; i++)
		{
			free_matrix(p[i], dimension[i]);
		}
		delete p;
	}
}

char*** read_matrix_cases(int& num_cases, int*& dimension_list)
{	
	cin >> num_cases;
	char*** cases = new char**[num_cases];
	dimension_list = new int[num_cases];

	for (int i=0; i<num_cases; i++)
	{
		int dimension = 0;
		cin >> dimension;
		dimension_list[i] = dimension;
		char** matrix = new char*[dimension];
		cases[i] = matrix;

		for (int j=0; j<dimension; j++)
		{
			char* row = new char[dimension];
			for (int k=0; k<dimension; k++)
			{
				cin >> row[k];
			}
			matrix[j] = row;
		}
	}

	return cases;
}

void zero_out_neighbors(char** matrix, int dimension, int x, int y)
{
	for (int i=x-1; i<=x+1; i++)
	{
		if (i < 0 || i >= dimension)
		{
			continue;
		}
		for (int j=y-1; j<=y+1; j++)
		{
			if (j < 0 || j >= dimension)
			{
				continue;
			}

			//printf("See %d, %d\n", i, j);
			if (matrix[i][j] == '1')
			{
				//printf("(%d, %d) is 1\n", i, j);
				matrix[i][j] = '0';
				zero_out_neighbors(matrix, dimension, i, j);
			}
		}
	}
}

int find_connected_set(char** matrix, int dimension)
{
	int count = 0;
	for (int i=0; i<dimension; i++)
	{
		for (int j=0; j<dimension; j++)
		{
			if (matrix[i][j] == '1')
			{
				//printf("Find (%d, %d) is 1\n", i, j);
				
				++count;
				zero_out_neighbors(matrix, dimension, i, j);
			}
		}
	}
	return count;
}

int solve_find_connected_set(void)
{
	int case_number;
	int* dimension_list;
	char*** cases = read_matrix_cases(case_number, dimension_list);
	//printf("Number of cases = %d\n", case_number);
	
	int answer = 0;
	for (int i=0; i<case_number; i++)
	{
		answer = find_connected_set(cases[i], dimension_list[i]);
		printf("%d\n", answer);
	}
	free_matrix_cases(cases, case_number, dimension_list);

	return 0;
}