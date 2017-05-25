#ifndef iTimer_HPP
#define iTimer_HPP

class iTimer
{
    public:
	virtual void begin()=0;			//poczatek pomiaru czasu
	virtual void stop()=0;			//koniec pomiaru czasu
	virtual double duration()=0;		//zwrocenie roznicy czasu
};
#endif
