/*
 Elhadj Diallo
 CSSE342 Major
 UWB Fall2019
*/

/*
 This program that can solve a maze: It read a file and get the input of the file, display it contains and give the path
 to the exit of the maze if there any way out or return X if no way out*/
//#include <iostream>
#include <fstream>
#include "Maze.h"

using namespace std;
Maze::Maze()
{

}

Maze::Maze(string mazeFile){
    //Read maze.txt header
   // ifstream infile(file.c_str());
    ifstream fin;
    fin.open(mazeFile.c_str());
    fin >> width_of_maze;
    fin >> heigth_of_maze;
    fin >> exit_row,
    fin >> exit_colum;
    //Read maze.txt body
    string line;
    getline(fin, line);
    for (int r = 0; r < heigth_of_maze; r++) {
        getline(fin, line);
        for (int c = 0; c < width_of_maze; c++) {
            field[r][c] = line[c];
        }
    }
    fin.close();
}
//geting the square of the maze
char Maze::getField(int r, int c) {
    char square = field[r][c];
    return square;
}

//return teh hight of the maze
int Maze::getHeigth_of_maze(){
    return heigth_of_maze;
}

//return the width of the maze
int Maze::getWidth_of_maze(){
    return width_of_maze;
}

//return the row exit of the maze
int Maze::getExitRow(){
    return exit_row;
}

//return the column exit of the maze
int Maze::getExitColum() {
    return exit_colum;
}

//looking if we are inside the maze area
bool Maze::IsClear(int row, int column) const{
    if(field[row][column] != 'x'){
        return true;
    }
    return false;
}

//check if we are in a wall or if it is clear
bool Maze::IsWall(int row, int column) const{
    return field[row][column] != ' ';
}

//return true if it is a path, false otherwise
bool Maze::IsPath(int row, int column) const{
    return field[row][column]=='*';
}

// if it is visited true, false autherwise
bool Maze::IsVisited(int row, int column) const{
    return field[row][column] == '+';
}

// mark the maze with *
void Maze::MarkAsPath(int row, int column){
    field[row][column]= '*';
}

// mark the maze with +
void Maze::MarkAsVisited(int row, int column){
    field[row][column] = '+';
}

//-------------------------------------------------------------------------
// follows the format provided above printing the maze
ostream &operator<<(ostream &out, const Maze &maze){
    out << maze.width_of_maze << " " << maze.heigth_of_maze << " " << endl;
    out<< maze.exit_row<< " "<< maze.exit_colum << " " << endl;
    for(int r=0; r< maze.heigth_of_maze; r++){
        for(int c=0; c< maze.width_of_maze; c++){
            out<<maze.field[r][c];
        }
        out<< endl;
    }
    return out;
}