CPP = g++ -std=c++11
C_FLAGS = -fPIC -g -c
LINK = g++ -std=c++11 -fPIC -g 

OBJS = BCNF.o BCNFCalculator.o BCNFTester.o FunctionalDependency.o Set.o

BCNF: $(OBJS)
	$(LINK) -o BCNF $(OBJS)
    
BCNF.o: BCNF.cpp
	$(CPP) $(C_FLAGS) BCNF.cpp
BCNFCalculator.o: BCNFCalculator.h BCNFCalculator.cpp
	$(CPP) $(C_FLAGS) BCNFCalculator.cpp
BCNFTester.o: BCNFTester.h BCNFTester.cpp
	$(CPP) $(C_FLAGS) BCNFTester.cpp
FunctionalDependency.o: FunctionalDependency.h FunctionalDependency.cpp
	$(CPP) $(C_FLAGS) FunctionalDependency.cpp
Set.o: Set.h Set.cpp
	$(CPP) $(C_FLAGS) Set.cpp
