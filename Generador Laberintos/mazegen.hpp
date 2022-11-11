#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ofstream;
using std::cout;

namespace MazeGenerator {
    const int MAZE_WALL = 1;
    enum { North, East, South, West };
    struct Coord {
        int x, y;
        int prev_dir{-1};
    };

    int min(int x, int y) { return x < y ? x : y; }
    int max(int x, int y) { return x > y ? x : y; }

    void randomize(int* array, int n) {
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1); //[0,i]
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }

    bool isValidPosition(Coord c, int height, int width) {
        // Do not consider maze borders
        return c.x >= 1 && c.y >= 1 && c.x < height - 1 && c.y < width - 1;
    }

    void removeWall(int** maze, Coord c, int height_char, int width_char) {
        for (int i = 0; i < height_char; ++i) {
            for (int j = 0; j < width_char; ++j) {
                maze[c.x + i][c.y + j] = 0;
            }
        }
    }

    void copyRow(int** maze, int row_src, int row_dst, int width) {
        for (int j = 0; j < width; ++j)
            maze[row_dst][j] = maze[row_src][j];
    }

    void copyCol(int** maze, int col_src, int col_dst, int height) {
        for (int i = 0; i < height; ++i)
            maze[i][col_dst] = maze[i][col_src];
    }

    void copyValidRowsAndCols(int** maze, int height, int width) {
        // copy last valid row
        int i = height - 2;
        while (i >= 0 && maze[i][1] == MAZE_WALL) --i;

        while (i < height - 2) {
            copyRow(maze, i, i + 1, width);
            i++;
        }

        // copy last valid column
        int j = width - 2;
        while (j >= 0 && maze[1][j] == MAZE_WALL) --j;

        while (j < width - 2) {
            copyCol(maze, j, j + 1, height);
            j++;
        }
    }

    int** generateMaze(int height, int width, int cell_height = 1, int cell_width = 1, bool copy = true) {
        /*
            Maze generator based on specified width and height, as well as the size of empty cells
            The size of the walls will always be 1

            Parameters:
                - height: maze height
                - width: maze width
                - cell_height: empty cell height
                - cell_width: empty cell width
                - copy: whether to copy last valid rows/cols or not

            Return:
                - maze: generated maze with 0's (empty) and 1's (wall)

            *Algorithm: Iterative DFS with implicit graph
        */
        int** maze = new int* [height];
        for (int i = 0; i < height; ++i) {
            maze[i] = new int[width];
            for (int j = 0; j < width; ++j) {
                maze[i][j] = MAZE_WALL;
            }
        }

        int V = height * width;
        Coord* stack = new Coord[V];
        int sz{0}, xoffset{1 + cell_height}, yoffset{1 + cell_width};
        Coord start = { 1, 1 };
        stack[sz++] = { start };
        int directions[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; //N, E, S, W
        int wall_sz[4][2] = { {1,cell_width}, {cell_height,1}, {1,cell_width}, {cell_height,1} };

        while (sz) {
            Coord cur = stack[--sz];
            int x = cur.x, y = cur.y;
            if (maze[x][y] != MAZE_WALL) continue;

            if (cur.prev_dir != -1) {
                // Remove wall between two valid positions
                int dx = directions[cur.prev_dir][0], dy = directions[cur.prev_dir][1];
                if (cur.prev_dir == West || cur.prev_dir == North) {
                    dx *= (xoffset - 1);
                    dy *= (yoffset - 1);
                }
                removeWall(maze, {x - dx, y - dy}, wall_sz[cur.prev_dir][0], wall_sz[cur.prev_dir][1]);
            }
            removeWall(maze, cur, cell_height, cell_width);

            int idx[4] = { North, East, South, West };
            randomize(idx, 4);
            for (int k = 0; k < 4; ++k) {
                int dx = directions[idx[k]][0], dy = directions[idx[k]][1];
                int nx = x + xoffset * dx, ny = y + yoffset * dy;

                // Considering empty cell size
                Coord ul, lr;
                ul = { min(x, nx), min(y, ny) };
                lr = { max(x, nx) + cell_height - 1, max(y, ny) + cell_width - 1 };

                if (isValidPosition(ul, height, width) &&
                    isValidPosition(lr, height, width) &&
                    maze[nx][ny] == MAZE_WALL) {
                    stack[sz++] = { nx, ny, idx[k] };
                }
            }
        }

        if (copy) {
            copyValidRowsAndCols(maze, height, width);
        }

        delete[] stack;
        return maze;
    }

    void recommendSizes(int cell_height, int cell_width, int limit = 10) {
        /*
            To have a exact maze the height and width size should be -> 1 + (x + 1) * k
            where k is a constant greater than 1 and x is the height and width of an empty cell
        */
        cout << "Recommended sizes\n";
        cout << "-----------------";
        cout << "\nRecommended heights:";
        for (int i = 1; i <= limit; ++i) {
            cout << " " << 1 + (cell_height + 1) * i;
        }
        cout << "\nRecommended widths: ";
        for (int i = 1; i <= limit; ++i) {
            cout << " " << 1 + (cell_width + 1) * i;
        }
        cout << "\n\nYou can consider any combination of height and width";
    }

    enum Format {
        CSV,
        MATRIX
    };

    void exportMaze(int** maze, int height, int width, int format = CSV, string name = "maze", string path = "./") {
        // Export maze in CSV or Matrix format
        string extension = ".csv";
        if (format == MATRIX) extension = ".txt";
        ofstream fout(path + name + extension);
        if (fout.is_open()) {
            if (format == MATRIX) fout << "{";
            for (int i = 0; i < height; ++i) {
                if (format == MATRIX) fout << "{";
                fout << maze[i][0];
                for (int j = 1; j < width; ++j) {
                    fout << "," << maze[i][j];
                }
                if (format == MATRIX) {
                    fout << "}";
                    fout << (i == height - 1 ? "};" : ",");
                }
                fout << "\n";
            }
            fout.close();
            cout << "Successfully exported\n";
        }
        else {
            cout << "Unable to open file\n";
        }
    }
}