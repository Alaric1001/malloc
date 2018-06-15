## Auto generated make tool, don't edit manually.
malloc/$(OBJECT_DIR)/%.o: malloc/%.c
	$(COMP) $@ $<
malloc/$(OBJECT_DIR)/alloc_block.o: malloc/alloc_block.c \
  malloc/algorithm.h malloc/malloc_data.h utils/utils.h \
  libft/output/output.h
malloc/algorithm.h:
malloc/malloc_data.h:
utils/utils.h:
libft/output/output.h:
malloc/$(OBJECT_DIR)/malloc.o: malloc/malloc.c malloc/malloc.h \
  malloc/algorithm.h malloc/malloc_data.h utils/utils.h
malloc/malloc.h:
