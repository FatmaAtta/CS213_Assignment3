// File name: A3_SheetPb06_20220834.cpp
// Purpose: game of life
// Author(s): muntasir gaafar
// ID(s): 20220834
// Section: S10
// Date: December 6 2023
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Define the size of the grid
const int ROWS = 20;
const int COLS = 50;

// Define the symbols for dead and alive cells
const char DEAD = '.';
const char ALIVE = 'O';

// Define a class called Universe
class Universe {
    private:
        // A 2D vector to store the current state of the grid
        vector<vector<char>> grid;

        // A 2D vector to store the next state of the grid
        vector<vector<char>> next_grid;

        // A function to generate a random layout
        void generate_layout() {
            // Initialize the random seed
            srand(time(NULL));

            // Loop through the grid and assign a random state to each cell
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    // Generate a random number between 0 and 1
                    int random = rand() % 2;

                    // If the random number is 0, set the cell as dead
                    if (random == 0) {
                        grid[i][j] = DEAD;
                    }

                    // If the random number is 1, set the cell as alive
                    else {
                        grid[i][j] = ALIVE;
                    }
                }
            }
        }

        // A function to count the number of alive neighbors of a given cell
        int count_neighbors(int row, int col) {
            // Initialize the count as 0
            int count = 0;

            // Loop through the adjacent cells
            for (int i = row - 1; i <= row + 1; i++) {
                for (int j = col - 1; j <= col + 1; j++) {
                    // Skip the cell itself
                    if (i == row && j == col) {
                        continue;
                    }

                    // Check the boundaries of the grid
                    if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                        // If the cell is alive, increment the count
                        if (grid[i][j] == ALIVE) {
                            count++;
                        }
                    }
                }
            }

            // Return the count
            return count;
        }

    public:
        // A constructor that initializes the grid and the next grid
        Universe() {
            // Resize the grid and the next grid to match the size
            grid.resize(ROWS, vector<char>(COLS));
            next_grid.resize(ROWS, vector<char>(COLS));

            // Generate a random layout for the grid
            generate_layout();
        }

        // A function to reset the grid and set all the cells as dead
        void reset() {
            // Loop through the grid and set each cell as dead
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    grid[i][j] = DEAD;
                }
            }
        }

        // A function to produce the next generation of the grid based on the transition rules
        void next_generation() {
            // Loop through the grid and apply the rules to each cell
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    // Get the current state of the cell
                    char state = grid[i][j];

                    // Get the number of alive neighbors of the cell
                    int neighbors = count_neighbors(i, j);

                    // Apply the rules based on the state and the neighbors
                    // Any live cell with fewer than two live neighbors dies, as if caused by underpopulation
                    if (state == ALIVE && neighbors < 2) {
                        next_grid[i][j] = DEAD;
                    }

                    // Any live cell with two or three live neighbors lives on to the next generation
                    else if (state == ALIVE && (neighbors == 2 || neighbors == 3)) {
                        next_grid[i][j] = ALIVE;
                    }

                    // Any live cell with more than three live neighbors dies, as if by overpopulation
                    else if (state == ALIVE && neighbors > 3) {
                        next_grid[i][j] = DEAD;
                    }

                    // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction
                    else if (state == DEAD && neighbors == 3) {
                        next_grid[i][j] = ALIVE;
                    }

                    // Otherwise, the cell remains the same
                    else {
                        next_grid[i][j] = state;
                    }
                }
            }

            // Copy the next grid to the current grid
            grid = next_grid;
        }

        // A function to display the grid on the console
        void display() {
            // Clear the console
            system("cls");

            // Loop through the grid and print each cell
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
        }

        // A function to run the game for a certain number of iterations
        void run(int iterations) {
            // Loop through the iterations
            for (int i = 0; i < iterations; i++) {
                // Display the current state of the grid
                display();

                // Produce the next generation of the grid
                next_generation();

                // Wait for 1 second
                system("timeout 1 >nul");
            }
        }
};

// The main function
int main() {
    // Create an object of the Universe class
    Universe u;

    // Run the game for 100 iterations
    u.run(50);

    // Return 0
    return 0;
}
