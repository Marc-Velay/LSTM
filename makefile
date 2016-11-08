CPP=clang++
CFLAG=-Wall -Wextra #-Werror -O3 

all: compile exec clean

compile: dataReader.o LSTM.o RNN.o
	${CPP} -o LSTM $^

%.o: %.cpp
	${CPP} -o $@ -c $< ${CFLAG}

exec:
	./LSTM

clean:
	rm *.o LSTM
