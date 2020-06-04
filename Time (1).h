#ifndef TIME_H_
#define TIME_H_

class Time{
public:
	Time();
	Time(int,int,int);
	void setTime(int,int,int);
	void printUniversal();
private:
	int hour,minute,second;
};
#endif /* TIME_H_ */
