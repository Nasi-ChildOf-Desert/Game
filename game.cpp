#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256

struct Pos
{
    int x;
    int y;
};

//*****************************************************************//
struct world
{
    int mapSize;
    int **userMap = nullptr;
    Pos p;
};

//*****************************************************************//
void getMapFile(world *world, const char *filepath)
{
    char buffer[BUFFER_SIZE];
    char *line;
    char *token;
    const char *delimiter = ",";
    const char *breaks = " ";

    FILE *fstream = fopen(filepath, "r");
    if (fstream == NULL)
    {
        printf("\nFile opening failed");
    }
    line = fgets(buffer, sizeof(buffer), fstream);
    if (line != NULL)
    {
        char *mapDimension = strtok(line, breaks);
        world->mapSize = atoi(mapDimension);

        world->userMap = (int **)malloc(world->mapSize * sizeof(int *));
        for (int i = 0; i < world->mapSize; i++)
        {
            world->userMap[i] = (int *)malloc(world->mapSize * sizeof(int));
        }
if ( world->userMap != NULL) {
        int row_count = 0;
        while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL)
        {
            printf("\nline = %s", line);
            int col_count = 0;
            token = strtok(line, delimiter);
            while (token != NULL && col_count < world->mapSize)
            {
                world->userMap[row_count][col_count] = atoi(token);
                col_count++;
                token = strtok(NULL, delimiter);
            }
            row_count++;
        }

        fclose(fstream);
    }}
}

//*****************************************************************//
int translate_user_input_x(char input)
{
    if (input == 'd')
    {
        return 1;
    }
    else if (input == 'a')
    {
        return -1;
    }
    return 0;
}

//*****************************************************************//
int translate_user_input_y(char input)
{
    if (input == 'w')
    {
        return -1;
    }
    else if (input == 's')
    {
        return 1;
    }

    return 0;
}

//*****************************************************************//
void translate_user_input(world *world, char input)
{
    int new_col = world->p.x + translate_user_input_x(input);
    int new_row = world->p.y + translate_user_input_y(input);

    if (world->userMap[new_row][new_col] != 1)
    {
        world->p.x = new_col;
        world->p.y = new_row;
    }
}

//*****************************************************************//
char get_user_input()
{
    char a = getch();
    return a;
}

//*****************************************************************//
void display(world *world, int mapsize)
{
    int dimention = mapsize;
    system("cls");
    for (int i = 0; i < dimention; i++)
    {
        for (int j = 0; j < dimention; j++)
        {
            if (world->userMap[i][j] != 0)
            {
                if (j == 0)
                    std::cout << "#";
                else
                    std::cout << " #";
            }

            else if (i == world->p.y && j == world->p.x)
            {
                std::cout << " *";
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

//*****************************************************************//
void render(world *world)
{
    
    display(world, world->mapSize);
    char input = get_user_input();
    translate_user_input(world, input);
}

//*****************************************************************//
int main()
{
    world w;
    w.p.x = 1;
    w.p.y = 1;
    const char *path = "test.txt";

    getMapFile(&w, path);
    while (1)
    {
        render(&w);
    }
    for (int i = 0; i < w.mapSize; i++)
    {
        free(w.userMap[i]);
    }
    free(w.userMap);
}
