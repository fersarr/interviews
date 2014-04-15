

//struct array init 
EndPoint interval[100]; //initializes. So if its a struct or class remember to have a construct with no params EndPoint()


//for struct sorting don't forget 2 CONST !!!!

//returns true if this.time<other.time or if this is a start endpoint and the other isnt
bool operator<(const EndPoint & other) const {
	return time!=other.time? time < other.time : (start && !other.start) ;
}


//multiline string
string events="11 13 " //dont forget the space
					"6 10 "
					"4 5 "
					"2 7 "
					"9 17 "
					"12 15 "
					"14 15 "
					"8 9 "
					"1 5 ";
