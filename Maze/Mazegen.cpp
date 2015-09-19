#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <time.h>


using namespace std;


int mazegen::direction(){
	
	return rand()%4+1;
}

bool mazegen::check (int x, int y){
	bool ans=false;
	if (x-2>0){
		if (graph[x-2][y]==false){
			ans=true;
		}
	}
	if (x+2<41){
		if (graph[x+2][y]==false){
			ans=true;
		}
	}
	if (y-2>0){
		if (graph[x][y-2]==false){
			ans=true;
		}
	}
	if (y+2<61){
		if (graph[x][y+2]==false){
			ans=true;
		}
	}
	return ans;

}
 

void mazegen::generatemaze(){
	stack <int> stackx;
	stack <int> stacky;
	graph[1][1]=true;



	stackx.push(1);
	stacky.push(1); 
	//cout<<stackx.size();
	int xpos;
	int ypos;
	int iter;

	while(stackx.size()>0){
		//iter+=1;
		xpos=stackx.top();
		ypos=stacky.top();
		//cout<<stackx.size()<<endl;
		//cout<<xpos<<" " << ypos<<endl;
		if (check(xpos,ypos)){
			int dir = direction();
			
			if (dir==1){
				if ((xpos+2)<41){
					if (graph[xpos+2][ypos]==false){
						graph[xpos+2][ypos]=true;
						graph[xpos+1][ypos]=true;
						stackx.push(xpos+2);
						stacky.push(ypos);
					}
				}
			}
			else if (dir==2){
				if ((xpos-2)>0){
					if (graph[xpos-2][ypos]==false){
						graph[xpos-2][ypos]=true;
						graph[xpos-1][ypos]=true;
						stackx.push(xpos-2);
						stacky.push(ypos);
					}
				}
			}
			else if (dir ==3){
				if ((ypos+2)<61){
					if (graph[xpos][ypos+2]==false){
						graph[xpos][ypos+1]=true;
						graph[xpos][ypos+2]=true;
						stackx.push(xpos);
						stacky.push(ypos+2);

					}
				}
			}
			else if (dir==4){
				if ((ypos-2)>0){
					if (graph[xpos][ypos-2]==false){
						graph[xpos][ypos-2]=true;
						graph[xpos][ypos-1]=true;
						stackx.push(xpos);
						stacky.push(ypos-2);

					}
				}
			}
		
			

		}
		else{
			stackx.pop();
			stacky.pop();

		}
	}

}



