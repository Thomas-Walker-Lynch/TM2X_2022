# local makefile
# without customization it doesn't do much
# no sharing or installing targets defined in the lib/makefile-cc yet, should share to $(RESOURCES)

# this file is also included into lib/makefile-cc
-include $(RESOURCE)/library/makefile-environment
-include makefile-environment

.PHONY: all 
all: version

.PHONY: dependency
dependency:
	if [ -e $(DEPFILE) ]; then rm $(DEPFILE); fi
	$(MAKE) $@

.PHONY: library
library:
	$(MAKE) $@

.PHONY: cantari
cantari:
	$(MAKE) $@

.PHONY: share
share:
	$(MAKE) $@

.PHONY: clean
clean:
	$(MAKE) $@

.PHONY: dist-clean
dist-clean:
	$(MAKE) $@

%::
	$(MAKE) $@




