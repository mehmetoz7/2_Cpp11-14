SUBDIRS := auto

.PHONY: $(SUBDIRS) subdirs

subdirs: $(SUBDIRS) 

$(SUBDIRS):
	@echo $@ "is being compiling..."
	$(MAKE) --directory=$@ $(TARGET)
clean:
	@echo $@ "is being cleaned..."
	$(MAKE) TARGET=clean
