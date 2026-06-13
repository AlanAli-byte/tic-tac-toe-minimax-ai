#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
int computerMove(char *spaces, char computer, char player);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
char get_winner(char *spaces);
int minimax(char *spaces, int depth, bool is_maximizing, char player, char computer, int alpha, int beta);
int best_move(char *spaces, char computer, char player);

int main()
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    std::srand((unsigned)time(0));

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }

        int move = computerMove(spaces, computer, player);
        spaces[move] = computer;
        std::cout << "Computer placed at " << (move + 1) << '\n';
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        else if(checkTie(spaces)){
            running = false;
            break;
        }
    }
    std::cout << "Thanks for playing!\n";
    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player){
    int number;
    while(true){
        std::cout << "Enter a spot to place a marker (1-9): ";
        if(!(std::cin >> number)){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number 1-9.\n";
            continue;
        }
        if(number < 1 || number > 9){
            std::cout << "Number out of range. Choose 1-9.\n";
            continue;
        }
        int idx = number - 1;
        if(spaces[idx] != ' '){
            std::cout << "Spot already taken. Choose another.\n";
            continue;
        }
        spaces[idx] = player;
        break;
    }
}

int computerMove(char *spaces, char computer, char player){
    
    return best_move(spaces, computer, player);
}

bool checkWinner(char *spaces, char player, char computer){
    
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
        spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
        spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
        spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
        spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])){
        spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOSE!\n";
    }
    else{
        return false;
    }
    return true;
}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "IT'S A TIE!\n";
    return true;
}

char get_winner(char *s){
    
    if((s[0] != ' ') && (s[0] == s[1]) && (s[1] == s[2])) return s[0];
    if((s[3] != ' ') && (s[3] == s[4]) && (s[4] == s[5])) return s[3];
    if((s[6] != ' ') && (s[6] == s[7]) && (s[7] == s[8])) return s[6];
    if((s[0] != ' ') && (s[0] == s[3]) && (s[3] == s[6])) return s[0];
    if((s[1] != ' ') && (s[1] == s[4]) && (s[4] == s[7])) return s[1];
    if((s[2] != ' ') && (s[2] == s[5]) && (s[5] == s[8])) return s[2];
    if((s[0] != ' ') && (s[0] == s[4]) && (s[4] == s[8])) return s[0];
    if((s[2] != ' ') && (s[2] == s[4]) && (s[4] == s[6])) return s[2];
    return ' ';
}

int minimax(char *spaces, int depth, bool is_maximizing, char player, char computer, int alpha, int beta){
    char winner = get_winner(spaces);
    if(winner == computer) return 10 - depth;
    if(winner == player) return depth - 10;
    bool any_empty = false;
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            any_empty = true;
            break;
        }
    }
    if(!any_empty) return 0;

    if(is_maximizing){
        int best = std::numeric_limits<int>::min();
        for(int i = 0; i < 9; i++){
            if(spaces[i] == ' '){
                spaces[i] = computer;
                int val = minimax(spaces, depth + 1, false, player, computer, alpha, beta);
                spaces[i] = ' ';
                if(val > best) best = val;
                if(best > alpha) alpha = best;
                if(beta <= alpha) break; 
            }
        }
        return best;
    } else {
        int best = std::numeric_limits<int>::max();
        for(int i = 0; i < 9; i++){
            if(spaces[i] == ' '){
                spaces[i] = player;
                int val = minimax(spaces, depth + 1, true, player, computer, alpha, beta);
                spaces[i] = ' ';
                if(val < best) best = val;
                if(best < beta) beta = best;
                if(beta <= alpha) break; 
            }
        }
        return best;
    }
}

int best_move(char *spaces, char computer, char player){
    int best_score = std::numeric_limits<int>::min();
    std::vector<int> candidates;
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            spaces[i] = computer;
            int score = minimax(spaces, 0, false, player, computer, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
            spaces[i] = ' ';
            if(score > best_score){
                best_score = score;
                candidates.clear();
                candidates.push_back(i);
            } else if(score == best_score){
                candidates.push_back(i);
            }
        }
    }
    if(candidates.empty()){
        
        for(int i = 0; i < 9; i++) if(spaces[i] == ' ') return i;
        return 0;
    }
    
    int pick = std::rand() % (int)candidates.size();
    return candidates[pick];
}
