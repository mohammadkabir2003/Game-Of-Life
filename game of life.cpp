#include <vector>
#include <iostream>
using namespace std;

vector<vector<bool>> world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
const int rows=10;
const int cols=20;

int countNghbrs(const vector<vector<bool>> w, int x, int y);
bool changeNghbrs(const vector<vector<bool>> w, int x, int y);


int main(int argc, char *argv[])
{
	vector<vector<bool>> future(world); 
	int gen = 0;
	if(argv[1])
	{
		gen += atoi(argv[1]);
	}
	for(int h = 0; h < gen; h++)
	{
		for (int i = 0; i < world.size(); i++)
		{
			for (int j = 0; j< world[i].size(); j++)
			{
				future[i][j] = changeNghbrs(world, i, j);
			}
		}
	world = future;
	}

	for(int i = 0; i < rows; i++){
    	for(int j = 0; j < cols; j++)
		{
            if(world[i][j]) 
			{
                cout << "O";
            } 
            else 
			{
                cout << ".";
            }
        }
        cout << "\n";
    }

	return 0;
}


int countNghbrs(const vector<vector<bool>> w, int x, int y)
{
	int numNghbrs = 0;
	for (int i=-1; i<2; i++ )
	{
		for (int j=-1; j<2; j++ )			
		{
			numNghbrs += world[(x+i+rows)%rows][(y+j+cols)%cols];
		}	
	}
	return numNghbrs - world[x][y];
}


bool changeNghbrs(const vector<vector<bool>> w, int x, int y)
{
	int numAlive = countNghbrs(w, x, y);
	if (w[x][y])
	{
		if (numAlive > 3 || numAlive < 2)
		{
			return false;
		}
		else 
		{
			return true;
		}
	}
	else 
	{
		if (numAlive == 3)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
}


