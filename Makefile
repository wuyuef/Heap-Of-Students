heap: Address.o Date.o Student.o  main.o
	g++ Address.o Date.o Student.o  main.o -o heap

Student.o: Student.cpp Student.h Address.h Date.h
	g++ -c Student.cpp

Address.o: Address.cpp Address.h
	g++ -c Address.cpp

Date.o: Date.cpp Date.h
	g++ -c Date.cpp	

main.o: main.cpp Address.h Date.h Student.h
	g++ -c main.cpp

clean: 
	rm -f *.o
	rm heap
