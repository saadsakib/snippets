#include <iostream> 
#include <math.h> 
  
#define N 8 
using namespace std; 

// The following definitions are used: 
//
// State – A state here in this context is any configuration of the N queens on
// the N X N board. To reduce the search space, only a single queen in a
// particular column is considered. A state is an array of length N.
//
// Neighbours – Neighbours of a state are other states with board
// configuration that differ from the current state’s board configuration with
// respect to the position of only a single queen.

// Originally posted:
// https://www.geeksforgeeks.org/n-queen-problem-local-search-using-hill-climbing-with-random-neighbour/
  
// Configures the 2D array "board" and array "state"
// randomly to provide a starting point for the algorithm. 
void configureRandomly(int board[][N], int* state) { 
    // Seed for the random function 
    srand(time(0)); 
  
    // Iterating through the column indices 
    for (int i = 0; i < N; i++) { 
        state[i] = rand() % N; 
        board[state[i]][i] = 1; 
    } 
} 
  
// Prints the 2D array "board". 
void printBoard(int board[][N]) { 
    for (int i = 0; i < N; i++) { 
        cout << " "; 
        for (int j = 0; j < N; j++) { 
            cout << board[i][j] << " "; 
        } 
        cout << "\n"; 
    } 
} 
  
// Prints the array "state". 
void printState(int* state) { 
    for (int i = 0; i < N; i++) { 
        cout << " " << state[i] << " "; 
    } 
    cout << endl; 
} 
  
// Compares two arrays, state1 and state2 and returns true on equal 
bool compareStates(int* state1, int* state2) { 
    for (int i = 0; i < N; i++) { 
        if (state1[i] != state2[i]) { 
            return false; 
        } 
    } 
    return true; 
} 
  
// A utility function that fills the 2D array "board" with values "value" 
void fill(int board[][N], int value) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            board[i][j] = value; 
        } 
    } 
} 
  
// This function calculates the objective value of the state(queens attacking
// each other) using the board by the following logic. 
int calculateObjective(int board[][N], int* state) { 
    // For each queen in a column, we check for other queens falling in the line
    // of our current queen and if found, any, then we increment the variable
    // attacking count. 
  
    // Number of queens attacking each other, initially zero. 
    int attacking = 0; 
  
    // Variables to index a particular row and column on board. 
    int row, col; 
  
    for (int i = 0; i < N; i++) { 
  
        // At each column 'i', the queen is placed at row 'state[i]', by the
        // definition of our state. 
  
        // To the left of same row (row remains constant and col decreases) 
        row = state[i], col = i - 1; 
        while (col >= 0 
               && board[row][col] != 1) { 
            col--; 
        } 
        if (col >= 0 
            && board[row][col] == 1) { 
            attacking++; 
        } 
  
        // To the right of same row (row remains constant and col increases) 
        row = state[i], col = i + 1; 
        while (col < N 
               && board[row][col] != 1) { 
            col++; 
        } 
        if (col < N 
            && board[row][col] == 1) { 
            attacking++; 
        } 
  
        // Diagonally to the left up (row and col simoultaneously decrease) 
        row = state[i] - 1, col = i - 1; 
        while (col >= 0 && row >= 0 
               && board[row][col] != 1) { 
            col--; 
            row--; 
        } 
        if (col >= 0 && row >= 0 
            && board[row][col] == 1) { 
            attacking++; 
        } 
  
        // Diagonally to the right down (row and col simoultaneously increase) 
        row = state[i] + 1, col = i + 1; 
        while (col < N && row < N 
               && board[row][col] != 1) { 
            col++; 
            row++; 
        } 
        if (col < N && row < N 
            && board[row][col] == 1) { 
            attacking++; 
        } 
  
        // Diagonally to the left down (col decreases and row increases) 
        row = state[i] + 1, col = i - 1; 
        while (col >= 0 && row < N 
               && board[row][col] != 1) { 
            col--; 
            row++; 
        } 
        if (col >= 0 && row < N 
            && board[row][col] == 1) { 
            attacking++; 
        } 
  
        // Diagonally to the right up (col increases and row decreases) 
        row = state[i] - 1, col = i + 1; 
        while (col < N && row >= 0 
               && board[row][col] != 1) { 
            col++; 
            row--; 
        } 
        if (col < N && row >= 0 
            && board[row][col] == 1) { 
            attacking++; 
        } 
    } 
  
    // Return pairs. 
    return (int)(attacking / 2); 
} 
  
