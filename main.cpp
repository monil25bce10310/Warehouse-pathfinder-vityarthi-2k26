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

int main(){
  
  return 0;
}
