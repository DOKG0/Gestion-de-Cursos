program   := program
compiler  := g++
flags     := -std=c++17 -fconcepts

include_dir := Include
obj_dir   := Obj

src_files := $(shell find $(src_dir) -name "*.cpp")
obj_files := $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(src_files))

$(obj_dir)/%.o: $(src_dir)/%.cpp
	@mkdir -p $(@D)
	@$(compiler) $(flags) -I$(include_dir) -o $@ -c $<

$(program): $(obj_files)
	@$(compiler) $(flags) -o $(program) $^

all: build

build: $(program)

run: $(program)
	@./$(program)

clean:
	@rm -rf $(obj_dir)
	@rm -f $(program)

rebuild: clean build

.PHONY: all build clean rebuild run