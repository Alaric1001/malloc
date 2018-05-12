TEST_CC			:= g++
TEST_CFLAGS		:= -I. -I$(CPPUNIT_PATH)/include
TEST_LFLAGS		:= -L$(CPPUNIT_PATH)/lib -L. -ldl -lcppunit -lft_malloc
COMPLINK		:= $(CC) $(TEST_CFLAGS) $(TEST_LFLAGS) -o

CURR_DIR		:= tests
TEST_FILES		:= test.cpp
TEST_OBJECTS	:= $(addprefix $(CURR_DIR)/$(OBJECT_DIR)/, $(TEST_FILES:.cpp=.o))
RUN_TEST_RULES	:= $(addprefix run-, $(TEST_FILES:.cpp=))

TEST_FILES		:= $(addprefix $(CURR_DIR)/, $(TEST_FILES))
TEST_TARGETS	:= $(TEST_FILES:.cpp=)
TEST_OBJ_DIR	:= $(CURR_DIR)/$(OBJECT_DIR)

OBJ_DIRS 		+= $(TEST_OBJ_DIR)

.PHONY: run-all-tests
run-all-tests: $(RUN_TEST_RULES)

.PHONY: $(RUN_TEST_RULES)
$(RUN_TEST_RULES): all $(TEST_OBJ_DIR) $(TEST_TARGETS)
	@echo $(BLUE)"Executing test:"$(RESET) $@
	@$(addprefix $(CURR_DIR)/, $(subst run-,, $@))

$(CURR_DIR)/%: $(CURR_DIR)/$(OBJECT_DIR)/%.o
	$(TEST_CC) $(TEST_LFLAGS) -o $@ $<

$(CURR_DIR)/$(OBJECT_DIR)/%.o: $(CURR_DIR)/%.cpp
	$(TEST_CC) $(TEST_CFLAGS) -c -o $@ $<
