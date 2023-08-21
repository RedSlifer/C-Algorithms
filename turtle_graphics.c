#include <stdio.h>

enum orientation {RIGHT, LEFT, UP, DOWN};
enum pen_state {PEN_UP, PEN_DOWN};

int main() {
    int board[50][50] = {0};
    char input[5] = "";
    int command_0, command_1, row = 0, column = 0;
    enum orientation orientation = RIGHT;
    enum pen_state pen_state = PEN_UP;

    while (1) {
        scanf("%4s", input);
        sscanf(input, "%d,%d", &command_0, &command_1);

        if (command_1 != 0) {
            switch (orientation) {
                case RIGHT:
                    if (pen_state == PEN_DOWN) {
                        if (column + command_1 <= 50) {
                            for (int j = column; j <= column + command_1; j++)
                                board[row][j] = 1;

                            column +=command_1;
                        }
                    }
                    else {
                        if (column + command_1 <= 50)
                            column +=command_1;
                    }
                    break;

                case LEFT:
                    if (pen_state == PEN_DOWN) {
                        if (column - command_1 >= 0) {
                            for (int j = column; j >= column - command_1; j--)
                                board[row][j] = 1;

                            column -= command_1;
                        }
                    }
                    else {
                        if (column - command_1 >= 0)
                            column -= command_1;
                    }
                    break;

                case DOWN:
                    if (pen_state == PEN_DOWN) {
                        if (row + command_1 <= 50) {
                            for (int i = row; i <= row + command_1; i++)
                                board[i][column] = 1;

                            row +=command_1;
                        }
                    }
                    else {
                        if (row + command_1 <= 50)
                            row +=command_1;
                    }
                    break;

                case UP:
                    if (pen_state == PEN_DOWN) {
                        if (row - command_1 >= 0) {
                            for (int i = row; i >= row - command_1; i--)
                                board[i][column] = 1;

                            row -= command_1;
                        }
                    }
                    else {
                        if (row - command_1 >= 0)
                            row -= command_1;
                    }
                    break;
            }
        }
        else {
            if (command_0 == 9)
                break;
            else if (command_0 == 6) {
                for (size_t i = 0; i < 50; i++) {
                    for (size_t j = 0; j < 50; j++) {
                        printf("%d ", board[i][j]);
                    }
                    printf("\n");
                }
                printf("%d,%d\n", row, column);
            }
            else {
                switch (command_0) {
                    case 1:
                        pen_state = PEN_UP;
                        break;
                    case 2:
                        pen_state = PEN_DOWN;
                        break;
                    case 3:
                        if (orientation == RIGHT)
                            orientation = DOWN;
                        else if (orientation == LEFT)
                            orientation = UP;
                        else if (orientation == UP)
                            orientation = RIGHT;
                        else
                            orientation = LEFT;

                        break;
                    case 4:
                        if (orientation == RIGHT)
                            orientation = UP;
                        else if (orientation == LEFT)
                            orientation = DOWN;
                        else if (orientation == UP)
                            orientation = LEFT;
                        else
                            orientation = RIGHT;

                        break;

                    default:
                        printf("Invalid Command!\n");
                        goto error;
                }
            }
        }
    }

    error:

    return 0;
}
