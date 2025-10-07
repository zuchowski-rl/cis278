// recursively solving a maze using an algorithm that follows the right wall

#include <iostream> // allow access to input/output streams

// constants for the maze array bounds
const int ROWS = 11;
const int COLS = 13;

//  function for displaying a maze
void print_maze(const char maze[ROWS][COLS]) {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            std::cout << maze[row][col];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

// manage the facing direction
enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

Direction rotate_right(Direction direction) {
    return static_cast<Direction>((direction + 1) % 4);
}

Direction rotate_left(Direction direction) {
    return static_cast<Direction>((direction + 3) % 4);
}

// map direction to symbol for display in the console
char direction_symbol(Direction direction) {
    switch (direction) {
        case NORTH:
            return '^'; // up
        case EAST:
            return '>'; // right
        case SOUTH:
            return 'v'; // down
        case WEST:
            return '<'; // left
        default:
            return 'X';
    }
}

// recursive function to sovle maze
bool maze_traverse(char maze[ROWS][COLS], int location_row, int location_col,
                   Direction direction) {

    // base cases
    if (location_col == 0 && direction == WEST) {
        return true; // exiting west
    }
    if (location_col == COLS - 1 && direction == EAST) {
        return true; // exiting east
    }
    if (location_row == 0 && direction == NORTH) {
        return true; // exiting north
    }
    if (location_col == ROWS && direction == SOUTH) {
        return true; // exiting south
    }

    // variables for the indices of the target path
    int target_row{0};
    int target_col{0};

    // identify target location based on current facing direction
    switch (direction) {
        case EAST:
            target_row = location_row;
            target_col = location_col + 1;
            break;
        case SOUTH:
            target_row = location_row + 1;
            target_col = location_col;
            break;
        case WEST:
            target_row = location_row;
            target_col = location_col - 1;
            break;
        case NORTH:
            target_row = location_row - 1;
            target_col = location_col;
            break;
    }

    // check target location is a path
    if (maze[target_row][target_col] == '.') {
        // move to target location
        maze[location_row][location_col] = '.';
        location_row = target_row;
        location_col = target_col;
        // draw direction symbol at new location and display maze
        maze[location_row][location_col] = direction_symbol(direction);
        print_maze(maze);
        // identify right side of new location for pathfinding
        direction = rotate_right(direction);
    } else {
        // update direction for new target path
        direction = rotate_left(direction);
    }

    // recursive call with new state
    return maze_traverse(maze, location_row, location_col, direction);
}

int main() {

    // initialize maze
    // built in array representing the maze
    char maze[ROWS][COLS] = {"############", "#...#......#", "..#.#.####.#",
                             "#....###.#..", "####.#.#.#.#", "#..#.#.#.#.#",
                             "##.#.#.#.#.#", "#........#.#", "######.###.#",
                             "#......#...#", "############"};

    // starting position at entrance
    const int starting_row{2};
    const int starting_col{0};
    const Direction starting_direction{EAST};

    maze[starting_row][starting_col] = direction_symbol(starting_direction);

    // display starting state
    print_maze(maze);

    maze_traverse(maze, starting_row, starting_col, starting_direction);
}
