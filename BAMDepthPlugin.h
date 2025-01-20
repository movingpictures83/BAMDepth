#ifndef BAMDepthPLUGIN_H
#define BAMDepthPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class BAMDepthPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "BAMDepth";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
