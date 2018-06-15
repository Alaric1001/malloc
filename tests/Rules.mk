TEST_CC			:= g++
TEST_CFLAGS		:= -I. -I$(CPPUNIT_PATH)/include -std='c++14' -g
TEST_LFLAGS		:= -L$(CPPUNIT_PATH)/lib -ldl -lcppunit -L./libft -lft
COMPLINK		:= $(CC) $(TEST_CFLAGS) $(TEST_LFLAGS) -o

CURR_DIR		:= tests
TEST_FILES		:= 	utest-utils.cpp
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
	$(eval TEST_NAME := $(subst run-,, $@))
	$(eval FAIL := $(shell $(addprefix $(CURR_DIR)/, $(TEST_NAME)) > $(TEST_NAME).out; echo $$?))
	@if [ $(FAIL) -gt 0 ]; \
	then \
		echo "["$(RED)KO$(RESET)"] -" $(TEST_NAME); \
		cat $(TEST_NAME).out; \
	else \
		echo "["$(GREEN)OK$(RESET)"] -" $(TEST_NAME); \
	fi
	@rm -f $(TEST_NAME).out

$(CURR_DIR)/%: $(CURR_DIR)/$(OBJECT_DIR)/%.o $(NAME)
	$(TEST_CC) $(TEST_LFLAGS) -o $@ $< $(OBJECTS)

$(CURR_DIR)/$(OBJECT_DIR)/%.o: $(CURR_DIR)/%.cpp
	$(TEST_CC) $(TEST_CFLAGS) -c -o $@ $<
