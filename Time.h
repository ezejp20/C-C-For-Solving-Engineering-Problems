#ifndef TIME_H_
#define TIME_H_

class Time{
public:
	Time(int=0,int=0,int=0);
	void setTime(int,int,int);
	void printUniversal();
private:
	int hour,minute,second;
};
#endif /* TIME_H_ */