// Generates a board configuration from the state. Overwrites board parameter.
void generateBoard(int board[][N], int* state) { 
    fill(board, 0); 
    for (int i = 0; i < N; i++) { 
        board[state[i]][i] = 1; 
    } 
} 
  
// A utility function that copies contents of state2 to state1. 
void copyState(int* state1, int* state2) { 
    for (int i = 0; i < N; i++) { 
        state1[i] = state2[i]; 
    } 
} 
  
// Gets the neighbour of the current state having the least objective value
// amongst all neighbours as well as the current state. 
void getNeighbour(int board[][N], int* state) { 
    // Declaring and initializing the optimal board and state with the current
    // board and the state as the starting point. 
    int opBoard[N][N]; 
    int opState[N]; 
  
    copyState(opState, state); 
    generateBoard(opBoard, opState); 
  
    // Initializing the optimal objective value 
    int opObjective = calculateObjective(opBoard, opState); 
  
    // Declaring and initializing the temporary board and state for the purpose
    // of computation. 
    int NeighbourBoard[N][N]; 
    int NeighbourState[N]; 
  
    copyState(NeighbourState, state); 
    generateBoard(NeighbourBoard, NeighbourState); 
  
    // Iterating through all possible neighbours of the board. 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            // Condition for skipping the current state 
            if (j != state[i]) { 
                // Initializing temporary neighbour with the current neighbour. 
                NeighbourState[i] = j; 
                NeighbourBoard[NeighbourState[i]][i] = 1; 
                NeighbourBoard[state[i]][i]  = 0; 
                // Calculating the objective value of the neighbour. 
                int temp = calculateObjective(NeighbourBoard, NeighbourState); 
  
                // Comparing temporary and optimal neighbour objectives and if
                // temporary is less than optimal then updating accordingly. 
                if (temp <= opObjective) { 
                    opObjective = temp; 
                    copyState(opState, NeighbourState); 
                    generateBoard(opBoard, opState); 
                } 
  
                // Going back to the original configuration for the next
                // iteration. 
                NeighbourBoard[NeighbourState[i]][i] = 0; 
                NeighbourState[i] = state[i]; 
                NeighbourBoard[state[i]][i] = 1; 
            } 
        } 
    } 
  
    // Copying the optimal board and state thus found to the current board and,
    // state since c++ doesn't allow returning multiple values. 
  
    copyState(state, opState); 
    fill(board, 0); 
    generateBoard(board, state); 
} 
  
void hillClimbing(int board[][N], int* state) { 
    // Declaring  and initializing the neighbour board and state with the
    // current board and the state as the starting point. 
  
    int neighbourBoard[N][N] = {}; 
    int neighbourState[N]; 
  
    copyState(neighbourState, state); 
    generateBoard(neighbourBoard, neighbourState); 
  
    do { 
        // Copying the neighbour board and state to the current board and state,
        // since a neighbour becomes current after the jump. 
        copyState(state, neighbourState); 
        generateBoard(board, state); 
  
        // Getting the optimal neighbour 
        getNeighbour(neighbourBoard, neighbourState); 
  
        if (compareStates(state, neighbourState)) { 
            // no optimal neighbour exists 
            printBoard(board); 
            break; 
        } 
        else if (calculateObjective(board, state) 
                 == calculateObjective(neighbourBoard, neighbourState)) { 
            // we are either approaching a shoulder or a local optimum, in any
            // case, jump to a random neighbour (not necessarity optimal) to
            // escape it. 
            neighbourState[rand() % N] = rand() % N; 
            generateBoard(neighbourBoard, neighbourState); 
        } 
    } while (true); 
} 
 
int main() { 
    int state[N] = {}; 
    int board[N][N] = {}; 
  
    // Getting a starting point by randomly configuring the board 
    configureRandomly(board, state); 
  
    // Do hill climbing on the board obtained 
    hillClimbing(board, state); 
    return 0; 
} 