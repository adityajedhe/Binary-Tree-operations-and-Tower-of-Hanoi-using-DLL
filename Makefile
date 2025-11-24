# Main Makefile

#TARGET_MAIN = main_target

OUTPUT_DIR := bin
Project_Common := Common
Project_BinaryTree := Binary_Tree_Operations
Project_HanoiTower := Tower_Of_Hanoi

TARGET := $(Project_BinaryTree) $(Project_HanoiTower)

all: $(TARGET)

$(TARGET):
	@$(MAKE) -s -C $@

clean:
	@for project in $(TARGET); do \
		$(MAKE) clean -s -C $$project; \
	done
	@echo "Cleaning output directory..."
	@rm -rf $(OUTPUT_DIR)

.PHONY: all clean $(TARGET)
