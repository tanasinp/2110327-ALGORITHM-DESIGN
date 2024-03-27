#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;
int mx[] = {0,0,1,-1};
int my[] = {1,-1,0,0};
int visited[1010][1010];
vector<int> ghost[101];
int k;

int main(){
    cin >> k;
    while(k--){
        //set map all 0;
        int g[1010][1010];
        for(int i=0;i<1010;i++){
            for(int j=0;j<1010;j++){
                g[i][j] = 0;
            }
        }
        ////
        int R,C,n,T,r,c;
        cin >> R >> C >> n >> T >> r >> c;
        int ti,ri,ci;
        g[r][c] = 1;
        queue<pair<pair<int,int>,pair<pair<int,int>,int>>> q;
        for(int i=0;i<n;i++){
            cin >> ti >> ri >> ci;
            q.push({{ri,ci},{{ti,1},1}}); // {r,c},{ti,T}
        }
        q.push({{r,c},{{-1,1},0}});
        for(int i=0;i<R;i++){
            string s; cin >> s;
            for(int j=0;j<C;j++){
                if(s[j] == '#') g[i][j] = 4;
            }
        }
        while(!q.empty()){
            int cr = q.front().first.first;
            int cc = q.front().first.second;
            int cti = q.front().second.first.first;
            int cd = q.front().second.first.second;
            int type = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = cr+mx[i];
                int nc = cc+my[i];
                if(0 <= nr && nr < R && 0 <= nc && nc < C && cd <= T){
                    if(cti >= 0){
                        if(type == 1 && cti == 0){
                            g[cr][cc] = 2;
                            q.push({{nr,nc},{{cti-1,cd+1},type}});
                        } else {
                            q.push({{nr,nc},{{cti-1,cd+1},type}});
                        }
                    } else {
                        if(type == 1){ //ghost
                            if(g[nr][nc] < 2) g[nr][nc] = 2;
                            q.push({{nr,nc},{{cti-1,cd+1},1}});
                        } else if(type == 0 && g[cr][cc] == 1){ //pacman
                            if(g[nr][nc] == 0) g[nr][nc] = 1;
                            q.push({{nr,nc},{{cti-1,cd+1},0}});
                        }
                    }
                }
            }
        }
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cout << g[i][j] << "\t";
            }
            cout << "\n";
        }

    }
}