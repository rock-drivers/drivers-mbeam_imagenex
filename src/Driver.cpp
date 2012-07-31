#include "Driver.hpp"
#include <iostream>

using namespace mbeam_imagenex;
using namespace std;

Driver::Driver(const Config& config, int max_packet_size, bool extract_last)
  : MBeamHandler(config,max_packet_size,extract_last)
{
}



void Driver::open(std::string const& uri)
{
    cout <<"open" <<endl;
    openURI(uri);
}

void Driver::collectData()
{
  read(2000);
}

void Driver::read(int timeout)
{
   std::vector<uint8_t> buffer(MBEAM_MAX_REPL_LENGTH);

    try {
        int size = readPacket(&buffer[0], buffer.size());
	cout << "received bytes " <<size <<endl;
	if(size){
	  parseReply(&buffer);
	}
    } catch ( std::runtime_error &e) {
        throw;
    }
}

int Driver::extractPacket (uint8_t const *buffer, size_t buffer_size) const
{
  cout <<"extractPacket " <<buffer_size <<endl;
  for (size_t i = 0; i < buffer_size; i++) {
    if (buffer[i] == MBEAM_REPL_START)
    {
      if(i){
	return -i;
      }
      if(buffer_size<7){
	return 0;
      }
      size_t len = 32;
      if(buffer[2]==MBEAM_REPLY_B){
	len = buffer[6];
	len |= (buffer[5] << 8);
	len |= (buffer[4] << 16);
      }
      else if(buffer[2]==MBEAM_REPLY_P){
	len = buffer[5];
	len |= (buffer[4] <<8);
      }
      cout <<"length: " <<len <<endl;
      if(buffer_size >= len){
	return len;
      }
      return 0;
    }
  }
  return -buffer_size;  
}

	
 