#ifndef _MBEAM_IMAGENEX_CONFIG_HPP_
#define _MBEAM_IMAGENEX_CONFIG_HPP_

#include "MBeamRaw.hpp"
#include "MBeamTypes.hpp"

namespace mbeam_imagenex
{

struct Config
{
      MBeamCtrl ctrl;
      MBeamTrans trans;
      MBeamRange range;
      uint8_t gain;
      uint8_t dispGain;
      bool gainEQ;
      MBeamSectorSize sectorSize;
      MBeamWidth beamWidth;
      MBeamNo noBeams;
      uint8_t averaging;
      uint16_t soundVelocity;
      MBeamMode mode;
      MBeamOut out83p83b;
      bool profPtEnable;
      uint8_t profMinRange;
      uint8_t profMinLev;
      MBeamXdrc xdcrUpDn;
      int profTilt;
      bool rec837;
      bool rec83p;
      MBeamProfPFilter profFilter;
      
      
      Config()
	: ctrl(EXTERNALCONTROL),
	  trans(TRANSREC),
	  range(RANGE5),
	  gain(6),
	  dispGain(50),
	  gainEQ(true),
	  sectorSize(SEC90),
	  beamWidth(WIDTHNORMAL),
	  noBeams(NUMBER240),
	  averaging(5),
	  soundVelocity(MBEAM_DEFAULT_SV),
	  mode(MODELINEAR),
	  out83p83b(OUT83P),
	  profPtEnable(1),
	  profMinRange(0),
	  profMinLev(10),
	  xdcrUpDn(XDRCDOWN),
	  profTilt(0),
	  rec837(false),
	  rec83p(true),
	  profFilter(BOTTOMFOLLOW) 
     {   
     } 
     
     Config& operator>>(raw::MBeamExtCmd& cmd)
     {
	  cmd.header1 = MBEAM_HEADER1;
	  cmd.header2 = MBEAM_HEADER2;
	  cmd.id = 0;
	  cmd.ctrlByte1 = ctrl;
	  cmd.ctrlByte2 = trans;
	  cmd.ctrlByte3 = 0;
	  cmd.ctrlByte4 = 0;
	  cmd.range = range;
	  cmd.gain = gain;
	  cmd.dispGain = dispGain;
	  cmd.gainEQ = gainEQ;
	  cmd.sectorSize = sectorSize;
	  cmd.beamWidth = beamWidth;
	  cmd.noBeams = noBeams;
	  cmd.averaging = averaging;
	  cmd.reserved0 = 0;
	  cmd.reserved1 = 0;  
	  cmd.svHigh = (soundVelocity*10 >> 8) & 0xFF;
	  cmd.svLow = (soundVelocity*10) & 0xFF;
	  cmd.mode = mode;
	  cmd.out83p83b = out83p83b;
	  cmd.profPtEnable = profPtEnable;
	  cmd.profMinRange = profMinRange;
	  cmd.profMinLev = profMinLev;
	  cmd.xdcrUpDn = xdcrUpDn;
	  cmd.profTilt = profTilt+180;
	  cmd.reserved2 = 0;
	  cmd.reserved3 = 0;
	  cmd.rec837 = rec837;
	  cmd.rec83p = rec83p;
	  cmd.reserved4 = 0;
	  cmd.reserved5 = 0;
	  cmd.reserved6 = 0;
	  cmd.reserved7 = 0;
	  cmd.profFilter = profFilter;
	  return *this;
    }
};

}

#endif