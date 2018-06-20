## Auto generated make tool, don't edit manually.
utils/$(OBJECT_DIR)/%.o: utils/%.c
	$(COMP) $@ $<
utils/$(OBJECT_DIR)/add_new_block.o: utils/add_new_block.c utils/utils.h \
  malloc/malloc_data.h
utils/utils.h:
malloc/malloc_data.h:
utils/$(OBJECT_DIR)/get_area_size.o: utils/get_area_size.c utils/utils.h \
  malloc/malloc_data.h
utils/$(OBJECT_DIR)/get_block_type.o: utils/get_block_type.c \
  malloc/malloc_data.h
utils/$(OBJECT_DIR)/is_in_free_list.o: utils/is_in_free_list.c \
  utils/utils.h malloc/malloc_data.h
utils/$(OBJECT_DIR)/iter_area.o: utils/iter_area.c utils/utils.h \
  malloc/malloc_data.h
utils/$(OBJECT_DIR)/mmap_area.o: utils/mmap_area.c utils/utils.h \
  malloc/malloc_data.h libft/memory/memory.h
libft/memory/memory.h:
utils/$(OBJECT_DIR)/round_size.o: utils/round_size.c utils/utils.h \
  malloc/malloc_data.h
utils/$(OBJECT_DIR)/show_alloc_mem_utils.o: utils/show_alloc_mem_utils.c \
  malloc/malloc.h utils/utils.h malloc/malloc_data.h \
  libft/output/obuff.h
malloc/malloc.h:
libft/output/obuff.h:
utils/$(OBJECT_DIR)/unmap_area.o: utils/unmap_area.c utils/utils.h \
  malloc/malloc_data.h
