#include <iostream>
#include "Maze.h"
#include "Creature.h"

void test1() {
    Maze maze1;
    maze1 = Maze("maze.txt");
    cout << maze1 << endl;
    //print the wat exit
    Creature creatAtExit(15, 2);
    creatAtExit.Solve(maze1);
    cout << "The Creature " << creatAtExit << " is right at the exit : " << creatAtExit.getPath() << endl;
    cout << maze1 << endl;
}

void test5() {
        Maze maze1;
        maze1 = Maze("maze.txt");
        cout << maze1 << endl;
//print the path of the maze
        Creature creat1(15, 2);
        creat1.Solve(maze1);
        cout << "The Creature " << creat1 << " has no path so it should return X: " << creat1.getPath() << endl;
        cout << maze1 << endl;
    }

void test2() {
    Maze maze2;
    maze2 = Maze("maze0.txt");
    //before solve funcion call
    cout << maze2 << endl;
    //print at exit
    Creature creat2(8, 0);
    creat2.Solve(maze2);
    cout << "The path of the coordinate " << creat2 << " is : " << creat2.getPath() << endl;
    cout << maze2 << endl;

}
void test3() {
    Maze maze2;
    maze2 = Maze("maze0.txt");
    cout << maze2 << endl;
    //print maze path
    Creature ziz(7, 3);
    ziz.Solve(maze2);
    cout << "The path of the coordinate " << ziz << " is : " << ziz.getPath() << endl;
    cout << maze2 << endl;
}

void test4(){
    Maze maze2;
    maze2 = Maze("maze0.txt");
    cout << maze2 << endl;
//invalid input, should print X meaning no way no exit
    Creature creat4(-123,-234);
    creat4.Solve(maze2);
    cout <<"The path of the coordinate "<<creat4 << " is : "<< creat4.getPath()<< endl;
    cout << maze2 << endl;
}


int main() {
    cout << "Test1: " << endl;
    test1();
//
//    cout << "Test2: " << endl;
//    test2();
//
//    cout << "Test3: " << endl;
//    test3();

    //cout << "Test4: " << endl;
  //  test5();
}