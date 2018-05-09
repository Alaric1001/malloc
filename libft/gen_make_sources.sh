#!/bin/bash

# This utility build each `subdir'/Sources.mk and `subdir'/Rules.mk
# where 'subdir` is given in parameters

for i in $*; do
	SOURCES_OUT="${i}/Sources.mk"
	echo -e "## Auto generated make tool, don't edit manually.\n" > "${SOURCES_OUT}"
	echo -n "OBJ_FILES_${i}  :=  " >> "${SOURCES_OUT}"

	ls "$i"/*.c | # list all the .c in the current subdirectory
	xargs -L1 basename | # just get the basename of these files
	sed -e '$ ! s/$/ &\\/g' | # putting a backslash at the end of each lines except the last one
	sed -e 's/\.c/\.o/g' | # replace .c to .o
	sed -e '2,$ s/^/&               /g' >> "${SOURCES_OUT}" #indent and output

	echo -n 'OBJECTS   += $(patsubst %, ' >> "${SOURCES_OUT}"
	echo -n "$i/" >> "${SOURCES_OUT}"
	echo -n '$(OBJECT_DIR)/%, $(' >> "${SOURCES_OUT}"
	echo "OBJ_FILES_${i}))" >> "${SOURCES_OUT}"

	RULES_OUT="${i}/Rules.mk"
	echo -e "## Auto generated make tool, don't edit manually.\n" > "${RULES_OUT}"
	echo "${i}/\$(OBJECT_DIR)/%.o: ${i}/%.c" >> "${RULES_OUT}"
	echo -e '\t$(COMP) $@ $<' >> "${RULES_OUT}"

done
