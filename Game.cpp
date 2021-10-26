#include "Game.h"
#include "Player.h"


class List;

void Game::display() {
    cout <<endl;
    cout << "   |   |   "<<endl;
    cout << " "<< board[0] <<" | "<<board[1]<<" | "<<board[2]<<endl;
    cout << "   |   |   "<<endl;
    cout << "-----------"<<endl;
    cout << "   |   |   "<<endl;
    cout << " "<< board[3] <<" | "<<board[4]<<" | "<<board[5]<<endl;
    cout << "   |   |   "<<endl;
    cout << "-----------"<<endl;
    cout << "   |   |   "<<endl;
    cout << " "<< board[6] <<" | "<<board[7]<<" | "<<board[8]<<endl;
    cout << "   |   |   "<<endl;
    cout <<endl;
}
void Game::botInput(){
    int pos;
    pos = rand()%10;
    if(emptyIndex[pos] == 1){
        if(emptyCount < 0)
            return;
        botInput();
    } else {
        cout<< "Bot choose: " << pos+1 << endl;
        emptyIndex[pos] =1;
        emptyCount-=1;
        board[pos] = 'O';
    }

}
void Game::playerInput(Player &player){
    int pos;
    cout << endl;
    cout << "\t" << player.getName() <<" Turn: ";
    cout <<"\t Enter the position " << endl;
    cin >> pos;
    pos -=1;
    if(emptyIndex[pos] == 1){
        cout << "-----Position not empty-------"<< endl;
        playerInput(player);
    } else {
        emptyIndex[pos] = 1;
        emptyCount= emptyCount - 1;
        player.getName().compare(player.getName()) == 0 ? board[pos] ='X': board[pos] ='O';
    }

}

void Game::checkWin(Player &p1,Player &p2){
    char first_symbol;
    int i,j,k;
    bool flag = false;

    for(i=0; i<8; i++){
        first_symbol = board[list[i].row[0]];

        if((first_symbol != 'X') && (first_symbol != 'O')){
            flag = false;
            continue;
        }
        flag = true;
        for(j=0;j<3;j++){
            if(first_symbol != board[list[i].row[j]]){
                flag = false;
                break;
            }
        }
        if(flag){
            gameOn = 0;
            if(first_symbol == 'X'){
                cout << "-----------------------"<< endl;
                cout << "\t Player I WON"<< endl;
                cout << "-----------------------"<< endl;
                p1.won();
            } else {
                p2.won();
                if(againstComputer){
                    cout << "-----------------------"<< endl;
                    cout << "\t Computer WON"<< endl;
                    cout << "-----------------------"<< endl;
                } else {
                    cout << "-----------------------"<< endl;
                    cout << "\t Player II WON"<< endl;
                    cout << "-----------------------"<< endl;

                }
            }
            displayScore(p1,p2);
            break;
        }
    }
}

void Game::play(Player &p1,Player &p2){
    char rematch ='\0';
    int hand = 0;
    gameOn =1;
    display();
    while((emptyCount > 0) && (gameOn != 0)){

        if(againstComputer)
            hand == 1 ? botInput() : playerInput(p2);
        else
            hand == 1 ? playerInput(p1): playerInput(p2);
        hand= !hand;
        display();
        checkWin(p1,p2);
    }
    if (emptyCount <=0){
        cout << "      -----------------------"<< endl;
        cout << "\t No WINNER"<< endl;
        cout << "      -----------------------"<< endl;
    }
    cout<< endl;
    cout << "Rematch Y/N: ";
    cin >> rematch;
    if((rematch == 'Y')||(rematch == 'y')){
        init();
        play(p1,p2);
    }

}

void Game::displayScore(Player &p1, Player &p2){
    cout << endl;
    cout << "\t SCORE: \t";
    if(againstComputer)
        cout<<" Player I: " <<p1.getScore()<<" \t Computer: "<<p2.getScore()<< endl;
    else
        cout<<" Player I: " <<p1.getScore()<<" \t Player II: "<<p2.getScore()<< endl;
}

emptyCount{0}, gameOn{1}, againstComputer{0}{
    init();
    winlist[0].row = new int[3]{0,1,2};
    winlist[1].row = new int[3]{3,4,5};
    winlist[2].row = new int[3]{6,7,8};
    winlist[3].row = new int[3]{0,3,6};
    winlist[4].row = new int[3]{1,4,7};
    winlist[5].row = new int[3]{2,5,8};
    winlist[6].row = new int[3]{0,4,8};
    winlist[7].row = new int[3]{2,4,6};
}

void Game::init(){
    gameOn = 1;

    emptyCount =0;
    srand(time(0));
    for(size_t i=0; i<10; i++){
        emptyIndex[i] = 0;
        board[i] = (i+1) +'0';
        emptyCount++;
    }
    emptyCount--;
}

void Game::onePlayerGame(){
    //Creating Player
    string p1;
    cin >> p1;
    Player p(p1);
    Player c("Computer");
    cout << "       -----------------------"<< endl;
    cout << "\t Player " + p.getName() + ": X" + "\t Computer: O"<< endl;
    cout << "       -----------------------"<< endl;
    cout << endl;
    againstComputer = 1;
    play(c,p);

}

void Game::twoPlayerGame(){
    //Creating Player
    string p1;
    string p2;
    cin >> p1;
    cin >> p2;
    Player p(p1);
    Player c(p2);
    cout << "       -----------------------"<< endl;
    cout << "\t Player " + p.getName() + ": X" "\t Player " + c.getName() + ": O"<< endl;
    cout << "       -----------------------"<< endl;
    cout << endl;
    againstComputer = 0;
    play(c,p);
}
const char *Game::getBoard() const {
    return board;
}

const int *Game::getEmptyIndex() const {
    return emptyIndex;
}

int Game::getGameOn() const {
    return gameOn;
}

void Game::setGameOn(int gameOn) {
    Game::gameOn = gameOn;
}

int Game::getAgainstComputer() const {
    return againstComputer;
}

void Game::setAgainstComputer(int againstComputer) {
    Game::againstComputer = againstComputer;
}

int Game::getEmptyCount() const {
    return emptyCount;
}

void Game::setEmptyCount(int emptyCount) {
    Game::emptyCount = emptyCount;
}

const List *Game::getlist() const {
    return list;
}
