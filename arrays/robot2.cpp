// Copy-right Madalina-Valentina Zanficu C++
#include <iostream>
#include <vector>
#include <cmath>

char direction;
float max_distance = 0;

// The origin will be centered in 5000 on Ox and 5000 on Oy
int x_origin = 5000;
int y_origin = 5000;

// The obstacles will be marked in the matrix
int matrix[10000][10000];


void read_obstacles(int nr_obstacles) {
    for (int i = 0; i < nr_obstacles; i++) {
        int a, b;

        // read and mark the obstacles
        std::cin >> a >> b;
        matrix[a + x_origin][b + y_origin] = 2;
    }
}

// Compute the distance from the current position (x, y) to the origin
void distance_origin(int x, int y) {
    int x2 = (x - x_origin) * (x - x_origin);
    int y2 = (y - y_origin) * (y - y_origin);
    float distance = sqrt(x2 + y2);

    // Keep track of the maximum distance
    if (distance > max_distance) {
        max_distance = distance;
    }
}

// Execute all the commands requested
void execute_command(int &current_x, int &current_y, int steps) {
    int x = current_x, y = current_y;
    for (int i = 0; i < steps; i++) {

        // Change the coordinates of the robot based on the direction
        if (direction == 'N') {
            y++;
        }
        if (direction == 'S') {
            y--;
        }
        if (direction == 'E') {
            x++;
        }
        if (direction == 'W') {
            x--;
        }

        // In case there is an obstacle, stop the robot and keep the original position
        if (matrix[x][y] == 2) {
            break;
        } else {

            // Change the current position
            current_x = x;
            current_y = y;

            // Compute the distance to the current position to the origin
            distance_origin(current_x, current_y);
        }
    }
}

void read_commands(int nr_commands, int &current_x, int &current_y) {
    for (int i = 0; i < nr_commands; i++) {
        int steps;
        char buff;

        std::cin >> buff;
        if (buff == 'M') {

            // Read the number of steps for the current command and execute it
            std::cin >> steps;
            execute_command(current_x, current_y, steps);
        }

         // Change the direction of the robot based on the previous direction
        if (buff == 'L') {
            if (direction == 'N') {
                direction = 'W';
            }
            else if (direction == 'S') {
                direction = 'E';
            }
            else if (direction == 'E') {
                direction = 'N';
            }
            else if (direction == 'W') {
                direction = 'S';   
            }
        }
        if (buff == 'R') {
            if (direction == 'N') {
                direction = 'E';
            }
            else if (direction == 'S') {
                direction = 'W';
            }
            else if (direction == 'E') {
                direction = 'S';
            }
            else if (direction == 'W') {
                direction = 'N';
            }
        }
    }
}

int main() {

    // starting point of the robot
    int x, y;
    std::cin >> x >> y >> direction;

    // centering the initial position
    x += x_origin;
    y += y_origin;

    // compute the distance to the origin from the starting point
    distance_origin(x, y);


    // read the numer of obstacles and the number of commands
    int nr_obstacles, nr_commands;
    std::cin >> nr_obstacles >> nr_commands;

    read_obstacles(nr_obstacles);
    read_commands(nr_commands, x, y);

    // the maximum distance obtained
    std::cout << max_distance << std::endl;
    return 0;
}