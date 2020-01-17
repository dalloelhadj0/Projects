/*
 Elhadj Diallo
 CSSE342 Major
 UWB Fall2019
*/

/*
 This program that can solve a maze: It read a file and get the input of the file, display it contains and give the path
 to the exit of the maze if there any way out or return X if no way out*/

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H
#include <iostream>
using namespace std;

class Maze {
// follows the format provided above printing the Maze
    friend ostream &operator<<(ostream &out, const Maze &maze);
public:
    //mazes constructor
    Maze();
    Maze(string mazeFile);
    bool IsClear(int row, int column) const;
    bool IsWall(int row, int column) const;
    bool IsPath(int row, int column) const;
    bool IsVisited(int row, int column) const;
    void MarkAsPath(int row, int column);
    void MarkAsVisited(int row, int column);
    int getExitRow();
    int getExitColum();
    int getHeigth_of_maze();
    int getWidth_of_maze();
    char getField(int r, int c);
private:
    string mazeFile;
    int heigth_of_maze;
    int width_of_maze;
    int exit_row, exit_colum;
    char  field[100][100];

};


#endif //ASS3_MAZE_H
