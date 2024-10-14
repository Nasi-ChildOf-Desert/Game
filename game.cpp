#include <iostream>
#include <conio.h>
const int dimention=10;
struct Pos {
    int x;
    int y;
};

struct world {
    int map[dimention][dimention];
    Pos p;
};
void generateMap(world* world)
{
   for(int i = 0; i < dimention; i++)
   {
    for(int j = 0; j < dimention; j++)
    {
        if ((i == 0 || i == dimention -1 ) && (j >= 0 || j < dimention-1 ))
            {
                 world->map[i][j] = 1;
            }
        else if ((j == 0 || j == dimention -1 ) && (i >= 0 || i < dimention-1 ))
            {
                 world->map[i][j] = 1;
            }
       
        else if (i ==  (dimention/2)-1 && j <  (dimention/2)-1  )
            {
               world->map[i][j] = 1;
            }
         else if (i ==  (dimention/2)+2 && j >  (dimention/2)-1 )
            {
               world->map[i][j] = 1;
            }
        else{
               world->map[i][j] = 0;
            }    
       
    }
   }
}
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

void translate_user_input(world* world, char input)
{
 int new_col = world->p.x + translate_user_input_x(input);
 int new_row = world->p.y + translate_user_input_y(input);

    if (world->map[new_row][new_col]  != 1 )
        {
              world->p.x = new_col;
               world->p.y = new_row;
        }
}

char get_user_input()
{
    char a = getch();
    return a;
}

void display(world* world)
{
    system("cls");
    for (int i = 0; i < dimention ; i++)
    {
        for (int j = 0; j < dimention ; j++)
        {
            if (world->map[i][j] != 0 )
            {
                if(j == 0)
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

void render(world* world)
{
    generateMap(world);
    display(world);
    char input = get_user_input();
    translate_user_input(world, input);

}


int main()
{

    world w;
    w.p.x = 1;
    w.p.y = 1;
    while (1)
    {
        render(&w);
    }
}