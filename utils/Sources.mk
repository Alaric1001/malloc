## Auto generated make tool, don't edit manually.

OBJ_FILES_utils  :=  add_new_block.o \
               get_area_size.o \
               get_block_type.o \
               is_in_free_list.o \
               mmap_area.o \
               remove_from_free_lst.o \
               round_size.o \
               show_alloc_mem_utils.o \
               unmap_area.o
OBJECTS   += $(patsubst %, utils/$(OBJECT_DIR)/%, $(OBJ_FILES_utils))
