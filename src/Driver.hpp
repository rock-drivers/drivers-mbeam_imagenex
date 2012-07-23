#ifndef _MBEAM_IMAGENEX_DRIVER_HPP_
#define _MBEAM_IMAGENEX_DRIVER_HPP_

#include <iostream>
#include "MBeamHandler.hpp"

namespace mbeam_imagenex
{
	class Driver : public MBeamHandler
	{
	  public: 
	    Driver(const Config& config = Config(), int max_packet_size = MBEAM_MAX_REPL_LENGTH, bool extract_last = false);
	    
	    void open(std::string const& uri);
	    
	    void collectData();
      
	  protected:  
     
	    /** reading reply  */
	    virtual void read(int timeout);

	    /** Extract a valid response from incoming Data
	    *
	    */
	    virtual int extractPacket (uint8_t const *buffer, size_t buffer_size) const;
	};

} 

#endif 
