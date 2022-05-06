//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file


#include <iostream>
#include <string>
using namespace std;

#include "globals.h"
#include "GameState.h"

// Function prototype for playMove
void playMove(GameState&);

// The main function
int main() {

    /**********************************************************************************/
    /* Create an initialized game state object                                        */
    /**********************************************************************************/
    GameState game_state;
    
    game_state.set_selectedRow(0);
    game_state.set_selectedColumn(0);
    game_state.set_turn(true);
    game_state.set_winCode(0);
    game_state.set_moveValid(true);
    game_state.set_gameOver(false);
    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardSize; j++){
            game_state.set_gameBoard(i,j,0);
        }
    }
    
    // Read two integers from the user that represent the row and column
    // the player would like to place an X or an O in
    // You can assume there will be no formatting errors in the input

    int row;
    int col;
    while (!game_state.get_gameOver()) {
        cout << "Enter row and column of a grid cell: ";
        cin >> row >> col;
        
        // Check that the read row and column values are valid grid coordinates
        if ( (row < 0) || (row > 2) || (col < 0) || (col > 2) ) {
            cout << "Invalid board coordinates " << row << " " << col << endl << endl;
           continue;
        }
        // The coordinates are valid; set the selectedRow and selectedColumn
        // members of the game state to the read values
        // Again, the corresponding mutators of GameState must be first
        // implemented before this works
        // ECE244 Student: add your code here
        else {
            game_state.set_selectedRow(row);
            game_state.set_selectedColumn(col);
        
            
        // Call playMove
        playMove(game_state);
            
            
        // Print the GameState object, as prescribed in the handout
        cout << "Selected row " << row << " and column " << col << endl;
        cout << "Game state after playMove:"<< endl;
        cout << "Board:"<< endl;
        
        
        //print the board
        //line 1
        cout << "   ";
        for (int j = 0; j < boardSize; j++){
            
            if (game_state.get_gameBoard(0,j)== 1){
                cout<< "X ";
            }
            else if(game_state.get_gameBoard(0,j)== -1){
                cout<< "O ";
            }
            else if (game_state.get_gameBoard(0,j)== 0){
                cout << "B ";
            }  
        }
        cout << " "<<endl;
        
        //line 2
        cout << "   ";
        for (int j = 0; j < boardSize; j++){
            
            if (game_state.get_gameBoard(1,j)== 1){
                cout<< "X ";
            }
            else if(game_state.get_gameBoard(1,j)== -1){
                cout<< "O ";
            }
            else if (game_state.get_gameBoard(1,j)== 0){
                cout << "B ";
            }
        }
        cout << " "<<endl;
        
        //line 3
        cout << "   ";
        for (int j = 0; j < boardSize; j++){
            
            if (game_state.get_gameBoard(2,j)== 1){
                cout<< "X ";
            }
            else if(game_state.get_gameBoard(2,j)== -1){
                cout<< "O ";
            }
            else if(game_state.get_gameBoard(2,j)== 0){
                cout << "B ";
            }
        }
        cout << " "<<endl;
      
        //print moveValid
        if (game_state.get_moveValid()== 1){
            cout <<"moveValid: true"<< endl;
        }
        else if (game_state.get_moveValid() == 0){
            cout <<"moveValid: false"<< endl;
        }
        
        //print gameOver
        if (game_state.get_gameOver()== 0){
            cout <<"gameOver: false"<< endl;
        }
        else if (game_state.get_gameOver()== 1){
            cout <<"gameOver: true"<< endl;
        }
        
        //print winCode
        cout <<"winCode: "<< game_state.get_winCode()<< endl;
        cout <<"  "<< endl;
        continue;
        
        }  
    }
    return 0;
}

