#ifndef _MBEAM_IMAGENEX_MBEAMHANDLER_HPP_
#define _MBEAM_IMAGENEX_MBEAMHANDLER_HPP_

#include <iostream>
#include <iodrivers_base/Driver.hpp>
#include "Config.hpp"
#include "MBeamRaw.hpp"

namespace mbeam_imagenex
{
	class MBeamHandler : public iodrivers_base::Driver
	{
	 public: 
	  MBeamHandler(const Config& config = Config(), int max_packet_size = MBEAM_MAX_REPL_LENGTH, bool extract_last = false);
	  void sendExtCmd();
	 protected:
	   Config mConfig;
	};

} 

#endif 