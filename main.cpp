#include <iostream>

#include "creature.h"
#include "maze.h"


void testMaze() {
    Maze M("maze.txt");
    // cout << m << endl;
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

void testMaze1(){
    Maze M("maze1.txt");
    Creature C(3, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

// void testMaze2(){
//     Maze M("maze2.txt");
//     Creature C(4, 4);
//     cout << "Path: " << C.solve(M) << endl;
//     cout << M << endl;
// }

int main() {
    testMaze();
    testMaze1();
    //testMaze2();
    cout << "Done!" << std::endl;
    return 0;
}