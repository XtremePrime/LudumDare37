#ifndef EVENT_H
#define EVENT_H

enum class Mode{
	FIXED_DAY,
	AFTER_DAY,
	ON_REQUIREMENTS
};

class Event
{
private:
	Mode mode;
	int day = -1;
	int requirements[5];
public:
	Event(int d, Mode m){
		this->day = d;
		this->mode = m;
	}

	void set_day(int d){this->day=d;}
	int get_day(){return this->day;}
	Mode get_mode(){return this->mode;}
};

#endif // EVENT_H
