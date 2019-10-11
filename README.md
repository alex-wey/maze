Instructions for use:
-
To generate a maze, type into terminal "./generator" followed by the name of the output file, the number of rows desired, and the number of columns desired.

There are two choices of solution for that maze. If the user wants the exact path from the starting points to the goal points, the PRUNED path, then type into terminal "./solver" followed by the name of the maze file, the number of rows in the maze, the number of columns in the maze, the path file, the starting row, the starting column, the goal row, and the goal column.

If the user wants the entire path that the solver took to search the maze, the FULL, then type into terminal "./solver_full" and the other following arguments for the previous solution.

Overview of design:
-
My program is mainly divided between generator.c and solver.c, both of which use functions is_in_range (determines if a room at [row][col] is a valid room within the maze), get_neighbor (returns a pointer to the room that neighbors the current room in a given direction), and initialize_maze (initializes a 2D array of maze rooms) from common.c.

The main function in generator.c takes in three parameters: file_name, num_rows, and num_cols. First, it calls initialize_maze to initialize a maze, composed of maze rooms with these necessary values: row, col, visited marker, array of connections, and a 'next' maze room. The drunken_walk function is called which steps through the maze setting openings or walls. After that, the encode_maze function will encode the each maze room into hexadecimals to be printed. Finally, the write_encoded_maze_to_file writes the encoded maze to the output file.

The main function in solver.c takes in eight parameters: file_name, num_rows, num_cols, path_file, start_row, start_col, goal_row, and goal_col. The path_file contains the solution path (either PRUNED or FULL). The start boundaries indicate where the starting point is and the goal boundaries indicate where the ending point is. First, the path_file is opened as 'sol_file'. As in generator.c, solver.c calls initialize_maze to initialize a maze. Then, read_encoded_maze_from_file will read in the encoded maze that generator.c produced, which decode_maze decodes and stores the resulting maze room data in the initialized maze. The dfs (depth-first search) algorithm is then implemented to solve the maze, printing every maze room coordinate searched to path_file. If the FULL flag is absent, the program only prints out the PRUNED path. Finally, 'sol_file' is closed.

Throughout the program, I also error check the arguments and certain functions necessary to generator.c and solver.c.
