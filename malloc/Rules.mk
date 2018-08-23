## Auto generated make tool, don't edit manually.
malloc/$(OBJECT_DIR)/%.o: malloc/%.c
	$(COMP) $@ $<
malloc/$(OBJECT_DIR)/interface.o: malloc/interface.c malloc/malloc.h \
  ft_malloc/ft_malloc.h
malloc/malloc.h:
ft_malloc/ft_malloc.h:
