#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

//given a set of intervals(start,end), output the union of them all, i.e. the covered time. 
//output a set of >= intervals that cover all the given intervals


struct Event{
	int start,end;
	Event(){
		start=-1;
		end=-1;
	}
	Event(int _start,int _end){
		start=_start;
		end=_end;
	}
	
	//sort by start first then by end
	bool operator<(const Event & other) const{
		return start!=other.start ? start<other.start : end<other.end ;
	}
};

int main(){

	string eventsString="7 8 "
					"2 4 "
					"1 1 "
					"12 14 "
					"0 3 "
					"9 11 "
					"12 15 "
					"5 7 "
					"8 11 "
					"16 17 "
					"13 13 "
					"12 15 "
					"3 4 ";
					
	vector<Event> events;
	stringstream ss(eventsString);
	int start,end,count=0;
	
	while(ss>>start>>end){
		events.push_back(Event(start,end));
		count++;
	}
	
	sort(events.begin(),events.end());
	
	vector<Event> answer;

		
	int firstStart, lastEnd=-1;
	bool firstTime=true;
	for(int i=0;i<count;i++){
		if(lastEnd<events[i].start){ //new interval in union
			if(!firstTime)
				answer.push_back(Event(firstStart,lastEnd));
			firstTime=false;
			firstStart=events[i].start;
			lastEnd=events[i].end;
		}
		else{ //continue expanding current interval
			lastEnd=max(lastEnd,events[i].end);
		}
		
	}
	//add the last one
	answer.push_back(Event(firstStart,lastEnd));

	cout<<"Union of events"<<endl;
	
	vector<Event>::iterator it;
	for(it=answer.begin();it!=answer.end();it++){
		cout<<"Interval "<<it->start<<","<<it->end<<endl;
	}


















	return 0;
	
	
}























