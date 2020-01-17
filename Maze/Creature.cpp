/*
 Elhadj Diallo
 CSSE342 Major
 UWB Fall2019
*/

/*
 This program that can solve a maze: It read a file and get the input of the file, display it contains and give the path
 to the exit of the maze if there any way out or return X if no way out*/
#include "Creature.h"

//default constructor
Creature::Creature() {
    startX_C =0;
    startY_R =0;
    path = "";
    this->success = false;
}

void Creature::setCreature(int row, int colum){
    if(startX_C < 0 || startX_C > 100 || startY_R <0 || startY_R>100){
         //should return nothing empthy ""

    }
        this->startY_R = row;
        this->startX_C= colum;

}
//not colum = startX_C and row =startY_R
Creature::Creature(int startX_C, int startY_R){
    setCreature( startY_R, startX_C);

}

//get the ciolum coordinate
int Creature::getColunm() {
    return startX_C;
}

//get the row coordonate
int Creature::getRow() {
    return startY_R;
}

//------------------------------------------------------------------------------
//prints current location of creature, for example C(7,3)
ostream &operator<<(ostream &out, const Creature &creature){
    out << "C(" << creature.startY_R << "," << creature.startX_C << ")";
    return out;
}

//get the path of the string
string Creature::getPath(){
    return path;
}

//check if success to move around the maze
bool Creature::isSuccessful() const {
    return success;
}

//solve methode helping us to solve the maze
string Creature::Solve(Maze &maze){
    if(startY_R == maze.getExitRow() && startX_C == maze.getExitColum()){
        path = "Maze at exit";
        maze.MarkAsVisited(startY_R, startX_C);
        return path;
    }
    else {
        //success = true;
        if (goNorth(maze)) {
            return path;
        } else {
            path = "X";
            return path;
        }
    }
}


//goNorth() function
//return true if path to the north, false otherwise
bool Creature::goNorth(Maze &maze) {
    if((maze.IsClear(startY_R-1, startX_C ) == true ||  maze.IsPath(startY_R-1, startX_C)==true)
    && startY_R-1 >= 0 && startX_C>=0)
    {
        startY_R --;
        path += "N";
        maze.MarkAsPath(startY_R, startX_C);
        if(startY_R == maze.getExitRow() && startX_C == maze.getExitColum()){
            success = true;
        }
        else{
            success = goNorth(maze);
            if(!success){
                success = goWest(maze);
                if(!success){
                    success = goEast(maze);
                    if(!success){
                        path = "";
                        maze.MarkAsVisited(startY_R, startX_C );
                        goSouth(maze);
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}

//moving west function
//return true find path moving to the west, false otherwise
bool Creature::goWest(Maze &maze) {
    if((maze.IsClear(startY_R,startX_C-1) == true || maze.IsPath(startY_R ,startX_C-1 ) == true)
       && startX_C-1 >= 0 && startY_R>=0)
    {
        //move west
        startX_C--;
        path += "W";
        //mark as path
        maze.MarkAsPath(startY_R, startX_C);
        if(startY_R == maze.getExitRow() && startX_C == maze.getExitColum()) {
            success = true;
        }else
        {
            success = goNorth(maze);
            if(!success){
                success = goWest(maze);
                if(!success){
                    success = goSouth(maze);
                    if(!success){
                        path = "";
                        maze.MarkAsVisited(startY_R, startX_C);
                        goEast(maze);
                    }
                }
            }
        }

    }
    else{
        success = false;
    }
    return success;
}

//true if find path to the east if possible, false otherwise
bool Creature::goEast(Maze &maze) {
    if((maze.IsClear(startY_R,startX_C+1) == true  || maze.IsPath (startY_R, startX_C+1)==true)
       && startX_C+1 <= maze.getWidth_of_maze() && startY_R>=0)
    {
        //move east
        startX_C++;
        path+= "E";
        maze.MarkAsPath(startY_R, startX_C);
        if(startY_R == maze.getExitRow() && startX_C == maze.getExitColum()){
            success = true;
        }
        else{
            success = goNorth(maze);
            if(!success){
                success = goEast(maze);
                if(!success){
                    success = goSouth(maze);
                    if(!success){
                        path = "";
                        maze.MarkAsVisited(startY_R, startX_C);
                        goWest(maze);
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}


//moving south to the same colum
//return true if path found to the south, false otherwise
bool Creature::goSouth(Maze &maze) {
    if((maze.IsClear(startY_R + 1,startX_C) == true  || maze.IsPath(startY_R + 1,startX_C ) == true)
    && startY_R + 1 <= maze.getHeigth_of_maze() && startX_C>=0)
      {
        //move south
        startY_R ++;
        path += "S";
        //mark as part of the path
        maze.MarkAsPath(startY_R,startX_C );
        if(startX_C == maze.getExitColum() && startY_R == maze.getExitRow()){
            success = true;
        }
        else{
            success = goWest(maze);
            if(!success)
            {
                success = goSouth(maze);
                if(!success){
                    success = goEast(maze);
                    if(!success){
                        path = "";
                        maze.MarkAsVisited( startY_R,startX_C);
                        goNorth(maze);
                    }
                }
            }
        }
    }
    else
    {
        success = false;
    }
    return success;
}

