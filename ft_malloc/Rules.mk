## Auto generated make tool, don't edit manually.
ft_malloc/$(OBJECT_DIR)/%.o: ft_malloc/%.c
	$(COMP) $@ $<
ft_malloc/$(OBJECT_DIR)/alloc_block.o: ft_malloc/alloc_block.c \
 ft_malloc/algorithm.h ft_malloc/malloc_data.h utils/utils.h \
 libft/output/output.h
ft_malloc/algorithm.h:
ft_malloc/malloc_data.h:
utils/utils.h:
libft/output/output.h:
ft_malloc/$(OBJECT_DIR)/ft_free.o: ft_malloc/ft_free.c \
 ft_malloc/ft_malloc.h ft_malloc/algorithm.h ft_malloc/malloc_data.h \
 utils/utils.h libft/output/output.h libft/memory/memory.h
ft_malloc/ft_malloc.h:
libft/memory/memory.h:
ft_malloc/$(OBJECT_DIR)/ft_malloc.o: ft_malloc/ft_malloc.c \
 ft_malloc/ft_malloc.h ft_malloc/algorithm.h ft_malloc/malloc_data.h \
 utils/utils.h
ft_malloc/$(OBJECT_DIR)/ft_show_alloc_mem.o: \
 ft_malloc/ft_show_alloc_mem.c ft_malloc/ft_malloc.h utils/utils.h \
 ft_malloc/malloc_data.h libft/output/obuff.h libft/memory/memory.h
libft/output/obuff.h:
ft_malloc/$(OBJECT_DIR)/join_free_blocks_around.o: \
 ft_malloc/join_free_blocks_around.c ft_malloc/algorithm.h \
 ft_malloc/malloc_data.h utils/utils.h
ft_malloc/$(OBJECT_DIR)/search_in_areas.o: ft_malloc/search_in_areas.c \
 ft_malloc/algorithm.h ft_malloc/malloc_data.h utils/utils.h
