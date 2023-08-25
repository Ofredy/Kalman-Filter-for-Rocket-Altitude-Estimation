# Complilation Rules
CXX = g++
FLAGS = -g
OUTPUT = kalman_filter

# Paths
IDIR =../include
ODIR = obj

# Files
INCS = $(wildcard $(IDIR)/*.h)
CPP_FILES = $(wildcard *.cpp)
OBJS = $(CPP_FILES:%.cpp=$(ODIR)/%.o)

main: $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(OUTPUT)

$(ODIR)/%.o: %.cpp
	if not exist $(ODIR) mkdir $(ODIR)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	if exist $(OUTPUT).exe del $(OUTPUT).exe
	if exist $(ODIR) rmdir /Q /S $(ODIR)	

# Print Files
echoes:
	@echo $(INCS)
	@echo $(CPP_FILES)
	@echo $(OBJS)
	