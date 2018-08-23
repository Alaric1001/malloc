## Auto generated make tool, don't edit manually.

OBJ_FILES_ft_malloc  :=  alloc_block.o \
               defrag_around_and_free.o \
               ft_calloc.o \
               ft_free.o \
               ft_malloc.o \
               ft_realloc.o \
               ft_show_alloc_mem.o \
               search_adress.o \
               search_in_areas.o
OBJECTS   += $(patsubst %, ft_malloc/$(OBJECT_DIR)/%, $(OBJ_FILES_ft_malloc))
