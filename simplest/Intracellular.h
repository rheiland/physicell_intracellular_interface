#ifndef __Intracellular_h__
#define __Intracellular_h__

//  g++ "-D LIBROADRUNNER"  (or, -U)  

#ifdef LIBROADRUNNER
#include "lib_roadrunner.h"
// #include "rrc_api.h"
// #include "rrc_types.h"
// extern "C" rrc::RRHandle createRRInstance();
#endif // LIBROADRUNNER


#ifdef LIBFBA
#include "lib_fba.h"
#endif

#ifdef LIBMABOSS
#include "lib_maboss.h"
#endif

// class Intracellular
// {
// private:
// public:
//     Intracellular();
// };

#endif