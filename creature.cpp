//Name: Andrew Chou
//For Assignment 3: Recursion
//This program is being used to solve the maze with max height/width  and exit row and column given
//It will provide the path to the exit grid from solve() method.

#include "creature.h"

//Pre: NA
//Post: print out the current place of the creature
//toString() of the class
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "( " << Creature.Row << ", " << Creature.Col << " )" << endl;
  return Out;
}
//Pre: no row or col initiated
//Post row and col initiated according to the param provided
//Constructor
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) {}

//Pre: no exit specify
//Post: able to tell if the creature is now at the exit (returning true)
//check if we reached exit
bool Creature::atExit(const Maze &Maze) const {
  return (Row == Maze.getExitRow() && Col == Maze.getExitColumn());
}

//Pre: no path access
//Post: able to use this to get the path of the creature to exit
//return the path string to the method
string Creature::getPath() const{
  return path;
}

//Pre: path remain the same
//Post: adding string in the param to the path private data member
//adding string to the path data member (concatenating)
void Creature::addPath(string &p){
  path += p;
}

//Pre: no blockage status check
//Post: able to know the next turn condition.
//Checking if the next turn is clear or not, if not clear, true, if clear, false
bool Creature::isBlocked(int Row, int Col, const Maze &Maze){
  return (!Maze.isClear(Row - 1, Col) && !Maze.isClear(Row + 1, Col) && !Maze.isClear(Row, Col - 1) && !Maze.isClear(Row, Col + 1));
}

//Pre: No creature solving the maze
//Post: recursively move position N, S, W, E until found way to the exit
//return path back to the method.
string Creature::solve(Maze &Maze) {
  //base case: if at the exit already, end the recursive
  if(atExit(Maze)){
    return path;
  }
  //recursive case
  //test if north moving is possible
  else if(Maze.isClear(Row - 1, Col)){
    //go North
    goNorth(Maze);
    string Word = "N";
    //add it as path for now regarless of being blocked
    addPath(Word);
    //Backtracking, check if the next turn is blocked,
    //move to opposite direction if blocked
    if(isBlocked(Row, Col, Maze) && !atExit(Maze)){
      path.pop_back();
      Maze.markAsVisited(Row, Col);
      goSouth(Maze);
    }
    return solve(Maze);
  }
  //test if south moving is possible
  else if(Maze.isClear(Row + 1, Col)){
    //go South
    goSouth(Maze);
    string Word = "S";
    //add it as path for now regarless of being blocked
    addPath(Word);
    //Backtracking, check if the next turn is blocked,
    //move to opposite direction if blocked
    //PS: my backtracking does seem to run really well, below "if" is my final work for backtracking
    //    please advise!
    if(isBlocked(Row, Col, Maze) && !atExit(Maze)){
      path.pop_back();
      Maze.markAsVisited(Row, Col);
      goNorth(Maze);
    }
    return solve(Maze);
  }
  //test ifi west moving is possible
  else if(Maze.isClear(Row, Col - 1)){
    goWest(Maze);
    string Word = "W";
    //add it as path for now regarless of being blocked
    addPath(Word);
    //Backtracking, check if the next turn is blocked,
    //move to opposite direction if blocked
    if(isBlocked(Row, Col, Maze) && !atExit(Maze)){
      path.pop_back();
      Maze.markAsVisited(Row, Col);
      goEast(Maze);
    }
    return solve(Maze);
  }
  //test if east moving is possible
  else{
    //go East
    goEast(Maze);
    string Word = "E";
    //add it as path for now regarless of being blocked
    addPath(Word);
    //Backtracking, check if the next turn is blocked,
    //move to opposite direction if blocked
    if(isBlocked(Row, Col, Maze) && !atExit(Maze)){
      path.pop_back();
      Maze.markAsVisited(Row, Col);
      goWest(Maze);
    }
    return solve(Maze);
  }
}

//Pre: stay current location
//Post: move up one grid
//Move one grid up (North)
string Creature::goNorth(Maze &Maze) {
  Row--;
  Maze.markAsPath(Row, Col);
  return "N";
}

//Pre: stay current location
//Post: move left one grid
//Move one grid left (west)
string Creature::goWest(Maze &Maze) {
  Col--;
  Maze.markAsPath(Row, Col);
  return "W";
}

//Pre: stay current location
//Post: move right one grid
//Move one grid right (east)
string Creature::goEast(Maze &Maze) {
  Col++;
  Maze.markAsPath(Row, Col);
  return "E";
}

//Pre: stay current location
//Post: move down one grid
//Move one grid down (South)
string Creature::goSouth(Maze &Maze) {
  Row++;
  Maze.markAsPath(Row, Col);
  return "S";
}
