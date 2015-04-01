CFLAGS=-ldb -pthread -lm
# Add .c files to this list as we add more files
FILES=Main.c DBSetup.c
OUT=mydbtest
# tmp/ for ease of testing, assignment spec is /tmp/
DIR=tmp/

# Call make userrun where user is your CCID
# and a temp directory under your CCID will be made
# and the program will start

%run1: %db
	./$(DIR)$*_db/$(OUT) btree

%run2: %db
	./$(DIR)$*_db/$(OUT) hash

%run3: %db
	./$(DIR)$*_db/$(OUT) indexfile

%db: | %dir
	gcc -o $(OUT) $(FILES) $(CFLAGS)
	mv ./$(OUT) $(DIR)$*_db/$(OUT)

%dir:
	mkdir $(DIR)$*_db

# Call make userdone where user is your CCID
# and the temp directory, including all contents
# will be removed

%done:
	rm -f $(DIR)$*_db/*
	rmdir $(DIR)$*_db