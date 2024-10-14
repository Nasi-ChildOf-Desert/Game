#include <iostream>
#include <conio.h>

struct Pos {
    int x;
    int y;
};

struct world {
    int x_size;
    int y_size;
    Pos p;
};

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
    int new_x = world->p.x + translate_user_input_x(input);
    if (new_x < world->x_size && new_x >= 0)
    { world->p.x = new_x;}
       
      if (new_x < 0)
        {
              world->p.x = 0;
        }
              if (new_x > world->x_size)
        {
              world->p.x = world->x_size;
        }


    int new_y = world->p.y + translate_user_input_y(input);
    if (new_y < world->y_size && new_y >= 0)
        world->p.y = new_y;
         if (new_y < 0)
        {
              world->p.y = 0;
        }
              if (new_y > world->y_size)
        {
              world->p.y = world->y_size;
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
    for (int i = -1; i < world->y_size + 1; i++)
    {
        for (int j = -1; j < world->x_size + 1; j++)
        {
            if (i == -1 || i == world->y_size)
            {
                if(j == -1)
                std::cout << "#";
                else 
                    std::cout << " #";
            }
            else if (j == -1 || j == world->x_size)
            {

                if (j == -1)
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
    display(world);
    char input = get_user_input();
    translate_user_input(world, input);

}


int main()
{

    world w;
    w.x_size = 10;
    w.y_size = 10;
    w.p.x = 0;
    w.p.y = 0;
    while (1)
    {
        render(&w);
    }
}
