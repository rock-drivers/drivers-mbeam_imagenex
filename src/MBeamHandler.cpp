
#include "MBeamHandler.hpp"
#include "MBeamRaw.hpp"

using namespace mbeam_imagenex;


MBeamHandler::MBeamHandler(const Config& config, int max_packet_size, bool extract_last)
    : iodrivers_base::Driver(max_packet_size,extract_last),
      mConfig(config)
{
}

void MBeamHandler::sendExtCmd()
{
  raw::MBeamExtCmd cmd;
  mConfig >> cmd;
  std::vector<uint8_t> msg;
  cmd >> msg;
  writePacket(msg.data(),msg.size());
}
#