/*
Project 2
Brad Hughes, Zohair Khan
Implementation of the A* algorithm on the 8-square puzzle
*/

#include <iostream>
#include <string>
#include <vector>


//Some basic psuedocode to get us started
//basic class to store the state of each node, still needs setters/getters
//vector of successors to this node
//method to add successors
//method to remove successors
//bestnode variable
//isGoal, checks if the current node is a goal node, returns bool
//parent, points to the parent node of this node, if empty node is the starting node
//g, h', f' , hueristic variables
class PuzzleNode{ 
	public:
		PuzzleNode()
		{
			int Board[3][3] = {}
		}

		PuzzleNode(int arr[])
		{
			int Board[3][3] = arr;
		}	

}

//object class for the puzzle data type
int main(){

	//create object for goalnode
	//create two initial nodes
	//vector of OPEN nodes
	//vector of CLOSED nodes
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