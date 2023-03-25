// don't try this in C#
// by3 is where the array by array by array idea sparkles
// suppose you'd like to track months worth of stuff for a few years for a bunch of things
#include <iostream>

int x;
int y;
int z;

struct xtimeframe              // things to keep track of  - could be many things and different types of things
{
    int xtime;
    char xframe;
};

struct yevents
{
    int id;                    // another thing to keep track of  - could be many things and different types of things
    xtimeframe xy_array[5];
};

struct zdetail
{
    int post;                 // another thing to keep track of - could be many things and different types of things
    yevents xyz_array[5];
};

zdetail zevents_array[5];     // so here we have an array of arrays of arrays with little extras to go along

int main()
{
    x = 0;
    y = 0;
    z = 0;

// let's initialize
//  so we move from the inside towards the outside - always starting at the first entry
    for (x = 0; x < 5; x++)
    {
        zevents_array[0].xyz_array[0].xy_array[x].xtime = 0;
        zevents_array[0].xyz_array[0].xy_array[x].xframe = 'A';
    }
//  next we move outwards to the next level
    zevents_array[0].xyz_array[0].id = 0; //initialize

    for (y = 1; y < 5; y++) //initialize the rest to the first
    {
        zevents_array[0].xyz_array[y] = zevents_array[0].xyz_array[0];
        zevents_array[0].xyz_array[y].id = y;
    }
//  keep moving outwards
    zevents_array[0].post = 0;

    for (z = 1; z < 5; z++)  // initialize the rest to the first
    {
        zevents_array[z] = zevents_array[0];
        zevents_array[z].post = z;
    }
//  so we have initialized a 5 x 5 x 5 (125)) element array with 14 assignments (5 + 4 + 4)
//  had the array been 500x500x500 that would be 125,000,000 versus 500 + 499 + 499 = 1,498 - there is a massive difference

// lets prove that this really works
    std::cout << "Before " <<std:: endl;

    for (z = 0; z < 5; z++)
    {
        std::cout << " post " << zevents_array[z].post << std::endl;
        for (y = 0; y < 5; y++)
        {
            std::cout << " id " << zevents_array[z].xyz_array[y].id;
            for (x = 0; x < 5; x++)
            {
                std::cout << " t " << zevents_array[z].xyz_array[y].xy_array[x].xtime
                          << " f " << zevents_array[z].xyz_array[y].xy_array[x].xframe;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    zevents_array[0].post = 8;

    zevents_array[0].xyz_array[0].id = 8;

    zevents_array[0].xyz_array[0].xy_array[0].xtime = 8;

    zevents_array[0].xyz_array[0].xy_array[0].xframe = 'B';

    std::cout << "After " << std::endl;

    for (z = 0; z < 5; z++)
    {
        std::cout << " post " << zevents_array[z].post << std::endl;
        for (y = 0; y < 5; y++)
        {
            std::cout << " id " << zevents_array[z].xyz_array[y].id ;
            for (x = 0; x < 5; x++)
            {
                std::cout << " t " << zevents_array[z].xyz_array[y].xy_array[x].xtime
                          << " f " << zevents_array[z].xyz_array[y].xy_array[x].xframe;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cin >> x;

    return 0;
}
// as for the result - oh - how pretty - beautiful even
