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
      uint8_t ctrlByte1;
      uint8_t ctrlByte2;
      uint8_t ctrlByte3;
      uint8_t ctrlByte4;
      uint8_t range;
      uint8_t gain;
      uint8_t dispGain;
      uint8_t gainEQ;
      uint8_t sectorSize;
      uint8_t beamWidth;
      uint8_t noBeams;
      uint8_t averaging;
      uint8_t reserved0;
      uint8_t reserved1;
      uint8_t svHigh;
      uint8_t svLow;
      uint8_t mode;
      uint8_t out83p83b;
      uint8_t profPtEnable;
      uint8_t profMinRange;
      uint8_t profMinLev;
      uint8_t xdcrUpDn;
      uint8_t profTilt;
      uint8_t reserved2;
      uint8_t reserved3;
      uint8_t rec837;
      uint8_t rec83p;
      uint8_t reserved4;
      uint8_t reserved5;
      uint8_t reserved6;
      uint8_t reserved7;
      uint8_t profFilter;
          
      MBeamExtCmd()
	: header1(MBEAM_HEADER1),
	  header2(MBEAM_HEADER2),
	  id(0),
	  ctrlByte1(EXTERNALCONTROL),
	  ctrlByte2(TRANSREC),
	  ctrlByte3(0),
	  ctrlByte4(0),
	  range(RANGE5),
	  gain(6),
	  dispGain(50),
	  gainEQ(1),
	  sectorSize(SEC120),
	  beamWidth(WIDTHNORMAL),
	  noBeams(NUMBER240),
	  averaging(5),
	  reserved0(0),
	  reserved1(0),	  
	  mode(MODELINEAR),
	  out83p83b(OUT83P),
	  profPtEnable(1),
	  profMinRange(0),
	  profMinLev(10),
	  xdcrUpDn(XDRCDOWN),
	  profTilt(180),
	  reserved2(0),
	  reserved3(0),
	  rec837(0),
	  rec83p(1),
	  reserved4(0),
	  reserved5(0),
	  reserved6(0),
	  reserved7(0),
	  profFilter(BOTTOMFOLLOW)  {
	   *((uint16_t*)(&svHigh)) = (uint16_t)MBEAM_DEFAULT_SV*10;
      }
      
      MBeamExtCmd & operator>>(std::vector<uint8_t>& msg)
      {
	msg.resize(MBEAM_CMD_LEN);
	msg[0] = header1;
	msg[1] = header2;
	msg[2] = id;
	msg[3] = ctrlByte1;
	msg[4] = ctrlByte2;
	msg[5] = ctrlByte3;
	msg[6] = ctrlByte4;
	msg[7] = range;
	msg[8] = gain;
	msg[9] = dispGain;
	msg[10] = gainEQ;
	msg[11] = sectorSize;
	msg[12] = beamWidth;
	msg[13] = noBeams;
	msg[14] = averaging;
	msg[15] = reserved0;
	msg[16] = reserved1;
	msg[17] = svHigh;
	msg[18] = svLow;
	msg[19] = mode;
	msg[20] = out83p83b;
	msg[21] = profPtEnable;
	msg[22] = profMinRange;
	msg[23] = profMinLev;
	msg[24] = xdcrUpDn;
	msg[25] = profTilt;
	msg[26] = reserved2;
	msg[27] = reserved3;
	msg[28] = rec837;
	msg[29] = rec83p;
	msg[30] = reserved4;
	msg[31] = reserved5;
	msg[32] = reserved6;
	msg[33] = reserved7;
	msg[34] = profFilter;
	for(int i = 35;i<MBEAM_CMD_LEN;i++){
	  msg[i] = 0;
	}
	return *this;
      }
    };    
  }
}

#endif