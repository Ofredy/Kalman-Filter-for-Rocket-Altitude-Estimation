# Complilation Rules
CXX = g++
FLAGS = -Wall -g
OUTPUT = rocket_attitude_estimation

# Paths
IDIR = ../include 
GAUSSIAN_LIB_PATH = ../libs/GaussianLib/include
ODIR = obj
DATA_PATH = results/data_rocket_altitude_estimation.txt
RESULTS_PLOT = results/rocket_altitude_kf_results.jpg

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
	if exist $(DATA_PATH) del $(DATA_PATH)
	if exist $(RESULTS_PLOT) del $(RESULTS_PLOT)
	if exist $(ODIR) rmdir /Q /S $(ODIR)	

# Print Files
echoes:
	@echo $(INCS)
	@echo $(CPP_FILES)
	@echo $(OBJS)
	