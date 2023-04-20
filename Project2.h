#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

//Bunch of constant and object declarations.

class PuzzleNode{ 
	private:
	PuzzleNode bestNode;
	PuzzleNode parent;

	public:
		vector<vector<int>> goal = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
		vector<vector<int>> board;
		vector<PuzzleNode> successors;
		PuzzleNode(vector<vector<int>> arr);
		bool isGoal();
		void setBoard(vector<vector<int>> arr);
		void setBest(PuzzleNode bestNode);
		void setParent(PuzzleNode parent);
		PuzzleNode getBest();
		PuzzleNode getParent();
		
		float g;
		float h;
		float f;

};