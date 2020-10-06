#ifndef __Molecular_h__
#define __Molecular_h__

#include "Intracellular.h"

class Molecular
{
private:
public: 
    Molecular(); 
		
#ifdef LIBROADRUNNER
	// rrc::RRHandle model_rr;  // SBML, libRoadrunner
    librr rr_data;
#endif
};

#endif