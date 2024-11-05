a: *.cpp
	g++ *.cpp -o task1

run: 
	./task1

clean:
	rm *.o task1

valgrind: a
	valgrind --leak-check=full -s ./task1

zip:
	tar -cvz *.cpp *.h -f u23681978.zip