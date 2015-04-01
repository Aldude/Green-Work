# Add .c files to this list as we add more files
FILES=Main.c
OUT=mydbtest

# Call make userdb where user is your CCID
# and a temp directory under your CCID will be made

%db:
	mkdir /tmp/$*_db
	gcc -o $(OUT) $(FILES) -ldb -pthread -lm
	mv ./$(OUT) /tmp/$*_db/$(OUT)

# Call make userdone where user is your CCID
# and the temp directory, including all contents
# will be removed

%done:
	cd ~
	rm -f /tmp/$*_db/*
	rmdir -f /tmp/$*_db