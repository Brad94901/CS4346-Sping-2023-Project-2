#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;
//Bunch of constant and object declarations.

class PuzzleNode{ 
	private:
		PuzzleNode *bestNode; //FIX THESE
		PuzzleNode *parent;	  //FIX THESE
	public:
		vector<vector<int>> goal = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
		vector<vector<int>> board;
		vector<PuzzleNode> successors;
		PuzzleNode(vector<vector<int>> arr);
		bool isGoal();
		void setBoard(vector<vector<int>> arr);


		void addSucc(PuzzleNode succ);
		void removeSucc(PuzzleNode rsucc);

		void setBest(PuzzleNode *bestNode); //FIX THESE
		void setParent(PuzzleNode *par); //FIX THESE
		PuzzleNode* getBest(); //FIX THESE
		PuzzleNode* getParent(); //FIX THESE
		
		float g;
		float h;
		float f;

};

PuzzleNode::PuzzleNode(vector<vector<int>> arr){
		board = arr;
		int parent = 0;
		int bestNode = 0;
	
		
	}

	bool PuzzleNode::isGoal(){ //FIX THIS DOESN'T WORK
		if(board == goal)
			return true;
		else
			return false;
	}

	void PuzzleNode::setBoard(vector<vector<int>> arr){
		this->board = arr;
	}

	void PuzzleNode::setBest(PuzzleNode *best){
		this->bestNode = best;
	}
	PuzzleNode* PuzzleNode::getBest(){
		return bestNode;
	}

	void PuzzleNode::setParent(PuzzleNode *par){
		this->parent = par;
	}
	PuzzleNode* PuzzleNode::getParent(){
		return parent;
	}
	
	void PuzzleNode::addSucc(PuzzleNode succ){
		this->successors.push_back(succ);

	}
	void PuzzleNode::removeSucc(PuzzleNode rsucc){
		//Check if rsucc is in successors and remove if so.
		for(int i = 0; i < this->successors.size(); i++){
			if (this->successors[i].board == rsucc.board){
				this->successors.erase(successors.begin() + i);
				break;
			}
		}

	}