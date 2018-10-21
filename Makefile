CXXFLAGS=-std=c++11


Projekt: main.o HashSet.o Mieszkanie.o MieszkanieHipoteczne.o MieszkanieWynajmowane.o Siedziba.o	
	g++ $(CXXFLAGS) main.o HashSet.o Mieszkanie.o MieszkanieHipoteczne.o MieszkanieWynajmowane.o Siedziba.o -o Mieszkanie 

main.o: main.cpp Mieszkanie.h
	
	g++ $(CXXFLAGS) -c main.cpp
HashSet.o: HashSet.h HashSet.cpp
	
	g++ $(CXXFLAGS) -c HashSet.cpp
 
Mieszkanie.o: Mieszkanie.h Mieszkanie.cpp
	
	g++ $(CXXFLAGS) -c Mieszkanie.cpp

MieszkanieHipoteczne.o: MieszkanieHipoteczne.h MieszkanieHipoteczne.cpp
	
	g++ $(CXXFLAGS) -c MieszkanieHipoteczne.cpp

MieszkanieWynajmowane.o: MieszkanieWynajmowane.h MieszkanieWynajmowane.cpp
	
	g++ $(CXXFLAGS) -c MieszkanieWynajmowane.cpp

Siedziba.o: Siedziba.h Siedziba.cpp
	
	g++ $(CXXFLAGS) -c Siedziba.cpp


clean:
	rm -f *.o
