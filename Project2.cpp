/*
Project 2
Brad Hughes, Zohair Khan
Implementation of the A* algorithm on the 8-square puzzle
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <Project2.h>
using namespace std;

//Some basic psuedocode to get us started
//basic class to store the state of each node
//vector of successors to this node
//method to add successors
//bestnode variable
//isGoal, checks if the current node is a goal node, returns bool 
//parent, points to the parent node of this node, if empty node is the starting node
//---------------------------DONE ^-----------------------------------------------------
//g, h', f' , hueristic variables
//method to remove successors

	PuzzleNode::PuzzleNode(vector<vector<int>> arr){
		board = arr;
		bestNode = NULL;
		parent = NULL;
		
	}

	bool PuzzleNode::isGoal(){ //FIX THIS DOESN'T WORK
		if(board == goal)
			return true;
		else
			return false;
	}

	void PuzzleNode::setBoard(vector<vector<int>> arr){
		board = arr;
	}

	void setBest(PuzzleNode best);{
		bestNode = best;
	}
	PuzzleNode getBest(){
		return bestNode;
	}

	void setParent(PuzzleNode par);{
		parent = par;
	}
	PuzzleNode getParent(){
		return parent;
	}
	
	void addSucc(PuzzleNode succ){
		successors.push_back(succ);

	}
	void removeSucc(PuzzleNode rsucc){
		//Check if rsucc is in successors and remove if so.
		for(int i = 0; i < successors.size(); i++){
			if (successors[i].board = rsucc.board){
				successors.erase(successors.begin() + index);
				break;
			}
		}

	}
	

	
	//Function to return vector of all successors



	//Hueristic function Manhattan Distance/H2
	int distance_m(PuzzleNode node){
		int dist;
		goal = node.goal;
		curr = node.board;
	}


	//Hueristic function: Bradley Hughes



	//Hueristic function: Zohair Khan

int main(){

	//create two initial nodes
	vector<vector<int>> init1 = {{2, 8, 3}, {1, 6, 4}, {0, 7, 5}};
	vector<vector<int>> init2 = {{2, 1, 6}, {4, 0, 8}, {7, 5, 3}};
	PuzzleNode init_node_1(init1);
	PuzzleNode init_node_2(init2);	

	//list of OPEN nodes
	list<PuzzleNode> OPEN;
	//list of CLOSED nodes
	list<PuzzleNode> CLOSED;
	//write functions to compute hueristic values, assign to nodes
	
	//add initial node to OPEN
	//loop
		//check if OPEN is empty, if true, report failure
		//compare f' values in open, assign lowest to BESTNODE
		//BESTNODE.isGoal, if true report solution, if false keep going.

		//generate SUCESSORS of BESTNODE
		//compute hueristics for sucessors of BESTNODE
		//check if sucessor is already on OPEN
			//if true, old = sucessor, delete sucessor, add old to BESTNODE's sucessors,
			//determine if OLD's parent should be BESTNODE or it's previously determined parent, check algorithm for specifics

		//check if sucessor is on CLOSED
			//if true, node on CLOSED == OLD
			//add old to BESTNODE's sucessors
			//compare old and new paths
			//reset OLD's parent link to BESTNODE
			//update OLD's hueristics
			//add SUCESSOR to OPEN, reorder OPEN based on f' value
			//compare paths

		//Else BESTNODE = SUCESSOR
			//add sucessor to OPEN
			//reorder OPEN


}