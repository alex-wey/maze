#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

/*
 * Determines whether or not the room at [row][col] is a valid room within the
 * maze with dimensions num_rows x num_cols
 *
 * Parameters:
 *	- row: row of the current room
 *	- col: column of the current room
 *	- num_rows: number of rows in the maze
 *	- num_cols: number of columns in the maze
 *
 * Returns:
 *	- 0 if room is not in the maze, 1 if room is in the maze
 */
int is_in_range(int row, int col, int num_rows, int num_cols) {
    if ((num_rows > row) && (row >= 0) && (num_cols > col) && (col >= 0))
        return 1;
    else
        return 0;
}

/*
 * Given a pointer to the room and a Direction to travel in, return a pointer to
 * the room that neighbors the current room on the given Direction. For example:
 * get_neighbor(&maze[3][4], EAST) should return &maze[3][5]
 *
 * Parameters:
 *	- num_rows: number of rows in the maze
 *	- num_cols: number of columns in the maze
 *	- room: pointer to the current room
 *	- dir: Direction to get the neighbor from
 *	- maze: a 2D array of maze_room structs representing your maze
 * Returns:
 *	- pointer to the neighboring room
 */
struct maze_room *get_neighbor(int num_rows, int num_cols,
                               struct maze_room maze[num_rows][num_cols],
                               struct maze_room *room, Direction dir) {
    int r = room->row;
    int c = room->col;
    if (dir == NORTH) r -= 1;
    if (dir == SOUTH) r += 1;
    if (dir == WEST) c -= 1;
    if (dir == EAST) c += 1;
    if (is_in_range(r, c, num_rows, num_cols))
        return &maze[r][c];
    else
        return NULL;
}

/*
 * Initializes a 2D array of maze rooms with all of the necessary values
 *
 * Parameters:
 *	- num_rows: the number of the rows in the maze
 *	- num_cols: the number of columns in the maze
 *	- maze: a 2D array of uninitialized maze_rooms (to be initialized in
 *          this function)
 *
 * Returns:
 *	- nothing (the initialized maze will be stored in the 'maze' array)
 */
void initialize_maze(int num_rows, int num_cols,
                     struct maze_room maze[num_rows][num_cols]) {
    int i, j;
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            struct maze_room m;
            int k;
            m.row = i;
            m.col = j;
            m.visited = 0;
            for (k = 0; k < 4; k++) {
                m.con[k] = -1;
            }
            m.next = NULL;
            maze[i][j] = m;
        }
    }
}
