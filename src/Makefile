# Complilation Rules
CXX = g++
FLAGS = -Wall -g
OUTPUT = rocket_attitude_estimation

# Paths
IDIR = ../include 
GAUSSIAN_LIB_PATH = ../libs/GaussianLib/include
ODIR = obj

# Files
INCS = $(wildcard $(IDIR)/*.h)
CPP_FILES = $(wildcard *.cpp)
OBJS = $(CPP_FILES:%.cpp=$(ODIR)/%.o)

# Project Complilation
main: $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(OUTPUT)

$(ODIR)/%.o: %.cpp
	if not exist $(ODIR) mkdir $(ODIR)
	$(CXX) $(FLAGS) -I $(GAUSSIAN_LIB_PATH) -c $< -o $@

# Project Clean Up
clean:
	if exist $(OUTPUT).exe del $(OUTPUT).exe
	if exist $(ODIR) rmdir /Q /S $(ODIR)	

# Print Files
echoes:
	@echo $(INCS)
	@echo $(CPP_FILES)
	@echo $(OBJS)
	