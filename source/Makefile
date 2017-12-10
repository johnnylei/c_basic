#!/bin/bash
SUBDIR = src xml
SUBDIR += osapi
C_FILE_LIST = $(wildcard *.c)
#O_FILE_LIST = $(wilecard *.o)
O_FILE_LIST = $(patsubst %.c, %.o, $(C_FILE_LIST))
APPLIACTION = sort
$(APPLIACTION):sort.h	sort.o _sort.o 
	gcc $^ -o $(APPLIACTION)

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm *.o $(APPLIACTION)

var:
	@echo $(SUBDIR)

wild_card:
	@echo $(C_FILE_LIST)
	@echo $(O_FILE_LIST)

