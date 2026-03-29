// Warehouse path finder 

#include<iostream>
#include<queue>
using namespace std;

// Grid setup
class Grid{
    public:
        int obst;
        char arr[10][10];   // matrix size defined 
        
        
        void girdSetup(void){
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < 10; j++){
                    arr[i][j] = '.';
                }
            }

            // Hardcoded map for testing 

           arr[0][0] = 'S';

            arr[0][2] = 'X';
            arr[1][2] = 'X';
            arr[2][2] = 'X';
            arr[3][2] = 'X';

            arr[5][0] = 'X';
            arr[5][1] = 'X';
            arr[5][2] = 'X';
            arr[5][3] = 'X';
            arr[5][4] = 'X';
            arr[5][5] = 'X';
            arr[5][7] = 'X';
            arr[5][8] = 'X';
            arr[5][9] = 'X';

            arr[2][8] = 'X';
            arr[3][8] = 'X';
            arr[4][8] = 'X';

            arr[7][1] = 'X';
            arr[7][2] = 'X';
            arr[8][1] = 'X';

            arr[7][6] = 'X';
            arr[8][6] = 'X';
            arr[8][7] = 'X';

            arr[9][9] = 'E';

            
        }
        void gridDisplay(void){
            for (int i = 0; i < 10; i++)
            {
                cout<<"|";
                for (int j = 0; j < 10; j++)
                {
                    cout<<" "<<arr[i][j]<<" ";
                }
                cout<<"|"<<endl;
                
            }
            
        }
};


// Making the Robot and initalzing its postion 
class Robot{
    public:
    // Placing robot at 0,0
        int map_row = 0;
        int map_col = 9;

        char up = 'V';
        char down = 'V';
        char right = 'V';
        char left = 'V';

        // Stores the address of the grid 
        Grid& grid;

        Robot(Grid& g): grid(g){}
        
        void location_fetcher(void){
            cout<<"The location of the robot is "<<map_row<<" , "<<map_col<<endl;
            cout<<"And the staus is "<<grid.arr[map_row][map_col]<<endl;
        }

        void getNeighbour(void){
            
            if (map_row > 0)  up = grid.arr[map_row - 1][map_col]; 
            if (map_row < 9)  down = grid.arr[map_row +1][map_col];
            if (map_col > 0)  left = grid.arr[map_row][map_col - 1];
            if (map_col < 9)  right = grid.arr[map_row][map_col + 1]; 
            
            
            cout<<up<<endl<<down<<endl<<right<<endl<<left<<endl;

        }
        
};

class BFS : public Grid{
    public:
        queue<pair<int,int>> q;
        
        // This is going to store the data if the cells are Visited or not and by default , all are set to zero
        bool visited[10][10] = {false};
        int parentRow[10][10];      // This is going to store the Row of the previos cell form which it came 
        int parentCol[10][10];      // same , stores col of previous cell and there will be a whole matrix for one cordinat (col here)
        // current row and col of the cell 
        

        void pathFind(void){
            q.push({0,0});
            visited[0][0] = true;
            int r , c;

            while (!q.empty())
            {
                r = q.front().first;
                c = q.front().second; 
                q.pop();
                if (arr[r][c] == 'E')
                {
                    break;
                }
                
                
                if (r-1 >= 0 && arr[r-1][c] != 'X' && visited[r-1][c] == false)  // up
                { 
                    visited[r-1][c] = true;
                    parentRow[r-1][c] = r;
                    parentCol[r-1][c] = c;
                    q.push({r-1,c}); 
                    // We do not do this by ourself that to move it harcoded way as BFS does the thing by iteself , not
                    // in predefined or our hadcoded way like this 
                    //r = r-1;
                }
                if (r+1 <= 9 && arr[r+1][c] != 'X' && visited[r+1][c] == false){    // down
                    visited[r+1][c] = true;
                    parentRow[r+1][c] = r;
                    parentCol[r+1][c] = c;
                    q.push({r+1,c}); 
                }
                if (c+1 <= 9 && arr[r][c+1] != 'X' && visited[r][c+1] == false){      // right 
                    visited[r][c+1] = true;
                    parentRow[r][c+1] = r;
                    parentCol[r][c+1] = c;
                    q.push({r,c+1});
                } 
                if (c-1 >= 0 && arr[r][c-1] != 'X' && visited[r][c-1] == false){        // left
                    visited[r][c-1] = true;
                    parentRow[r][c-1] = r;
                    parentCol[r][c-1] = c;
                    q.push({r,c-1});
                }
                
            }
            
        }
        void tracePath(void){
        int r = 9, c = 9;   // start from E
    
        while (r != 0 || c != 0){
            arr[r][c] = '*';         // mark as path
            int pr = parentRow[r][c];
            int pc = parentCol[r][c];
            r = pr;
            c = pc;
        }
        arr[0][0] = 'S';    // keep S visible
        arr[9][9] = 'E';    // keep E visible
        }
};

int main(){
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n////////////////// Ware house path-finder\n\n\n ====================================\n\nA robot in storage facility is going to find a way out of this maze"<<endl;
    cout<<"This is hardcoded map but it can be customized also according to the layout of the building"<<endl;
    cout<<"\n\n\n\n Starting process......"<<endl<<endl;
    cout<<"\n\nMap layout\n\n\n";
    BFS bfs;
    bfs.girdSetup();
    bfs.gridDisplay();
    cout<<"\n\n\n============================================\n\n\n";
    cout << "Finding path...\n\n";
    bfs.pathFind();
    bfs.tracePath();
    bfs.gridDisplay();
    cout<<"\n\n\nPath found sucessfully !!\n\n";
    cout<<"Terminating process.........\n\nThank You !\n\n\n\n\n";
  return 0;
}
