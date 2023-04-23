/*
Project 2
Brad Hughes, Zohair Khan
Implementation of the A* algorithm on the 8-square puzzle
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include "Project2.h"
using namespace std;
#define ROW 3
#define COL 3

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

    bool isValid(int x, int y)
    {
    return (x >= 0) && (x < ROW) && (y >= 0)
           && (y < COL);
    }


	//Function to return vector of all successors

	//Hueristic function Manhattan Distance/H2
	int distance_m(int x1, int x2, int y1, int y2){
		int dist = abs(x1 - x2) + abs(y1-y2);
		return dist;
	}

	int x2_coord(PuzzleNode node, int value){
		for(int i = 0; i<3; i++){ //PuzzleNode.board[i][j]
			for (int j = 0; j<3; j++){
				if (node.board[i][j] == value)
					return i;
			}
		}
	}
	int y2_coord(PuzzleNode node, int value){
		for(int i = 0; i<3; i++){ //PuzzleNode.board[i][j]
			for (int j = 0; j<3; j++){
				if (node.board[i][j] == value)
					return j;
			}
		}
	}

	int distance_m_coords(PuzzleNode node){
		int x1, y1;
		int dist = 0;

		for(int i = 0; i<3; i++){ //PuzzleNode.board[i][j]
			for (int j = 0; j<3; j++){
				if(node.board[i][j]==0)
					continue;
				x1 = i;
				y1 = j;
				
				dist += distance_m(x1, x2_coord(node, node.goal[i][j]), y1, y2_coord(node, node.goal[i][j]));
				//cout << dist << endl;
			}
		}

		return dist;
	}


	//Hueristic function: Bradley Hughes
	// row column sum score the f value is determined by the additional offset of the goal row and column
	int brad_heuristic(PuzzleNode node){
		int dist = 0;
		int sum = 0;
		vector<vector<int>> board = node.board;

		//Rows
		for (auto& n : board[0])
     		sum += n;

     	dist += abs(sum - 6);
     	sum = 0;

     	for (auto& n : board[1])
     		sum += n;

     	dist += abs(sum - 12);
     	sum = 0;

     	for (auto& n : board[2])
     		sum += n;

     	dist += abs(sum - 18);
     	sum = 0;

     	//Cols

     	for(int i = 0; i < 3; i++)
     		sum += board[i][0];

     	dist += abs(sum - 16);
     	cout << sum << endl;
     	sum = 0;
     	

     	for(int i = 0; i < 3; i++)
     		sum += board[i][1];

     	dist += abs(sum - 8);
     	cout << sum << endl;
     	sum = 0;
     	

     	for(int i = 0; i < 3; i++)
     		sum += board[i][2];

     	dist += abs(sum - 12);
     	cout << sum << endl;
     	sum = 0;
     	

     	return dist;

	}


	//Hueristic function: Zohair Khan




	//Generate Successors
	vector<PuzzleNode> genSuccessors(PuzzleNode BESTNODE){

		int x = x2_coord(BESTNODE, 0);
        int y = y2_coord(BESTNODE, 0);
        vector<PuzzleNode> tempV;
        
        // Generate North
        if (isValid(x - 1, y) == true){
            vector<vector<int>> SUCCESSOR = BESTNODE.board;
            int temp = SUCCESSOR[x - 1][y];
            SUCCESSOR[x - 1][y] = 0;
            SUCCESSOR[x][y] = temp;
            PuzzleNode tempN(SUCCESSOR);
            tempV.push_back(tempN);
        }
        // Generate South
        if (isValid(x + 1, y) == true){
            vector<vector<int>> SUCCESSOR = BESTNODE.board;
            int temp = SUCCESSOR[x + 1][y];
            SUCCESSOR[x + 1][y] = 0;
            SUCCESSOR[x][y] = temp;
            PuzzleNode tempN(SUCCESSOR);
            tempV.push_back(tempN);
        }
        // Generate East
        if (isValid(x, y + 1) == true){
            vector<vector<int>> SUCCESSOR = BESTNODE.board;
            int temp = SUCCESSOR[x][y + 1];
            SUCCESSOR[x][y + 1] = 0;
            SUCCESSOR[x][y] = temp;
            PuzzleNode tempN(SUCCESSOR);
            tempV.push_back(tempN);
        }
        // Generate West
        if (isValid(x, y - 1) == true){

            vector<vector<int>> SUCCESSOR = BESTNODE.board;
            int temp = SUCCESSOR[x][y - 1];
            SUCCESSOR[x][y - 1] = 0;
            SUCCESSOR[x][y] = temp;
            PuzzleNode tempN(SUCCESSOR);
            tempV.push_back(tempN);
        }

        return tempV;
	}

	void printb(PuzzleNode test){
		for (int i = 0; i < test.board.size(); i++)
		{
		    for (int j = 0; j < test.board.size(); j++)
		    {
		    	if(test.board[i][j]!=0)
		        	cout << test.board[i][j];
		        else
		        	cout << " ";
		    }
		    cout << endl;
		}
		cout << endl;

	}

	vector<PuzzleNode> f_sort(vector<PuzzleNode> vect){

	}

int main(){

    PuzzleNode OLD(empty);
	//create two initial nodes
	vector<vector<int>> init1 = {{2, 8, 3}, {1, 6, 4}, {0, 7, 5}};
	vector<vector<int>> init2 = {{2, 1, 6}, {4, 0, 8}, {7, 5, 3}};
	vector<vector<int>> empty = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	PuzzleNode init_node_1(init1);
	PuzzleNode init_node_2(init2);	


	//list of OPEN nodes
	vector<PuzzleNode> OPEN;
	//list of CLOSED nodes
	vector<PuzzleNode> CLOSED;
	//write functions to compute hueristic values, assign to nodes
	
	//add initial node to OPEN
    OPEN.push_back(init_node_1);
    OPEN.front().setHeur(0, distance_m_coords(init_node_1));

    CLOSED.clear();
    PuzzleNode BESTNODE(empty);
    
    while (true) {
        if (OPEN.empty() == true) {
            cout << "Failure: OPEN is empty";
            abort();
        }

        int it;
        int lowest;
        for (int i = 0; i < OPEN.size(); i++){
        	if(i == 0)
        		lowest = OPEN[i].f;
        	else if(lowest > OPEN[i].f){
        		it = i;
        		lowest = OPEN[i].f;
        	}
        }
        
        BESTNODE = OPEN[it];
        OPEN.erase(OPEN.begin() + it);

        CLOSED.push_back(BESTNODE);
        if (BESTNODE.isGoal() == true) {
            cout << "We are finished!";
            abort();
        }

        // use x2_coord and y2_coord to find the cartesian coord of 0 and then store in x and y value
        // after I find the successor use something like vector<vector<int>> init1 = {{2, 8, 3}, {1, 6, 4}, {0, 7, 5}}
        // as an array and put new coordinates in here, init1 changes to successor
        // create vector<vector<int>> SUCCESSOR; before the loop for successor
        BESTNODE.successors = genSuccessors(BESTNODE);
        
        for (int j = 0; i < BESTNODE.successors.size(); j++ ){ //looping through all the successors
            BESTNODE.successors[j].setHeur(BESTNODE.g + 1, distance_m_coords(BESTNODE.successors[j].board));
            BESTNODE.successors[j].setParent(&BESTNODE);

            for(int i = 0; i < OPEN.size(); i++) {
                    if (OPEN[i].board == BESTNODE.sucessors[j].board) {
                        OLD = OPEN[i];
                        BESTNODE.successors[j] = OLD;

                        if ()
                        OLD.setParent(&BESTNODE);

                        // last part of 2.1
                        OPEN.push_back(BESTNODE.successors[j]);
                        OPEN = f_sort(OPEN);
                    }
            }

            else if(BESTNODE.successors[j]) // 2(ii)

            else{ // 2(iii)

            	OPEN.push_back(BESTNODE.successors[j]);
            	//Write a function to sort OPEN

            }

        }

        } 
    }



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


