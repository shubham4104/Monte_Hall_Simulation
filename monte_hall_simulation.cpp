/*
Problem Statement: Simulate Monte Hall game simulation
Doors are represented using variables to improve the readibiloty and help others understand the code who dont have the backgrouund.
Doors and moves can be captured using Array or Vector. (This would reduce the code further)
*/
#include<bits/stdc++.h>
using namespace std;

class State {
private:
	int doorA,doorB,doorC;
public:
	State() {
		initialise();
	}
	
	void initialise() {
		int door_car = rand()%3;
		setDoorA(0); setDoorB(0); setDoorC(0);
		switch(door_car) {
			case 0:
				setDoorA(1);
				break;
			case 1:
				setDoorB(1);
				break;
			case 2:
				setDoorC(1);
				break;
		}
	}
	// setters
	void setDoorA(int state) {
		doorA=state;
	}
	void setDoorB(int state) {
		doorB=state;
	}
	void setDoorC(int state) {
		doorC=state;
	}

	// getters
	int getDoorA() {
		return doorA;
	}	
	int getDoorB() {
		return doorB;
	}
	int getDoorC() {
		return doorC;
	}
};

class Monte_Hall {
public:
	int generate_choice() {
		return rand()%3;
	}

	int simulate(int iter, int mode=0) {
		int count_wins=0;
		while(iter--) {
			State curr_state;
			int choice = generate_choice();
			switch(choice) {
				case 0:
					if(mode==1 && curr_state.getDoorA()==0) {
						count_wins++;	
					}
					else if(mode==0 && curr_state.getDoorA()==1) {
						count_wins++;
					}
					break;
				case 1:
					if(mode==1 && curr_state.getDoorB()==0) {
						count_wins++;	
					}
					else if(mode==0 && curr_state.getDoorB()==1) {
						count_wins++;
					}
					break;
				case 2:
					if(mode==1 && curr_state.getDoorC()==0) {
						count_wins++;	
					}
					else if(mode==0 && curr_state.getDoorC()==1) {
						count_wins++;
					}
					break;
			}
		}
		return count_wins;
	}

};
int main() {
	int seed, iterations=10000;
	srand(seed);
	Monte_Hall obj;
	int wins = obj.simulate(iterations, 0);
	cout<<"total wins if we stick to the choice: "<<wins<<endl;
	cout<<"probability of winning inn this case: "<<wins*1.0/iterations<<"\n\n";

	wins = obj.simulate(10000, 1);
	cout<<"total wins if we change the choice: "<<wins<<endl;
	cout<<"probability of winning inn this case: "<<wins*1.0/iterations<<endl;	
	return 0;
}
