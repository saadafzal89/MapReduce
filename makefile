all:	mapper reducer combiner

mapper: mapper.c
	gcc -o mapper mapper.c
reducer: reducer.c
	gcc -o reducer reducer.c
combiber: combiner.c
	gcc -o combiber combiner.c
clean:
	rm -rf mapper reducer combiner
