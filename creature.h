//Name: Andrew Chou
//For Assignment 3: Recursive
//This is the header(contract) file for the creature.cpp

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  int Row;
  int Col;
  string path;

public:
  //constructor: initialize row and col
  Creature(int Row, int Col);
  //-----self added function----
  //returning the path on where the creature went to until reaching exit
  string getPath() const;
  //Adding string to the private member path
  void addPath(string &p);
  //Checking if the next turn is clear or not
  bool isBlocked(int Row, int Col, const Maze &Maze);
  //----------------------------
  //method to have the creature recursively run the maze until exit
  string solve(Maze &Maze);
  //testing if current location is the exit
  bool atExit(const Maze &Maze) const;
  //move up
  string goNorth(Maze &Maze);
  //move down
  string goSouth(Maze &Maze);
  //move right
  string goEast(Maze &Maze);
  //move left
  string goWest(Maze &Maze);
};

#endif //ASS3_CREATURE_H
