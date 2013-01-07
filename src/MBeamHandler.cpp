
#include "MBeamHandler.hpp"
#include "MBeamRaw.hpp"
#include <iostream>


using namespace std;
using namespace mbeam_imagenex;

MBeamHandler::MBeamHandler(const Config& config, int max_packet_size, bool extract_last)
    : iodrivers_base::Driver(max_packet_size,extract_last),
      mConfig(config)
{
    mSonarScan.memory_layout_column = false; 
    mSonarScan.polar_coordinates = true;
}

void MBeamHandler::sendExtCmd()
{
  raw::MBeamExtCmd cmd;
  mConfig >> cmd;
  cout <<"SoundVelocity " <<mConfig.sound_velocity <<endl
       <<"gain " <<(int)mConfig.gain <<endl
       <<"range " <<mConfig.range <<endl;
  std::vector<uint8_t> msg;
  cmd >> msg;
  cout <<"writing bytes " <<msg.size() <<endl;
  writePacket(msg.data(),msg.size());
}

void MBeamHandler::setGain(const int& gain)
{
  if(gain < 0){
    mConfig.gain = 0;
    return;
  }
  if(gain > 20){
    mConfig.gain = 20;
    return;
  }
  mConfig.gain = gain;  
}

void MBeamHandler::setRange(const int& range)
{
  if(range <= 5){
    mConfig.range = RANGE5;
    return;
  }
  if(range <= 10){
    mConfig.range = RANGE10;
    return;
  }
  if(range <= 20){
    mConfig.range = RANGE20;
    return;
  }
  if(range <= 30){
    mConfig.range = RANGE30;
    return;
  }
  if(range <= 40){
    mConfig.range = RANGE40;
    return;
  }
  if(range <= 50){
    mConfig.range = RANGE50;
    return;
  }
  if(range <= 60){
    mConfig.range = RANGE60;
    return;
  }
  if(range <= 80){
    mConfig.range = RANGE80;
    return;
  }
  if(range <= 100){
    mConfig.range = RANGE100;
    return;
  }
  if(range <= 150){
    mConfig.range = RANGE150;
    return;
  }
  if(range <= 200){
    mConfig.range = RANGE200;
    return;
  }
  if(range <= 250){
    mConfig.range = RANGE250;
    return;
  }
  mConfig.range = RANGE300;
  return;
}

base::samples::SonarScan MBeamHandler::getData() const
{
  return mSonarScan;
}

void MBeamHandler::parseReply(const std::vector<uint8_t>* buffer)
{
  if(buffer->size()<89){
    cout <<"buffer incomplete" <<endl;
    return;
  }
  mSonarScan.time = base::Time::now();
  mSonarScan.time_beams.clear();
  mSonarScan.number_of_beams = (*buffer)[71];
  mSonarScan.number_of_beams |= (*buffer)[70] <<8;
  uint16_t val = (*buffer)[77];
  val |= (*buffer)[76] <<8;
  mSonarScan.start_bearing  = base::Angle::fromDeg(fabs(double(val)/100-180));
  val = (*buffer)[78];
  mSonarScan.angular_resolution = base::Angle::fromDeg(double(val)/100);
  if((*buffer)[83] & 0x80){
    val = (*buffer)[84];
    val |= ((*buffer)[83] & 0x7F) <<8;
    mSonarScan.speed_of_sound = float(val)/10;
  }
  else{
    mSonarScan.speed_of_sound = 1500;
  }
  float ang = 0;
  switch(mConfig.beam_width){
    case WIDTHWIDE: ang = 3;break;
    case WIDTHNORMAL: ang = 1.5;break;
    case WIDTHNARR:
    case WIDTHNARRMIX: ang = 0.75;break;
    default: ang = 0;break;
  }
  mSonarScan.beamwidth_horizontal = base::Angle::fromDeg(ang);
  mSonarScan.beamwidth_vertical = mSonarScan.beamwidth_horizontal ;
  size_t len = 0;
  
  if((*buffer)[2]==MBEAM_REPLY_B){
    mSonarScan.number_of_bins = (*buffer)[73];
    mSonarScan.number_of_bins |= (*buffer)[72] <<8;
    val = (*buffer)[88];
    val |= (*buffer)[87] <<8;
    mSonarScan.sampling_interval = double(val)/1000;
    len = (*buffer)[6];
    len |= (*buffer)[5] << 8;
    len |= (*buffer)[4] << 16;
  }
  else if((*buffer)[2]==MBEAM_REPLY_P){
    mSonarScan.number_of_bins = 1;
    mSonarScan.sampling_interval = 0;
    len = (*buffer)[5];
    len |= (*buffer)[4] <<8;
  }
  mSonarScan.data.clear();
  for (uint i = 256; i < len; i++){
    mSonarScan.data.push_back((*buffer)[i]);
  }
  cout << "number_of_beams " <<mSonarScan.number_of_beams <<endl
	<< "number_of_bins " <<mSonarScan.number_of_bins <<endl
	<< "start_bearing " <<mSonarScan.start_bearing <<endl
	<< "angular_resolution " <<mSonarScan.angular_resolution <<endl
	<< "sampling_interval " <<mSonarScan.sampling_interval <<endl
	<< "speed_of_sound " <<mSonarScan.speed_of_sound <<endl
	<< "datasize " <<mSonarScan.data.size() <<endl
	<< "datasize/beamnumber " <<mSonarScan.data.size()/mSonarScan.number_of_beams <<endl
	<< "len " <<len <<endl;
  return;
}