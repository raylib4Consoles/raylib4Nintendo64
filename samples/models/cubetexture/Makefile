BUILD_DIR=build
include $(N64_INST)/include/n64.mk

src = main.c
assets_png = $(wildcard assets/*.png)

assets_conv = $(addprefix filesystem/,$(notdir $(assets_png:%.png=%.sprite)))

MKSPRITE_FLAGS ?=

LDFLAGS += -lraylib
all: raylib.z64

filesystem/%.sprite: assets/%.png
	@mkdir -p $(dir $@)
	@echo "    [SPRITE] $@"
	echo @$(N64_MKSPRITE) -v -f RGBA16 --compress -o "$(dir $@)" "$<"
	@cp "$<" "$(dir $@)"

$(BUILD_DIR)/raylib.dfs: $(assets_conv)
$(BUILD_DIR)/raylib.elf: $(src:%.c=$(BUILD_DIR)/%.o)

raylib.z64: N64_ROM_TITLE="raylib"
raylib.z64: $(BUILD_DIR)/raylib.dfs

clean:
	rm -rf $(BUILD_DIR) filesystem/ raylib.z64

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean
