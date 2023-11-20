# Default target executed when no arguments are given to make.
default_target: all

#The .PHONY line declares all and clean as phony targets. A phony target is one that does not represent a file; it purely represents a command to be executed.
.PHONY: all clean run deploy submit

all:
	./build.sh

clean:
	./build.sh clean

run:
	./build.sh web

deploy:
	./build.sh deploy

submit:
	juniorit submit