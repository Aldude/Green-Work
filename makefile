CFLAGS=-ldb -pthread -lm
DFLAGS=-g -Wall
# Add .c files to this list as we add more files
FILES=main.c DBSetup.c
OUT=mydbtest
# tmp/ for ease of testing, assignment spec is /tmp/
DIR=tmp/

# Call make userrun where user is your CCID
# and a temp directory under your CCID will be made
# and the program will start

%db:
	gcc -o $(OUT) $(FILES) $(CFLAGS)
	mv ./$(OUT) $(DIR)$*_db/$(OUT)

%debug:
	gcc -o $(OUT) $(FILES) $(CFLAGS) $(DFLAGS)
	mv ./$(OUT) $(DIR)$*_db/$(OUT)

%dir:
	mkdir $(DIR)
	mkdir $(DIR)$*_db

# Call make userdone where user is your CCID
# and the temp directory, including all contents
# will be removed

%done:
	rm -f $(DIR)$*_db/*
	rmdir $(DIR)$*_db
	rmdir $(DIR)