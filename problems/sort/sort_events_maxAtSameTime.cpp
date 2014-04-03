#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

//given set of events (start,end) determine max # of events that happen at same time
//solution sort the endpoints (start & end) in ASC order and iterate from smallest. If it's a starting time +1 else -1

struct EndPoint{
	int time;	
	bool start; //true=start, false=end
	
	EndPoint(){ //for array initialization
		time=-1;
	}
	
	EndPoint(int _time,bool _start){
		time=_time;
		start=_start;
	}
	
	//returns true if this.time<other.time or if this is a start endpoint and the other isnt
	//endpoint should be before start if equal times. SO that 8-9 doesnt intersect 9-17
	bool operator<(const EndPoint & other) const {
		return time!=other.time? time < other.time : (!start && other.start) ;
	}
};


int main(){
	string events="11 13 " //dont forget the space
					"6 10 "
					//"4 5 " this one makes it easier
					"2 7 "
					"9 17 "
					"12 15 "
					"14 15 "
					"8 9 "
					"1 5 ";
			
	EndPoint interval[100];	
					
	stringstream ss(events);
	int start,end,count=0;
	while(ss>>start>>end){
		EndPoint endpointA=EndPoint(start,true);
		EndPoint endpointB=EndPoint(end,false);
		interval[count++]=endpointA;
		interval[count++]=endpointB;

	}
	
	sort(interval,interval+count);
	
	int concurrent=0;
	int max=0;
	for(int i=0;i<count;i++){
		if(interval[i].start==true){
			concurrent++;
		}
		else{
			concurrent--;
		}
		if(concurrent>max){
			cout<<"Max at: "<<interval[i].time<<" isStart:"<<interval[i].start<<endl;
			cout<<"\t max:"<<concurrent<<endl;
			max=concurrent;
		}
	}

	return 0;
}




































