//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void winChecker (int value, GameState& );
void playMove(GameState& game_state) {
    
    if (game_state.get_gameOver()){
        return;
    }
    
    //check move and assign turn
    if (game_state.get_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn()) == 0){
        game_state.set_moveValid(true);
        if (game_state.get_turn()){
            game_state.set_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn(),1);
            game_state.set_turn(false);
        }
	else {
	    game_state.set_gameBoard(game_state.get_selectedRow(),game_state.get_selectedColumn(),-1);
	    game_state.set_turn(true);
	}
    }
    else {
    	game_state.set_moveValid(false);
    }
    
    winChecker(1, game_state);
    winChecker(-1, game_state);
    
    //check board for a draw/no win
    if (game_state.get_gameOver() != true){
        bool available;
        for (int i = 0; i <= 2; i++){
            for (int j = 0; j <= 2; j++){
                if (game_state.get_gameBoard(i,j) == 0){
                    available = true;
                }
            }
        }
        
        if (available){
            game_state.set_winCode(0);
            game_state.set_gameOver(false);
        }
        else{
            game_state.set_winCode(0);
            game_state.set_gameOver(true);
        } 
    } 
}

//checking which type of win occurred, if multiple wins: winCode should be highest value 
void winChecker (int value, GameState& game_state){
	//diagonal [2,0] to [0,2]
        if (game_state.get_gameBoard(2,0) == value && game_state.get_gameBoard(1,1) == value && game_state.get_gameBoard(0,2) == value){
                        game_state.set_winCode(8);
                        game_state.set_gameOver (true);
                        
        }
	//diagonal [0,0] to [2,2]
	else if (game_state.get_gameBoard(0,0) == value && game_state.get_gameBoard(1,1) == value && game_state.get_gameBoard(2,2) == value){
                        game_state.set_winCode(7);
                        game_state.set_gameOver (true);
                        
        } 
	//column 2
	else if (game_state.get_gameBoard(0,2) == value && game_state.get_gameBoard(1,2) == value && game_state.get_gameBoard(2,2) == value){
                        game_state.set_winCode(6);
                        game_state.set_gameOver (true);
                        
        }
	//column 1
	else if (game_state.get_gameBoard(0,1) == value && game_state.get_gameBoard(1,1) == value && game_state.get_gameBoard(2,1) == value){
                        game_state.set_winCode(5);
                        game_state.set_gameOver (true);
                        
        } 
	//column 0
	else if (game_state.get_gameBoard(0,0) == value && game_state.get_gameBoard(1,0) == value && game_state.get_gameBoard(2,0) == value){
                        game_state.set_winCode(4);
                        game_state.set_gameOver (true);
                        
        }
	//row 2
	else if (game_state.get_gameBoard(2,0) == value && game_state.get_gameBoard(2,1) == value && game_state.get_gameBoard(2,2) == value){
                        game_state.set_winCode(3);
                        game_state.set_gameOver (true);
                        
        }
	//row 1
	else if (game_state.get_gameBoard(1,0) == value && game_state.get_gameBoard(1,1) == value && game_state.get_gameBoard(1,2) == value){
                        game_state.set_winCode(2);
                        game_state.set_gameOver (true);
                        
        }
	//row 0
	else if (game_state.get_gameBoard(0,0) == value && game_state.get_gameBoard(0,1) == value && game_state.get_gameBoard(0,2) == value){
                        game_state.set_winCode(1);
                        game_state.set_gameOver (true);
                        
        }
	return;    	  	 	  	    	    
}
