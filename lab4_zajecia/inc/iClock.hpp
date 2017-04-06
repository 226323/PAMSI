#ifndef iClock_HPP
#define iClock_HPP

class iClock
{
    public:
	virtual void begin()=0;			//poczatek pomiaru czasu
	virtual void stop()=0;			//koniec pomiaru czasu
	virtual void duration_out()=0;	//wydrukowanie roznicy czasy
	virtual double duration()=0;		//zwrocenie roznicy czasu
};
#endif
