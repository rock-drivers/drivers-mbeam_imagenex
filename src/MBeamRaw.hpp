#ifndef MBEAM_IMAGENEX_MBEAMRAW_HPP
#define MBEAM_IMAGENEX_MBEAMRAW_HPP

//#include "Config.hpp"
#include "MBeamTypes.hpp"

#include <stdint.h>
#include <vector>


namespace mbeam_imagenex {
  namespace raw {
    
#define MBEAM_CMD_LEN		0x100
#define MBEAM_HEADER1		0x45
#define MBEAM_HEADER2		0x43
#define MBEAM_REPL_START	0x38
#define MBEAM_MAX_REPL_LENGTH	0xEB60
#define MBEAM_REPLY_B		0x42
#define MBEAM_REPLY_P		0x50
#define MBEAM_DEFAULT_SV	1500


   
       
    struct MBeamExtCmd{
      uint8_t header1;
      uint8_t header2;
      uint8_t id;
      uint8_t ctrl_byte1;
      uint8_t ctrl_byte2;
      uint8_t ctrl_byte3;
      uint8_t ctrl_byte4;
      uint8_t range;
      uint8_t gain;
      uint8_t disp_gain;
      uint8_t gain_eq;
      uint8_t sector_size;
      uint8_t beam_width;
      uint8_t no_beams;
      uint8_t averaging;
      uint8_t reserved0;
      uint8_t reserved1;
      uint8_t sv_high;
      uint8_t sv_low;
      uint8_t mode;
      uint8_t out83p83b;
      uint8_t prof_pt_enable;
      uint8_t prof_min_range;
      uint8_t prof_min_lev;
      uint8_t xdcr_up_dn;
      uint8_t prof_tilt;
      uint8_t reserved2;
      uint8_t reserved3;
      uint8_t rec837;
      uint8_t rec83p;
      uint8_t reserved4;
      uint8_t reserved5;
      uint8_t reserved6;
      uint8_t reserved7;
      uint8_t prof_filter;
          
      MBeamExtCmd()
	: header1(MBEAM_HEADER1),
	  header2(MBEAM_HEADER2),
	  id(0),
	  ctrl_byte1(EXTERNALCONTROL),
	  ctrl_byte2(TRANSREC),
	  ctrl_byte3(0),
	  ctrl_byte4(0),
	  range(RANGE5),
	  gain(6),
	  disp_gain(50),
	  gain_eq(1),
	  sector_size(SEC120),
	  beam_width(WIDTHNORMAL),
	  no_beams(NUMBER240),
	  averaging(5),
	  reserved0(0),
	  reserved1(0),	  
	  mode(MODELINEAR),
	  out83p83b(OUT83P),
	  prof_pt_enable(1),
	  prof_min_range(0),
	  prof_min_lev(10),
	  xdcr_up_dn(XDRCDOWN),
	  prof_tilt(180),
	  reserved2(0),
	  reserved3(0),
	  rec837(0),
	  rec83p(1),
	  reserved4(0),
	  reserved5(0),
	  reserved6(0),
	  reserved7(0),
	  prof_filter(BOTTOMFOLLOW)  {
	   *((uint16_t*)(&sv_high)) = (uint16_t)MBEAM_DEFAULT_SV*10;
      }
      
      MBeamExtCmd & operator>>(std::vector<uint8_t>& msg)
      {
	msg.resize(MBEAM_CMD_LEN);
	msg[0] = header1;
	msg[1] = header2;
	msg[2] = id;
	msg[3] = ctrl_byte1;
	msg[4] = ctrl_byte2;
	msg[5] = ctrl_byte3;
	msg[6] = ctrl_byte4;
	msg[7] = range;
	msg[8] = gain;
	msg[9] = disp_gain;
	msg[10] = gain_eq;
	msg[11] = sector_size;
	msg[12] = beam_width;
	msg[13] = no_beams;
	msg[14] = averaging;
	msg[15] = reserved0;
	msg[16] = reserved1;
	msg[17] = sv_high;
	msg[18] = sv_low;
	msg[19] = mode;
	msg[20] = out83p83b;
	msg[21] = prof_pt_enable;
	msg[22] = prof_min_range;
	msg[23] = prof_min_lev;
	msg[24] = xdcr_up_dn;
	msg[25] = prof_tilt;
	msg[26] = reserved2;
	msg[27] = reserved3;
	msg[28] = rec837;
	msg[29] = rec83p;
	msg[30] = reserved4;
	msg[31] = reserved5;
	msg[32] = reserved6;
	msg[33] = reserved7;
	msg[34] = prof_filter;
	for(int i = 35;i<MBEAM_CMD_LEN;i++){
	  msg[i] = 0;
	}
	return *this;
      }
    };    
  }
}

#endif