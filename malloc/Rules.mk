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
malloc/$(OBJECT_DIR)/join_free_blocks_around.o: \
  malloc/join_free_blocks_around.c malloc/algorithm.h \
  malloc/malloc_data.h
malloc/$(OBJECT_DIR)/malloc.o: malloc/malloc.c malloc/malloc.h \
  malloc/algorithm.h malloc/malloc_data.h utils/utils.h
malloc/malloc.h:
malloc/$(OBJECT_DIR)/search_in_areas.o: malloc/search_in_areas.c \
  malloc/algorithm.h malloc/malloc_data.h utils/utils.h
malloc/$(OBJECT_DIR)/show_alloc_mem.o: malloc/show_alloc_mem.c \
  malloc/malloc.h utils/utils.h malloc/malloc_data.h \
  libft/output/obuff.h libft/memory/memory.h
libft/output/obuff.h:
libft/memory/memory.h:
