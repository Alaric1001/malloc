## Auto generated make tool, don't edit manually.

OBJ_FILES_malloc  :=  alloc_block.o \
               join_free_blocks_around.o \
               malloc.o \
               search_in_areas.o \
               show_alloc_mem.o
OBJECTS   += $(patsubst %, malloc/$(OBJECT_DIR)/%, $(OBJ_FILES_malloc))
