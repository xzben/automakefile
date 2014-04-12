#######################################################
# 配置参数
# 是否使用C++11 特性
USE_Cplusplus11 	= 1
#预编译宏每个宏之间用空格隔开
PRE_MARCO 	= LINUX_MACRO	LINUX_MACRO_TWO	
#扩展包含头文件目录
ADD_INCLUDE 	=
#扩展的库目录引用目录
ADD_LIBDIR	=
#要包含的库名
ADD_LIB		=
#编译生存的obj文件存放路径
BIN_DIR		=
#生成输出目录
OUTPUT_DIR	=
#生成的output的类型
# 1 代表生成可执行文件
# 2 代表生成静态库文件
# 3 代表生存动态库文件
OUTPUT_TYPE	= 3
#生文件的名字，不包括后缀
OUTPUT_NAME	= output

#####################################################################
#完整的输出名字
#strip 是去掉字符串两头的空格
OUTPUT_FULL_NAME =\
$(strip $(OUTPUT_DIR))$(shell if [ 2 -eq $(OUTPUT_TYPE) -o 3 -eq $(OUTPUT_TYPE) ];then echo -n "lib";fi)$(strip $(OUTPUT_NAME)).$(shell if [ 1 -eq $(OUTPUT_TYPE) ];then echo -n "out";elif [ 2 -eq $(OUTPUT_TYPE) ];then echo -n "a";elif [ 3 -eq $(OUTPUT_TYPE) ];then echo -n "so";fi)
#使用的编译器
CC		= g++
######################################################################
#编译器编译的配置参数
FLAGS		= \
 $(shell if [ 0 -ne $(USE_Cplusplus11) ];then echo "-std=c++11"; fi) \
 $(addprefix -D, $(PRE_MARCO))\
 $(addprefix -I, $(ADD_INCLUDE))\
 $(addprefix -L, $(ADD_LIBDIR))\
 $(addprefix -l, $(ADD_LIB))\

################################################################

#这个参数是FLAGS的扩展，主要是针对output文件生存的配置，		
FLAGS_LINK	= $(FLAGS)
 #需要编译的文件名，文件间用空格分隔
FILES		= $(shell ls *.c*) 	
#所有生成的obj名字
OBJECTS		= $(addprefix $(BIN_DIR), $(patsubst %.cpp,%.o,$(shell ls *.c*)))
#######################################################

all:pre_command $(OBJECTS)
	@if [ 1 -eq $(OUTPUT_TYPE) ];then\
		$(CC) -o $(OUTPUT_FULL_NAME) $(OBJECTS) $(FLAGS_LINK) ;\
	elif [ 2 -eq $(OUTPUT_TYPE) ];then\
		ar crs $(OUTPUT_FULL_NAME) $(OBJECTS);\
	elif [ 3 -eq $(OUTPUT_TYPE) ];then\
		$(CC) -shared -o $(OUTPUT_FULL_NAME) $(OBJECTS);\
	else \
		@echo "请选择选择正确 OUTPUT_TYPE";\
	fi

#先处理创建一些必要的目录
pre_command:
	$(shell if [ -n "$(BIN_DIR)" -a ! -e "$(BIN_DIR)" ];then mkdir -p $(BIN_DIR); fi) #创建obj输出目录 bin 目录
	$(shell if [ -n "$(OUTPUT_DIR)" -a ! -e "$(OUTPUT_DIR)" ];then mkdir -p $(OUTPUT_DIR); fi ) #创建output文件的输出目录

#自动匹配 OBJECTS 中需要的 *.o 目标文件	
$(BIN_DIR)%.o: %.c*
	$(CC) $(FLAGS) -c $< -o $@

#指定伪目标
.PHONY:clean clean_objs

#清除所有的生成文件，包括输出文件和生成的obj文件
clean:
	-rm $(OUTPUT_FULL_NAME) $(OBJECTS)

#只清除生成obj文件，不删除生成的输出文件
clean_objs:
	-rm $(OBJECTS)

echo:
	echo $(OBJECTS)
	echo $(OUTPUT_FULL_NAME)
