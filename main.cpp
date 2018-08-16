#include <iostream>
#include <fstream>
#include "Stack.h"
#include "Maze.h"

bool findPath(Stack& s, MazeLocation cur, Maze& m) {
	if (!m.isOpen(cur)) {
		return false;
	}

	s.push(cur);
	m.setChar(cur, '*');
	cout << m << endl;

	if (m.isFinished(cur)) {
		return true;
	}

	bool up = findPath(s, cur.upOne(), m);
	bool down = findPath(s, cur.downOne(), m);
	bool left = findPath(s, cur.leftOne(), m);
	bool right = findPath(s, cur.rightOne(), m);

	if (up || down || left || right) {
		return true;
	} else {
		m.setChar(cur, ':');
		cout << m << endl;
		s.pop();
		return false;
	}
}

int main(int argc, char* argv[]) {
	// Main maze program

	// Consumes the maze data file as a command line argument.
	if (argc < 2) {
		cerr << "ERROR" << endl << "usage: ./pa2 maze.txt" << endl;
		return 1;
	}
		
	ifstream inputFile(argv[1]);
	  
	// Calls maze constructor linked to input file.
	Maze m(inputFile);
	// Creates a stack with enough space to hold every location in m
	Stack s(m.getSize());

	if (findPath(s, m.getStart(), m)) {
		cout << "Maze solved" << endl;
	} else {
		cout << "Ahhh, couldn't get out!" << endl;
	}

	// Stack should contain only locations on path to finish (not dead-ends)
	// or be empty if no solution was found (as everything was popped off).
	while(!s.isEmpty()) {
		s.printTop();
		s.pop();
	}

}