#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "BAMDepthPlugin.h"

void BAMDepthPlugin::input(std::string file) {
   readParameterFile(file);
}

void BAMDepthPlugin::run() {}

void BAMDepthPlugin::output(std::string file) {
       	std::string outputfile = file;
//Avg_depth_ont=$(samtools depth ./ont_alignments/contig_${i}_reads.bam | awk '{sum+=$3; count++} END {if (count > 0) print sum/count; else print "0"}')
//#echo -e "contig_${i}\t${Avg_depth_ont}" >> ./stats/Avg_depth_ont.txt


	std::string myCommand = "while read -r line; do Avg_depth_ont=$(samtools depth "+PluginManager::addPrefix(myParameters["alignmentdir"])+"/\"${line}\"_reads.bam | awk '{sum+=$3; count++} END {if (count > 0) print sum/count; else print \"0\"}'); echo -e \"${line}\t${Avg_depth_ont}\" >> "+file+"; done < "+PluginManager::addPrefix(myParameters["contigs"]);
		
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<BAMDepthPlugin> BAMDepthPluginProxy = PluginProxy<BAMDepthPlugin>("BAMDepth", PluginManager::getInstance());
