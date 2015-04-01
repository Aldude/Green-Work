BTMPDIR=sakaluk_db
# Corey, put your CCID here instead of corey
CTMPDIR=corey_db

corey:
	mkdir /tmp/$(CTMPDIR)
	gcc -o mydbtest sample.c -ldb -pthread -lm
	mv ./mydbtest /tmp/$(CTMPDIR)

blake:
	mkdir /tmp/$(BTMPDIR)
	gcc -o mydbtest sample.c -ldb -pthread -lm
	mv ./mydbtest /tmp/$(BTMPDIR)
	
clean:
	cd ~
	rm -f /tmp/$(BTMPDIR)/*
	rm -f /tmp/$(CTMPDIR)/*
	rmdir /tmp/$(BTMPDIR)
	rmdir /tmp/$(CTMPDIR)