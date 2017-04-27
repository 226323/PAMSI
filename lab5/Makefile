CPP = g++ -std=c++11
FLAGS= -Wall -pedantic -I inc/ 
OBJECTS = obj/main.o obj/klasa.o obj/plus1.o obj/razy2.o obj/iclock.o
__start__: a.out
	./a.out

a.out: ${OBJECTS}
	${CPP} ${FLAGS} ${OBJECTS}

obj/main.o: src/main.cpp inc/klasa.hh inc/plus1.hh
	${CPP} ${FLAGS} -c -o obj/main.o src/main.cpp

obj/klasa.o: src/klasa.cpp inc/klasa.hh 
	${CPP} ${FLAGS} -c -o obj/klasa.o src/klasa.cpp

obj/plus1.o: src/plus1.cpp inc/plus1.hh
	${CPP} ${FLAGS} -c -o obj/plus1.o src/plus1.cpp

obj/razy2.o: src/razy2.cpp inc/razy2.hh
	${CPP} ${FLAGS} -c -o obj/razy2.o src/razy2.cpp

#obj/ilist.o: src/ilist.cpp inc/ilist.hh
#	${CPP} ${FLAGS} -c -o obj/ilist.o src/ilist.cpp

obj/istack.o: src/istack.cpp inc/istack.hh
	${CPP} ${FLAGS} -c -o obj/stack.o src/stack.cpp

obj/iqueue.o: src/iqueue.cpp inc/iqueue.hh
	${CPP} ${FLAGS} -c -o obj/iqueue.o src/iqueue.cpp

obj/iclock.o: src/iclock.cpp inc/iclock.hh
	${CPP} ${FLAGS}	-c -o obj/iclock.o src/iclock.cpp


clean:
	-rm -rf ${OBJECTS} a.out
