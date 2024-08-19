# Written for Mac OSX - 10.7.4

chap4: main.cpp payoff_double_digital.o payoff.o
	clang++ -o chap4 main.cpp payoff_double_digital.o payoff.o -arch x86_64

payoff_double_digital.o: payoff_double_digital.cpp payoff.o
	clang++ -c payoff_double_digital.cpp payoff.o -arch x86_64

payoff.o: payoff.cpp
	clang++ -c payoff.cpp -arch x86_64
