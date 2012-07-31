#ifndef _MBEAM_IMAGENEX_MBEAMHANDLER_HPP_
#define _MBEAM_IMAGENEX_MBEAMHANDLER_HPP_

#include <iostream>
#include <iodrivers_base/Driver.hpp>
#include "base/samples/sonar_scan.h"
#include "Config.hpp"
#include "MBeamRaw.hpp"

namespace mbeam_imagenex
{
	class MBeamHandler : public iodrivers_base::Driver
	{
	 public: 
	  MBeamHandler(const Config& config = Config(), int max_packet_size = MBEAM_MAX_REPL_LENGTH, bool extract_last = false);
	  void sendExtCmd();
	  base::samples::SonarScan getData() const;
	 protected:
	   Config mConfig;
	   base::samples::SonarScan mSonarScan;
	   virtual void parseReply(const std::vector<uint8_t>* buffer);
	};

} 

#endif 