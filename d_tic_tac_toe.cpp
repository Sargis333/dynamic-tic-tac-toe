#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void printBoard(int n, vector<vector<char>>& board) {
    system("cls");
    for(int i=0; i< n; i++){
        if(i==0){
            cout<<" ";
        }
        cout<<" "<<i;
    }
    cout<<endl;
    for (int i = 0; i < board.size(); i++) {
        cout<<i<<" ";
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        } 
        cout<<endl;
    }
    cout<<endl;
}


char checkWinner(vector<vector<char>>& board) {
    
    for (int i = 0; i < board.size(); i++) {
        char first = board[i][0];
        bool same = true;
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j] != first) {
                same = false;
                break;
            }
        }
        if (same && first != '.') {
            return first;
        }
    }

    for (int j = 0; j < board[0].size(); j++) {
        char first = board[0][j];
        bool same = true;
        for (int i = 1; i < board.size(); i++) {
            if (board[i][j] != first) {
                same = false;
                break;
            }
        }
        if (same && first != '.') {
            return first;
        }
    }

    char first = board[0][0];
    bool same = true;
    for (int i = 1; i < board.size(); i++) {
        if (board[i][i] != first) {
            same = false;
            break;
        }
    }
    if (same && first != '.') {
        return first;
    }
    first = board[0][board.size()-1];
    same = true;
    for (int i = 1; i < board.size(); i++) {
        if (board[i][board.size()-1-i] != first) {
            same = false;
            break;
        }
    }
    if (same && first != '.') {
        return first;
    }
    
    return '.';
}


void makeMove(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}


int main() {
    int n;
    cout << "enter the number of columns(3-10): ";
    cin>>n;
   
    while(true)
    {
        if(n<3 || n>10 || cin.fail()){
            cout << "enter the number of columns(3-10): ";
            cin.clear();
            cin.ignore(256, '\n');
            cin>>n;
           
        }
        else{
           break;
        }
    }
    int k;
    while(true){
    if(k<3 || k>10 || cin.fail()){
        cout<<"enter the number of row(3-10): ";
        cin.clear();
        cin.ignore(256, '\n');
        cin>>k;
        
        }
        else{
            break;
        }
    }
    vector<vector<char>> board(k, vector<char>(n, '.'));

    char currentPlayer = 'X';
    while (true) {
        printBoard(n,board);

        
        int row, col;
        cout << "Player " << currentPlayer << " make a move (row): ";
        cin >> row;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(true){
            if(row < 0 || cin.fail() || row>=k){
                cout<<"Invalid move! Try again. "<< "\n";
                printBoard(n,board);
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Player " << currentPlayer << " make a move (row): ";
                cin>>row;
            }else{
                break;
            }
        }
        cout << "Player " << currentPlayer << " make a move (col): ";
        cin >> col;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while(true){
            if(cin.fail() || col < 0 || col >= n){
                cout<<"Invalid move! Try again. "<< "\n";
                printBoard(n,board);
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Player " << currentPlayer << " make a move (col): ";
                cin>>col;
            }else{
                break;
            }
        }
        if (board[row][col] != '.') {
            cout <<"\n"<< "Invalid move! Try again. \n" << endl;
            //printBoard(n,board);
            continue;
        }

        
        makeMove(board, row, col, currentPlayer);

        
        char winner = checkWinner(board);
        if (winner != '.') {
            cout << "Player " << winner << " wins!" << endl;
            printBoard(n,board);
            system("pause");
            break;
        }

       
        bool full = true;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    full = false;
                    break;
                }
            }
            if (!full) {
                break;
            }
        }
        if (full) {
            cout << "Tie game!" << endl;
            printBoard(n,board);
            system("pause");
            break;
        }

      
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    return 0;
}