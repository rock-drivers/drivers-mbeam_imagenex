#ifndef MBEAM_IMAGENEX_MBEAMTYPES_HPP
#define MBEAM_IMAGENEX_MBEAMTYPES_HPP

namespace mbeam_imagenex{

 enum MBeamCtrl{
      LOCALCONTROL,
      EXTERNALCONTROL
    };
    
    enum MBeamTrans{
      TRANSREC,
      RECONLY
    };
    
    enum MBeamRange{
      RANGE5 = 2,
      RANGE10 = 3,
      RANGE20 = 4,
      RANGE30 = 5,
      RANGE40 = 6,
      RANGE50 = 7,
      RANGE60 = 8,
      RANGE80 = 9,
      RANGE100 = 10,
      RANGE150 = 11,
      RANGE200 = 12,
      RANGE250 = 13,
      RANGE300 = 14      
    };
    
    enum MBeamSectorSize{
      SEC30,
      SEC60,
      SEC90,
      SEC120
    };
    
    enum MBeamWidth{
      WIDTHWIDE,
      WIDTHNORMAL,
      WIDTHNARR,
      WIDTHNARRMIX,
    };    
    
    enum MBeamNo{
      NUMBER480,
      NUMBER240,
      NUMBER120,
    };
    
    enum MBeamMode{
      MODESECTOR,
      MODELINEAR,
      MODEPERSP,
      MODEPROF,
      MODEBEAMTEST
    };
    
    enum MBeamOut{
      OUT83P,
      OUT83B
    };
    
    enum MBeamXdrc{
      XDRCDOWN,
      XDRCUP,
    };

    enum  MBeamProfPFilter{
      FIRSTRETURN,
      MAXRETURN,
      BOTTOMFOLLOW
    };

    
}
    
#endif