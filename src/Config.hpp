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
      uint8_t disp_gain;
      bool gain_eq;
      MBeamSectorSize sector_size;
      MBeamWidth beam_width;
      MBeamNo no_beams;
      uint8_t averaging;
      uint16_t sound_velocity;
      MBeamMode mode;
      MBeamOut out83p83b;
      bool prof_pt_enable;
      uint8_t prof_min_range;
      uint8_t prof_min_lev;
      MBeamXdrc xdcr_up_dn;
      int prof_tilt;
      bool rec837;
      bool rec83p;
      MBeamProfPFilter prof_filter;
      
      
      Config()
	: ctrl(EXTERNALCONTROL),
	  trans(TRANSREC),
	  range(RANGE5),
	  gain(6),
	  disp_gain(50),
	  gain_eq(true),
	  sector_size(SEC90),
	  beam_width(WIDTHNORMAL),
	  no_beams(NUMBER240),
	  averaging(5),
	  sound_velocity(MBEAM_DEFAULT_SV),
	  mode(MODELINEAR),
	  out83p83b(OUT83P),
	  prof_pt_enable(1),
	  prof_min_range(0),
	  prof_min_lev(10),
	  xdcr_up_dn(XDRCDOWN),
	  prof_tilt(0),
	  rec837(false),
	  rec83p(true),
	  prof_filter(BOTTOMFOLLOW) 
     {   
     } 
     
     Config& operator>>(raw::MBeamExtCmd& cmd)
     {
	  cmd.header1 = MBEAM_HEADER1;
	  cmd.header2 = MBEAM_HEADER2;
	  cmd.id = 0;
	  cmd.ctrl_byte1 = ctrl;
	  cmd.ctrl_byte2 = trans;
	  cmd.ctrl_byte3 = 0;
	  cmd.ctrl_byte4 = 0;
	  cmd.range = range;
	  cmd.gain = gain;
	  cmd.disp_gain = disp_gain;
	  cmd.gain_eq = gain_eq;
	  cmd.sector_size = sector_size;
	  cmd.beam_width = beam_width;
	  cmd.no_beams = no_beams;
	  cmd.averaging = averaging;
	  cmd.reserved0 = 0;
	  cmd.reserved1 = 0;  
	  cmd.sv_high = (sound_velocity*10 >> 8) & 0xFF;
	  cmd.sv_low = (sound_velocity*10) & 0xFF;
	  cmd.mode = mode;
	  cmd.out83p83b = out83p83b;
	  cmd.prof_pt_enable = prof_pt_enable;
	  cmd.prof_min_range = prof_min_range;
	  cmd.prof_min_lev = prof_min_lev;
	  cmd.xdcr_up_dn = xdcr_up_dn;
	  cmd.prof_tilt = prof_tilt+180;
	  cmd.reserved2 = 0;
	  cmd.reserved3 = 0;
	  cmd.rec837 = rec837;
	  cmd.rec83p = rec83p;
	  cmd.reserved4 = 0;
	  cmd.reserved5 = 0;
	  cmd.reserved6 = 0;
	  cmd.reserved7 = 0;
	  cmd.prof_filter = prof_filter;
	  return *this;
    }
};

}

#endif