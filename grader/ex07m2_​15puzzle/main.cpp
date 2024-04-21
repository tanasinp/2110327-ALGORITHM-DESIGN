#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
// #include<bits/stdc++.h>
using namespace std;

int ans = INT_MAX;
const int space = 0;

const vector<vector<int>> goal = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

const vector<vector<int>> goal_pos = {
    {3,3},
    {0,0},
    {0,1},
    {0,2},
    {0,3},
    {1,0},
    {1,1},
    {1,2},
    {1,3},
    {2,0},
    {2,1},
    {2,2},
    {2,3},
    {3,0},
    {3,1},
    {3,2},
};

class Board{
    public:
    vector<vector<int>> b;
    vector<int> move;

    int r,c;
    int heuristic_value;
    int heuristic_mode;

    Board(){
        b = goal;
        r = c = 3;
        heuristic_mode = 1;
    }

    bool isGoal(){
        return b == goal;
    }

    bool doMove(int direction){
        if(direction == 0){//up
            if(r == 0) return false;
            b[r][c] = b[r-1][c];
            b[r-1][c] = space;
            r--;
        } else if (direction == 1){//down
            if(r == 3) return false;
            b[r][c] = b[r+1][c];
            b[r+1][c] = space;
            r++;
        } else if (direction == 2){//left
            if(c == 0) return false;
            b[r][c] = b[r][c-1];
            b[r][c-1] = space;
            c--;
        } else if (direction == 3){//right
            if(c == 3) return false;
            b[r][c] = b[r][c+1];
            b[r][c+1] = space;
            c++;
        }
        move.push_back(direction);
        
        if(heuristic_mode == 0){
            heuristic_value = heuristic_0();
        }else{
            heuristic_value = heuristic_1();
        }
        
        return true;
    }

    int heuristic_0(){
        int count = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(b[i][j] != space && b[i][j] != goal[i][j]) count++;
            }
        }
        return move.size() + count;
    }

    int heuristic_1(){
        int sum = 0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(b[i][j] != space){
                    int rowDiff = abs(i-goal_pos[b[i][j]][0]);
                    int colDiff = abs(j-goal_pos[b[i][j]][1]);
                    sum = sum + rowDiff + colDiff;
                }
            }
        }
        return move.size() + sum;
    }

    bool operator<(const Board& other) const {
        return this->b < other.b;
    }
    
};

class heuristic_comparer {
    public:
    bool operator()(const Board &b1,Board &b2){
        return b1.heuristic_value > b2.heuristic_value;
    }
};

const vector<int> opposite_move = {1,0,3,2};

void lc_search(Board &start){
    set<Board> boards;
    priority_queue<Board,vector<Board>,heuristic_comparer> q;
    q.push(start);
    while(!q.empty()){
        Board b = q.top(); q.pop();

        if(b.isGoal()){
            cout << b.move.size();
            return;
        }

        for(int dir = 0;dir < 4;dir++){
            if(b.move.empty() == true || b.move.back() != opposite_move[dir]){
                Board newB = b;
                if(newB.doMove(dir)){
                    if(boards.find(newB) == boards.end()){
                        boards.insert(newB);
                        q.push(newB);
                    }
                }
            }
        }
    }
}

int main(){
    Board start;

    int ar,ac;
    vector<vector<int>> v(4,vector<int>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int x; cin >> x;
            if(x == 0){
                ar = i;
                ac = j;
            }
            v[i][j] = x;
        }
    }
    start.b = v;
    start.r = ar;
    start.c = ac;
    
    lc_search(start);
}