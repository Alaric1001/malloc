## Auto generated make tool, don't edit manually.

OBJ_FILES_ft_malloc  :=  alloc_block.o \
               ft_free.o \
               ft_malloc.o \
               ft_show_alloc_mem.o \
               join_free_blocks_around.o \
               search_in_areas.o
OBJECTS   += $(patsubst %, ft_malloc/$(OBJECT_DIR)/%, $(OBJ_FILES_ft_malloc))
