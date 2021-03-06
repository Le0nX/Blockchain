# Главный makefile проекта. Сюда подключаются 
# Остальные файлы для сборки. 
TARGET := X

export BUILD
export TARGET

.PHONY: clean clean_all all create_file

clean: clean_all

clean_all:
	rm -rf .d
	rm -rf .obj
	rm -rf bin


#флаги оптимизации
BFLAGS += -Os

#Сборка сабмейкфайлов
all: .obj/x_seed
	@echo -Building $(TARGET) project
	@make all -j4 --makefile=main_sources.mk
	@echo -Building Crypto Module
	@make all -j4 --makefile=crypto/makefile
	@echo -Building src folder
	@make all -j4 --makefile=src/makefile
	@echo -Building HTTP Server
	@make all -j4 --makefile=web_server/makefile
	@echo Executing linker
	@make all --makefile=build_toolzzz/linker.mk
	
#Компиляция только, если есть изменения в файлах.	
.obj/%_seed :
	@make clean_all
	@mkdir .obj
	@touch $@
	
create_file:
	@mkdir .obj
	@touch $(patsubst %,.obj/%_seed,$(TARGET))