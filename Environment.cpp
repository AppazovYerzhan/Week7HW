#include "Environment.h"
#include "Player.h"


class List;

void Environment::display() {
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
void Environment::botInput(){
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
void Environment::playerInput(Player &player, int whichPlayer){
    int pos;
    cout << endl;
    cout << "\t" << player.getName() <<"`s Turn: ";
    cout <<"\t Enter the position " << endl;
    cin >> pos;
    pos -=1;
    if(emptyIndex[pos] == 1){
        cout << "-----Position not empty-------"<< endl;
        playerInput(player, whichPlayer);
    } else {
        emptyIndex[pos] = 1;
        emptyCount--;
        if (whichPlayer == 1){
            board[pos] ='O';
        }
        else{
            board[pos] ='X';
        }
    }

}

void Environment::checkWin(Player &p1,Player &p2){
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
                cout <<"\t"<< p2.getName()<<" WON!"<< endl;
                cout << "-----------------------"<< endl;
                p1.won();
            } else {
                p2.won();
                if(againstComputer){
                    cout << "-----------------------"<< endl;
                    cout << "\t Even Computer without logic WON You"<< endl;
                    cout << "-----------------------"<< endl;
                } else {
                    cout << "-----------------------"<< endl;
                    cout <<"\t"<<p2.getName()<<" WON!"<< endl;
                    cout << "-----------------------"<< endl;
                }
            }
            displayScore(p1,p2);
            break;
        }
    }
}

void Environment::play(Player &p1,Player &p2){
    char rematch ='\0';
    int hand = 0;
    gameOn =1;
    display();
    while((emptyCount > 0) && (gameOn != 0)){

        if(againstComputer)
            hand == 1 ? botInput() : playerInput(p2, 3);
        else
            hand == 1 ? playerInput(p1, 1): playerInput(p2, 2);
         hand= !hand;
        display();
        checkWin(p1,p2);
    }
    if (emptyCount <=0){
        cout << "      -----------------------"<< endl;
        cout << "\t No WINNERS"<< endl;
        cout << "      -----------------------"<< endl;
    }
    cout<< endl;
    cout << "Rematch Y/N: ";
    cin >> rematch;
    if((rematch == 'Y')||(rematch == 'y')||(rematch == 'yes')){
        init();
        play(p1,p2);
    }

}

void Environment::displayScore(Player &p1, Player &p2){
    cout << endl;
    cout << "\t SCORE: \t";
    if(againstComputer)
        cout<<" "<<p2.getName()<<": " <<p1.getScore()<<" \t Computer: "<<p2.getScore()<< endl;
    else
        cout<<"\t"<<p2.getName()<<": " <<p1.getScore()<<"\t"<<p1.getName()<<": "<<p2.getScore()<< endl;
}

Environment::Environment() : emptyCount{0}, gameOn{1}, againstComputer{0}{
    init();
    Environment::list[0].row = new int[3]{0,1,2};
    Environment::list[1].row = new int[3]{3,4,5};
    Environment::list[2].row = new int[3]{6,7,8};
    Environment::list[3].row = new int[3]{0,3,6};
    Environment::list[4].row = new int[3]{1,4,7};
    Environment::list[5].row = new int[3]{2,5,8};
    Environment::list[6].row = new int[3]{0,4,8};
    Environment::list[7].row = new int[3]{2,4,6};
}

void Environment::init(){
    gameOn = 1;

    emptyCount =0;
    srand(time(NULL));
    for(int i=0; i<10; i++){
        emptyIndex[i] = 0;
//        board[i] = (i+1) +'0';
        board[i] = ' ';
        emptyCount++;
    }
    emptyCount--;
}

void Environment::onePlayerGame(){
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

void Environment::twoPlayerGame(){
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
const char *Environment::getBoard() const {
    return board;
}

const int *Environment::getEmptyIndex() const {
    return emptyIndex;
}

int Environment::getGameOn() const {
    return gameOn;
}

void Environment::setGameOn(int gameOn) {
    Environment::gameOn = gameOn;
}

int Environment::getAgainstComputer() const {
    return againstComputer;
}

void Environment::setAgainstComputer(int againstComputer) {
    Environment::againstComputer = againstComputer;
}

int Environment::getEmptyCount() const {
    return emptyCount;
}

void Environment::setEmptyCount(int emptyCount) {
    Environment::emptyCount = emptyCount;
}

