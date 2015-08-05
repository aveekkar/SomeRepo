##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Problems
ConfigurationName      :=Debug
WorkspacePath          := "/home/rik/STUFF/workspace/Test"
ProjectPath            := "/home/rik/STUFF/workspace/Test/problems"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Rik
Date                   :=04/08/15
CodeLitePath           :="/home/rik/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Problems.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/problemsMain.cpp$(ObjectSuffix) $(IntermediateDirectory)/BSTIterator.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/problemsMain.cpp$(ObjectSuffix): problemsMain.cpp $(IntermediateDirectory)/problemsMain.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/problems/problemsMain.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/problemsMain.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/problemsMain.cpp$(DependSuffix): problemsMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/problemsMain.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/problemsMain.cpp$(DependSuffix) -MM "problemsMain.cpp"

$(IntermediateDirectory)/problemsMain.cpp$(PreprocessSuffix): problemsMain.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/problemsMain.cpp$(PreprocessSuffix) "problemsMain.cpp"

$(IntermediateDirectory)/BSTIterator.cpp$(ObjectSuffix): BSTIterator.cpp $(IntermediateDirectory)/BSTIterator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/rik/STUFF/workspace/Test/problems/BSTIterator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BSTIterator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BSTIterator.cpp$(DependSuffix): BSTIterator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BSTIterator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BSTIterator.cpp$(DependSuffix) -MM "BSTIterator.cpp"

$(IntermediateDirectory)/BSTIterator.cpp$(PreprocessSuffix): BSTIterator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BSTIterator.cpp$(PreprocessSuffix) "BSTIterator.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


