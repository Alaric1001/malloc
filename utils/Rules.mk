## Auto generated make tool, don't edit manually.
utils/$(OBJECT_DIR)/%.o: utils/%.c
	$(COMP) $@ $<
utils/$(OBJECT_DIR)/add_new_block.o: utils/add_new_block.c utils/utils.h \
 ft_malloc/malloc_data.h
utils/utils.h:
ft_malloc/malloc_data.h:
utils/$(OBJECT_DIR)/get_area_size.o: utils/get_area_size.c utils/utils.h \
 ft_malloc/malloc_data.h
utils/$(OBJECT_DIR)/get_block_type.o: utils/get_block_type.c \
 utils/utils.h ft_malloc/malloc_data.h
utils/$(OBJECT_DIR)/is_in_free_list.o: utils/is_in_free_list.c \
 utils/utils.h ft_malloc/malloc_data.h
utils/$(OBJECT_DIR)/mmap_area.o: utils/mmap_area.c utils/utils.h \
 ft_malloc/malloc_data.h libft/memory/memory.h
libft/memory/memory.h:
utils/$(OBJECT_DIR)/remove_from_free_lst.o: utils/remove_from_free_lst.c \
 utils/utils.h ft_malloc/malloc_data.h
utils/$(OBJECT_DIR)/round_size.o: utils/round_size.c utils/utils.h \
 ft_malloc/malloc_data.h
utils/$(OBJECT_DIR)/show_alloc_mem_utils.o: utils/show_alloc_mem_utils.c \
 ft_malloc/ft_malloc.h utils/utils.h ft_malloc/malloc_data.h \
 libft/output/obuff.h
ft_malloc/ft_malloc.h:
libft/output/obuff.h:
utils/$(OBJECT_DIR)/unmap_area.o: utils/unmap_area.c utils/utils.h \
 ft_malloc/malloc_data.h
