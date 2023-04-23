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
#define ROW 2
#define COL 2

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


	//Hueristic function: Zohair Khan

int main(){

	//create two initial nodes
	vector<vector<int>> init1 = {{2, 8, 3}, {1, 6, 4}, {0, 7, 5}};
	vector<vector<int>> init2 = {{2, 1, 6}, {4, 0, 8}, {7, 5, 3}};
	PuzzleNode init_node_1(init1);
	PuzzleNode init_node_2(init2);	


	//----------------TEST STUFFS---------------------
	vector<vector<int>> test = {{1, 0, 3}, {4, 2, 6}, {7, 8, 9}};
	vector<vector<int>> test2 = {{1, 0, 3}, {4, 2, 6}, {9,8,7}};
	PuzzleNode testn(test);
	PuzzleNode testn2(test2);
	testn.setBest(&testn2);
	testn.printn();

	//print_board(testnode.board);
	//print_board(testnode.goal);
	//----------------TEST STUFFS---------------------


	//list of OPEN nodes
	vector<PuzzleNode> OPEN;
	//list of CLOSED nodes
	vector<PuzzleNode> CLOSED;
	//write functions to compute hueristic values, assign to nodes
	
	//add initial node to OPEN
    OPEN.push_back(init_node_1);
    OPEN.front().setHeur(0, distance_m_coords(init_node_1));

    CLOSED.clear();
    PuzzleNode BESTNODE(test);

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

            // Generate North
            int x = x2_coord(BESTNODE, 0);
            int y = y2_coord(BESTNODE, 0);
            if (isValid(x - 1, y) == true){
                vector<vector<int>> SUCCESSOR = BESTNODE.board;
                int temp = SUCCESSOR[x - 1][y];
                SUCCESSOR[x - 1][y] = 0;
                SUCCESSOR[x][y] = temp;
                PuzzleNode tempN(SUCCESSOR);
                BESTNODE.addSucc(tempN);
            }
            // Generate South
            if (isValid(x + 1, y) == true){
                vector<vector<int>> SUCCESSOR = BESTNODE.board;
                int temp = SUCCESSOR[x + 1][y];
                SUCCESSOR[x + 1][y] = 0;
                SUCCESSOR[x][y] = temp;
                PuzzleNode tempN(SUCCESSOR);
                BESTNODE.addSucc(tempN);
            }
            // Generate East
            if (isValid(x, y + 1) == true){
                vector<vector<int>> SUCCESSOR = BESTNODE.board;
                int temp = SUCCESSOR[x][y + 1];
                SUCCESSOR[x][y + 1] = 0;
                SUCCESSOR[x][y] = temp;
                PuzzleNode tempN(SUCCESSOR);
                BESTNODE.addSucc(tempN);
            }
            // Generate West
            if (isValid(x, y - 1) == true){
                vector<vector<int>> SUCCESSOR = BESTNODE.board;
                int temp = SUCCESSOR[x][y - 1];
                SUCCESSOR[x][y - 1] = 0;
                SUCCESSOR[x][y] = temp;
                PuzzleNode tempN(SUCCESSOR);
                BESTNODE.addSucc(tempN);
            }

            for (int i = 0; i < BESTNODE.successors.size(); i++ ){ //looping through all the successors
                BESTNODE.successors[i].setHeur(BESTNODE.g + 1, distance_m_coords(BESTNODE.successors[i].board));
                BESTNODE.successors[i].setParent(&BESTNODE);
                if(SUCCESSOR  ) // 2(i)
                    else if(SUCCESSOR) // 2(ii)
                        else // 2(iii)
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


