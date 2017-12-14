COMPLIED = complied
SRC = src
C_FILE_LIST = $(foreach dir, $(SRC), $(wildcard $(dir)/*.c))
O_FILE_LIST = $(patsubst $(SRC)/%.c, $(COMPLIED)/%.o, $(C_FILE_LIST))
D_FILE_LIST = $(patsubst $(SRC)/%.c, $(COMPLIED)/%.d, $(C_FILE_LIST))
APPLICATION = sort
APPLICATION_DEPENDENCE = $(COMPLIED)/sort.o $(COMPLIED)/_sort.o
$(APPLICATION):$(APPLICATION_DEPENDENCE)
	gcc $^ -o $(APPLICATION)

$(COMPLIED)/%.o:$(SRC)/%.c
	gcc -c -MMD $< -o $@

-include $(D_FILE_LIST)

clean:
	rm -rf *.o *.d $(APPLICATION)
	rm -rf $(COMPLIED)/* 

var:
	@echo $(C_FILE_LIST)
	@echo $(O_FILE_LIST)
	@echo $(D_FILE_LIST)
	@echo $(APPLICATION)
	@echo $(APPLICATION_DEPENDENCE)

