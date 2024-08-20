# Written for Mac OSX - 10.7.4

chap16: main.cpp heston_mc.o correlated_snd.o statistics.o option.o payoff.o
	clang++ -o chap16 main.cpp heston_mc.o correlated_snd.o statistics.o option.o payoff.o -arch x86_64

heston_mc.o: heston_mc.cpp option.o
	clang++ -c heston_mc.cpp option.o -arch x86_64

correlated_snd.o: correlated_snd.cpp statistics.o
	clang++ -c correlated_snd.cpp statistics.o -arch x86_64

statistics.o: statistics.cpp 
	clang++ -c statistics.cpp -arch x86_64

option.o: option.cpp payoff.o
	clang++ -c option.cpp payoff.o -arch x86_64 

payoff.o: payoff.cpp
	clang++ -c payoff.cpp -arch x86_64
