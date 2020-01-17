/*
 Elhadj Diallo
 CSSE342 Major
 UWB Fall2019
*/

/*
 This program that can solve a maze: It read a file and get the input of the file, display it contains and give the path
 to the exit of the maze if there any way out or return X if no way out*/
#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include <string>
#include "Maze.h"
using namespace std;

class Creature {
// prints current location of creature, for example C(7,3)
    friend ostream &operator<<(ostream &out, const Creature &creature);
public:
    Creature();
    Creature(int startX_C, int startY_R);
    int getColunm();
    int getRow();
    //solve maze methide
    string Solve(Maze &maze);
    //return the path of the string
    string getPath();
    //return boolean success
    bool isSuccessful() const;
    //make sure we got the correct input for Creature
    void setCreature(int row, int colum);

private:
    //initialize the boolean that is making the recursion NEWS run
    bool success;
// starting the creature that we are looking for a way out
    int startX_C, startY_R;
//get the path taken by maze
    string path;
//help maze recurse north
    bool goNorth(Maze &maze);
    //help maze recurse south
    bool goSouth(Maze &maze);
    //help maze recurse east
    bool goEast(Maze &maze);
    //help maze recurse west
    bool goWest(Maze &maze);

};


#endif //ASS3_CREATURE_H
