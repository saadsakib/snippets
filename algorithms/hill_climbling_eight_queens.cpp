#include <iostream> 
#include <math.h> 
  
#define N 8 
#define QUEEN 1
#define EMPTY 0
using namespace std; 

// The following definitions are used: 
//
// State – A state here in this context is any configuration of the N queens on
// the N X N board. To reduce the search space, only a single queen in a
// particular column is considered. A queen can move only in y-axis. A state is
// an array of length N.
//
// Neighbours – Neighbours of a state are other states with board configuration
// that differ from the current state’s board configuration by  moving a single
// queen columnwise.
//
// Objective = pairs of queens attacking each other
// 
// In the following, 
// i = column # / x-coordinate
// state[i] / j = row # / y-coordinate


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
  
int calculateObjective(int board[][N], int* state) { 
    // For each queen in a column, we check for other queens falling in the line
    // of our current queen and if found, any, then we increment the variable
    // attacking count. 
  
    // Number of queens attacking each other, initially zero. 
    int attacking = 0; 
  
    // Variables to index a particular row and column on board. 
    int row, col; 
  
    for (int i = 0; i < N; i++) { 
        // To the left of same row (row remains constant and col decreases) 
        row = state[i], col = i - 1; 
        while (col >= 0 && board[row][col] != QUEEN) { 
            col--; 
        } 
        if (col >= 0 && board[row][col] == QUEEN) { 
            attacking++; 
        } 
  
        // To the right of same row (row remains constant and col increases) 
        row = state[i], col = i + 1; 
        while (col < N && board[row][col] != 1) { 
            col++; 
        } 
        if (col < N && board[row][col] == 1) { 
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
void getOptimalNeighbour(int board[][N], int* state) { 
    // Optimal board and state; ultimately copied to board and state
    // parameters. 
    int opState[N]; 
    copyState(opState, state); 
    
    int opBoard[N][N]; 
    generateBoard(opBoard, opState); 
  
    // Initializing the optimal objective value 
    int opObjective = calculateObjective(opBoard, opState); 
  
    // Declaring and initializing the temporary board and state for the purpose
    // of computation. 
    int tempBoard[N][N]; 
    int tempState[N]; 
  
    copyState(tempState, state); 
    generateBoard(tempBoard, tempState); 
  
    // Iterating through all possible neighbours.
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) { 
            // Consider a neighbour
            if (j != state[i]) { 
                tempState[i] = j; 
                tempBoard[j][i] = QUEEN; 
                tempBoard[state[i]][i]  = EMPTY; 
                
                int tempObjective = calculateObjective(tempBoard, tempState); 
                if (tempObjective <= opObjective) { 
                    opObjective = tempObjective; 
                    copyState(opState, tempState); 
                    generateBoard(opBoard, opState); 
                } 
  
                // Re-positioning current column's queen. 
                tempBoard[tempState[i]][i] = EMPTY; 
                tempState[i] = state[i]; 
                tempBoard[state[i]][i] = QUEEN; 
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
    // variables for storing the optimal neighbour 
    int neighbourBoard[N][N] = {}; 
    int neighbourState[N]; 
  
    copyState(neighbourState, state); 
    generateBoard(neighbourBoard, neighbourState); 
  
    while (true) { 
        getOptimalNeighbour(neighbourBoard, neighbourState); 
  
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
        copyState(state, neighbourState); 
        generateBoard(board, state); 
    }  
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