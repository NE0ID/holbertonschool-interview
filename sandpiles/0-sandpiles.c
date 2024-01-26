#include "sandpiles.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_sum - computes the sum of sandpiles
 *
 * @grid1: first drid
 * @grid2: grid to add
 *
 * Return: nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	i = 0;

	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			grid1[i][j] += grid2[i][j];
			j++;
		}
		i++;
	}

	if (is_stable(grid1) == 1)
	{
		while (is_stable(grid1) == 1)
		{
			printf("=\n");
			print_grid(grid1);
			topple_grid(grid1);
		}
	}
}

/**
 * is_stable - check if a sandpile is stable
 *
 * @grid: grid to check
 *
 * Return: 0 if stable, 1 if not
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple_grid - topple unstable grids
 *
 * @grid1: grid to check
 *
 * Return: nothing
 */
void topple_grid(int grid1[3][3])
{
	int i, j;

	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				grid1[i][j] -= 4;
				if ((i + 1) < 3)
					grid1[i + 1][j] += 1;
				if ((i - 1) >= 0)
					grid1[i - 1][j] += 1;
				if ((j + 1) < 3)
					grid1[i][j + 1] += 1;
				if ((j - 1) >= 0)
					grid1[i][j - 1] += 1;
			}
		}
	}
}
